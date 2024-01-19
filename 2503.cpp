// https://www.acmicpc.net/problem/2503

#include <vector>
#include <iostream>

int cnt;

int check_b(std::string &num, std::string &str, int i) {
	int flag;

	flag = 0;
	if (num[0] == str[1] || num[0] == str[2])
		flag++;
	if (num[1] == str[0] || num[1] == str[2])
		flag++;
	if (num[2] == str[0] || num[2] == str[1])
		flag++;
	if (flag != i)
		return 1;
	return 0;
}

int check_s(std::string &num, std::string &str, int i) {
	int flag;

	flag = 0;
	for (int k = 0; k < 3; k++) {
		if (num[k] == str[k]) {
			flag++;
		}
	}
	if (flag != i)
		return 1;
	return 0;
}

void	check_num(std::string &num, std::vector<std::string> &str, int n) {
	for (int i = 0; i < n; i++) {
		if (check_s(num, str[i], str[i][4] - '0') || check_b(num, str[i], str[i][6] - '0'))
			return ;
	}
	cnt++;
}

int	check_same(std::string &num, int len) {
	if (len == 2) {
		if (num[0] == num[1])
			return 1;
	}
	else {
		if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2])
			return 1;
	}
	return 0;
}

void	algo(std::string &num, int len, std::vector<std::string> &str, int n) {
	if (len > 1)
		if (check_same(num, len))
			return ;
	if (len == 3) {
		check_num(num, str, n);
		return ;
	}
	for (int i = 1; i <= 9; i++) {
		num += std::to_string(i);
		len++;
		algo(num, len, str, n);
		len--;
		num.erase(len, 1);
	}
}

int main(void) {
	int n;

	std::cin >> n;

	std::vector<std::string>	str;
	std::string					tmp;

	std::cin.ignore();
	for (int i = 0; i < n; i++) {
		std::getline(std::cin, tmp);
		str.push_back(tmp);
	}
	std::string num;
	algo(num, 0, str, n);

	std::cout << cnt << std::endl;
}
