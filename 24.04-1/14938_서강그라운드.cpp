// https://www.acmicpc.net/problem/14938
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int arr[101][101];
int t[101];
int n, m, r, a, b, c, ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		fill(arr[i], arr[i] + n + 1, INF);
		arr[i][i] = 0;
		cin >> t[i];
	}
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> c;
		if (arr[a][b] > c) {arr[a][b] = c; arr[b][a] = c;}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++)
			if (arr[i][j] <= m) tmp += t[j];
		if (ans < tmp) ans = tmp;
	}
	cout << ans << '\n';
}