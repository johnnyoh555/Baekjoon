// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int arr[22][22];
int N, s, cnt, t;
bool vis[22][22];

struct info {
	int y;
	int x;
	int len;
};

struct compare {
	bool operator()(info a, info b) {
		if (a.len == b.len) {
			if (a.y == b.y) return a.x > b.x;
			return a.y > b.y;
		}
		return a.len > b.len;
	}
};

priority_queue<info, vector<info>, compare> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	s = 2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				vis[i][j] = 1;
				Q.push({i, j, 0});
				arr[i][j] = 0;
			}
		}
	}
	while (!Q.empty()) {
		info cur = Q.top();
		Q.pop();
		if (0 < arr[cur.y][cur.x] && arr[cur.y][cur.x] < s) {
			while (!Q.empty()) Q.pop();
			cnt++;
			if (cnt == s) {
					s++;
					cnt = 0;
			}
			t = cur.len;
			memset(vis, 0, sizeof(vis));
			vis[cur.y][cur.x] = 1;
			arr[cur.y][cur.x] = 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (vis[ny][nx] || arr[ny][nx] > s) continue;
			vis[ny][nx] = 1;
			Q.push({ny, nx, cur.len + 1});
		}
	}
	cout << t << '\n';
}