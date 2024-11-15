// https://www.acmicpc.net/problem/16928
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, ladder[101], snake[101];
bool vis[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a; cin >> a >> ladder[a];
	}
	for (int i = 0; i < M; i++) {
		int a; cin >> a >> snake[a];
	}
	queue<pair<int, int>> q;
	q.push({1, 0});
	vis[1] = 1;
	while (!q.empty()) {
		auto [idx, cnt] = q.front(); q.pop();
		if (idx == 100) {cout << cnt << '\n'; return 0;}
		for (int i = 1; i <= 6; i++) {
			int tmp = idx + i;
			if (tmp > 100) continue;
			if (vis[tmp]) continue;
			vis[tmp] = 1;
			if (snake[tmp]) {tmp = snake[tmp]; vis[tmp] = 1;}
			if (ladder[tmp]) {tmp = ladder[tmp]; vis[tmp] = 1;}
			q.push({tmp, cnt + 1});
		}
	}
}