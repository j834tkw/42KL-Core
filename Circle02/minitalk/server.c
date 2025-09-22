
#define _XOPEN_SOURCE 700 //remove later

#include "minitalk.h"

void	ft_handle(int sig, siginfo_t *info, void *context)
{
	static int	count_bits_till_byte;
	static int	eventually_a_char;
	int			bits;

	(void)context;
	bits = 0;
	if (sig == SIGUSR1)
		bits = 1;
	eventually_a_char <<= 1;
	eventually_a_char += bits;
	count_bits_till_byte++;
	if (count_bits_till_byte == 8)
	{
		write(1, &eventually_a_char, 1);
		if (eventually_a_char == 0)
			kill(info->si_pid, SIGUSR1);
		count_bits_till_byte = 0;
		eventually_a_char = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = &ft_handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "Server PID = ", 13);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
