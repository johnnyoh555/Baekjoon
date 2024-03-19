// https://www.acmicpc.net/problem/1707

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

short vis[20001];
int K, V, E;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> V >> E;
		bool flag = 0;
		vector<int> arr[V + 1];
		memset(vis, 0, sizeof(short) * (V + 1));
		for (int j = 0; j < E; j++) {
			int a, b;
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		for (int j = 1; j <= V; j++) {
			if (vis[j] != 0) continue;
			queue<int> Q;
			vis[j] = 1;
			Q.push(j);
			while (!Q.empty() && !flag) {
				int cur = Q.front();
				Q.pop();
				for (int l = 0; l < arr[cur].size(); l++) {
					if (vis[arr[cur][l]] != 0) {
						if (vis[arr[cur][l]] != vis[cur] * -1) {
							flag = 1;
							break;
						} else continue;
					} else {
						vis[arr[cur][l]] = vis[cur] * -1;
						Q.push(arr[cur][l]);
					}
				}
			}
			if (flag) break;
		}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
}