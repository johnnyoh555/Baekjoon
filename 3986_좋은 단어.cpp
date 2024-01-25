// https://www.acmicpc.net/problem/3986

#include <iostream>
#include <stack>

int	cnt;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;

	std::cin >> N;
	std::string	str;

	for (int i = 0; i < N; i++) {
		std::stack<char>	st;
		std::cin >> str;
		int flag = 0;
		if (str.size() % 2 == 1) {
			flag = 1;
		}
		else {
			for (int j = 0; j < str.size(); j++) {
				if (st.empty() || str[j] != st.top())
					st.push(str[j]);
				else if (!st.empty() && str[j] == st.top())
					st.pop();
			}
			if (!st.empty())
				flag = 1;
		}
		if (flag == 0)
			cnt++;
	}
	std::cout << cnt << '\n';
}