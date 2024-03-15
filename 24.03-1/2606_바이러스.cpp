// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[101];
bool vis[101];
int N, M, cnt;

void dfs(int x) {
	for (int i = 0; i < arr[x].size(); i++) {
		if (vis[arr[x][i]]) continue;
		vis[arr[x][i]] = 1;
		cnt++;
		dfs(arr[x][i]);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vis[1] = 1;
	dfs(1);
	cout << cnt << '\n';
}