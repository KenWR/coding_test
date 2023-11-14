#include <iostream>
#include <vector>

int	N, M, i;
// std::vector<int> A;
int	A[100005];

int		partition(int start_idx, int end_idx);
void	quick_sort(int start_idx, int end_idx);
void	swap(int idx_1, int idx_2);
int		binary_search(int n);
bool	check(int idx, int num);

int main(){
	int	num;

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	for (int i = 0; i < N; i++){
		std::cin >> num;
		// A.push_back(num);
		A[i] = num;
	}
	quick_sort(0, N - 1);
	std::cin >> M;
	for (int i = 0; i < M; i++){
		std::cin >> num;
		std::cout << binary_search(num);
		std::cout << ' ';
	}
}

void	quick_sort(int start_idx, int end_idx){
	int	mid_idx;

    if (start_idx < end_idx){
        mid_idx = partition(start_idx, end_idx); 
        quick_sort(start_idx, mid_idx - 1); 
        quick_sort(mid_idx + 1, end_idx); 
    }
}

int	partition(int start_idx, int end_idx){
	int	pivot;

    pivot = A[end_idx];       
    for (int j = start_idx; j <= end_idx - 1; j++){
		if (A[j] <= pivot) {
			swap(start_idx, j);
			start_idx++; 
		}
	}
    if ((start_idx) != end_idx){
		swap(start_idx, end_idx);
	} 
    return (start_idx);
}

void	swap(int idx_1, int idx_2){
	int	tmp;

	tmp = A[idx_1];
	A[idx_1] = A[idx_2];
	A[idx_2] = tmp;
}

int    binary_search(int num){
	int	mid, left, right;

	left = 0;
	right = N;
	while (left + 1 < right){
		mid = (left + right) / 2;
		if (check(left, num) == check(mid, num)){
			left = mid;
		}
		else
			right = mid;
	}
	if (A[left] == num)
		return (true);
	return (false);
}

bool	check(int idx, int num){
	if (A[idx] <= num)
		return (true);
	return (false);
}