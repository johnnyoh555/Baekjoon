// https://www.acmicpc.net/problem/2623

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
queue<int> ans;
vector<int> v[1001];
int id[1001];
int N, M, a, b, pd;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> pd;
		for (int j = 0; j < pd; j++) {
			cin >> b;
			if (j > 0) {v[a].push_back(b); id[b]++;}
			a = b;
		}
	}
	for (int i = 1; i <= N; i++) if (id[i] == 0) q.push(i);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		ans.push(cur);
		for (int idx : v[cur]) {
			id[idx]--;
			if (id[idx] == 0) q.push(idx);}
	}
	for (int i = 1; i <= N; i++) if (id[i]) {cout << "0\n"; return 0;}
	while (!ans.empty()) {cout << ans.front() << '\n'; ans.pop();} 
}