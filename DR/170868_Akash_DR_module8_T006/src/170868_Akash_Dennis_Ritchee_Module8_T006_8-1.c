/*Description:Rewrite the program cat from Chapter 7 using read, write, open, and close
  instead of their standard library equivalents. Perform experiments to determine              the relative speeds of the two versions. 
Author:Akash Gupta
Modified At:27-04-2026
Craeted At:27-04-2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024
/*Function name : cat_main();
Description:- handle cli and no file is given through cli then read the text from stdin and   write that text on stdout. if file is given then print content of that file on stdout.
Author:Akash Gupta
Modified At:27-04-2026
Craeted At:27-04-2026
 */
int cat_main(int argc, char *argv[]) {
	int fd;
	ssize_t n;
	char buffer[BUF_SIZE];

	if (argc == 1) {
		write(1, "Usage: ./cat filename\n", 22);
		exit(1);

	}

	if (argc == 2) {
		while ((n = read(0, buffer, BUF_SIZE)) > 0) {
			write(1, buffer, n);
		}
		return 0;
	}

	for (int i = 2; i < argc; i++) {
		fd = open(argv[i], O_RDONLY);

		if (fd < 0) {
			perror(argv[i]);
			continue;          
		}

		while ((n = read(fd, buffer, BUF_SIZE)) > 0) {
			write(1, buffer, n);
		}

		close(fd);
	}
	return 0;
}
