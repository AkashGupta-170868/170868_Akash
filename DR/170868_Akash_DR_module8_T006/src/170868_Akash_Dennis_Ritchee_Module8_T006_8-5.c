/*Modify the fsize program to print the other information contained in the inode
  entry. 
 * Author: Akash Gupta
 * Created: 30 April, 2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

void fsize(char *name);
/*
 * Function Name: dirwalk()
 * Function Description: read the directory till the not null and closedirectory.
 * Author: Akash Gupta
 * Created: 30 April, 2026
 */
void dirwalk(char *dir)
{
	struct dirent *dp;
	DIR *dfd;
	char path[1024];

	if ((dfd = opendir(dir)) == NULL) {
		printf("Cannot open %s\n", dir);
		return;
	}

	while ((dp = readdir(dfd)) != NULL) {

		if (strcmp(dp->d_name, ".") == 0 ||
				strcmp(dp->d_name, "..") == 0)
			continue;

		sprintf(path, "%s/%s", dir, dp->d_name);

		fsize(path);
	}

	closedir(dfd);
}
/*
 * Function Name: fsize()
 * Function Description: print information about file like stat.
 * Author: Akash Gupta
 * Created: 30 April, 2026
 */
void fsize(char *name)
{
	struct stat stbuf;

	if (stat(name, &stbuf) == -1) {
		printf("Can't access %s\n", name);
		return;
	}

	if (S_ISDIR(stbuf.st_mode))
		dirwalk(name);
	printf("\n-----------------------------------\n");
	printf("File: %s\n", name);
	printf("Inode: %ld\n", (long)stbuf.st_ino);
	printf("Size: %ld bytes\n", (long)stbuf.st_size);
	printf("Device ID: %ld\n", (long)stbuf.st_dev);
	printf("Links: %ld\n", (long)stbuf.st_nlink);
	printf("User ID (UID): %d\n", stbuf.st_uid);
	printf("Group ID (GID): %d\n", stbuf.st_gid);

	printf("Last Access: %s", ctime(&stbuf.st_atime));
	printf("Last Modified: %s", ctime(&stbuf.st_mtime));
	printf("Last Status Change: %s", ctime(&stbuf.st_ctime));

	printf("Permissions: %o\n", stbuf.st_mode & 0777);
	printf("-----------------------------------\n");     

}
/*
 * Function Name: stat_main()
 * Function Description: call the function from here
 * Author: Akash Gupta
 * Created: 30 April, 2026
 */
int stat_main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Usage: ./a.out <file/directory>\n");
		return 1;
	}

	for (int i = 2; i < argc; i++)
		fsize(argv[i]);

	return 0;
}
