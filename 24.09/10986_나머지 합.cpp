// https://www.acmicpc.net/problem/10986
#include <iostream>
using namespace std;
long N, M, d[1000001], ans, m[1001];
bool v[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> d[i];
		d[i] += d[i - 1];
	}
	for (int i = 0; i < N; i++) {
		long tmp = d[i] % M;
		if (!tmp || v[tmp]) m[tmp] += 1; 
		else v[tmp] = 1;
		ans += m[tmp];
	}
	cout << ans << '\n';
}