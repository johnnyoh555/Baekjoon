// https://www.acmicpc.net/problem/14889

#include <iostream>
#include <cmath>

using namespace std;

int arr[22][22];
int N, total, mn;
bool b[22];

void check() {
	int sum = 0;
	int sum2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (b[i] && b[j]) {
				sum += arr[i][j];
				sum += arr[j][i];
			}
			if (!b[i] && !b[j]) {
				sum2 += arr[i][j];
				sum2 += arr[j][i];
			}
		}
	}
	mn = min(mn, abs(sum - sum2));
}

void dfs(int num, int idx) {
	if (idx == N / 2) {
		check();
		return;
	}
	for (int i = num; i < N; i++) {
		b[i] = 1;
		dfs(i + 1, idx + 1);
		b[i] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	mn = 2e9+1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	b[0] = 1;
	dfs(1, 1);
	cout << mn << '\n';
}