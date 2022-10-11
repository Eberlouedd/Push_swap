#include "push_swap.h"

int	strchr_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (!strchr_num(str))
		return (0);
	while (str[i])
	{
		if (!((str[i] <= '9' && str[i] >= '0') || str[i] == ' ' || str[i] == '-' || str[i] == '+'))
			return (0);
		if ((str[i] == '-' || str[i] == '+'))
		{
			if (!(str[i + 1] <= '9' && str[i + 1] >= '0'))
				return (0);
		}
		i++;
	}
	if (str[0] == '\0')
		return (0);
	return (1);
}

int	check_doublon(char **str)
{
	int	i;
	int	c;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!test_limit(str[i]))
			return (0);
		c = i + 1;
		while (str[c])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[c]))
				return (0);
			c++;
		}
		i++;
	}
	return (1);
}

int	test_format(int n, char **arg, int *med, int *max)
{
	char	*str;
	char	**splited;

	str = ft_strrejoin(n, arg, " ", 1);
	if(!check_str(str))
	{
		free(str);
		return (0);
	}
	splited = ft_split(str, ' ');
	if(!check_doublon(splited))
	{
		free(str);
		free(splited);
		return(0);
	}
	*med = find_med(splited);
	*max = find_max(splited);
	free(str);
	free(splited);
	return (1);
}

char	**final_parsing(int n, char **arg)
{
	return (ft_split(ft_strrejoin(n, arg, " ", 1), ' '));
}