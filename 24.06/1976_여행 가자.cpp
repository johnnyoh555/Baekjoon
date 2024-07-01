// https://www.acmicpc.net/problem/1976
#include <iostream>
using namespace std;
int map[200][200], N, T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (map[i][k] == 1 && map[k][j] == 1) map[i][j] = 1;
	int a, b;
	cin >> a;
	for (int i = 0; i < T - 1; i++) {
		cin >> b;
		if (a != b && !map[a - 1][b - 1]) {
			cout << "NO\n";
			return 0;
		}
		a = b;
	}
	cout << "YES\n";
}