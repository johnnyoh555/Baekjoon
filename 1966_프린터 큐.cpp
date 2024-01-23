// https://www.acmicpc.net/problem/1966

#include <iostream>
#include <queue>
#include <utility>

int	main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int M;
		int idx;
		std::cin >> M >> idx;

		std::queue<std::pair<int, int> > arr;
		int	point[9] = {0,};
		for (int j = 0; j < M; j++) {
			std::pair<int, int>	tmp;
			std::cin >> tmp.first;
			point[tmp.first - 1]++;
			tmp.second = j;
			arr.push(tmp);
		}
		int	cnt = 0;
		while (1) {
			int flag = 0;
			for (int k = 0; k < 9; k++) {
				if (point[k] != 0 && k + 1 > arr.front().first) {
					arr.push(arr.front());
					arr.pop();
					flag = 1;
				}
			}
			if (flag == 0) {
				if (arr.front().second == idx) {
					std::cout << cnt + 1 << std::endl;
					break ;
				}
				point[arr.front().first - 1]--;
				arr.pop();
				cnt++;
			}
		}
	}
}