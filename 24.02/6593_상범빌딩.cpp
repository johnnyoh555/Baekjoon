// https://www.acmicpc.net/problem/6593

#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;


int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		char board[31][31][31] = {0, };
		int vis[31][31][31] = {0, };
		int L, R, C;
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			return 0;
		queue<tuple<int, int, int> > Q;
		tuple<int, int, int>	end;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string str;
				cin >> str;
				for (int k = 0; k < C; k++) {
					board[i][j][k] = str[k];
					if (str[k] == 'S') {
						Q.push({i, j, k});
						vis[i][j][k] = 1;
					}
					if (str[k] == 'E')
						end = {i, j , k};
				}
			}
		}
		int flag = 0;
		while (!Q.empty()) {
			if (Q.front() == end) {
				flag = 1;
				break;
			}
			tuple<int, int, int> cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int nx = get<2>(cur) + dx[dir];
				int ny = get<1>(cur) + dy[dir];
				int nz = get<0>(cur) + dz[dir];
				if (nx < 0 || ny < 0 || nz < 0 || nx >= C || ny >= R || nz >= L)
					continue ;
				if (vis[nz][ny][nx] || board[nz][ny][nx] == '#')
					continue ;
				vis[nz][ny][nx] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				Q.push({nz, ny, nx});
			}
		}
		if (flag)
			cout << "Escaped in " << vis[get<0>(end)][get<1>(end)][get<2>(end)] - 1 << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}
}