#include "push_swap.h"

void	sort_int_tab(int *tab, int size)
{
	int	min;
	int	n;
	int	i;
	int	c;

	n = 0;
	c = 0;
	i = 0;
	while (c < size)
	{
		min = tab[c];
		i = c;
		while (i < size)
		{
			if (min > tab[i])
			{
				min = tab[i];
				n = i;
				tab[n] = tab[c];
			}
			tab[c] = min;
			i++;
		}
		c++;
	}
}

int *tab_char_to_int(char **tab, int size)
{
    int *new_tab;
    int i;

    new_tab = malloc(size * sizeof(int));
    i = 0;
    while (tab[i])
    {
        new_tab[i] = ft_atoi(tab[i]);
        i++;
    }
    return(new_tab);
}

int find_med(char **splited)
{
	int	*tab;
	int	size;

	size = strlen_double(splited);
	tab = tab_char_to_int(splited, size);
    sort_int_tab(tab, size);
    return (tab[size / 2]);
}

int	strlen_double(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int find_max(char **splited)
{
    int i;
    int max;
	int	*tab;
	int	size;

    i = 0;
    max = tab[0];
	size = strlen_double(splited);
	tab = tab_char_to_int(splited, size);
    while (i < size)
    {
        if (max < tab[i])
            max = tab[i];
        i++;
    }
    return (max);
}