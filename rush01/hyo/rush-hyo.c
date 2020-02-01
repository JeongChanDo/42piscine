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
		printf("*");
		printf("<- %d \n", tmp[5]);
	}
	printf("wowdfjiq");
}

void	ft_receive(char *str)
{
	/*int recv[16];
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
*/
	int res_arr[24][6];
	ft_possible_case(res_arr);
}

/*
int		main(int argc, char *argv[])
{
	//char *str = "1 3 4 2 2 2 1 2 1 3 2 2 2 1 3 2";
	//char *str1 = "1 3 4 2 2 2 1 2 1 3 2 2 2 1 3 2";
	//char *str2 = "3 1 2 2 1 2 2 3 2 2 3 1 3 1 2 3";
	char *str3 = "2 3 1 3 3 2 2 1 2 1 2 4 2 4 2 1";
	//char *str4 = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	//char *str = argv[1];
	ft_receive(str3);

}*/


void		psbarray(int res_arr[24][6], int left, int right)
{	
	int row;
	int col;
	int count;
	int temparray[6][6] = {{0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0}};

	count = 0;
	row = 0;	
	while (row < 24)
	{
		if (res_arr[row][0] == left && res_arr[row][5] == right)
		{	
			col = 0;	
			while (col < 6)
			{		
				temparray[count][col] = res_arr[row][col];
				col++;
			}
			count++;
		}
		row++;
	}
	
	int i = 0;

	while (i < 6)
	{
		int j = 0;
		while (j < 6)	
		{
			printf("%d ", temparray[i][j]);
			//printf("i :%d, j:%d result : %d\n", i, j, temparray[i][j]); 
			j++;
		}
		printf("\n");
		i++;
	}
	printf("c");

}

int		main(void)
{
	int res_arr[24][6];
	ft_possible_case(res_arr);
	//printf("%d", res_arr[1][1]);
	psbarray(res_arr, 2, 2);
}
