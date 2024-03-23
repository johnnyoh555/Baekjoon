// https://www.acmicpc.net/problem/7662

#include <iostream>
#include <set>

using namespace std;

int T, k, n;
char c;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		multiset<int>	s;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> c >> n;
			if (c == 'I') {
				s.insert(n);
			} else if (c == 'D' && !s.empty()) {
				if (n == -1) s.erase(s.begin());
				else s.erase(prev(s.end()));
			}
		}
		if (s.empty()) cout << "EMPTY\n";
		else cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
	}
}