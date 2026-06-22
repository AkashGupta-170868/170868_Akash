#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#define NALLOC 1024

typedef long Align;

union header {
	struct {
		union header *ptr;
		unsigned size;
	} s;
	Align x;
};

typedef union header Header;

static Header base;
static Header *freep = NULL;
static Align buffer[5000 / sizeof(Align)];

static void myfree(void *ap);
static void *mymalloc(unsigned nbytes);
static Header *morecore(unsigned nu);
static void bfree(void *ptr, unsigned num);


/* Function Name: morecore()
 * Description: Request memory from system
 */
static Header *morecore(unsigned nu)
{
	char *cp;
	Header *up;

	if (nu < NALLOC)
		nu = NALLOC;

	cp = sbrk(nu * sizeof(Header));

	if (cp == (char *)-1)
		return NULL;

	up = (Header *)cp;
	up->s.size = nu;

	myfree((void *)(up + 1));

	return freep;
}


/* Function Name: mymalloc()
 * Description: Allocate memory
 */
static void *mymalloc(unsigned nbytes)
{
	Header *p;
	Header *prevp;
	unsigned nunits;

	nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

	if ((prevp = freep) == NULL) {
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}

	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {

		if (p->s.size >= nunits) {

			if (p->s.size == nunits)
				prevp->s.ptr = p->s.ptr;
			else {
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}

			freep = prevp;
			return (void *)(p + 1);
		}

		if (p == freep)
			if ((p = morecore(nunits)) == NULL)
				return NULL;
	}
}


/* Function Name: myfree()
 * Description: Free allocated memory
 */
static void myfree(void *ap)
{
	Header *bp;
	Header *p;

	bp = (Header *)ap - 1;

	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break;

	if (bp + bp->s.size == p->s.ptr) {
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	} else
		bp->s.ptr = p->s.ptr;

	if (p + p->s.size == bp) {
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else
		p->s.ptr = bp;

	freep = p;
}


/* Function Name: bfree()
 * Description: Free arbitrary block into free list
 */
static void bfree(void *ptr, unsigned num)
{
	Header *hp;
	unsigned nunits;

	if (ptr == NULL) {
		printf("bfree: NULL pointer\n");
		return;
	}

	if ((uintptr_t)ptr % sizeof(Header) != 0) {
		printf("bfree: unaligned pointer\n");
		return;
	}

	if (num < 2 * sizeof(Header)) {
		printf("bfree: block too small\n");
		return;
	}

	if (freep == NULL) {
		base.s.ptr = freep = &base;
		base.s.size = 0;
	}

	nunits = num / sizeof(Header);

	hp = (Header *)ptr;
	hp->s.size = nunits;

	myfree((void *)(hp + 1));
}

int displaybfree(void)
{
	void *p;
	void *q;

	printf("Adding static buffer using bfree...\n");

	bfree(NULL, sizeof(buffer));

	p = mymalloc(100);
	q = mymalloc(200);

	printf("Allocated p = %p\n", p);
	printf("Allocated q = %p\n", q);

	myfree(p);
	myfree(q);

	printf("Memory freed successfully\n");

	return 0;
}
