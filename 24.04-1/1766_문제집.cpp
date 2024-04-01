// https://www.acmicpc.net/problem/1766

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v[32001];
int id[32001];
int N, M, a, b;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b); id[b]++;
	}
	for (int i = 1; i <= N; i++) if (!id[i]) pq.push(i);
	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		cout << cur << ' ';
		for (int idx : v[cur]) {
			id[idx]--;
			if (!id[idx]) pq.push(idx);
		}
	}
}