/* Write a program to display and change the attributes of files present on the disk interactively
 * Author: Akash Gupta
 * Created: 25 March,2026
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
/* Function name: displayInfo()                                                                                                    
 * Function Description: This function is used to display attributes of files present on the disk interactively.
  * Author: Akash Gupta
  * Created: 25 March, 2026
  */
void displayInfo() {
    struct stat sb;
    char path[1024];

    /* Ask user for the file or directory name */
    printf("Enter file or directory name: ");
    if (scanf("%1023s", path) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return;
    }

    /* Retrieve metadata using lstat */
    if (lstat(path, &sb) == -1) {
        perror("lstat");
        return;
    }

    printf("ID of containing device:  [%jx,%jx]\n",
           (uintmax_t) major(sb.st_dev),
           (uintmax_t) minor(sb.st_dev));

    printf("File type:                ");
    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n"); break;
        case S_IFCHR:  printf("character device\n"); break;
        case S_IFDIR:  printf("directory\n"); break;
        case S_IFIFO:  printf("FIFO/pipe\n"); break;
        case S_IFLNK:  printf("symlink\n"); break;
        case S_IFREG:  printf("regular file\n"); break;
        case S_IFSOCK: printf("socket\n"); break;
        default:       printf("unknown\n"); break;
    }

    printf("I-node number:            %ju\n", (uintmax_t) sb.st_ino);
    printf("Mode:                     %jo (octal)\n", (uintmax_t) sb.st_mode);
    printf("Link count:               %ju\n", (uintmax_t) sb.st_nlink);

    printf("Ownership:                UID=%ju   GID=%ju\n", (uintmax_t) sb.st_uid, (uintmax_t) sb.st_gid);

    printf("Preferred I/O block size: %jd bytes\n", (intmax_t) sb.st_blksize);
    printf("File size:                %jd bytes\n", (intmax_t) sb.st_size);
    printf("Blocks allocated:         %jd\n", (intmax_t) sb.st_blocks);

    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));
}

