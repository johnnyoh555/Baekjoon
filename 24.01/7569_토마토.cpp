// https://www.acmicpc.net/problem/7569

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int board[101][101][101];
bool vis[101][101][101];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int M, N, H;

	queue<tuple<int, int, int> > Q;
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					Q.push(make_tuple(i, j, k));
			}
		}
	}

	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front();
		Q.pop();			
		for (int dir = 0; dir < 6; dir++) {
			int nx = get<2>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<0>(cur) + dz[dir];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H)
				continue;
			if (vis[nz][ny][nx] || board[nz][ny][nx] != 0)
				continue;
			vis[nz][ny][nx] = 1;
			board[nz][ny][nx] = board[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push(make_tuple(nz, ny, nx));
		}
	}
	
	int max = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (board[i][j][k] == 0) {
					cout << "-1\n";
					return 0;
				}
				if (board[i][j][k] > max)
					max = board[i][j][k];
			}
		}
	}
	if (max == 0)
		cout << "-1\n";
	else
		cout << max - 1 << '\n';
}