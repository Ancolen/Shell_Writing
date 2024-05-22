/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:59:53 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/22 23:59:55 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *command)
{
	if (!command)
		return (0);
	if (str_equal(command, "echo"))
		return (1);
	if (str_equal(command, "cd"))
		return (1);
	if (str_equal(command, "pwd"))
		return (1);
	if (str_equal(command, "export"))
		return (1);
	if (str_equal(command, "unset"))
		return (1);
	if (str_equal(command, "env"))
		return (1);
	if (str_equal(command, "exit"))
		return (1);
	return (0);
}
