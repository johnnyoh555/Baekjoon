// https://www.acmicpc.net/problem/14500

#include <iostream>
#include <cmath>

using namespace std;

int arr[502][502];
bool vis[502][502];
int N, M, mx;

void check(int i, int j) {
	int a = arr[i - 1][j];
	int b = arr[i + 1][j];
	int c = arr[i][j + 1];
	int d = arr[i][j - 1];
	int sum = arr[i][j] + a + b + c + d - min(min(a,b), min(c,d));
	mx = max(mx, sum);
}

void	dfs(int i, int j, int idx, int sum) {
	if (i <= 0 || i > N || j <= 0 || j > M || vis[i][j]) return ;
	sum += arr[i][j];
	if (idx == 4) {
		if (sum > mx) mx = sum;
		return ;
	}
	vis[i][j] = 1;
	dfs(i - 1, j, idx + 1, sum);
	dfs(i, j - 1, idx + 1, sum);
	dfs(i + 1, j, idx + 1, sum);
	dfs(i, j + 1, idx + 1, sum);
	vis[i][j] = 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			check(i, j);
			dfs(i, j, 1, 0);
		}
	}
	cout << mx << '\n';
}