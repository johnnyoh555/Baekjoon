// https://www.acmicpc.net/problem/4949

#include <iostream>
#include <string>
#include <stack>

int	main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	while (1) {
		std::stack<int>	st;
		std::string		str;
		std::getline(std::cin, str);
		int	flag = 0;
		if (str[0] == '.')
			break ;
		for (int i = 0; i < (int)str.size(); i++) {
			if (str[i] == '(' || str[i] == '[')
				st.push(str[i]);
			else if (str[i] == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else {
					flag = 1;
					break ;
				}
			}
			else if (str[i] == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else {
					flag = 1;
					break ;
				}
			}
		}
		if (st.size())
			flag = 1;
		if (flag == 1)
			std::cout << "no" << '\n';
		else
			std::cout << "yes" << '\n';
	}
	return 0;
}