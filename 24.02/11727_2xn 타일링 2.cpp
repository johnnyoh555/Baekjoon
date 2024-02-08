// https://www.acmicpc.net/problem/11727

#include <iostream>

using namespace std;

long d[1001];
int mod = 10007;

int main ( void ) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 3;
	for(int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2] * 2) % mod;
	}
	cout << d[n] << '\n';
}
