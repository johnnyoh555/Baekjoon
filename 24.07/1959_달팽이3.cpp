// https://www.acmicpc.net/problem/1959
#include <iostream>
#include <cmath>
using namespace std;
long M, N, x, y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	if (M >= N) {
		y = N / 2 + 1;
		if (N % 2 == 0) x = 1 + (N - 1) / 2;
		else x = M - (N - 1) / 2;
	} else {
		x = (M + 1) / 2;
		if (M % 2 == 0) y = 1 + M / 2;
		else y = N - M / 2;
	}
	long tmp = min(M, N) * 2 - 2;
	if (N > M) tmp++;
	cout << tmp << "\n";
	cout << y << ' ' << x << '\n';
}