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
