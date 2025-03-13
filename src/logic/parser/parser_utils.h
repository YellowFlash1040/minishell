#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

int		is_redir(t_token *token);
t_token *read_token(t_list *tokens, int index);
int		n_word_tokens(t_list *tokens, int index);
#endif
