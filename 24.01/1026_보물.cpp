// https://www.acmicpc.net/problem/1026

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;

	std::cin >> N;

	std::vector<int>	a(N);
	std::vector<int>	b(N);

	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += a[i] * b[N - 1 - i];
	}
	std::cout << sum << std::endl;
}