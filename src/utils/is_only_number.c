/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_only_number.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 09:13:50 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/03/12 09:18:04 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum e_bool	is_only_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i > 0 && (str[i] == '-'))
			return (false);
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}
