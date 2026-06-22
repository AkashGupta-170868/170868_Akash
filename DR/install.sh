#!/bin/bash

# File Name   : install.sh
# Description : Script to install the project directory structure
# Author      : Akash Gupta
# Code        : 170868
# Created     : 24-02-2026
# Version     : 1.0

REPO_URL="https://github.com/AkashGupta-170868/170868_Akash.git"

read -p "Enter directory where project should be installed: " TARGET_DIR


if [ -z "$TARGET_DIR" ]; then
    echo "Error: Directory name cannot be empty."
    exit 1
fi

if [ ! -d "$TARGET_DIR" ]; then
    echo "Creating directory $TARGET_DIR ..."
    mkdir -p "$TARGET_DIR"
fi

cd "$TARGET_DIR" || exit

echo "Cloning repository..."
git clone -b dennis-d "$REPO_URL"

if [ $? -eq 0 ]; then
    echo "Project installed successfully in $(pwd)"
    echo "after the successfully installing the project then you have to compiled all the file and to that project using following command
1.make
2.make execute
3.enter the choice which module you want to run.
4.enter the choice of which task that you want to run ." 
else
    echo "Error while cloning repository."
    exit 1
fi
