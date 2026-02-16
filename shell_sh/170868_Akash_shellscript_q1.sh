#!/bin/bash
# Calculator Script and various validation for a input pressed by the user
# Author: Akash Gupta
# Created: 19 January 2026
# Modified: 20 January 2026
#------------------------------------------------------------------------------------------------------------------------------------

source /home/akash/shellscripts/functions/shell_sh/function.sh
main() {

# Function to check valid number (integer or decimal)
is_number() {
    [[ $1 =~ ^-?[0-9]+([.][0-9]+)?$ ]]
}

# Read Num1 until valid
while true; do
    read -p "Enter Num1: " num1

    if [ -z "$num1" ] || ! is_number "$num1"; then
        echo "num1 is not a valid number"
    else
        break
    fi
done

# Read Num2 until valid
while true; do
    read -p "Enter Num2: " num2

    if [ -z "$num2" ] || ! is_number "$num2"; then
        echo "Num2 is not a valid number. Please enter again."
    else
        break
    fi
done

# Perform operations
echo "Add : $(echo "$num1 + $num2" | bc)"
echo "Sub : $(echo "$num1 - $num2" | bc)"
echo "Mul : $(echo "$num1 * $num2" | bc)"

# Division check
if [ "$num2" == "0" ]; then
    echo "Div : cannot divide by zero"
else
    echo "Div : $(echo "scale=2; $num1 / $num2" | bc)"
fi
}
main ;
askagain ;

