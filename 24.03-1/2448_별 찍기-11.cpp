// https://www.acmicpc.net/problem/2448

#include <iostream>

using namespace std;

bool arr[3073][6146];
int N;

void	ft(int y, int x, int s) {
	if (s == 3) {
		arr[y][x] = 1;
		arr[y + 1][x + 1] = 1;
		arr[y + 1][x - 1] = 1;
		arr[y + 2][x] = 1;
		arr[y + 2][x - 1] = 1;
		arr[y + 2][x - 2] = 1;
		arr[y + 2][x + 1] = 1;
		arr[y + 2][x + 2] = 1;
		return ;
	} else {
		int tmp = s / 2;
		ft(y, x, tmp);
		ft(y + tmp, x - tmp, tmp);
		ft(y + tmp, x + tmp, tmp);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	ft(0, N, N);
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N * 2; j++) {
			if (arr[i][j]) cout << '*';
			else cout << ' ';
		}
		cout << '\n';
	}
}