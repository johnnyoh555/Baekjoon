// https://www.acmicpc.net/submit/18258

#include <iostream>
#include <queue>

int	main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::queue<int>		q;
	std::string	str;
	int			N;
	int			tmp;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		if (str == "push") {
			std::cin >> tmp;
			q.push(tmp);
		}
		else if (str == "pop") {
			if (q.empty()) {
				std::cout << "-1" << '\n';
			}
			else {
				std::cout << q.front() <<'\n';
				q.pop();
			}
		}
		else if (str == "front") {
			if (q.empty()) {
				std::cout << "-1" << '\n';
			}
			else {
				std::cout << q.front() << '\n';
			}
		}
		else if (str == "back") {
			if (q.empty()) {
				std::cout << "-1" << '\n';
			}
			else {
				std::cout << q.back() << '\n';
			}
		}
		else if (str == "size")
			std::cout << q.size() << '\n';
		else if (str == "empty") {
			if (q.empty()) {
				std::cout << "1" << '\n';
			}
			else {
				std::cout << "0" << '\n';
			}
		}
	}
}