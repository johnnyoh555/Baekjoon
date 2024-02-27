// https://www.acmicpc.net/workbook/view/15663

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr(8);
int save[10001];
int d[9];
int N, M;

void dfs(int s) {
	if (s == M) {
		for (int i = 0; i < M; i++ ) {
			cout << d[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (!save[arr[i]]) continue;
		save[arr[i]]--;
		d[s] = arr[i];
		dfs(s + 1);
		save[arr[i]]++;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		save[arr[i]]++;
	}
	sort(arr.begin(), arr.begin() + N);
	arr.erase(unique(arr.begin(), arr.begin() + N), arr.end());
	dfs(0);
}