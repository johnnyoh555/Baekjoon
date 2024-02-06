// https://www.acmicpc.net/problem/1463

#include <iostream>

int board[1000001];

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int X;
	cin >> X;
	board[1] = 0;
	for(int i = 2; i <= X; i++) {
		board[i] = board[i - 1] + 1;
		if (i % 2 == 0) board[i] = min(board[i], board[i/2] + 1);
		if (i % 3 == 0) board[i] = min(board[i], board[i/3] + 1);
	}
	cout << board[X];
}
