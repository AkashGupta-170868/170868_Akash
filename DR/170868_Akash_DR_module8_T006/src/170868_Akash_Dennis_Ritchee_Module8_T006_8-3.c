/*
description :Design and write _flushbuf, fflush, and fclose. 
Author : Akash Gupta
Modified At : 28-04-2026
Created At: 28-04-2026
 */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define NULL 0
#define EOF (-1)
#define BUFSIZE 1024
#define OPEN_MAX 20

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	int fd;

	int is_read;
	int is_write;
	int is_unbuf;
	int is_eof;
	int is_err;
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin  (&_iob[0])
#define stdout (&_iob[1])

int _fillbuf(FILE *fp);
int _flushbuf(int c, FILE *fp);
int fflush(FILE *fp);
int fclose(FILE *fp);
FILE *fopen(char *name, char *mode);

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), (p)))
/*
description : _flushbuf() flushes the output buffer by writing its contents to the file and resetting the buffer for further use.
Author : Akash Gupta
Modified At : 28-04-2026
Created At: 28-04-2026
 */
int _flushbuf(int c, FILE *fp) {
	int n;

	if (!fp->is_write || fp->is_err)
		return EOF;

	/* unbuffered */
	if (fp->is_unbuf) {
		if (c == EOF)
			return EOF;

		if (write(fp->fd, &c, 1) != 1) {
			fp->is_err = 1;
			return EOF;
		}
		return c;
	}

	/* allocate buffer */
	if (fp->base == NULL) {
		fp->base = (char *)malloc(BUFSIZE);
		if (fp->base == NULL) {
			fp->is_err = 1;
			return EOF;
		}
	}

	/* write existing data */
	n = (fp->ptr) ? (fp->ptr - fp->base) : 0;

	if (n > 0) {
		if (write(fp->fd, fp->base, n) != n) {
			fp->is_err = 1;
			return EOF;
		}
	}

	fp->ptr = fp->base;
	fp->cnt = BUFSIZE - 1;

	if (c != EOF)
		*fp->ptr++ = c;

	return c;
}
/*
description : fflush() forces the output buffer to be written to the file, ensuring no data remains pending in the buffer.
Author : Akash Gupta
Modified At : 28-04-2026
Created At: 28-04-2026
 */

int fflush(FILE *fp) {
	int n;

	if (!fp || !fp->is_write)
		return EOF;

	if (fp->base == NULL)
		return 0;

	n = fp->ptr - fp->base;

	if (n > 0) {
		if (write(fp->fd, fp->base, n) != n) {
			fp->is_err = 1;
			return EOF;
		}
	}

	fp->ptr = fp->base;
	fp->cnt = fp->is_unbuf ? 0 : BUFSIZE;

	return 0;
}
/*
description : fclose() flushes any pending output, releases the buffer, and closes the file.
Author : Akash Gupta
Modified At : 28-04-2026
Created At: 28-04-2026
 */
int fclose(FILE *fp) {
	if (!fp)
		return EOF;

	fflush(fp);

	if (fp->base != NULL)
		free(fp->base);

	if (close(fp->fd) < 0)
		return EOF;

	fp->cnt = 0;
	fp->ptr = NULL;
	fp->base = NULL;
	fp->is_read = 0;
	fp->is_write = 0;
	fp->is_unbuf = 0;
	fp->is_eof = 0;
	fp->is_err = 0;
	fp->fd = -1;

	return 0;
}
/*
description : io_main() take file from command line argument and get charcters from terminal and put them into file
Author : Akash Gupta
Modified At : 28-04-2026
Created At: 28-04-2026
 */
int io_main(int argc, char *argv[]) {
	FILE *fp;
	int c;

	if (argc != 3)
		return 1;

	fp = fopen(argv[2], "w");
	if (fp == NULL)
		return 1;

	while ((c = getc(stdin)) != EOF)
		putc(c, fp);

	fclose(fp);
	return 0;
}
