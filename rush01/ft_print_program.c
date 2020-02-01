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

int	ft_isspace(char c);
int	main(int argc, char *argv[])
{
	int i;
	int j;
	int k;
	int input_val[16];

	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		while(ft_isspace(argv[1][j]))
		{
			printf("j >>>> %d \n", j);
			if (argv[1][j] > '0' && argv[1][j] < '5')
			{
				printf("if %c\n", argv[1][j]);
				input_val[j] = argv[1][j] - '0';
				//printf("%d", input_val[j]);
			}
			printf("next isspace argment : %d - %c \n",argv[1][j], argv[1][j]);
		}
		j++;
		printf("\n");
		i++;
	}
/*
	i = 0;
	while(i < 16)
	{
		printf("%d", input_val[i]);
		i++;
	}
*/
}

int	ft_isspace(char c)
{
	printf("c - %c - %d \n",c, c);
	return((c > 8 && c < 14) || (c == 32) ? 0 : 1);
}

