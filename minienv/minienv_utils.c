/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minienv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:18:44 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:18:46 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*minienv_value(char *name, t_env *minienv)
{
	t_env	*aux;

	aux = minienv_node(name, minienv);
	if (!aux)
		return (NULL);
	return (value_only(aux->key_pair));
}

t_env	*minienv_node(char *name, t_env *minienv)
{
	int		size;

	size = ft_strlen(name);
	while (minienv)
	{
		if (ft_strncmp(name, minienv->key_pair, size) == 0)
			return (&*minienv);
		minienv = minienv->next;
	}
	return (NULL);
}

void	minienv_update(char *name, char *value, t_env *minienv)
{
	t_env	*aux;
	char	*new_keypair;

	new_keypair = NULL;
	aux = minienv_node(name, minienv);
	if (!aux)
	{
		new_keypair = create_keypair(name, value);
		if (list_append(new_keypair, &minienv))
		{
			if (!new_keypair)
			{
				free(new_keypair);
				new_keypair = NULL;
			}
			free_minienv(&minienv);
		}
		free(new_keypair);
		new_keypair = NULL;
		return ;
	}
	free (aux->key_pair);
	if (value == NULL)
		return ;
	export_set(name, value, aux, new_keypair);
}

size_t	minienv_size(t_env *minienv)
{
	size_t	size;
	t_env	*aux;

	size = 0;
	aux = minienv;
	while (aux)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

char	**minienv_to_envp(t_env *minienv)
{
	char	**envp;
	t_env	*aux;
	int		i;

	envp = malloc(sizeof(char *) * (minienv_size(minienv) + 1));
	if (!envp)
		return (NULL);
	aux = minienv;
	i = 0;
	while (aux)
	{
		envp[i] = ft_strdup(aux->key_pair);
		i++;
		aux = aux->next;
	}
	envp[i] = NULL;
	return (envp);
}
