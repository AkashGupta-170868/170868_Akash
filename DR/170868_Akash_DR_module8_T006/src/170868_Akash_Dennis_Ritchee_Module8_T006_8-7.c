/*
Descripton: malloc accepts a size request without checking its plausibility; free believes
that the block it is asked to free contains a valid size field. Improve these routines so they make
more pains with error checking.
Author : Akash Gupta
Created At: 04-05-2026
Modified At: 04-05-2026
 */
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

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

void myfree(void *ap);
static Header *morecore(unsigned nu);

/*Function name: malloc function
Descripton: allocates the memory as per request.
Author : Akash Gupta
Created At: 04-05-2026
 */
void *mymalloc(unsigned nbytes)
{
	Header *p, *prevp;
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
/*Function name: morecore
Descripton: request more memory from OS
Author : Akash Gupta
Created At: 04-05-2026
 */ 
static Header *morecore(unsigned nu)
{
	char *cp;
	Header *up;

	if (nu < 1024)
		nu = 1024;

	cp = sbrk(nu * sizeof(Header));

	if (cp == (char *) -1)
		return NULL;

	up = (Header *) cp;
	up->s.size = nu;

	myfree((void *)(up + 1));

	return freep;
}

/*Function name: myfree()
Descripton: free the allocated memory.
Author : Akash Gupta
Created At: 04-05-2026
 */
void myfree(void *ap)
{
	Header *bp, *p;

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
#define MAX_SIZE 10000

int32_t malloc_main()
{
	int32_t size;
	void *ptr;

	printf("Enter allocation size: ");
	scanf("%d", &size);

	if (size <= 0 || size > MAX_SIZE)
	{
		printf("Error: Invalid allocation size %d bytes.\n", size);
		return 1;
	}

	ptr = mymalloc(size);

	if (ptr == NULL)
	{
		printf("Allocation failed.\n");
		return 1;
	}

	printf("Successful allocation of %d bytes.\n", size);

	myfree(ptr);

	printf("Memory freed successfully.\n");

	return 0;
}
