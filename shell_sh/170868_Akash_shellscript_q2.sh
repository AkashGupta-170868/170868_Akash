#!/bin/bash
# Odd Even Script
# Author: Akash Gupta
# Created: 20 January 2026
# Modified: 20 January 2026


source /home/akash/shellscripts/functions/shell_sh/function.sh
# Check number is correct or not
is_number() {
    [[ "$1" =~ ^[+-]?[0-9]+(\.[0-9]+)?$ ]]
}

main() {
	#takes continous input from the user utill the correct i#nput is not pressed
    while true; do
        read -p "Enter the number: " num1

#checks the inputs is space or not ?
        if [[ -z "$num1" ]]; then
            echo "invalid"
            continue
        fi

        if is_number "$num1"; then
            break
        else
            echo "Enter a valid number"
        fi
    done

    # is_float (only .0 allowed)
    if [[ "$num1" == *.* && "$num1" != *.0 ]]; then
        echo "Float is not valid"
        return
    fi

    # Odd / Even
    local result
    result=$(echo "$num1 % 2" | bc)

    case "$result" in
        1|-1)
            echo ""$num1" Number is Odd"
            ;;
        0)
            echo ""$num1" Number is Even"
            ;;
    esac
}
main;
askagain;
