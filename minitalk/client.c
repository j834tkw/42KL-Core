
#define _XOPEN_SOURCE 700 //remove later

#include "minitalk.h"

void	ft_send_byte(pid_t pid, char word)
{
	int	checker;

	checker = 128;
	while (checker > 0)
	{
		if ((word & checker) > 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		checker >>= 1;
		usleep(75);
	}
}

void	ft_confirm_success(void)
{
	write(1, "Message recieved\n", 17);
}

int	main(int argc, char **argv)
{
	char				*message;
	pid_t				pid;
	struct sigaction	sa;
	int					i;

	if (argc != 3)
	{
		write(1, "Error", 5);
		return (0);
	}
	i = 0;
	pid = (pid_t)ft_atoi(argv[1]);
	message = argv[2];
	sa.sa_handler = &ft_confirm_success;
	sigaction(SIGUSR1, &sa, NULL);
	while (message[i] != 0)
	{
		ft_send_byte(pid, message[i]);
		i++;
	}
	ft_send_byte(pid, 0);
	return (0);
}
