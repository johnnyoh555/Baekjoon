// https://www.acmicpc.net/problem/1620

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m_s;
unordered_map<int, string> m_i;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		m_s.insert({tmp, i});
		m_i.insert({i, tmp});
	}
	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		int a;
		a = atoi(tmp.c_str());
		if (a > 0) {
			cout << m_i.at(a) << '\n';
		} else {
			cout << m_s.at(tmp) << '\n';
		}
	}
}