// https://www.acmicpc.net/problem/5427

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int T;
    cin >> T;
    
	for (int k = 0; k < T; k++) {
    	int w, h;
		cin >> w >> h;
		char	board[1001][1001] = {0, };
		int		vis[1001][1001] = {0, };
		int 	fire[1001][1001] = {0, };

    	queue<pair<int, int> > Q;
   		queue<pair<int, int> > FQ;
    	for (int i = 0; i < h; i++) {
        	string str;
        	cin >> str;
        	for (int j = 0; j < w; j++) {
            	board[i][j] = str[j];
	            if (str[j] == '@') {
	            	Q.push({i, j});
	                vis[i][j] = 1;
	            }
	            if (str[j] == '*') {
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
	            if (nx < 0 || ny < 0 || nx >= w || ny >= h)
	                continue;
	            if (fire[ny][nx] || board[ny][nx] == '#')
	                continue;
	            fire[ny][nx] = fire[cur.first][cur.second] + 1;
	            FQ.push({ny, nx});
	        }
		}   

		int flag = 0;

	    while (!Q.empty()) {
	        pair<int, int> cur = Q.front();
	        Q.pop();
	        if (cur.first == 0 || cur.second == 0 || cur.first == h - 1 || cur.second == w - 1) {
	            cout << vis[cur.first][cur.second] << '\n';
				flag = 1;
				break ;
	        }
	        for (int dir = 0; dir < 4; dir++) {
	            int nx = cur.second + dx[dir];
	            int ny = cur.first + dy[dir];
	            if (nx < 0 || ny < 0 || nx >= w || ny >= h)
	                continue;
	            if (vis[ny][nx] || board[ny][nx] != '.')
	                continue;
	            vis[ny][nx] = vis[cur.first][cur.second] + 1;
	            if (fire[ny][nx] && vis[ny][nx] >= fire[ny][nx])
	                continue;
	            Q.push({ny, nx});
	        }
	    }
		if (flag == 0)
    		cout << "IMPOSSIBLE\n";
	}
}