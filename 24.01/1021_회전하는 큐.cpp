// https://www.acmicpc.net/problem/1021

#include <iostream>
#include <deque>

int sum;

int	main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::deque<int>	dq;
	int N;
	int M;

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) dq.push_back(i);

	for (int i = 0; i < M; i++) {
		int	tmp;
		std::cin >> tmp;
		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == tmp) {
				int cnt;
				if (j < dq.size() - j ) {
					cnt = j;
					for (int k = 0; k < j; k++) {
						dq.push_back(dq.front());
						dq.pop_front();
					}
					dq.pop_front();
				}
				else {
					cnt = dq.size() - j;
					for (int k = 0; k < dq.size() - j; k++) {
						dq.push_front(dq.back());
						dq.pop_back();
					}
					dq.pop_front();
				}
				sum += cnt;
			}
		}
	}
	std::cout << sum << '\n';
}