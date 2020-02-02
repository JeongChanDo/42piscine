#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_print_board(int board[4][4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("---------\n");
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf(" %d ",board[i][j]);	
			j++;
		}
		printf("\n");
		i++;
	}
	printf("----------\n");
}

//가능한 숫자 정렬
void	ft_possible_case(int res_arr[24][6]){
	int i;
	int j;
	// 1st column, 2nd column, 3rd column, 4th column
	int psb_rows[4];
	int	left;
	int right;
	int max;

	left = 0;
	right = 0;
	max = 0;

	int z = 0;


	//경우의수 만들기 조합알고리즘, 재귀로 구현할것

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
						/*board를 봤을때 최소 하나는 보임, (4층 건물이 바로앞에
						 * 있는경우)
						 * left_view =1
						 */
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
	int tmp[6];
	for (z = 0; z < 24; z++)
	{
		for (i = 0; i < 6; i++)
			tmp[i] = res_arr[z][i];
	}
}

void	ft_receive(char *str)
{
	int recv[16];
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 16)
	{
		recv[i] = str[2 * i] - '0';
		i++;
	}

	// board declaration and initailization devision is needed.
	int board[4][4] = {{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0}};
	ft_print_board(board);

	int res_arr[24][6];
	ft_possible_case(res_arr);

}


int	is_valid(int res_arr[24][6], int t, int b, int tmp[4])
{
	int i;
	int j;

	int valid_cnt = 0;
	//top, bottom value check
	for (i = 0; i <24; i++)
	{
		valid_cnt = 0;
		if (res_arr[i][0] == t)
		{
			if (res_arr[i][5] == b)
			{
				//4 value check 
				for (j = 0; j <4; j++)
				{
					if (res_arr[i][j+1] == tmp[j])
						valid_cnt++;
				}
			}
		}
		if (valid_cnt == 4)
		{
			return valid_cnt;
		}
	}
	return valid_cnt;
}

int		**(psbarray(int res_arr[24][6], int left, int right))
{	
	int row;
	int col;
	int count;
	int **temparray;

	//동적 배열 만들기
	row = 0;
	count = 0;
	while (row < 24)
	{	
		if (res_arr[row][0] == left && res_arr[row][5] == right)	
			count++;
		row++;
	}

	temparray = (int **)malloc(count * sizeof(int *));
	

	//동적배열에 경우의 수 대입
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


void	ft_skyscrapper(int *input)
{
	int i;
	int j;
	int res_arr[24][6];
	int **arr1;
	int **arr2;
	int **arr3;
	int **arr4;
	int *arrlen;
	int arrrows[4];
	int idx_arr[4];
	int solution_len;
	int solution_idx;
	int x;
	int y;


	//top 4 -> bottom 4 -> left 4 -> right 4;
	//int input[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	//int input[16] = {1, 3, 4, 2, 2, 2, 1, 2, 1, 3, 2, 2, 2, 1, 3, 2};

	ft_possible_case(res_arr);
	arr1 = psbarray(res_arr, input[8] ,input[12]);
	arr2 = psbarray(res_arr, input[9] ,input[13]);
	arr3 = psbarray(res_arr, input[10] ,input[14]);
	arr4 = psbarray(res_arr, input[11] ,input[15]);
	
	arrlen = arraysize(input,res_arr);
	
	i = 0;
	while (i < 4)
	{
		arrrows[i] = arrlen[i]/sizeof(int);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		idx_arr[i] = 0;
		i++;
	}

	solution_len = 0;
	solution_idx = 0;

	//soltuion length calculation
	for (idx_arr[0] = 0; idx_arr[0] < arrrows[0]; idx_arr[0]++)
	{
		for (idx_arr[1] = 0; idx_arr[1] < arrrows[1]; idx_arr[1]++)
		{
			for (idx_arr[2] = 0; idx_arr[2] < arrrows[2]; idx_arr[2]++)
			{
				for (idx_arr[3] = 0; idx_arr[3] < arrrows[3]; idx_arr[3]++)
				{
					solution_len++;
				}
			}
		}
	}

	//insert to 3d ( solution_len x 4 x 4)
	int col_arrs[solution_len][4][4];

	// solution_len x 4 x 4
	for (idx_arr[0] = 0; idx_arr[0] < arrrows[0]; idx_arr[0]++)
	{
		for (idx_arr[1] = 0; idx_arr[1] < arrrows[1]; idx_arr[1]++)
		{
			for (idx_arr[2] = 0; idx_arr[2] < arrrows[2]; idx_arr[2]++)
			{
				for (idx_arr[3] = 0; idx_arr[3] < arrrows[3]; idx_arr[3]++)
				{
					for (j = 0; j < 4; j++)
					{
						col_arrs[solution_idx][0][j] = arr1[idx_arr[0]][j];
						col_arrs[solution_idx][1][j] = arr2[idx_arr[1]][j];
						col_arrs[solution_idx][2][j] = arr3[idx_arr[2]][j];
						col_arrs[solution_idx][3][j] = arr4[idx_arr[3]][j];
					}
					solution_idx++;
				}
			}
		}
	}

	int psb_rows[24][6];
	ft_possible_case(psb_rows);
	
	//check_vertically
	int tmp[4];

	//left 4-> right 4-> top 4 -> bottom 4;
	// top : 0 ~ 3, bottom 4 ~ 8;
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
				//temp vertical arr
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
