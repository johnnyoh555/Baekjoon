// https://www.acmicpc.net/problem/2447

#include <iostream>

using namespace std;

bool s[2188][2188];

void recursion(short x, short y, short N) {
	short tmp = N / 3;
	short tmp2 = tmp * 2;
	for (short i = y + tmp; i < y + tmp2; i++) {
		for (short j = x + tmp; j < x + tmp2; j++) {
			s[i][j] = 1;
		}
	}
	if (N == 3)
		return ;
	recursion(x, y, tmp);
	recursion(x + tmp, y, tmp);
	recursion(x, y + tmp, tmp);
	recursion(x + tmp2, y , tmp);
	recursion(x, y + tmp2, tmp);
	recursion(x + tmp2, y + tmp, tmp);
	recursion(x + tmp, y + tmp2, tmp);
	recursion(x + tmp2, y + tmp2, tmp);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	recursion(1, 1, N);
	for (short i = 1; i <= N; i++) {
		for (short j = 1; j <= N; j++) {
			if (s[i][j])
				cout << ' ';
			else
				cout << '*';
		}
		cout << '\n';
	}
}