// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	int	N;
	int	cnt;
	int	end_time;

	std::cin >> N;
	std::vector<std::pair<int, int> >	arr(N);
	
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i].second >> arr[i].first;
	}
	sort(arr.begin(), arr.end());
	end_time = 0;
	cnt = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i].second >= end_time){
			end_time = arr[i].first;
			cnt++;
		}
	}
	std::cout << cnt << std::endl;
}