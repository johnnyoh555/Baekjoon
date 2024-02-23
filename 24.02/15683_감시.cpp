// https://www.acmicpc.net/problem/15683

#include <iostream>
#include <vector>

using namespace std;

int arr[10][10];
int N, M, mn;
vector<pair<int, int> > v;

void look(int idx, int i, int c) {
	int a;
	int x = v[idx].second;
	int y = v[idx].first;
	if (i == 0) {
		while (--y >= 1) {
			if (arr[y][x] == 6) return ;
			if (arr[y][x] <= 0) arr[y][x] += c;
		}
	} else if (i == 1) {
		while (++x <= M) {
			if (arr[y][x] == 6) return ;
			if (arr[y][x] <= 0) arr[y][x] += c;
		}
	} else if (i == 2) {
		while (++y <= N) {
			if (arr[y][x] == 6) return ;
			if (arr[y][x] <= 0) arr[y][x] += c;
		}
	} else if (i == 3) {
		while (--x >= 1) {
			if (arr[y][x] == 6) return ;
			if (arr[y][x] <= 0) arr[y][x] += c;
		}
	}
}

void ft_s(int idx, int i, int c) {
	switch (arr[v[idx].first][v[idx].second]) {
		case 1:
			look(idx, i % 4, c);
			break;
		case 2:
			look(idx, i % 4, c);
			look(idx, (i + 2) % 4, c);
			break;
		case 3:
			look(idx, i % 4, c);
			look(idx, (i + 1) % 4, c);
			break;
		case 4:
			look(idx, i % 4, c);
			look(idx, (i + 1) % 4, c);
			look(idx, (i + 2) % 4, c);
			break;
		case 5:
			look(idx, i % 4, c);
			look(idx, (i + 1) % 4, c);
			look(idx, (i + 2) % 4, c);
			look(idx, (i + 3) % 4, c);
			break;
	};
}

void check() {
	int a = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) a++;
		}
	}
	if (a < mn) mn = a;
}

void dfs(int idx) {
	if (idx == v.size()) {
		check();
		return;
	}
	for (int i = 0; i < 4; i++) {
		ft_s(idx, i, -1);
		dfs(idx + 1);
		ft_s(idx, i, +1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	mn = 2e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] && arr[i][j] != 6) v.push_back({i, j});
		}
	}
	dfs(0);
	cout << mn << '\n';
}