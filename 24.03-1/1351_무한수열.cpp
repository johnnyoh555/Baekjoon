// https://www.acmicpc.net/problem/1351

#include <iostream>
#include <map>

using namespace std;

long N, P, Q;
map<long, long> m;

long ft(long i) {
	if (m.find(i) != m.end()) return m[i];
	return m[i] = ft(i / P) + ft(i / Q);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	m[0] = 1;
	cin >> N >> P >> Q;
	cout << ft(N) << '\n';
}