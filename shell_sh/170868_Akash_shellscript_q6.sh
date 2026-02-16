#!/bin/bash

# Description : its a script about that checks if a specific process runing or not and print on the  terminal weather the process is running or not .
# Author: Akash Gupta
# Created: 21 January 2026
# Modified: 21 January 2026


source /home/akash/shellscripts/functions/shell_sh/function.sh

main() {
	read -p " enter the process id : " pid;

	if [[ -z "$pid" ]]; then 
		echo " invalid input : " ;
	else 
		is_pid "$pid" ;
	fi
	 
}
main;
askagain;
