// https://www.acmicpc.net/problem/5430

#include <iostream>
#include <deque>
#include <cctype>


void	parse(std::string& x, std::deque<int>& dq) {
	int	num = 0;

	for (int i = 0; i < x.size(); i ++) {
		if (x[i] == ',' || x[i] == ']') {
			dq.push_back(num);
			num = 0;
		}
		if (isdigit(x[i])) {
			num *= 10;
			num += x[i] - '0';
		}
	}
}

void	print(std::deque<int>& dq, int R) {
	std::cout << '[';
	if (!R) {
		for (int i = 0; i < dq.size(); i++) {
			std::cout << dq[i];
			if (i != (int)dq.size() - 1)
				std::cout << ',';
		}
	} else {
		for (int i = dq.size() - 1; i >= 0; i--) {
			std::cout << dq[i];
			if (i != 0)
				std::cout << ',';
		}
	}
	std::cout << "]\n";
}


int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::string 		p;
		int					n;
		std::string 		x;
		std::deque<int>		dq;

		std::cin >> p;
		std::cin >> n; 
		std::cin >> x;
		if (n)
			parse(x, dq);
		int	R = 0;
		int flag = 0;

		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R')
				R = !R;
			else if (p[j] == 'D') {
				if (dq.empty()) {
					flag = 1;
					break ;
				}
				else if (!R)
					dq.pop_front();
				else if (R)
					dq.pop_back();
			}
		}
		if (flag)
			std::cout << "error" << '\n';
		else
			print(dq, R);
	}
}