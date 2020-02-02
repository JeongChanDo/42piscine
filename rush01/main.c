/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:06:45 by eunpark           #+#    #+#             */
/*   Updated: 2020/02/02 20:31:58 by jdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_skyscrapper(int *);

int		*ft_input_arr(char *argv)
{
	int		i;
	int		index;
	int		*input_val;

	i = 0;
	index = -1;
	input_val = (int*)malloc(sizeof(int) * 16);
	while (argv[i] != '\0')
	{
		if (i % 2 == 0)
			input_val[++index] = argv[i] - '0';
		i++;
	}
	return (input_val);
}

int		ft_error_chk(char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (!(argv[i] > '0' && argv[i] < '5'))
				return (0);
			count++;
		}
		else if (i % 2 == 1 && !(argv[i] == 32))
			return (0);
		i++;
	}
	if (argv[i - 1] == ' ' || count != 16)
		return (0);
	return (1);
}

int		main(int argc, char *argv[])
{
	int	*input_val;

	if (argc != 2)
		return (0);
	if (ft_error_chk(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	input_val = ft_input_arr(argv[1]);

	ft_skyscrapper(input_val);
}
