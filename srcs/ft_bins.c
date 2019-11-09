/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:19:13 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 16:42:40 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_from_bins(char **cmd, char *path)
{
	extern char	**environ;
	pid_t		pid;

	if ((pid = fork()) == 0)
	{
		execve(path, cmd, environ);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
	}
	else
	{
		ft_putendl_fd("fork failed", 2);
		exit(1);
	}
}
