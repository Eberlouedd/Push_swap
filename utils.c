
int	check_str(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if ((str[i][0] > '9' || str[i][0] < '0'))
			return (0);
	}
	return (1);
}

int	check_doublon(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		while (/* condition */)
		{
			/* code */
		}
		
	}
}

int	check_argument(char **arg, int n)
{
	int	i;

	i = 1;
}