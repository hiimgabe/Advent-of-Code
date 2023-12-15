
#include "trebuchet.h"

int	get_sum(char *str)
{
	int		first;
	int		last;
	int		sum;
	int		i;
	bool	flag_first;

	if (!str)
		return (0);
	flag_first = false;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			if (!flag_first)
			{
				first = str[i] - 48;
				flag_first = true;
			}
			last = str[i] - 48;
		}
		i++;
	}
	sum = (first * 10) + last;
	return (sum);
}

int	main(int argc, char **argv)
{
	int		sum;
	int		fd;
	char	*line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	sum = 0;
	while (1)
	{
		line = get_next_line(fd);
		sum += get_sum(line);
		if (!line)
			break ;
		free (line);
	}
	close(fd);
	printf("%d\n", sum);
	return (0);
}