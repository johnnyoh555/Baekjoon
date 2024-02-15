// https://www.acmicpc.net/problem/1074

#include <iostream>
#include <cmath>

using namespace std;

unsigned int cnt;
int N, r, c;

void func(int y, int x, int tmp) {
	if (tmp == 0) {
		if (y == r && x == c) {
			cout << cnt << '\n';
			return ;
		}
	}
	if (y <= r && y + tmp > r && x <= c && x + tmp > c)
		func(y, x, tmp / 2);
	else
		cnt += tmp * tmp;
	if (y <= r && y + tmp > r && x + tmp <= c && x + tmp * 2 > c)
		func(y, x + tmp, tmp / 2);
	else
		cnt += tmp * tmp;
	if (y + tmp <= r && y + tmp * 2 > r && x <= c && x + tmp > c)
		func(y + tmp, x, tmp / 2);
	else
		cnt += tmp * tmp;
	if (y + tmp <= r && y + tmp * 2 > r && x + tmp <= c && x + tmp * 2 > c)
		func(y + tmp, x + tmp, tmp / 2);
	else
		cnt += tmp * tmp;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> r >> c;
	func(0, 0, pow(2, N - 1));
}