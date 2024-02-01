// https://www.acmicpc.net/problem/2164

#include <iostream>
#include <deque>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::deque<int>	dq;

	for (int i = 0; i < N; i++) {
		dq.push_back(i + 1);
	}
	while (dq.size() > 1) {
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
	}
	std::cout << dq.front() << std::endl;
}