/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 01:21:52 by jdo               #+#    #+#             */
/*   Updated: 2020/02/01 12:29:58 by jdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_mat(int mat[6][6])
{
	int i;
	int j;

	printf("---------(table)--------\n");
	for(i = 0; i < 6; i++)
	{
		for(j = 0; j < 6; j++)
		{
			printf(" %d ",mat[i][j]);
			if ( ((i == 0) || i == 5) )
				printf(" ");
			else if( j == 5)
				printf("");
			else
				printf("|");
		}
		if (i != 5)
			printf("\n   -----------------  \n");
	}
	printf("\n----------(end)---------\n");
}

void	print_mats(int mat[6][6])
{
	int i;
	int j;

	for(i = 1; i < 5; i++)
	{
		for(j = 1; j < 5; j++)
		{
			printf(" %d ",mat[i][j]);
			if ( ((i == 0) || i == 5) )
				printf(" ");
		}
		printf("\n");
	}
}

void	view_result(int res_arr[24][6]){
	int i;
	int j;
	int b[4];
	int left_view = 0;
	int right_view = 0;
	int z = 0;
	for (b[0] = 1; b[0] <= 4; b[0]++)
	{
		for (b[1] = 1; b[1] <= 4; b[1]++)
		{
			for (b[2] = 1; b[2] <= 4; b[2]++)
			{
				for (b[3] = 1; b[3] <=4; b[3]++)
				{
					if ( ((b[0] !=  b[1]) && (b[0] != b[2]) && (b[0] != b[3])) &&
							((b[1] != b[2])&&(b[1] != b[3])) && (b[2] != b[3]))
					{
						left_view = 1;
						for (i =0; i < 3; i ++)
						{
							if (b[i] < b[i+1])
								left_view++;
						}
						right_view = 1;
						for (i =3; i > 0; i--)
						{
							if (b[i] <  b[i-1])
								right_view++;
						}
						res_arr[z][0] = left_view;
						res_arr[z][1] = b[0];
						res_arr[z][2] = b[1];
						res_arr[z][3] = b[2];
						res_arr[z][4] = b[3];
						res_arr[z][5] = right_view;
						z++;
					}
				}
			}
		}
	}
	printf("length of res arr : %d\n", z);
	printf("left\t\tright\n");
	int tmp[6];
	for (z = 0; z < 24; z++)
	{
		tmp[0] = res_arr[z][0];
		tmp[1] = res_arr[z][1];
		tmp[2] = res_arr[z][2];
		tmp[3] = res_arr[z][3];
		tmp[4] = res_arr[z][4];
		tmp[5] = res_arr[z][5];
		printf("%d -> ", tmp[0]);
		printf("|");
		printf("%d %d %d %d", tmp[1], tmp[2], tmp[3], tmp[4]);
		printf("|");
		printf("<- %d \n", tmp[5]);
	}



}

void	insert_mat(int *input, int mat[6][6])
{
	int i = 0;
	//horizontal left - insert 1 2 3 4 if row left is 4;
	i = 8;
	while (i >= 8 && i <= 11)
	{
		if (input[i] == 4)
		{
			mat[i-7][1] = 1;
			mat[i-7][2] = 2;
			mat[i-7][3] = 3;
			mat[i-7][4] = 4;
		}
		else if (input[i] == 1)
		{
			mat[i-7][1] = 4;
		}
		i++;
	}

	i = 12;
	while (i >= 12 && i <= 15)
	{
		if (input[i] == 4)
		{
			mat[i-11][4] = 1;
			mat[i-11][3] = 2;
			mat[i-11][2] = 3;
			mat[i-11][1] = 4;
		}
		else if (input[i] == 1)
		{
			mat[i-11][4] = 4;
		}
		i++;
	}
	//vertical up - insert 1 2 3 4 if col up is 4;
	i = 0;
	while (i >= 0 && i <= 3)
	{
		if (input[i] == 4)
		{
			mat[1][i + 1] = 1;
			mat[2][i + 1] = 2;
			mat[3][i + 1] = 3;
			mat[4][i + 1] = 4;
		}
		else if (input[i] == 1)
		{
			mat[1][i + 1] = 4;
		}
		i++;
	}
}


void	rush(char *str)
{
	//char *str = argv[1];
	int input[16];
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 16)
	{
		input[i] = str[2 * i] - '0';
		printf("%d ", input[i]);
		i++;
	}
	printf("\n");
	int mat[6][6] = {
						{0, input[0], input[1], input[2], input[3], 0},
						{input[8], 0, 0, 0, 0, input[12]},
						{input[9], 0, 0, 0, 0, input[13]},
						{input[10], 0, 0, 0, 0, input[14]},
						{input[11], 0, 0, 0, 0, input[15]},
						{0, input[4], input[5], input[6], input[7], 0}
					};
	insert_mat(input, mat);
	print_mat(mat);
	print_mats(mat);


	int res_arr[24][6];
	view_result(res_arr);

}

void	main(int argc, char *argv[])
{
	char *str = "2 3 1 3 3 2 2 1 2 1 2 4 2 4 2 1";
	//char *str = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	/*
	if (argc != 2)
		write(1, "Error\n", 6);
	*/
	//char *str = argv[1];
	rush(str);
}
