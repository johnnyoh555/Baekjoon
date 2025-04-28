// https://www.acmicpc.net/problem/28069
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, K;
bool ans, vis[1000001];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	q.push({0, 0});
	while (!q.empty()) {
		auto [a, b] = q.front(); q.pop();
		if (a == N) break;
		if (b >= K) continue;
		if (!vis[a + 1]) {
			vis[a + 1] = 1;
			q.push({a + 1, b + 1});
		}
		int tmp = a + a / 2;
		if (tmp <= 1000000 && !vis[tmp]) {
			vis[tmp] = 1;
			q.push({tmp, b + 1});
		}
	}
	cout << (vis[N] ? "minigimbob" : "water") << '\n';
}