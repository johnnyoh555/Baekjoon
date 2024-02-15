// https://www.acmicpc.net/problem/1780

#include <iostream>

using namespace std;

short d[2188][2188];

int p, m, z;

void func(int y, int x, int N) {
	short f = d[y][x];
	for (int i = y; i < y + N; i++) {
		for (int j = x; j < x + N; j++) {
			if (d[i][j] != f) {
				for (int k = y; k < y + N; k += N / 3) {
					for (int l = x; l < x + N; l += N / 3) {
						func(k, l, N / 3);
					}
				}
				return ;
			}
		}
	}
	if (f == 0) z++;
	else if (f == 1) p++;
	else m++;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	short N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> d[i][j];
		}
	}
	func(0, 0, N);
	cout << m << '\n';
	cout << z << '\n';
	cout << p << '\n';
}