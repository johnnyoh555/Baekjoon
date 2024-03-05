// https://www.acmicpc.net/problem/2630

#include <iostream>
#include <cmath>

using namespace std;

bool arr[128][128];
int N, w_cnt, b_cnt;

void ft(int y, int x, int s) {
	bool tmp = arr[y][x];
	for (int i = y; i < y + s; i++) {
		for (int j = x; j < x + s; j++) {
			if (arr[i][j] != tmp) {
				ft(y, x, s / 2);
				ft(y + s / 2, x, s / 2);
				ft(y, x + s / 2, s / 2);
				ft(y + s / 2, x + s / 2, s / 2);
				return ;
			}
		}
	}
	if (tmp == 1) b_cnt++;
	else w_cnt++;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	ft(0, 0, N);
	cout << w_cnt << '\n' << b_cnt << '\n';
}