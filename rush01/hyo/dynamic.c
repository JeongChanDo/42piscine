#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



//가능한 숫자 정렬
void	ft_possible_case(int res_arr[24][6])
{
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

void		psbarray(int res_arr[24][6], int left, int right)
{	
	int row;
	int col;
	int count;
	int temparray[6][6] = {0,};

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
			j++;
		}
		printf("\n");
		i++;
	}

}

int		main(void)
{
	int res_arr[24][6];
	ft_possible_case(res_arr);
	psbarray(res_arr, 4, 1);
}
