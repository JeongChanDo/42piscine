#include <stdio.h>
#include <unistd.h>

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
	printf("length of res arr : %d\n", z);
	printf("left\t\tright\n");
	int tmp[6];
	for (z = 0; z < 24; z++)
	{
		for (i = 0; i < 6; i++)
			tmp[i] = res_arr[z][i];
		printf("%d -> ", tmp[0]);
		printf("|");
		printf("%d %d %d %d", tmp[1], tmp[2], tmp[3], tmp[4]);
		printf("|");
		printf("<- %d \n", tmp[5]);
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


int		testbed()
{
	int arr1[1][4] = {{1, 2, 3, 4}};
	int arr2[3][4] = {{4, 1, 3, 2},
					{4, 2, 3, 1},
					{4, 3, 1, 2}};
	int arr3[2][4] = {{4, 1, 2, 3},
					{4, 2, 3, 1}};
	int arr4[1][4] = {{4, 3, 2, 1}};
	int i;
	int j;
	
	i = 0;
	
	// all rows length and cnt
	int arrlen[4] = {sizeof(arr1)/sizeof(int),
				sizeof(arr2)/sizeof(int),
				sizeof(arr3)/sizeof(int),
				sizeof(arr4)/sizeof(int)};
	int arrrows[4] = {arrlen[0]/sizeof(int),
					arrlen[1]/sizeof(int),
					arrlen[2]/sizeof(int),
					arrlen[3]/sizeof(int)};
	

	int idx_arr[] = {0, 0, 0, 0};
	int solution_len = 0;

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
	int solution_idx = 0;
	for (i = 0; i< solution_len; i++)
	{
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
					}
				}
			}
		}
		solution_idx++;
	}

	//print all solutions
	int x;
	int y;
	for (i = 0; i< solution_len; i++)
	{
		for (y = 0; y < 4; y++)
		{
			for (x = 0; x < 4; x++)
			{
				printf("%d ", col_arrs[i][y][x]);
			}
			printf("\n");
		}
		printf("--------\n");
	}

	
	//check_vertically


}

void	main(int argc, char *argv[])
{
	testbed();
	//char *str = "1 3 4 2 2 2 1 2 1 3 2 2 2 1 3 2";
	//char *str1 = "1 3 4 2 2 2 1 2 1 3 2 2 2 1 3 2";
	//char *str2 = "3 1 2 2 1 2 2 3 2 2 3 1 3 1 2 3";
	//char *str3 = "2 3 1 3 3 2 2 1 2 1 2 4 2 4 2 1";
	//char *str4 = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	//char *str = argv[1];
	//ft_receive(str3);
}
