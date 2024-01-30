// https://www.acmicpc.net/problem/7562

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int	dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		int I;
		pair<int, int> start;
		pair<int, int> end;

		cin >> I >> start.second >> start.first >> end.second >> end.first;

		
		int board[300][300] = {0, };
		int vis[300][300] = {0, };

		queue<pair<int, int> > Q;
	
		Q.push(start);
		while (Q.front() != end) {
			pair<int, int> cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.second + dx[dir];
				int ny = cur.first + dy[dir];
				if (nx < 0 || ny < 0 || nx >= I || ny >= I)
					continue;
				if (vis[ny][nx])
					continue;
				vis[ny][nx] = vis[cur.first][cur.second] + 1;
				Q.push(make_pair(ny, nx));
			}
		}
		cout << vis[end.first][end.second] << '\n';
	}
}