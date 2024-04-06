// https://www.acmicpc.net/problem/11404
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int arr[101][101];
int n, m, a, b, c;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) fill(arr[i], arr[i] + 1 + n, INF);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (arr[a][b] > c) arr[a][b] = c;
	}
	for (int i = 1; i <= n; i++) arr[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				if(arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF) cout << "0 ";
			else cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}