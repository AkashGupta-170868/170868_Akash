#!/bin/bash
# This script takes three numbers as input and finds the largest one
# Author   : Akash Gupta
# Created  : 20 January 2026
# Modified : 20 January 2026
source /home/akash/shellscripts/functions/shell_sh/function.sh
is_integer() {
    [[ $1 =~ ^-?[0-9]+$ ]]
}

main() {

    read -p "Enter number 1: " num1
    read -p "Enter number 2: " num2
    read -p "Enter number 3: " num3

    # check if num1 is missing
    if [[ -z "$num1" ]]; then
        echo "No. 1 Invalid"
        return
    fi

    # floating point check
    if [[ "$num1" == *.* || "$num2" == *.* || "$num3" == *.* ]]; then
        echo "Invalid"
        return
    fi

    # check num1
    if ! is_integer "$num1"; then
        echo "num1 is not a valid number"
        return
    fi

    # check num2
    if ! is_integer "$num2"; then
        echo "num2 is not a valid number"
        return
    fi

    # check num3
    if ! is_integer "$num3"; then
        echo "num3 is not a valid number"
        return
    fi

    # check very large numbers
    if [[ ${#num1} -gt 10 || ${#num2} -gt 10 || ${#num3} -gt 10 ]]; then
        echo "Cannot process large no."
        return
    fi

    # find largest
    largest=$num1
    (( num2 > largest )) && largest=$num2
    (( num3 > largest )) && largest=$num3

    echo "$largest"
}
main;
askagain;

