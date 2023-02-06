#include "libft.h"

void	**ft_free_split(char **ptr)
{
	unsigned int	i;
	unsigned int	s;

	i = 0;
	s = 0;
	while (ptr[s] != NULL)
		s++;
	while (i < s)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}