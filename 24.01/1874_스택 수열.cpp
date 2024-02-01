// https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string	str;
	int n;
	int tmp;
	stack<int>	sk;
	cin >> n;
	int idx = 1;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		while (true) {
			if (!sk.empty() && sk.top() == tmp) {
				sk.pop();
				str += '-';
				break ;
			}
			if (sk.empty() || idx <= tmp) {
				sk.push(idx);
				str += '+';
				idx++;
			} else if (idx > tmp) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << '\n';
	}
}