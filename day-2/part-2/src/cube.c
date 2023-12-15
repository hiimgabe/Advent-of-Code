
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

int	get_power(char *str)
{
	int	i;
	int	cube;
	int	red;
	int	green;
	int	blue;
	int	power;

	if (!str)
		return (0);
	i = 0;
	cube = 0;
	red = 0;
	green = 0;
	blue = 0;
	while (str[i] != 58)
		i++;
	while (str[i])
	{
		while (str[i] >= 48 && str[i] <= 57)
		{
			cube = (cube * 10) + (str[i] - 48);
			i++;
		}
		if (!ft_strncmp_i(" red", str, 4, i) && cube > red)
			red = cube;
		else if (!ft_strncmp_i(" green", str, 6, i) && cube > green)
			green = cube;
		else if (!ft_strncmp_i(" blue", str, 5, i) && cube > blue)
			blue = cube;
		cube = 0;
		i++;
	}
	power = red * green * blue;
	return (power);
}

int	main(int argc, char **argv)
{
	int		sum;
	int		fd;
	char	*line;

	if (argc != 2)
		return (1);
	sum = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		sum += get_power(line);
		if (!line)
			break ;
		free (line);
	}
	close(fd);
	printf("%d\n", sum);
	return (0);
}