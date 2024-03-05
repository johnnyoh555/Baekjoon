// https://www.acmicpc.net/problem/1992

#include <iostream>

using namespace std;

bool arr[64][64];
int N;
string str;

void	ft(int y, int x, int s) {
	bool tmp = arr[y][x];
	int r = s / 2;
	for (int i = y; i < y + s; i++) {
		for (int j = x; j < x + s; j++) {
			if (arr[i][j] != tmp) {
				str += '(';
				ft(y, x, r);
				ft(y, x + r, r);
				ft(y + r, x, r);
				ft(y + r, x + r, r);
				str += ')';
				return ;
			}
		}
	}
	if (tmp == 0) str += '0';
	else str += '1';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			arr[i][j] = tmp[j] - '0';
		}
	}
	ft(0, 0, N);
	cout << str << '\n';
}