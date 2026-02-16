#!/bin/bash
#its a script that generates a disk usage report for all mounted file systems and saves it to a file.
# Author: Akash Gupta 
# Created: 19 January 2026   
# Modified: 20 January 2026


source /home/akash/shellscripts/functions/shell_sh/function.sh

main() {
	disk_status
}
main;
askagain;
