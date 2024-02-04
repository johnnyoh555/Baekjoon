// https://www.acmicpc.net/problem/4179

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

char board[1001][1001];
int vis[1001][1001];
int fire[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int R, C;
    queue<pair<int, int> > Q;
    queue<pair<int, int> > FQ;
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            board[i][j] = str[j];
            if (str[j] == 'J') {
                Q.push({i,j});
                vis[i][j] = 1;
            }
            if (str[j] == 'F') {
                FQ.push({i, j});
                fire[i][j] = 1;
            }
        }
    }
    
	while (!FQ.empty()) {
        pair<int, int> cur = FQ.front();
        FQ.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.second + dx[dir];
            int ny = cur.first + dy[dir];
            if (nx < 0 || ny < 0 || nx >= C || ny >= R)
                continue;
            if (fire[ny][nx] || board[ny][nx] == '#')
                continue;
            fire[ny][nx] = fire[cur.first][cur.second] + 1;
            FQ.push({ny, nx});
        }
    }   
    
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        if (cur.first == 0 || cur.second == 0 || cur.first == R - 1 || cur.second == C - 1) {
            cout << vis[cur.first][cur.second] << '\n';
            return 0;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.second + dx[dir];
            int ny = cur.first + dy[dir];
            if (nx < 0 || ny < 0 || nx >= C || ny >= R)
                continue;
            if (vis[ny][nx] || board[ny][nx] != '.')
                continue;
            vis[ny][nx] = vis[cur.first][cur.second] + 1;
            if (fire[ny][nx] && vis[ny][nx] >= fire[ny][nx])
                continue;
            Q.push({ny, nx});
        }
    }
    cout << "IMPOSSIBLE\n";
}