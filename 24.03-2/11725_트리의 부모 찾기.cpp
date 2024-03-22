// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr[100001];
int p[100001];

void	dfs(int x) {
	for (int i = 0; i < arr[x].size(); i++) {
		if (p[arr[x][i]]) continue;
		p[arr[x][i]] = x;
		dfs(arr[x][i]);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	p[1] = 1;
	dfs(1);
	for (int i = 2; i <= N; i++) cout << p[i] << '\n';
}