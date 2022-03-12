/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:47:33 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/12 10:13:17 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char	*ptr_dest;

	ptr_dest = dest;
	while (len > 0)
	{
		*ptr_dest = val;
		ptr_dest++;
		len--;
	}
	return (dest);
}

static void	*ft_bzero(void *ptr, size_t len)
{
	return (ft_memset(ptr, 0, len));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
