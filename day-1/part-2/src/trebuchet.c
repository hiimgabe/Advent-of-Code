#include "trebuchet.h"

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

int	get_str_nb(char *str, int i)
{
	int	str_nb;

	str_nb = 0;
	if (!ft_strncmp_i("one", str, 3, i))
		str_nb = 1;
	else if (!ft_strncmp_i("two", str, 3, i))
		str_nb = 2;
	else if (!ft_strncmp_i("three", str, 5, i))
		str_nb = 3;
	else if (!ft_strncmp_i("four", str, 4, i))
		str_nb = 4;
	else if (!ft_strncmp_i("five", str, 4, i))
		str_nb = 5;
	else if (!ft_strncmp_i("six", str, 3, i))
		str_nb = 6;
	else if (!ft_strncmp_i("seven", str, 5, i))
		str_nb = 7;
	else if (!ft_strncmp_i("eight", str, 5, i))
		str_nb = 8;
	else if (!ft_strncmp_i("nine", str, 4, i))
		str_nb = 9;
	return(str_nb);
}

int	get_sum(char *str)
{
	int		first;
	int		last;
	int		sum;
	int		str_nb;
	int		i;
	bool	flag_first;

	if (!str)
		return (0);
	flag_first = false;
	i = 0;
	while (str[i])
	{
		str_nb = get_str_nb(str, i);
		if (str[i] >= 48 && str[i] <= 57)
		{
			if (!flag_first)
			{
				first = str[i] - 48;
				flag_first = true;
			}
			last = str[i] - 48;
		}
		else if (str_nb != 0)
		{
			if (!flag_first)
			{
				first = str_nb;
				flag_first = true;
			}
			last = str_nb;
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