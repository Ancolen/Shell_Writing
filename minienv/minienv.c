/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minienv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:18:49 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:21:42 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_minienv2(t_env **list)
{
	char	*home;

	if (!minienv_node("OLDPWD", *list))
		if (list_append("OLDPWD", list))
			return (NULL);
	home = ft_strjoin("__HOME=", minienv_value("HOME", *list));
	if (!home)
		return (NULL);
	if (list_append(home, list))
		return (NULL);
	free(home);
	home = NULL;
	return (*list);
}

t_env	*init_minienv(char **envp)
{
	t_env	*list;
	int		i;

	list = NULL;
	i = 0;
	while (envp[i])
	{
		if (list_append(envp[i], &list))
		{
			free_minienv(&list);
			return (NULL);
		}
		i++;
	}
	init_minienv2(&list);
	return (list);
}

int	list_append(char *key_pair, t_env **list)
{
	t_env	*new_node;
	t_env	*aux_node;

	new_node = malloc(sizeof(t_env));
	new_node->key_pair = ft_strdup(key_pair);
	if (!new_node)
		return (1);
	if (!new_node->key_pair)
		return (1);
	if (ft_strncmp(key_pair, new_node->key_pair, ft_strlen(key_pair)))
		return (1);
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return (0);
	}
	aux_node = *list;
	while (aux_node->next)
		aux_node = aux_node->next;
	aux_node->next = new_node;
	return (0);
}
