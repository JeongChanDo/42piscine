#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

void	printarray(int **array)
{	
	int i = 0;
	int j = 0;
	int width = 0;
	int height = 0;

	printf("%lu\n", sizeof(array));
	width = sizeof(array[0])/sizeof(int);
	printf("%d\n", width);
	height = sizeof(array)/width;
	printf("%d\n", height); 
	while (i < height)
	{
		int j = 0;
		while (j < width)	
		{
			printf("%d ", array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
	//printf("%lu", sizeof(temparray));

	return temparray;
}

int		main(int argc, char *argv[])
{
	int input[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	int res_arr[24][6];

	ft_possible_case(res_arr);
	


	int **row1 = psbarray(res_arr, input[0] ,input[4]);
	int **row2 = psbarray(res_arr, input[1] ,input[5]);
	int **row3 = psbarray(res_arr, input[2] ,input[6]);
	int **row4 = psbarray(res_arr, input[3] ,input[7]);

	int **col1 = psbarray(res_arr, input[8] ,input[12]);
	int **col2 = psbarray(res_arr, input[9] ,input[13]);
	int **col3 = psbarray(res_arr, input[10] ,input[14]);
	int **col4 = psbarray(res_arr, input[11] ,input[15]);
	


	/*
	int i = 0;
	while (i < 4)
	{
		printf("%d", array1[0][i]);
		i++;
	}
	while (i < 4)
	{
		printf("%d", array1[1][i]);
		i++;
	}*/
	//	printarray(array1);
 	
	
}
	
