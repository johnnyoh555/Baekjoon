// https://www.acmicpc.net/problem/2504

#include <iostream>
#include <stack>
#include <cmath>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string			str;
	std::stack<char>	sk;
	int					cnt_s = 0;
	int					cnt_b = 0;
	int sum = 0;
	int	flag = 0;
	int add_flag = 0;

	std::cin >> str;


	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			sk.push(str[i]);
			cnt_s++;
			add_flag = 1;
		}
		else if (str[i] == '[') {
			sk.push(str[i]);
			cnt_b++;
			add_flag = 1;
		}
		else if (str[i] == ')') {
			if (sk.empty() || sk.top() != '(') {
				flag = 1;
				break ;
			}
			sk.pop();
			cnt_s--;
			if (add_flag)
				sum += pow(2, cnt_s) * pow(3, cnt_b) * 2;
			add_flag = 0;
		}
		else if (str[i] == ']') {
			if (sk.empty() || sk.top() != '[') {
				flag = 1;
				break ;
			}
			sk.pop();
			cnt_b--;
			if (add_flag)
				sum += pow(2, cnt_s) * pow(3, cnt_b) * 3;
			add_flag = 0;
		}
	}
	if (!sk.empty())
		flag = 1;
	if (flag)
		sum = 0;
	std::cout << sum << '\n';
	return 0;
}