// https://www.acmicpc.net/problem/1449

#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	int	N;
	int L;

	std::cin >> N >> L;

	std::vector<int>	arr(N);
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int start = 0;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (!start)
			start = arr[i];
		if (arr[i] >= start + L) {
			start = arr[i];
			cnt++;
		}
	}
	std::cout << ++cnt <<std::endl;
	return 0;
}