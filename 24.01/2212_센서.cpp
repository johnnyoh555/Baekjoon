// https://www.acmicpc.net/problem/2212

#include <iostream>
#include <vector>
#include <algorithm>

int	main() {
	int N;
	int	K;

	std::cin >> N >> K;

	std::vector<int>	arr(N);
	std::vector<int>	len(N - 1);

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N - 1; i++) {
		len[i] = arr[i + 1] - arr[i];
	}
	sort(len.begin(), len.end());

	int sum = 0;

	for (int i = 0; i < N - K; i++) {
		sum+= len[i];
	}
	std::cout << sum << std::endl;
}