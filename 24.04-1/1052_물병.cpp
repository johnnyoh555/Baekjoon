// https://www.acmicpc.net/problem/1052
#include <iostream>
#include <cmath>
using namespace std;
long N, K;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	if (N <= K) {cout << "0\n"; return 0;}
	long tmp;
	while (N) {
		int i = 0;
		tmp = 1;
		while (tmp < N) tmp *= 2;
		if (K == 1) break;
		N -= tmp / 2;
		K--;
	}
	if (!N || N == tmp) cout << "0\n";
	else cout << tmp - N << '\n';
}	