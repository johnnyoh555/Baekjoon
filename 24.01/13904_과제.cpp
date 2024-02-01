// https://www.acmicpc.net/problem/13904

#include <iostream>
#include <algorithm>
#include <vector>

bool	compare(std::pair<int, int> &a, std::pair<int, int> &b) {
	return a.first > b.first;
}

int	main(void) {
	int	N;
	int sum;
	int cnt;
	int max;
	int max_idx;

	std::cin >> N;
	std::vector<std::pair<int, int> >	arr(N);

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end(), compare);
	sum = 0;
	max = -1;
	max_idx = -1;
	for (int i = arr[0].first; i > 0; i--) {
		for (int j = 0; j < N; j++) {
			if (arr[j].first >= i && arr[j].second > max) {
				max = arr[j].second;
				max_idx = j;
			}
		}
		if (max_idx >= 0) {
			sum += arr[max_idx].second;
			arr[max_idx].second = -100;
			max_idx = -1;
			max = -1;
		}
	}
	std::cout << sum << std::endl;
}