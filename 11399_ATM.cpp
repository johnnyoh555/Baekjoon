// https://www.acmicpc.net/problem/11399

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;

	std::cin >> N;

	std::vector<int>	arr(N);

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int time = 0;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		time += arr[i];
		sum += time;
	}
	std::cout << sum << std::endl;
}