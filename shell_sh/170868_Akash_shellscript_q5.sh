#!/bin/bash

# Description :its a  script about that to takes a directory as input, creates a backup of all .txt files, and stores them in a compressed archive with the current date as the filename.
# Author: Akash Gupta
# Created: 21 January 2026
# Modified: 21 January 2026

source /home/akash/shellscripts/functions/shell_sh/function.sh
main() {

    read -p " enter the directory " input;
    valid_dir "$input";
}

main;
askagain;

