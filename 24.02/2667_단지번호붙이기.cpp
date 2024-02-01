// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[26][26];
int vis[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	queue<pair<int, int> >	Q;
	vector<int>				V;

	for (int i = 0; i < N; i++) {
		std::string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			board[i][j] = str[j] - '0';
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] || board[i][j] != 1)
				continue ;
			cnt++;
			int size = 1;
			vis[i][j] = cnt;
			Q.push(make_pair(i, j));
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.second + dx[dir];
					int ny = cur.first + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;
					if (vis[ny][nx] || board[ny][nx] != 1)
						continue;
					vis[ny][nx] = cnt;
					size++;
					Q.push(make_pair(ny, nx));
				}
			}
			V.push_back(size);
		}
	}
	sort(V.begin(), V.end());
	cout << cnt << '\n';
	for (int i = 0; i < V.size(); i++) {
		cout << V[i] << '\n';
	}
}