/*
 * The standard library function int fseek(FILE *fp, long offset, int origin) is identical to lseek except that fp is a file pointer
 * instead of a file descriptor and return value is an int status, not a position. Write fseek.
 * Make sure that your fseek coordinates properly with the buffering done for the other functions of the library.
 * Author: Akash Gupta
 * Created: 29 April, 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 8
#define MYEOF (-1)

/* Custom FILE structure */
typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	int fd;

	int read;
	int write;
	int eof;
	int err;
} FILE_CUSTOM;

static int mygetc(FILE_CUSTOM *fp);
static int myfseek(FILE_CUSTOM *fp, long offset, int origin);
static int fillbuf(FILE_CUSTOM *fp);
static int myfclose(FILE_CUSTOM *fp);
static FILE_CUSTOM *myfopen(char *name, char *mode);
/*
 * Function Name: myfopen()
 * Function Description: This function is open the file according it's mode.
 * Author: Akash Gupta
 * Created: 29 April, 2026
 */

static FILE_CUSTOM *myfopen(char *name, char *mode)
{
	int fd;
	FILE_CUSTOM *fp;

	fp = (FILE_CUSTOM *)malloc(sizeof(FILE_CUSTOM));

	if(fp == NULL)
		return NULL;

	if(*mode == 'r')
		fd = open(name, O_RDONLY);
	else
		return NULL;

	if(fd == -1)
	{
		free(fp);
		return NULL;
	}

	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->ptr = NULL;
	fp->read = 1;
	fp->write = 0;
	fp->eof = 0;
	fp->err = 0;

	return fp;
}

/*
 * Function Name: fillbuf();
 * Function Description: This function use buffer if unbuff is zero and if unbuff is non-zero then don't use buffer.
 * Author: Akash Gupta
 * Created: 29 April, 2026
 */
static int fillbuf(FILE_CUSTOM *fp)
{
	if(fp == NULL || fp->read == 0)
		return MYEOF;

	if(fp->base == NULL)
		fp->base = (char *)malloc(BUFSIZE);

	if(fp->base == NULL)
		return MYEOF;

	fp->ptr = fp->base;

	fp->cnt = read(fp->fd, fp->ptr, BUFSIZE);

	if(fp->cnt <= 0)
	{
		fp->cnt = 0;
		return MYEOF;
	}

	fp->cnt--;

	return *(fp->ptr++);
}

/*
 * Function Name: mygetc();
 * Function Description: get charcters as a size of bufsize at once .
 * Author: Akash Gupta
 * Created: 29 April, 2026
 */
static int mygetc(FILE_CUSTOM *fp)
{
	if(--fp->cnt >= 0)
		return *(fp->ptr++);
	else
		return fillbuf(fp);
}
/* Function Name: myfseek()
 * Function Description: This function perform lseek() system call and update file pointer at specific offset.
 * Author: Akash Gupta
 * Created: 28 April, 2026
 */
static int myfseek(FILE_CUSTOM *fp, long offset, int origin)
{
	if(fp == NULL)
		return -1;

	if(fp->read == 1)
	{
		if(origin == SEEK_CUR)
			offset = offset - fp->cnt;

		fp->cnt = 0;
		fp->ptr = fp->base;
	}

	if(lseek(fp->fd, offset, origin) == -1)
		return -1;

	return 0;
}

/* Function Name: myfclose()
 * Function Description: 
 * Author: Akash Gupta
 * Created: 29 April, 2026
 */
static int myfclose(FILE_CUSTOM *fp)
{
	int fd;

	if(fp == NULL)
		return -1;

	fd = fp->fd;

	free(fp->base);
	free(fp);

	return close(fd);
}

/*
 * Function Name: fseek_main();
 * Function Description: main handling all the function and test fseek function .
 * Author: Akash Gupta
 * Created: 29 April, 2026
 */
int fseek_main(int argc, char *argv[])
{
	FILE_CUSTOM *fp;
	char ch;

	if(argc != 3)
	{
		printf("Usage: %s filename\n", argv[0]);
		return 1;
	}

	fp = myfopen(argv[2], "r");

	if(fp == NULL)
	{
		printf("File open error\n");
		return 1;
	}

	if(myfseek(fp, 5, SEEK_SET) == 0){
		while ((ch = mygetc(fp)) != EOF) {
			putchar(ch);
		}
	}else{
		printf("not possible!\n");
	}
	myfclose(fp);

	return 0;
}
