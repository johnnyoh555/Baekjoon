// https://www.acmicpc.net/problem/11403

#include <iostream>

using namespace std;

bool arr[101][101];
bool vis[101][101];

int N;

void dfs(int s, int idx) {
	for (int i = 1; i <= N; i++) {
		if (arr[idx][i] && !vis[s][i]) {
			vis[s][i] = 1;
			dfs(s, i);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> arr[i][j];
	}
	for (int i = 1; i <= N; i++) dfs(i, i);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cout << vis[i][j] << ' ';
		cout << '\n';
	}
}