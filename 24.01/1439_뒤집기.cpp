// https://www.acmicpc.net/problem/1439

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string	str;

	std::cin >> str;
	
	int	t = 0;
	int f = 0;
	int flag = -1;

	for (int i = 0; i < str.length(); i++) {
		if (flag != 0 && str[i] == '0') {
			f++;
			flag = 0;
		}
		else if (flag != 1 && str[i] == '1') {
			t++;
			flag = 1;
		}
	}
	int min = t < f ? t : f;

	std::cout << min << std::endl;
}