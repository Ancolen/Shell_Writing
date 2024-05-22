/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:19:21 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:19:22 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	if (argv && argc > 1)
	{
		ft_putstr_fd("Minishell can't take arguments 🧙🏻‍♂️\n", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	return (minishell(init_minienv(envp)));
}
