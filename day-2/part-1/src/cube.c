
#include "cube.h"

int	ft_strncmp_i(const char *s1, const char *s2, size_t n, size_t  i)
{
	size_t	j;

	j = 0;
	if (n == 0)
		return (0);
	while (s1[j] != '\0' && s2[i] != '\0' && (s1[j] == s2[i] && j < n - 1))
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[j] - (unsigned char)s2[i]);
}

bool	is_valid_game(char *str)
{
	int		i;
	int		cube;
	bool	valid;

	i = 0;
	cube = 0;
	valid = true;
	while (str[i] != 58)
		i++;
	while (str[i])
	{
		while (str[i] >= 48 && str[i] <= 57)
		{
			cube = (cube * 10) + (str[i] - 48);
			i++;
		}
		if (cube > 12 && !ft_strncmp_i(" red", str, 4, i))
		{
			valid = false;
			break ;
		}
		else if (cube > 13 && !ft_strncmp_i(" green", str, 6, i))
		{
			valid = false;
			break ;
		}
		else if (cube > 14)
		{
			valid = false;
			break ;
		}
		cube = 0;
		i++;
	}
	return (valid);
}

int	main(int argc, char **argv)
{
	int		sum;
	int		i;
	int		fd;
	char	*line;

	if (argc != 2)
		return (1);
	i = 1;
	sum = 0;
	fd = open(argv[1], O_RDONLY);
	while (i <= 100)
	{
		line = get_next_line(fd);
		if (is_valid_game(line))
			sum += i;
		if (!line)
			break ;
		free (line);
		i++;
	}
	close(fd);
	printf("%d\n", sum);
	return (0);
}