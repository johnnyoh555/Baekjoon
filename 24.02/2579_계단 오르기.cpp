// https://www.acmicpc.net/problem/2579

#include <iostream>

unsigned int vis[301][2];
unsigned int d[301];

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];;
	}
	if (n == 1) {
		cout << d[1] << '\n';
		return 0;
	}
	vis[1][0] = d[1];
	vis[1][1] = d[1];
	vis[2][0] = d[2];
	vis[2][1] = d[1] + d[2];
	for (int i = 3; i <= n; i++) {
		vis[i][1] = d[i] + vis[i - 1][0];
		vis[i][0] = d[i] + max(vis[i - 2][0], vis[i - 2][1]);
	}
	cout << max(vis[n][1], vis[n][0]) << '\n';
}