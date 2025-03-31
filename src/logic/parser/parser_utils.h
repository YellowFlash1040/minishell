#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

int		is_file(t_token *token);
int		is_redir(t_token *token);
t_token *read_token(t_list *tokens, int index);
int		n_args(t_list *tokens, int index);
char	*quote_str(t_token *token);
#endif
