#include <stdio.h>
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

void	ft_print(char *str)
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
	print_mat(mat);
}

void	ft_solve()
{

}

//pull test

void	main(int argc, char *argv[])
{

	/* test argv */
	//char *str = "1 3 4 2 2 2 1 2 1 3 2 2 2 1 3 2";
	//char *str1 = "1 3 4 2 2 2 1 2 1 3 2 2 2 1 3 2";
	//char *str2 = "3 1 2 2 1 2 2 3 2 2 3 1 3 1 2 3";
	char *str3 = "2 3 1 3 3 2 2 1 2 1 2 4 2 4 2 1";
	//char *str4 = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	ft_print(str3);
}
