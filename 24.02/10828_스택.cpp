// https://www.acmicpc.net/problem/10828

#include <iostream>
#include <stack>

using namespace std;
int N;
stack<int> s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int tmp;
			cin >> tmp;
			s.push(tmp);
		} else if (str == "pop") {
			if (s.empty()) {
				cout << "-1\n";
			} else {
				cout << s.top() << '\n';
				s.pop();
			}
		} else if (str == "size") {
			cout << s.size() << '\n';
		} else if (str == "empty") {
			cout << s.empty() << '\n';
		} else if (str == "top") {
			if (s.empty()) {
				cout << "-1\n";
			} else {
				cout << s.top() << '\n';
			}
		}
	}
}