// https://www.acmicpc.net/problem/10942

#include <iostream>

using namespace std;

int board[2001];
bool d[2001][2001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, S, E;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> board[i];
		d[i][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = i - 1; j >= 1; j--) {
				if (board[j] != board[i]) continue ;
				if (j == i - 1 || d[i - 1][j + 1] == 1)
					d[i][j] = 1; 
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		cout << d[E][S] << '\n';
	}
}