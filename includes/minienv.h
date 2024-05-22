/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minienv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:14:30 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:14:31 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIENV_H
# define MINIENV_H

typedef struct s_env
{
	char			*key_pair;
	struct s_env	*next;
}				t_env;

t_env		*init_minienv(char **envp);
t_env		*init_minienv2(t_env **list);
t_env		*minienv_node(char *name, t_env *minienv);
char		*minienv_value(char *name, t_env *minienv);
void		minienv_update(char *name, char *value, t_env *minienv);
void		export_set(char *name, char *value, t_env *aux, char *new_keypair);
int			list_append(char *key_pair, t_env **list);
char		**minienv_to_envp(t_env *minienv);
void		free_minienv(t_env **minienv);
char		*create_keypair(char *name, char *value);
char		*name_only(char *key_pair);
char		*value_only(char *key_pair);

#endif
