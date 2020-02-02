#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_possible_case(int res_arr[24][6]){
	int i;
	int j;
	int psb_rows[4];
	int	left;
	int right;
	int max;
	int z;

	z = 0;
	left = 0;
	right = 0;
	max = 0;

	for (psb_rows[0] = 1; psb_rows[0] <= 4; psb_rows[0]++)
	{
		for (psb_rows[1] = 1; psb_rows[1] <= 4; psb_rows[1]++)
		{
			for (psb_rows[2] = 1; psb_rows[2] <= 4; psb_rows[2]++)
			{
				for (psb_rows[3] = 1; psb_rows[3] <=4; psb_rows[3]++)
				{
					if ( ((psb_rows[0] != psb_rows[1]) 
								&& (psb_rows[0] != psb_rows[2] 
									&& (psb_rows[0] != psb_rows[3])) 
								&& ((psb_rows[1] != psb_rows[2]) 
									&& (psb_rows[1] != psb_rows[3])) 
								&& (psb_rows[2] != psb_rows[3])) )
					{
						max = 0;
						left = 0;
						for (i =0; i < 4; i++)
						{
							if (psb_rows[i] > max)
							{
								max = psb_rows[i];
								left++;
							}
						}
						max = 0;
						right = 0;
						for (i =3; i >= 0; i--)
						{
							if (psb_rows[i] > max)
							{
								max = psb_rows[i];
								right++;
							}
						}
						res_arr[z][0] = left;
						res_arr[z][1] = psb_rows[0];
						res_arr[z][2] = psb_rows[1];
						res_arr[z][3] = psb_rows[2];
						res_arr[z][4] = psb_rows[3];
						res_arr[z][5] = right;
						z++;
					}
				}
			}
		}
	}
}



int ft_valid_cnt(int res_arr[6], int t, int b, int tmp[4])
{
	int valid_cnt;
	int j;
	valid_cnt = 0;
	if (res_arr[0] == t)
	{
		if (res_arr[5] == b)
		{
			for (j = 0; j <4; j++)
			{
				if (res_arr[j+1] == tmp[j])
					valid_cnt++;
			}
		}
	}
	return (valid_cnt);
}

int	is_valid(int res_arr[24][6], int t, int b, int tmp[4])
{
	int idx_arr[3];
	int i;
	int j;
	int valid_cnt;
	
	i = 0;
	while (i < 24)
	{
		valid_cnt = ft_valid_cnt(res_arr[i], t, b, tmp);
		if (valid_cnt == 4)
		{
			return (valid_cnt);
		}
		i++;
	}
	return (valid_cnt);
}

int		**(psbarray(int res_arr[24][6], int left, int right))
{	
	int row;
	int col;
	int count;
	int **temparray;

	row = 0;
	count = 0;
	while (row < 24)
	{	
		if (res_arr[row][0] == left && res_arr[row][5] == right)	
			count++;
		row++;
	}

	temparray = (int **)malloc(count * sizeof(int *));
	
	row = 0;
	count = 0;
	while (row < 24)
	{
		if (res_arr[row][0] == left && res_arr[row][5] == right)
		{	
			col = 1;
			temparray[count] = (int *)malloc(4 * sizeof(int *));
			while (col < 5)
			{		
				temparray[count][col - 1] = res_arr[row][col];
				col++;
			}
			count++;
		}
		row++;
	}
	return temparray;
}

int		*arraysize(int *input, int res_arr[][6])
{
	int size[4];
	
	int row = 0;
	int count;
	int i = 0;
	while (i < 4)
	{
		count = 0;
		row = 0;
		while (row < 24)
		{	
			if (res_arr[row][0] == input[8 + i] && res_arr[row][5] == input[12 + i])	
				count++;
			row++;
		}
		size[i] = count * 4;
		i++;
	}
	return size; 
}

int	ft_solutions_cnt(int idx_arr[4] , int row_cnt[4])
{
	int solution_len;

	solution_len = 0;
	for (idx_arr[0] = 0; idx_arr[0] < row_cnt[0]; idx_arr[0]++)
	{
		for (idx_arr[1] = 0; idx_arr[1] < row_cnt[1]; idx_arr[1]++)
		{
			for (idx_arr[2] = 0; idx_arr[2] < row_cnt[2]; idx_arr[2]++)
			{
				for (idx_arr[3] = 0; idx_arr[3] < row_cnt[3]; idx_arr[3]++)
				{
					solution_len++;
				}
			}
		}
	}
	return (solution_len);
}

void ft_arr_init(int **arr[4], int res_arr[24][6], int *input)
{
	arr[0] = psbarray(res_arr, input[8] ,input[12]);
	arr[1] = psbarray(res_arr, input[9] ,input[13]);
	arr[2] = psbarray(res_arr, input[10] ,input[14]);
	arr[3] = psbarray(res_arr, input[11] ,input[15]);
	printf("arr1 : %p \n", arr[0]);
}


void	ft_skyscrapper(int *input)
{
	int i;
	int j;
	int res_arr[24][6];
	int *row_len;
	int row_cnt[4];
	int idx_arr[4];
	int solution_len;
	int solution_idx;
	int x;
	int y;
	int **arr[4];

	ft_possible_case(res_arr);
	ft_arr_init(arr, res_arr, input);

	row_len = arraysize(input,res_arr);

	
	i = 0;
	while (i < 4)
	{
		row_cnt[i] = row_len[i]/sizeof(int);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		idx_arr[i] = 0;
		i++;
	}

	solution_idx = 0;
	j = 0;



	solution_len = ft_solutions_cnt(idx_arr, row_cnt);


	int col_arrs[solution_len][4][4];

	printf("row_cnt : %p \n");
	//ft_generate_solutions(col_arrs, solution_len, arr, idx_arr, row_cnt);


	solution_idx = 0;
	for (idx_arr[0] = 0; idx_arr[0] < row_cnt[0]; idx_arr[0]++)
	{
		for (idx_arr[1] = 0; idx_arr[1] < row_cnt[1]; idx_arr[1]++)
		{
			for (idx_arr[2] = 0; idx_arr[2] < row_cnt[2]; idx_arr[2]++)
			{
				for (idx_arr[3] = 0; idx_arr[3] < row_cnt[3]; idx_arr[3]++)
				{
					for (j = 0; j < 4; j++)
					{
						for (i = 0; i < 4; i++)
							col_arrs[solution_idx][i][j] = arr[i][idx_arr[i]][j];
					}
					solution_idx++;
				}
			}
		}
	}


	int psb_rows[24][6];
	ft_possible_case(psb_rows);
	
	int tmp[4];

	int top = 0;
	int bottom = top + 4;
	int z = 0;
	int valid_cnt = 0; 

	int solution;
	for( i = 0 ; i < solution_len; i++)
	{
		valid_cnt = 0;
		top = 0;
		bottom = top + 4;
		for( y = 0; y < 4; y++)
		{
			z = 0;
			for( x = 0; x < 4; x++)
			{
				tmp[z] = col_arrs[i][x][y];
				z++;
			}
			valid_cnt = valid_cnt + is_valid(psb_rows, input[top], input[bottom], tmp);
			top++;
			bottom++;
		}
		if (valid_cnt == 16)
		{
			solution = i;
			break;
		}
	}
	if (solution != 0)
	{
		for(x = 0; x < 4; x++)
		{
			for(y = 0; y < 4; y++)
			{
				printf("%d ",col_arrs[solution][x][y]);
			}
			printf("\n");
		}
	}

}
