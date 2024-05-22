/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:19:03 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:19:04 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_output(char *command)
{
	char	*output_redirect;
	char	*file_name;
	int		fd;
	int		open_flags;

	output_redirect = get_redirect_position(command, '>');
	if (!output_redirect)
		return (SUCCESS);
	if (output_redirect[1] == '>')
		open_flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		open_flags = O_WRONLY | O_CREAT | O_TRUNC;
	file_name = get_label_name(output_redirect);
	fd = open(file_name, open_flags, 0644);
	if (fd == -1)
	{
		print_perror_msg("open", file_name);
		free_and_null(file_name);
		return (FAILED);
	}
	else
		redirect_fd(fd, STDOUT_FILENO);
	free_and_null(file_name);
	return (SUCCESS);
}
