// https://www.acmicpc.net/problem/2982
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, A, B, K, G, gon[1001], d[1001];
vector<pair<int, int>> v[1001], way;
vector<int> sum;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cin >> A >> B >> K >> G;
	for (int i = 0; i < G; i++) cin >> gon[i];
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	for (int i = 1; i < G; i++) {
		for (auto nxt : v[gon[i - 1]]) {
			if (nxt.first != gon[i]) continue;
			sum.push_back({(sum.size() ? sum[i - 2] : -1) + nxt.second});
			way.push_back({gon[i], gon[i - 1]});
		}
	}
	fill(d, d + 1001, 1e9);
	d[A] = K;
	pq.push({K, A});
	while (!pq.empty()) {
		auto [c, x] = pq.top(); pq.pop();
		if (d[x] != c) continue;
		for (auto nxt : v[x]) {
			int idx = lower_bound(sum.begin(), sum.end(), c) - sum.begin();
			int tmp = 0;
			if (idx < G && ((nxt.first == way[idx].first && x == way[idx].second) || (nxt.first == way[idx].second && x == way[idx].first))) {
				tmp = sum[idx] - c + 1;
			}
			if (d[nxt.first] <= c + tmp + nxt.second) continue;
			d[nxt.first] = c + tmp + nxt.second;
			pq.push({d[nxt.first], nxt.first});
		}
	}
	cout << d[B] - K << '\n';
}
