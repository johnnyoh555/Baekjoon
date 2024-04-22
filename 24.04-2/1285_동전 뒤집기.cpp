// https://www.acmicpc.net/problem/1285
#include <iostream>
using namespace std;
int N, arr[21][21], mn = 2e9;

void	check() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++)
			if (arr[i][j]) cnt++;
		if (cnt > N - cnt) cnt = N - cnt;
		sum += cnt;
	}
	if (sum < mn) mn = sum;
}

void	dfs(int dep) {
	if (dep == N) {check(); return;}
	dfs(dep + 1);
	for (int i = 0; i < N; i++)
		arr[i][dep] = arr[i][dep] ? 0 : 1;
	dfs(dep + 1);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		for (int j = 0; j < N; j++)
			if (str[j] == 'T') arr[i][j] = 1;
	}
	dfs(0);
	cout << mn << '\n';
}