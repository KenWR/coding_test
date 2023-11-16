#include <iostream>

void	merge_all(int p, int q, int r) ;
void	merge_sort(int p, int r);

int	size_of_arr, save_times, num;
int	arr[500002];
int	tmp[500002];
int	count = 0;

int main()
{
	std::cin >> size_of_arr >> save_times;
	// 배열 삽입
	for (int i = 0; i < size_of_arr; i++)
		std::cin >> arr[i];
	merge_sort(0, size_of_arr - 1);
	if (count < save_times)
		std::cout << -1;
	else
		std::cout << num;
	return (0);
}

void	merge_sort(int p, int r)
{
	int	q;

	if (count == save_times)
		return ;
	if (p < r)
	{
		q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge_all(p, q, r);
	}
}

void	merge_all(int p, int q, int r) 
{
	int	i, j, t;

	i = p; j = q + 1; t = 1;
	if (count == save_times)
		return ;
	while (i <= q and j <= r) 
	{
		if (arr[i] <= arr[j])
		{
			tmp[t++] = arr[i++];
		}
		else 
		{
			tmp[t++] = arr[j++];
		}
	}
	while (i <= q)  // 왼쪽 배열 부분이 남은 경우
	{
		tmp[t++] = arr[i++];
	}
	while (j <= r)  // 오른쪽 배열 부분이 남은 경우
	{
		tmp[t++] = arr[j++];
	}
	i = p; t = 1;
	while (i <= r)  // 결과를 A[p..r]에 저장
	{
		num = tmp[t];
		arr[i++] = tmp[t++];
		count++;
		if (count == save_times)
			return ;
	}
}