// https://www.acmicpc.net/problem/15651

#include <iostream>

using namespace std;

int arr[9];
int N, M;

void dfs(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
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

	cin >> N >> M;
	dfs(0);
}