// https://www.acmicpc.net/problem/15652

#include <iostream>

using namespace std;

int arr[9];
int N, M;

void dfs(int idx, int s) {
	if (s == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return ;		
	}
	for (int i = idx; i <= N; i++) {
		arr[s] = i;
		dfs(i, s + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	dfs(1, 0);
}