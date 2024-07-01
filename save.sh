make fclean
rm -rf .vscode
rm -rf minishell.dSYM
zip -r $(date +"%Y-%m-%d_%H-%M-%S").zip *
clear


