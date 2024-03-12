// https://www.acmicpc.net/problem/2748

#include <iostream>

using namespace std;

long d[91];
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	d[1] = 1;
	for (int i = 2; i <= n; i++) d[i] = d[i - 1] + d[i - 2];
	cout << d[n] << '\n';
}