// https://www.acmicpc.net/problem/10799

#include <iostream>
#include <stack>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::string	str;
	std::stack<char>	st;

	std::cin >> str;

	int flag = 0;
	int sum = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			flag = 0;
			st.push(str[i]);
		}
		else if (str[i] == ')') {
			st.pop();
			if (flag == 0)
				sum += st.size();
			if (flag == 1)
				sum += 1;
			flag = 1;
		}
	}
	std::cout << sum << '\n';
}