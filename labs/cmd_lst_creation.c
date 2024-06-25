#include "head.h"


t_cmd	*cmd_create_node();
t_cmd	*get_last_node(t_cmd *lst);
t_cmd	*get_prev_node(t_cmd *lst, t_cmd *node);
void	cmd_addback(t_cmd **lst, t_cmd *new);
void	cmd_addfront(t_cmd **lst, t_cmd *new);
void	cmd_delete_1node(t_cmd *node);
void	cmd_clear_list(t_cmd **list);
void	cmd_insert_between();
void	cmd_delete_if();
