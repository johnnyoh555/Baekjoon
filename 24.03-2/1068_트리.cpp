// https://www.acmicpc.net/problem/1068

#include <iostream>
#include <vector>

using namespace std;

vector<int> v[51];
int N, M, root, cnt;

void dfs(int x) {
	int flag = 0;
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i] == M) continue;
		flag++;
		dfs(v[x][i]);
	}
	if (!flag) cnt++;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == -1) root = i;
		else v[tmp].push_back(i);
	}
	cin >> M;
	if (M != root) dfs(root);
	cout << cnt << '\n';
}