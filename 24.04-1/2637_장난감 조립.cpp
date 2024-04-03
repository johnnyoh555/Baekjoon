// https://www.acmicpc.net/problem/2637

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int> > v[101];
queue<pair<int, int> > q;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > ans;
int id[101];
int d[101];
int N, M, x, y, k;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> k;
		id[y]++; v[x].push_back({y, k});
	}
	q.push({N, 1});
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		if (!v[cur.first].size()) ans.push(cur);
		for (pair<int, int> nxt : v[cur.first]) {
			id[nxt.first]--;
			d[nxt.first] += cur.second * nxt.second;
			if (!id[nxt.first]) q.push({nxt.first, d[nxt.first]});
		}
	}
	while (!ans.empty()) {
		cout << ans.top().first << ' ' << ans.top().second << '\n';
		ans.pop();
	}
}