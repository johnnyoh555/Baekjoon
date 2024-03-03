// https://www.acmicpc.net/problem/9375

#include <iostream>
#include <map>

using namespace std;

int T, n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		map<string, int> m;
		for (int j = 0; j < n; j++) {
			string c;
			string type;
			cin >> c >> type;
			if (m.find(type) != m.end()) {
				m[type]++;
			} else {
				m.insert({type, 1});
			}
		}
		int cnt = 1;
		for (auto j = m.begin(); j != m.end(); j++) {
			cnt *= (j->second + 1);
		}
		cout << cnt - 1 << '\n';
	}
}