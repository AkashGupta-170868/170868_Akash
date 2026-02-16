#!/bin/bash


# Description :its a  script about that checks the size of a specified directory and warns if it exceeds a certain limit
# Author: Akash Gupta
# Created: 21 January 2026
# Modified: 21 January 2026
source /home/akash/shellscripts/functions/shell_sh/function.sh

main() {
	read -p "enter the directory to check its size " dir;
	dir_size "$dir"
}
main;
askagain;

