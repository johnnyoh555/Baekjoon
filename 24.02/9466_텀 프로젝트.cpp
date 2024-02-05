// https://www.acmicpc.net/problem/9466

#include <iostream>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n;
		int board[100001] = {0, };
		int vis[100001] = {0, };
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> board[j];
		}
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j] != 0)
				continue ;
			int tmp = j;
			while (true) {
				vis[tmp] = j;
				tmp = board[tmp];
				if (vis[tmp] == j) {
					while (vis[tmp] != -1) {
						vis[tmp] = -1;
						tmp = board[tmp];
					}
					break ;
				}
				else if (vis[tmp] != 0)
					break ;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (vis[j] != -1)
				cnt++;
		}
		cout << cnt << '\n';
	}
}
