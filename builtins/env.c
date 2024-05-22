/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:00:09 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:00:10 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(t_env *minienv)
{
	t_env	*aux;

	aux = minienv;
	while (aux)
	{
		if (ft_strchr(aux->key_pair, '='))
		{
			ft_putstr_fd(aux->key_pair, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		aux = aux->next;
	}
	return (0);
}
