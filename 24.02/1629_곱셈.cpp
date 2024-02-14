// https://www.acmicpc.net/problem/1629

#include <iostream>

using namespace std;

long func(long A, long B, long C) {
	if (B == 1) return A % C;
	long val = func(A, B/2, C);
	val = val * val % C;
	if (B % 2 == 0) return val;
	return val * A % C;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;
	cout << func(A, B, C) << '\n';
}