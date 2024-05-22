/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:14:16 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/23 00:14:17 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minienv.h"

int		is_builtin(char *command);
int		cd(char **args, t_env *minienv);
int		echo(char **args);
int		pwd(void);
int		builtin_export(char **args, t_env **minienv);
void	keypair_if_any(char *key_pair, t_env **minienv);
int		env(t_env *envp);
int		unset(char **args, t_env **minienv);
int		builtin_exit(char **args, t_env **minienv);

int		is_varname(char c);
int		is_valid_varname(char *name);

#endif
