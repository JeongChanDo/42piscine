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
	printf("ft_isspace input char::  %c char int ::  %d \n",c, c);
	return((c > 8 && c < 14) || (c == 32) ? 0 : 1);
}

int	main(int argc, char *argv[])
{
	int i;
	int index;
	int input_val[16];

	i = 0;
	index = 0;
	while (argv[1][i] != '\0')
	{	
		printf("while i :: %d \n", i);

		if (ft_isspace(argv[1][i]) == 1) //32가 아니면  true
		{
			printf("sp가 아니면 index ::  %d \n", index);

			if (argv[1][i] > 48 && argv[1][i] < 53)
			{
				printf("argv[1][%d] value ::  %c\n", i, argv[1][i]);
				input_val[index] = argv[1][i] - '0';
				index++;
			}
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
