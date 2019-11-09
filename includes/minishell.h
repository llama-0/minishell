/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:28:54 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 19:57:12 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define LEN_BOOST 1000

# include <dirent.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct		s_envs
{
	char			*key;
	char			*value;
	struct s_envs	*next;
}					t_dict;

void				init(t_dict *envs, t_dict **bins);
size_t				ft_built_in(char **input, t_dict *envs, t_dict **bins);
void				ft_from_bins(char **cmd, char *path);
char				*ft_strjoin_chr(const char *s1, const char *s2,
										const char c);
char				*ft_path(t_dict *envs);
char				*ft_only_current_dir(t_dict *envs, char *s);
char				*base_split(char *s);
char				**ft_substitute_vars(char **s, t_dict *envs);

t_dict				*new_pair(char *s, int need_to_free);
t_dict				*new_bin(char *key, char *path);
void				push_back_pair(t_dict **head, t_dict *elem);
void				remove_pair(t_dict **head, char *key);
size_t				key_present(t_dict **head, char *key);
size_t				value_present(t_dict **head, char *value);
t_dict				*get_dict_elem(t_dict **head, char *key);
void				dict_clear(t_dict **head);

size_t				is_a_dir(char *s);
size_t				go_to_dir(char **cmd, t_dict *envs);

char				*tilda_slash(char **res_str, char *s, t_dict *envs);
char				*ft_rubbish_at_start(char *s, char *env_value,
											size_t flag, int j);
char				*ft_rubbish_no_tilda(char *s, char *tmp,
											char *env_value);
char				*ft_interior_no_tilda(char *s, char *tmp,
											char *env_value);
char				*ft_leftovers(char *s, char *tmp, t_dict *envs,
											size_t flag);
char				*ft_tilda_env(char *s, char *env_value, t_dict *envs,
											size_t flag);
char				*ft_tilda_rubbish_dir(char *s, char c, char *env_value,
											size_t flag);
char				*ft_tilda_rubbish(char *s, char *tmp, size_t flag);

size_t				ft_echo(char **input);
void				ft_exit(char **input, t_dict *envs);
size_t				ft_env(char **input, t_dict *envs);
size_t				ft_setenv(char **input, t_dict *envs, t_dict **bins);
size_t				ft_unsetenv(char **input, t_dict *envs, t_dict **bins);
size_t				ft_cd(char **input, t_dict *envs);

void				bins_dict(t_dict **dict_bins, t_dict *envs);

size_t				is_input_rubbish(char **cmd, t_dict *envs, size_t flag);
void				file_not_found_error(char **cmd_arr);

void				add_envp_value(char *key, char *value);
void				add_envp(char *key, char *value);
void				remove_envp(char *key, t_dict *envs, t_dict **bins);
size_t				ft_unsetenv(char **input, t_dict *envs, t_dict **bins);

#endif
