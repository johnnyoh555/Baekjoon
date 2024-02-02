// https://www.acmicpc.net/problem/1600

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[201][201];
bool vis[31][201][201];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int kx[8] = {-2, -1, -2, -1, 1, 2, 1, 2};
int ky[8] = {-1, -2, 1, 2, -2, -1, 2, 1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K, W, H;
	cin >> K >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}

	queue<vector<int>> Q;
	vis[0][0][0] = 1;
	Q.push({0, 0, 0});
	while (!Q.empty()) {
		vector<int> cur = Q.front();
		Q.pop();
		if (cur[0] == H -1 && cur[1] == W -1) {
			std::cout << cur[3] << '\n';
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur[1] + dx[dir];
			int ny = cur[0] + dy[dir];
			if (nx < 0 || ny < 0 || nx >= W || ny >= H)
				continue ;
			if (vis[cur[2]][ny][nx] || board[ny][nx])
				continue ;
			vis[cur[2]][ny][nx] = 1;
			Q.push({ny, nx, cur[2], cur[3] + 1});
		}
		if (cur[2] == K)
			continue ;
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur[1] + kx[dir];
			int ny = cur[0] + ky[dir];
			if (nx < 0 || ny < 0 || nx >= W || ny >= H)
				continue ;
			if (vis[cur[2] + 1][ny][nx] || board[ny][nx])
				continue ;
			vis[cur[2] + 1][ny][nx] = 1;
			Q.push({ny, nx, cur[2] + 1, cur[3] + 1});
		}
	}
	std::cout << "-1\n";
}
