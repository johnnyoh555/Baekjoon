// https://www.acmicpc.net/problem/9019
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		bool vis[10001] = {0};
		int a, b; cin >> a >> b;
		vis[a] = 1;
		queue<pair<int, string> > q;
		q.push({a, ""});
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			if (cur.first == b) {
				cout << cur.second << '\n';
				break;
			}
			if (!vis[(cur.first * 2) % 10000]) {
				vis[(cur.first * 2) % 10000] = 1;
				q.push({(cur.first * 2) % 10000, cur.second + "D"});
			}
			if (!vis[(cur.first + 9999) % 10000]) {
				vis[(cur.first + 9999) % 10000] = 1;
				q.push({(cur.first + 9999) % 10000, cur.second + "S"});
			}
			if (!cur.first) continue;
			int c = 1000;
			int d = cur.first / c;
			int tmp = (cur.first % c) * 10 + d;
			if (!vis[tmp]) {
				vis[tmp] = 1;
				q.push({tmp, cur.second + "L"});
			}
			d = cur.first % 10;
			tmp = (cur.first / 10) + d * c;
			if (!vis[tmp]) {
				vis[tmp] = 1;
				q.push({tmp, cur.second + "R"});
			}
		}
	}
}