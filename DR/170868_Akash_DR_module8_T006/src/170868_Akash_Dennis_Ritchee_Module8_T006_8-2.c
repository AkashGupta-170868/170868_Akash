#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define NULL 0
#define EOF (-1)
#define BUFSIZE 1024
#define OPEN_MAX 20

/* Custom FILE structure (no bit flags) */
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

FILE _iob[OPEN_MAX] = {
	{0, NULL, NULL, 0, 1, 0, 0, 0, 0},  /* stdin */
	{0, NULL, NULL, 1, 0, 1, 0, 0, 0},  /* stdout */
	{0, NULL, NULL, 2, 0, 1, 1, 0, 0}   /* stderr (unbuffered) */
};

#define stdin  (&_iob[0])
#define stdout (&_iob[1])

/* Macros */
#define getc(p) (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ : _fillbuf(p))

/* Description:_fillbuf() is used to read data from a file into the input buffer when the buffer becomes empty.
Author : Akash Gupta
Modified At: 28-04-2026
Created At: 28-04-2026
 */
int _fillbuf(FILE *fp) {
	int bufsize;

	if (!fp->is_read || fp->is_eof || fp->is_err)
		return EOF;

	bufsize = fp->is_unbuf ? 1 : BUFSIZE;

	if (fp->base == NULL) {
		fp->base = (char *)malloc(bufsize);
		if (fp->base == NULL)
			return EOF;
	}

	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);

	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->is_eof = 1;
		else
			fp->is_err = 1;

		fp->cnt = 0;
		return EOF;
	}

	return (unsigned char)*fp->ptr++;
}

/* Description:fopen() fopen implementation.
Author : Akash Gupta
Modified At: 28-04-2026
Created At: 28-04-2026
 */
FILE *fopen(char *name, char *mode) {
	int fd;
	FILE *fp;

	for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
		if (!fp->is_read && !fp->is_write)
			break;
	}

	if (fp >= _iob + OPEN_MAX)
		return NULL;

	if (*mode == 'r') {
		fd = open(name, O_RDONLY);
		if (fd == -1) return NULL;
		fp->is_read = 1;
	} 
	else if (*mode == 'w') {
		fd = creat(name, 0666);
		if (fd == -1) return NULL;
		fp->is_write = 1;
	} 
	else if (*mode == 'a') {
		fd = open(name, O_WRONLY | O_APPEND);
		if (fd == -1) return NULL;
		fp->is_write = 1;
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define NULL 0
#define EOF (-1)
#define BUFSIZE 1024
#define OPEN_MAX 20

/* Custom FILE structure (no bit flags) */
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

FILE _iob[OPEN_MAX] = {
        {0, NULL, NULL, 0, 1, 0, 0, 0, 0},  /* stdin */
        {0, NULL, NULL, 1, 0, 1, 0, 0, 0},  /* stdout */
        {0, NULL, NULL, 2, 0, 1, 1, 0, 0}   /* stderr (unbuffered) */
};

#define stdin  (&_iob[0])
#define stdout (&_iob[1])

/* Macros */
#define getc(p) (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ : _fillbuf(p))

/* Description:_fillbuf() is used to read data from a file into the input buffer when the buffer becomes empty.
Author : Akash Gupta
Modified At: 28-04-2026
Created At: 28-04-2026
 */
int _fillbuf(FILE *fp) {
        int bufsize;

        if (!fp->is_read || fp->is_eof || fp->is_err)
                return EOF;

        bufsize = fp->is_unbuf ? 1 : BUFSIZE;

        if (fp->base == NULL) {
                fp->base = (char *)malloc(bufsize);
                if (fp->base == NULL)
                        return EOF;
        }

        fp->ptr = fp->base;
        fp->cnt = read(fp->fd, fp->ptr, bufsize);

        if (--fp->cnt < 0) {
                if (fp->cnt == -1)
                        fp->is_eof = 1;
                else
                        fp->is_err = 1;

                fp->cnt = 0;
                return EOF;
        }

        return (unsigned char)*fp->ptr++;
}

/* Description:fopen() fopen implementation.
Author : Akash Gupta
Modified At: 28-04-2026
Created At: 28-04-2026
 */
FILE *fopen(char *name, char *mode) {
        int fd;
        FILE *fp;

        for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
                if (!fp->is_read && !fp->is_write)
                        break;
        }

        if (fp >= _iob + OPEN_MAX)
                return NULL;

        if (*mode == 'r') {
                fd = open(name, O_RDONLY);
                if (fd == -1) return NULL;
                fp->is_read = 1;
        }
        else if (*mode == 'w') {
                fd = creat(name, 0666);
                if (fd == -1) return NULL;
                fp->is_write = 1;
        }
        else if (*mode == 'a') {
                fd = open(name, O_WRONLY | O_APPEND);
                if (fd == -1) return NULL;
                fp->is_write = 1;
        }
        else {
                return NULL;
        }

        fp->fd = fd;
        fp->cnt = 0;
        fp->base = NULL;
        fp->ptr = NULL;
        fp->is_unbuf = 0;
        fp->is_eof = 0;
        fp->is_err = 0;

        return fp;
}

/* Description:read file and print to stdout
Author : Akash Gupta
Modified At: 28-04-2026
Created At: 28-04-2026
 */
int getc_main(int argc, char *argv[]) {
        FILE *fp;
        int c;

        if (argc != 3)
                return 1;

        fp = fopen(argv[2], "r");
        if (fp == NULL)
                return 1;

        while ((c = getc(fp)) != EOF) {
                putchar(c);
        }

        return 0;
}	} 
	else {
		return NULL;
	}

	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->ptr = NULL;
	fp->is_unbuf = 0;
	fp->is_eof = 0;
	fp->is_err = 0;

	return fp;
}

/* Description:read file and print to stdout
Author : Akash Gupta
Modified At: 28-04-2026
Created At: 28-04-2026
 */
int getc_main(int argc, char *argv[]) {
	FILE *fp;
	int c;

	if (argc != 3)
		return 1;

	fp = fopen(argv[2], "r");
	if (fp == NULL)
		return 1;

	while ((c = getc(fp)) != EOF) {
		putchar(c);
	}

	return 0;
}
