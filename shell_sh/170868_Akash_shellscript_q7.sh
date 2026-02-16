#!/bin/bash


# Description :its a  script about that adds a new user to the system and set a default password.
# Author: Akash Gupta
# Created: 21 January 2026
# Modified: 21 January 2026

source /home/akash/shellscripts/functions/shell_sh/function.sh
main() {
	read -p " enter the username to add " username

	add_user "$username" ;
}
main;
askagain;
