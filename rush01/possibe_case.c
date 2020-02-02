int		*ft_possible_chk(int *psb_rows, int **res_arr, int z)
{
	int max_left;
	int max_right;
	int cnt_left;
	int cnt_right;
	int index;

	max_left = 0;
	max_right = 0;
	cnt_left = 0;
	cnt_right = 0;
	index = -1;
	while (++index < 4)
	{
		if (psb_rows[index] > max_left)
		{
			max_left = psb_rows[index];
			cnt_left++;
		}
		if (psb_rows[3 - index] > max_right)
		{
			max_right = psb_rows[3 - index];
			cnt_right++;
		}
	}
	return (insert_value(psb_rows, res_arr, z, cnt_right, cnt_left));
}

int		**insert_value(int *psb_rows, int **res_arr, int z, int cnt_right, int cnt_left)
{
	int i;

	i = 1;
	while (i < 5)
	{
		res_arr[z][i] = psb_rows[i-1];
		i++;
	}
	res_arr[z][0] = cnt_left;
	res_arr[z][5] = cnt_right;
	return (res_arr);
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permutations(int *psb_rows, int **res_arr, const int k, const int m, int *z)
{
	int i;
	
	if(k == m)
 	{
		res_arr = ft_possible_chk(psb_rows, res_arr, z++);
 	}

	else
	{
		i = k;
    	while(i <= m)
    	{
			swap(&psb_rows[k],&psb_rows[i]);
			permutations(psb_rows,k+1,m);
			swap(&psb_rows[k],&psb_rows[i]);
			i++;
		}
	}
}
