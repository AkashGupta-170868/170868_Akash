#!/bin/bash

REPO_URL="https://github.com/your-username/your-repo.git"

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
git clone "$REPO_URL"

if [ $? -eq 0 ]; then
    echo "Project installed successfully in $(pwd)"
else
    echo "Error while cloning repository."
    exit 1
fi
