#!/bin/sh

echo "[1] Compiling $1"
cc -Wall -Wextra -Werror $1 

echo "[2] Running ./a.out"
./a.out

echo "\n"
echo "[3] Checking with norminette..."
norminette -R CheckForbiddenSourceHeader $1
