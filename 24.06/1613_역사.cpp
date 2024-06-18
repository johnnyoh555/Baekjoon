// https://www.acmicpc.net/problem/1613
#include <iostream>
#include <vector>
using namespace std;
int n, k, s;
int map[401][401];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		map[a][b] = -1;
		map[b][a] = 1;
	}
	for (int l = 1; l <= n; l++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!map[i][j]) {
					if (map[i][l] == 1 && map[l][j] == 1) map[i][j] = 1;
					else if (map[i][l] == -1 && map[l][j] == -1) map[i][j] = -1;
				}
			}
		}
	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b; cin >> a >> b;
		cout << map[a][b] << '\n';		
	}
}