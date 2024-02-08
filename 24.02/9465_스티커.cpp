// https://www.acmicpc.net/problem/9465

#include <iostream>
#include <algorithm>

using namespace std;

int d[100001][2] = {0,};
int vis[100001][2] = {0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> d[k][j];
			}
		}
		vis[1][0] = d[1][0];
		vis[1][1] = d[1][1];
		vis[2][0] = d[2][0] + d[1][1];
		vis[2][1] = d[2][1] + d[1][0];
		for (int j = 3; j <= n; j++) {
			vis[j][0] = d[j][0] + max(vis[j - 1][1], vis[j - 2][1]);
			vis[j][1] = d[j][1] + max(vis[j - 1][0], vis[j - 2][0]);
		}
		cout << max(vis[n][0], vis[n][1]) << '\n';
	}
}