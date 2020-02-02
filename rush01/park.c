int	ft_solution_cnt(int idx_arr[4], int row_cnt[4])
{
	int solution_len;

	solution_len = 0;
	idx_arr[0] = 0;
	while (idx_arr[0] < row_cnt[0])
	{
		idx_arr[1] = 0;
		while (idx_arr[1] < row_cnt[1])
		{
			idx_arr[2] = 0;
			while (idx_arr[2] < row_cnt[2])
			{
				idx_arr[3] = 0;
				while (idx_arr[3] < row_cnt[3])
				{
					solution_len++;
					idx_arr[3]++;
				}
			idx_arr[2]++;
			}
		idx_arr[1]++;
		}
	idx_arr[0]++;
	}
	return (solution_len);	
}
