/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:14:06 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:14:07 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_varname(char c)
{
	return (ft_isalnum(c) || c == '_');
}

int	is_valid_varname(char *name)
{
	if (!ft_isalpha(*name))
		return (FALSE);
	while (*name)
	{
		if (!is_varname(*name))
			return (FALSE);
		name++;
	}
	return (TRUE);
}
