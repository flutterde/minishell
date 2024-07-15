#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>



int main(int ac, char **av, char **env)
{
	int x = -1;
	printf("=>> %s\n", av[0]);
	char	*args[3] = {"", "-la", NULL} ;
	if (execve("/Users/ochouati/Desktop/minihell/labs/a.out", args, NULL))
	{
		printf("===> Error, %d\n", errno);
		perror(strerror(errno));
	}
}