/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:53 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/11/21 12:39:06 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	**ft_split(char *str)
{
	char	**split = (char **)malloc(1000);
	int		i = 0;
	int		j = 0;
	int		k = 0;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		split[k] = malloc(1000);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n')
		{
			split[k][j] = str[i];
			i++;
			j++;
		}
		split[k][j] = '\0';
		if (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\0')
			k++;
		j = 0;
	}
	split[k] = NULL;
	return (split);
}