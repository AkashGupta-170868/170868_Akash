#!/bin/bash
#description : a script to  Read the Kernel log file to find the kernel panic , segmentation fault messages with full line with timestamp.
# Author: Akash Gupta
# Created: 27 January 2026                
# Modified: 27 January 2026
source /home/akash/shellscripts/functions/shell_sh/function.sh
main() {
        fault_msg ;
}
main;
askagain;
