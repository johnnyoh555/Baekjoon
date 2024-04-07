// https://www.acmicpc.net/problem/1507
#include <iostream>
using namespace std;
int arr[21][21], N, ans;
bool w[21][21];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (k == i || k == j) continue;
				if (arr[i][j] == arr[i][k] + arr[k][j]) {w[i][j] = w[j][i] = 1;}
				else if (arr[i][j] > arr[i][k] + arr[k][j]) {cout << "-1\n"; return 0;}
			}
		}
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			if (!w[i][j]) ans += arr[i][j];
	cout << ans << '\n';
}