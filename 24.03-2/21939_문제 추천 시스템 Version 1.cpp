// https://www.acmicpc.net/problem/21939

#include <iostream>
#include <set>

using namespace std;

set<int>	s[101];
string str;
int N, M, P, L, tmp;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		s[L].insert(P);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (str == "add") {
			cin >> P >> L;
			s[L].insert(P);
		}	else if (str == "solved") {
			cin >> P;
			for (int j = 1; j <= 100; j++) {
				auto it = s[j].find(P);
				if (it != s[j].end()) {
					s[j].erase(P);
					break;
				}
			}
		}	else if (str == "recommend") {
			cin >> tmp;
			if (tmp == -1) {
				for(int j = 1; j <= 100; j++) {
					if (s[j].size()) {
						cout << *s[j].begin() << '\n';
						break;
					}
				}
			} else {
				for(int j = 100; j >= 1; j--) {
					if (s[j].size()) {
						cout << *prev(s[j].end()) << '\n';
						break;
					}
				}
			}
		}
	}
}