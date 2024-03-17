// https://www.acmicpc.net/problem/1707

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int t, N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N >> M;
		int vis[20001] = {0, };
		vector<int> v[N];
		queue<int> Q;
		for (int j = 0; j < M; j++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		bool flag = 0;
		for (int j = 1; j <= N; j++) {
			if (vis[j]) continue;
			Q.push(j);
			while (!Q.empty()) {
				
				
			}
		}
	}
}