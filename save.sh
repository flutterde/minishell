#!/bin/bash

make fclean

rm -rf .vscode

rm -rf ./labs/app

rm -rf ./labs/a.out

rm -rf ./srcs/a.out

rm -rf ./src/piping

rm -rf minishell.dSYM

zip -r /Users/ochouati/Desktop/minishell-backup/$(date +"%Y-%m-%d_%H-%M-%S")_src.zip  *

clear


echo -n "Enter the git message: "
read message
echo -n "Do you want to push it ? (y/n): "
read push

if [ "$push" == "y" ]; then
	git add .
	git commit -m "$message"
	git push
fi




