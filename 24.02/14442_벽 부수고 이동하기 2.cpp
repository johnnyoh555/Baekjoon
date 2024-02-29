// https://www.acmicpc.net/problem/14442

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int board[11][1001][1001];
int vis[11][1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for(int j = 0; j < M; j++) {
			for (int l = 0; l <= K; l++) {
				board[l][i][j] = str[j] - '0';
			}
		}
	}
	queue<tuple<int, int, int> > Q;
	Q.push({0, 0, 0});
	vis[0][0][0] = 1;
	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front();
		if (get<1>(cur) == N - 1 && get<2>(cur) == M - 1) {
			cout << vis[get<0>(cur)][N - 1][M - 1] << '\n';
			return 0;
		}
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = get<2>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue ;
			if (vis[get<0>(cur)][ny][nx] || board[get<0>(cur)][ny][nx])
				continue ;
			vis[get<0>(cur)][ny][nx] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push({get<0>(cur), ny, nx});
		}
		if (get<0>(cur) == K)
			continue ;
		for (int dir = 0; dir < 4; dir++) {
			int nx = get<2>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue ;
			if (vis[get<0>(cur) + 1][ny][nx] || !board[get<0>(cur) + 1][ny][nx])
				continue ;
			vis[get<0>(cur) + 1][ny][nx] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push({get<0>(cur) + 1, ny, nx});
		}
	}
	cout << "-1\n";
}