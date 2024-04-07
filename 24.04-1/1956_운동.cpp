// https://www.acmicpc.net/problem/1956
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int arr[401][401];
int n, m, a, b, c, mx = INF;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) fill(arr[i], arr[i] + 1 + n, INF);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (arr[a][b] > c) arr[a][b] = c;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				if(arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
	for (int i = 1; i <= n; i++)
		if (mx > arr[i][i]) mx = arr[i][i];
	if (mx == INF) mx = -1;
	cout << mx << '\n';
}