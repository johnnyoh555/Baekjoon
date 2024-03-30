// https://www.acmicpc.net/problem/2252

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
vector<int> v[320001];
int id[320001];
int N, M, a, b;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		id[b]++;
		v[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) if (!id[i]) q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int idx : v[cur]) {
			id[idx]--;
			if (id[idx] == 0) q.push(idx);
		}
	}
	cout << '\n';
}