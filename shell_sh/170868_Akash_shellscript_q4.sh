#!/bin/bash

source /home/akash/shellscripts/functions/shell_sh/function.sh

main() {
	read -p " enter the string " str;
	is_palindrome "$str" ;
}
main;
askagain;


