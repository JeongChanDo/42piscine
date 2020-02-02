/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 01:07:22 by eunpark           #+#    #+#             */
/*   Updated: 2020/02/02 02:28:30 by eunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isspace(char c)
{
	if (!(c > 48 && c < 53)
		return ();
	else
		return (0);
	return(!(c > 48  && c < 53) ? 0 : 1);
}

int	main(int argc, char *argv[])
{
	int i;
	int index;
	int input_val[16];

	i = 0;
	index = 0;

	if (argc != 2)
		return (0);	
	while (argv[1][i] != '\0')
	{	
		if (ft_isspace(argv[1][i]) == 1) //32가 아니면  true
		{
			input_val[index] = argv[1][i] - '0';
			index++;
		}
		i++;
	}

	int j = 0;
	while(j < 16)
	{
		printf("input_val[%d] ::  %d\n ",j, input_val[j]);
		j++;
	}

}
