// https://www.acmicpc.net/problem/1238
#include <iostream>
#include <vector>
#include <queue>
#define F first
#define S second
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
vector<pair<int, int> > v[1001];
vector<pair<int, int> > rv[1001];
int d[1001];
int rd[1001];
int N, M, X, a, b, c, mx;
const int INF = 0x3f3f3f3f;

void dj(bool flag) {
	vector<pair<int, int> > *vv;
	int *arr;
	if (flag == 0) {arr = d; vv = v;}
	else {arr = rd; vv = rv;}
	fill(arr, arr + 1 + N, INF);
	arr[X] = 0;
	pq.push({arr[X], X});
	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		if (arr[cur.S] != cur.F) continue;
		for (pair<int, int> nxt : vv[cur.S]) {
			if (arr[nxt.S] <= arr[cur.S] + nxt.F) continue;
			arr[nxt.S] = arr[cur.S] + nxt.F;
			pq.push({arr[nxt.S], nxt.S});
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({c, b});
		rv[b].push_back({c, a});
	}
	dj(1); dj(0);
	for (int i = 1; i <= N; i++) 
		if (mx < rd[i] + d[i]) mx = rd[i] + d[i];
	cout << mx << '\n';
}