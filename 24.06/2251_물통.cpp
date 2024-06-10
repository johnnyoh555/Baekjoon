// https://www.acmicpc.net/problem/2251
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;
int A, B, C;
queue<tuple<int, int, int> > q;
vector<int> v;
bool vis[201][201][201];

int main(void) {
	ios::sync_with_stdio(0);

	cin >> A >> B >> C;
	q.push({0, 0, C});
	while (!q.empty()) {
		int a, b, c; tie(a, b, c) = q.front(); q.pop();
		if (vis[a][b][c]) continue;
		vis[a][b][c] = 1;
		if (a == 0) v.push_back(c);

		int x = min(a, B - b); q.push({a - x, b + x, c});
		x = min(a, C - c); q.push({a - x, b, c + x});
		x = min(b, A - a); q.push({a + x, b - x, c});
		x = min(b, C - c); q.push({a, b - x, c + x});
		x = min(c, A - a); q.push({a + x, b, c - x});
		x = min(c, B - b); q.push({a, b + x, c - x});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	cout << '\n';
}