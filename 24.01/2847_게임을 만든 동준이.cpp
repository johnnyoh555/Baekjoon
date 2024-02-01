// https://www.acmicpc.net/problem/2847

#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;

	std::cin >> N;

	std::vector<int>	arr(N);

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	int cnt = 0;

	for (int i = N - 1; i > 0; i--) {
		if (N == 1)
			break ;
		if (arr[i] <= arr[i - 1]) {
			cnt += arr[i - 1] - arr[i] + 1;
			arr[i - 1] = arr[i] - 1;
		}
	}
	std::cout << cnt << std::endl;
}