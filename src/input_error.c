/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:19:16 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:19:18 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_input_error(char *input, int *exit_status, t_env *minienv)
{
	int	result;

	result = FALSE;
	if (is_empty(input))
		result = TRUE;
	else if (has_unclosed_quotes(input))
		result = TRUE;
	else if (is_invalid_syntax(input))
	{
		*exit_status = 2;
		result = TRUE;
	}
	else if (handle_heredoc(input, exit_status, minienv) == FAILED)
		result = TRUE;
	if (result == TRUE)
	{
		free(input);
		input = NULL;
	}
	return (result);
}
