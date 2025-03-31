#ifndef PARSER_H
# define PARSER_H

int	parse_tokens(t_list *tokens, t_pipeline **pipeline, t_list *env);
int	parse_variable(t_list *tokens, t_variable **var);
#endif
