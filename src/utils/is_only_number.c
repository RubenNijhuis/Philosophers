/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_only_number.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 09:40:18 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/14 09:40:19 by rnijhuis      ########   odam.nl         */
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
