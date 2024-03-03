// https://www.acmicpc.net/problem/1941

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

char arr[6][6];
bool mask[25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int cnt;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	
	fill(mask + 7, mask + 25, true);
	do {
		queue<pair<int, int>> q;
    int s_cnt = 0, adj = 0;
    bool isp7[5][5] = {}, vis[5][5] = {};
    for (int i = 0; i < 25; i++)
      if (!mask[i]) {
        int x = i / 5, y = i % 5;
        isp7[x][y] = true;
        if (q.empty()) {
          q.push({x, y});
          vis[x][y] = true;
        }
      }
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      adj++;
      s_cnt += arr[cur.first][cur.second] == 'S';
      for (int k = 0; k < 4; k++) {
        int nx = cur.first + dx[k], ny = cur.second + dy[k];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !isp7[nx][ny])
          continue;
        q.push({nx, ny});
        vis[nx][ny] = true;
      }
    }
    cnt += (adj >= 7 && s_cnt >= 4);

  } while (next_permutation(mask, mask + 25));
  cout << cnt << '\n';
}