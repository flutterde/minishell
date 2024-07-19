#include "head.h"


int main()
{
	int fd = open("", O_RDWR);
	if (fd == -1)
	{
		perror("minishell: ");
		printf("===>>> errno: %d\n", errno);
		// printf("===>>> errno: %s\n", strerror(errno));
		return (1);
	}
}