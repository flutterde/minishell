#include "head.h"

static void	ft_errno3(int nbr)
{
	if (nbr == ENFILE)
		mini_printf(2, "\033[0;91mError:\033[0m File table overflow\n");
	else if (nbr == EMFILE)
		mini_printf(2, "\033[0;91mError:\033[0m Too many open files\n");
	else if (nbr == ENOTTY)
		mini_printf(2, "\033[0;91mError:\033[0m Not a typewriter\n");
	else if (nbr == ETXTBSY)
		mini_printf(2, "\033[0;91mError:\033[0m Text file busy\n");
	else if (nbr == EFBIG)
		mini_printf(2, "\033[0;91mError:\033[0m File too large\n");
	else if (nbr == ENOSPC)
		mini_printf(2, "\033[0;91mError:\033[0m No space left on device\n");
	else if (nbr == ESPIPE)
		mini_printf(2, "\033[0;91mError:\033[0m Illegal seek\n");
	else if (nbr == EROFS)
		mini_printf(2, "\033[0;91mError:\033[0m Read-only file system\n");
	else if (nbr == EMLINK)
		mini_printf(2, "\033[0;91mError:\033[0m Too many links\n");
	else if (nbr == EPIPE)
		mini_printf(2, "\033[0;91mError:\033[0m Broken pipe\n");
	else if (nbr == EDOM)
		mini_printf(2, "\033[0;91mError:\033[0m Math argument out of domain of func\n");
	else
		mini_printf(2, "\033[0;91mError:\033[0m Unknown error\n");
}

static void	ft_errno2(int nbr)
{
	if (nbr == ENOMEM)
		mini_printf(2, "\033[0;91mError:\033[0m Out of memory\n");
	else if (nbr == EACCES)
		mini_printf(2, "\033[0;91mError:\033[0m Permission denied\n");
	else if (nbr == EFAULT)
		mini_printf(2, "\033[0;91mError:\033[0m Bad address\n");
	else if (nbr == ENOTBLK)
		mini_printf(2, "\033[0;91mError:\033[0m Block device required\n");
	else if (nbr == EBUSY)
		mini_printf(2, "\033[0;91mError:\033[0m Device or resource busy\n");
	else if (nbr == EEXIST)
		mini_printf(2, "\033[0;91mError:\033[0m File exists\n");
	else if (nbr == EXDEV)
		mini_printf(2, "\033[0;91mError:\033[0m Cross-device link\n");
	else if (nbr == ENODEV)
		mini_printf(2, "\033[0;91mError:\033[0m No such device\n");
	else if (nbr == ENOTDIR)
		mini_printf(2, "\033[0;91mError:\033[0m Not a directory\n");
	else if (nbr == EISDIR)
		mini_printf(2, "\033[0;91mError:\033[0m Is a directory\n");
	else if (nbr == EINVAL)
		mini_printf(2, "\033[0;91mError:\033[0m Invalid argument\n");
	else
		ft_errno3(nbr);
}

void	ft_errno(int nbr)
{
	if (nbr == EPERM)
		mini_printf(2, "\033[0;91mError:\033[0m Operation not permitted\n");
	else if (nbr == ENOENT)
		mini_printf(2, "\033[0;91mError:\033[0m No such file or directory\n");
	else if (nbr == ESRCH)
		mini_printf(2, "\033[0;91mError:\033[0m No such process\n");
	else if (nbr == EINTR)
		mini_printf(2, "\033[0;91mError:\033[0m Interrupted system call\n");
	else if (nbr == EIO)
		mini_printf(2, "\033[0;91mError:\033[0m I/O error\n");
	else if (nbr == ENXIO)
		mini_printf(2, "\033[0;91mError:\033[0m No such device or address\n");
	else if (nbr == E2BIG)
		mini_printf(2, "\033[0;91mError:\033[0m Argument list too long\n");
	else if (nbr == ENOEXEC)
		mini_printf(2, "\033[0;91mError:\033[0m Exec format error\n");
	else if (nbr == EBADF)
		mini_printf(2, "\033[0;91mError:\033[0m Bad file number\n");
	else if (nbr == ECHILD)
		mini_printf(2, "\033[0;91mError:\033[0m No child processes\n");
	else if (nbr == EAGAIN)
		mini_printf(2, "\033[0;91mError:\033[0m Try again\n");
	else
		ft_errno2(nbr);
}

