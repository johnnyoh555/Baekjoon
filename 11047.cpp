// https://www.acmicpc.net/problem/11047.cpp

#include <iostream>
#include <vector>

int cnt;

void	greedy(std::vector<int> &arr, int K, int idx) {
	for(; idx >= 0; idx--) {
		if (arr[idx] <= K) {
			cnt += K / arr[idx];
			K = K % arr[idx];
			break ;
		}
	}
	if (K == 0)
		return ;
	greedy(arr, K, idx - 1);
}

int	main(void) {
	int	N;
	int	K;

	std::cin >> N >> K;

	std::vector<int>	arr(N);
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	greedy(arr, K, arr.size() - 1);
	std::cout << cnt << std::endl;
	return 0;
}