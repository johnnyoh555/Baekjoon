// https://www.acmicpc.net/problem/2461
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[1000]; 
int N, M, p[1000], ans, mx;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp; cin >> tmp;
			v[i].push_back(tmp);
		}
		sort(v[i].begin(), v[i].end());
		pq.push({v[i][0], i});
		if (v[i][0] > mx) mx = v[i][0];
	}
	ans = mx - pq.top().first;
	while (true) {
		int a = pq.top().second; pq.pop();
		p[a]++;
		if (p[a] == M) break; 
		pq.push({v[a][p[a]], a});
		if (v[a][p[a]] > mx) mx = v[a][p[a]];
		if (ans > mx - pq.top().first) ans = mx - pq.top().first;
	}
	cout << ans << '\n';
}