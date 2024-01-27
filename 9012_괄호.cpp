// https://www.acmicpc.net/problem/9012

#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int	T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string 		str;
		stack<char> sk;
		int 		flag = 0;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(')
				sk.push('(');
			else if (str[j] == ')') {
				if (sk.empty()) {
					flag = 1;
					break ;
				}
				else
					sk.pop();
			}
		}
		if (!sk.empty())
			flag = 1;
		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}