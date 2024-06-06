// https://www.acmicpc.net/problem/2096
#include <iostream>
#include <cmath>
using namespace std;
int N;
int dps[3];
int dpl[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b, c, aa, bb, cc;
		cin >> a >> b >> c;
		aa = a; bb = b; cc = c;
		a += max(dpl[0], dpl[1]);
		b += max(dpl[0], max(dpl[1], dpl[2]));
		c += max(dpl[1], dpl[2]);
		aa += min(dps[0], dps[1]);
		bb += min(dps[0], min(dps[1], dps[2]));
		cc += min(dps[1], dps[2]);
		dpl[0] = a; dpl[1] = b; dpl[2] = c;
		dps[0] = aa; dps[1] = bb; dps[2] = cc;
	}
	cout << max(dpl[0], max(dpl[1], dpl[2])) << ' ' << min(dps[0], min(dps[1], dps[2])) << '\n';
}