// https://www.acmicpc.net/problem/11780
#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int arr[101][101];
vector<int> v[101][101];
int n, m, a, b, c;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) fill(arr[i], arr[i] + 1 + n, INF);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (arr[a][b] > c) {
			arr[a][b] = c;
			v[a][b] = {a, b};
		}
	}
	for (int i = 1; i <= n; i++) arr[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
					v[i][j] = v[i][k];
					for (int o = 1; o < v[k][j].size(); o++) v[i][j].push_back(v[k][j][o]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF) cout << "0 ";
			else cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << v[i][j].size();
			for (int k = 0; k < v[i][j].size(); k++)
				cout << ' ' << v[i][j][k];
			cout << '\n';
		}
	}
}