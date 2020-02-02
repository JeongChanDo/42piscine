/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psbarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:49:05 by hyolim            #+#    #+#             */
/*   Updated: 2020/02/02 23:07:34 by jdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int numcheck(int res_arr[24][6], int left, int right )
{
	int row;
	int count;

	row = 0;
	count = 0;
	while (row < 24)
	{	
		if (res_arr[row][0] == left && res_arr[row][5] == right)	
			count++;
		row++;
	}
	return count;
}

int		**(psbarray(int res_arr[24][6], int left, int right))
{	
	int row;
	int col;
	int count;
	int **temparray;
	
	count = numcheck(res_arr, left, right);
	temparray = (int **)malloc(count * sizeof(int *));
	row = -1;
	count = 0;
	while (++row < 24);
}
