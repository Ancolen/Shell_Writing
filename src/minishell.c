/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:19:26 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:19:28 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell(t_env *minienv)
{
	int		exit_status;
	char	*input;
	char	**commands;

	exit_status = EXIT_SUCCESS;
	while (31)
	{
		define_main_signals();
		input = prompt_input(minienv);
		if (has_input_error(input, &exit_status, minienv))
			continue ;
		handle_expansions(&input, minienv, exit_status);
		if (!has_pipe(input))
			exit_status = execute_one_command(input, &minienv);
		else
		{
			commands = split_commands(input);
			free(input);
			input = NULL;
			exit_status = execute_multiple_commands(commands, &minienv);
			free_array(commands);
		}
	}
	return (exit_status);
}
