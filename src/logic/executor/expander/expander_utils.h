#ifndef EXPANDER_UTILS_H
# define EXPANDER_UTILS_H

char	*dup_env_var(t_list *env, char *name);
char	*expand_double_quote(t_list *env, char	*str);
#endif
