// https://www.acmicpc.net/problem/1541

#include <iostream>

using namespace std;

string str;
int num, p, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	bool flag = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			if (flag == 1) p += num;
			else	m += num;
			num = 0;
			if (str[i] == '-') flag = 0;
		} else {
			num *= 10;
			num += str[i] - '0';
		}
	}
	if (flag == 1) p += num;
	else	m += num;
	cout << p - m << '\n';
}