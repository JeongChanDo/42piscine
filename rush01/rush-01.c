/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 01:21:52 by jdo               #+#    #+#             */
/*   Updated: 2020/02/01 14:12:53 by jdo              ###   ########.fr       */
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

int	search_zerone_cnt(int mat[6][6])
{
	int pos_cnt = 0;
	int zero_cnt = 0;
	int i = 0;
	int j = 0;

	//search horizontal
	for ( i = 1; i <5; i++)
	{
		zero_cnt = 0;
		for (j = 1; j <5; j++)
		{
			if(mat[i][j] == 0)
				zero_cnt++;
		}
		if (zero_cnt == 1)
			pos_cnt++;
	}
	//search vertical
	for ( i = 1; i <5; i++)
	{
		zero_cnt = 0;
		for (j = 1; j <5; j++)
		{
			if(mat[j][i] == 0)
				zero_cnt++;
		}
		if (zero_cnt == 1)
			pos_cnt++;
	}
	//printf("zero one cnt : %d\n",pos_cnt);
	return (pos_cnt);
}

int	search_zerone(int zerone_cnt, int *coord[2], int mat[6][6])
{
	int zero_cnt = 0;
	int i = 0;
	int j = 0;
	int pos_cnt = 0;

	//int coord[pos_cnt][2];

	//search horizontal
	for ( i = 1; i <5; i++)
	{
		zero_cnt = 0;
		for (j = 1; j <5; j++)
		{
			if(mat[i][j] == 0)
				zero_cnt++;
		}
		if (zero_cnt == 1)
		{
			for (j = 1; j <5; j++)
			{
				if(mat[i][j] == 0)
				{
					coord[pos_cnt][0] = i;
					coord[pos_cnt][1] = j;
					//printf("zero_one pos : (%d, %d)\n", i, j);
				}
			}
			pos_cnt++;
		}
	}

	pos_cnt = 0;
	//search vertical
	for ( i = 1; i <5; i++)
	{
		zero_cnt = 0;
		for (j = 1; j <5; j++)
		{
			if(mat[j][i] == 0)
				zero_cnt++;
		}
		if (zero_cnt == 1)
		{
			for (j = 1; j <5; j++)
			{
				if(mat[j][i] == 0)
				{
					coord[pos_cnt][0] = i;
					coord[pos_cnt][1] = j;
					//printf("zero_one pos : (%d, %d)\n", i, j);
				}
			}
			pos_cnt++;
		}
	}
}

int	find_empty_val(int x, int y, int mat[6][6])
{
	int val[] = {1, 2, 3, 4};
	int i = 1;
	int j = 1;
	int val_idx = 0;
	int zero_cnt = 0;

	//horizontal check
	i = x;
	for (j = 1; j < 5; j++)
	{
		if (mat[i][j] == 0)
			zero_cnt++;
	}

	if (zero_cnt != 1)
	{
		//printf("horizontal zero one not found\n");
	}
	else
	{
		for (j = 1; j < 5; j++)
		{
			if (mat[i][j] != 0)
			{
				for (val_idx = 0; val_idx < 4; val_idx++)
				{
					if(val[val_idx] == mat[i][j])
					{
						val[val_idx] = 9;
					}
				}
			}
		}

		for (val_idx = 0; val_idx < 4; val_idx++)
		{
			if(val[val_idx] != 9)
			{
				//printf("horizontal direction zero one is founded insert %d(%d, %d) \n", val_idx+1, x, y);
				mat[x][y] = val_idx+1;
			}
		}
	}


	//vertical check
	zero_cnt = 0;
	j = y;
	for (i = 1; i < 5; i++)
	{
		if (mat[i][j] == 0)
			zero_cnt++;
	}
	if (zero_cnt != 1)
	{
		//printf("vertical zero one not found\n");
	}
	else
	{
		for (i = 1; i < 5; i++)
		{
			if (mat[i][j] != 0)
			{
				for (val_idx = 0; val_idx < 4; val_idx++)
				{
					if(val[val_idx] == mat[i][j])
					{
						val[val_idx] = 9;
					}
				}
			}
		}

		for (val_idx = 0; val_idx < 4; val_idx++)
		{
			if(val[val_idx] != 9)
			{
				//printf("vertical direction zero one is founded insert %d(%d, %d) \n", val_idx+1, x, y);
				mat[x][y] = val_idx+1;
			}
		}

	}

	//print_mat(mat);

}
void	fill_zerone(int zerone_cnt, int *coord[2], int mat[6][6])
{
	int i = 0;
	int x = 0;
	int y = 0;
	int empty_val = 0;
	for (i = 0; i < zerone_cnt ; i++)
	{
		x = coord[i][0];
		y = coord[i][1];
		empty_val = find_empty_val(x, y, mat);
		mat[x][y] = empty_val;
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

	int zerone_cnt = search_zerone_cnt(mat);
	int coord[zerone_cnt][2];
	search_zerone(zerone_cnt, coord, mat);
	fill_zerone(zerone_cnt, coord, mat);

	//int res_arr[24][6];
	//view_result(res_arr);

}

void	rush_simple(char *str)
{
	int input[16];
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 16)
	{
		input[i] = str[2 * i] - '0';
		i++;
	}
	int mat[6][6] = {
						{0, input[0], input[1], input[2], input[3], 0},
						{input[8], 0, 0, 0, 0, input[12]},
						{input[9], 0, 0, 0, 0, input[13]},
						{input[10], 0, 0, 0, 0, input[14]},
						{input[11], 0, 0, 0, 0, input[15]},
						{0, input[4], input[5], input[6], input[7], 0}
					};
	insert_mat(input, mat);
	int zerone_cnt = search_zerone_cnt(mat);
	int coord[zerone_cnt][2];
	search_zerone(zerone_cnt, coord, mat);
	fill_zerone(zerone_cnt, coord, mat);
	print_mats(mat);

}

void	show_examples(char **str)
{

}


void	main(int argc, char *argv[])
{
	char *str = "1 3 4 2 2 2 1 2 1 3 2 2 2 1 3 2";
	char *str1 = "1 3 4 2 2 2 1 2 1 3 2 2 2 1 3 2";
	char *str2 = "3 1 2 2 1 2 2 3 2 2 3 1 3 1 2 3";
	char *str3 = "2 3 1 3 3 2 2 1 2 1 2 4 2 4 2 1";
	char *str4 = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	/*
	if (argc != 2)
		write(1, "Error\n", 6);
	*/
	//char *str = argv[1];
	//rush(str);
	printf("input : %s \n", str1);
	rush_simple(str1);
	printf("----------\n");
	printf("input : %s \n", str2);
	rush_simple(str2);
	printf("----------\n");
	printf("input : %s \n", str3);
	rush_simple(str3);
	printf("----------\n");
	printf("input : %s \n", str4);
	rush_simple(str4);
	printf("----------\n");
}
