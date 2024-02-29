// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <cmath>

using namespace std;
int arr[15];
int N, cnt;

int check(int idx) {
	for (int i = 1; i < idx; i++) {
		if (arr[i] == arr[idx]) return 1;
		if (abs(arr[i] - arr[idx]) == idx - i) return 1;
	}
	return 0;
}

void dfs(int idx) {
	if (check(idx - 1)) return ;
	if (idx == N + 1) {
		cnt++;
		return ;
	}
	for (int i = 1; i <= N; i++) {
		arr[idx] = i;
		dfs(idx + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dfs(1);
	cout << cnt << '\n';
}