// https://www.acmicpc.net/problem/11660

#include <iostream>

using namespace std;

int arr[1030][1030];
int d[1030][1030];
int N, M, sx, sy, ex, ey;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			d[i][j] += d[i - 1][j] + d[i][j - 1] + arr[i][j] - d[i - 1][j - 1];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> sy >> sx >> ey >> ex;
		cout << d[ey][ex] + d[sy - 1][sx - 1] - d[ey][sx - 1] - d[sy - 1][ex] << '\n';
	}
}