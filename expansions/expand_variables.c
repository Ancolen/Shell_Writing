/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:13:36 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:13:37 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_var_position(char *input)
{
	while (*input)
	{
		if (*input == '\'')
		{
			input++;
			while (*input && *input != '\'')
				input++;
		}
		if (*input == '\"')
		{
			input++;
			while (*input && *input != '\"')
			{
				if (*input == '$' && is_varname(input[1]))
					return (input);
				input++;
			}
		}
		if (*input == '$' && is_varname(input[1]))
			return (input);
		input++;
	}
	return (NULL);
}

static void	update_input(char **input, char *var_value, char *second_part)
{
	char	*first_part;
	char	*updated_input;

	if (!*input[0] && !var_value)
		first_part = ft_strdup("");
	else if (!*input[0] && var_value)
		first_part = ft_strdup(var_value);
	else if (!var_value)
		first_part = ft_strdup(*input);
	else
		first_part = ft_strjoin(*input, var_value);
	updated_input = ft_strjoin(first_part, second_part);
	free(first_part);
	first_part = NULL;
	free(*input);
	*input = NULL;
	*input = updated_input;
}

void	expand_variables(char **input, t_env *minienv)
{
	char	*var_position;
	char	*var_name;
	char	*var_value;
	int		name_size;

	var_position = find_var_position(*input);
	if (var_position)
	{
		name_size = 0;
		while (is_varname(var_position[name_size + 1]))
			name_size++;
		var_name = ft_substr(var_position, 1, name_size);
		*var_position = '\0';
		var_value = minienv_value(var_name, minienv);
		update_input(input, var_value, (var_position + 1 + name_size));
		free(var_name);
		var_name = NULL;
		expand_variables(input, minienv);
	}
}
