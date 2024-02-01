// https://www.acmicpc.net/problem/2217

#include <iostream>
#include <vector>
#include <algorithm>

bool	compare(int a, int b) {
	return a > b;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int	N;

	std::cin >> N;

	std::vector<int>	arr(N);
	
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), compare);

	int max = 0;

	for (int i = 0; i < N; i++) {
		if (arr[i] * (i + 1) > max)
			max = arr[i] * (i + 1);
	}
	std::cout << max << std::endl;
}