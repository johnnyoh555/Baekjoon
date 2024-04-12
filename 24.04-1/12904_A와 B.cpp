// https://www.acmicpc.net/problem/12904
#include <iostream>
#include <algorithm>
using namespace std;
string s, t;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;
	while (t.size() > s.size()) {
		bool flag = 0;
		if (t[t.size() - 1] == 'B') flag = 1;
		t.erase(t.size() - 1);
		if (flag) reverse(t.begin(), t.end());
	}
	cout << (t == s) << '\n';
}