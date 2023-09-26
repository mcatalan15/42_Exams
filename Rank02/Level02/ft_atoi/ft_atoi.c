/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:54:08 by mcatalan          #+#    #+#             */
/*   Updated: 2022/12/15 16:56:29 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_blank_spaces(char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] == ' ' || str[cont] == '\f' || str[cont] == '\n'
		|| str[cont] == '\r' || str[cont] == '\t' | str[cont] == '\v')
		cont++;
	return (cont);
}

int	ft_simbols(char *str, int *cont)
{
	int	numeroofnegative;

	numeroofnegative = 0;
	while (str[*cont] == '+' || str[*cont] == '-')
	{
		if (str[*cont] == '-')
			numeroofnegative++;
		*cont = *cont + 1;
	}
	return (numeroofnegative);
}

int	ft_stringtonumber(char *str, int nn, int cont)
{
	int	cont1;
	int	cont2;
	int	numtemp;
	int	result;

	cont1 = 0;
	result = 0;
	while (cont1 < nn)
	{
		cont2 = 0;
		numtemp = str[(cont - 1 + nn) - cont1];
		numtemp -= 48;
		while (cont2 < cont1)
		{
			numtemp = numtemp * 10;
			cont2++;
		}
		result += numtemp;
		cont1++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	cont;
	int	numberofnegative;
	int	nn;
	int	result;

	result = 0;
	nn = 0;
	cont = 0;
	if (str[0] == 0)
		return (0);
	cont = ft_blank_spaces(str);
	numberofnegative = ft_simbols(str, &cont);
	while (str[cont + nn] >= '0' && str[cont + nn] <= '9')
		nn++;
	result = ft_stringtonumber (str, nn, cont);
	if ((numberofnegative % 2) != 0)
		result = -result;
	return (result);
}
