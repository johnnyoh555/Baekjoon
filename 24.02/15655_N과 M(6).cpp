// https://www.acmicpc.net/problem/15655

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr(8);
int d[9];
int N, M;

int check(int s) {
	for (int i = 0; i < s; i++) {
		if (d[i] == d[s]) return 1;
	}
	return 0;
}

void dfs(int idx, int s) {
	if (check(s - 1)) return ;
	if (s == M) {
		for (int i = 0; i < M; i++ ) {
			cout << d[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = idx; i < N; i++) {
		d[s] = arr[i];
		dfs(i + 1, s + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr.begin(), arr.begin() + N);
	dfs(0 ,0);
}