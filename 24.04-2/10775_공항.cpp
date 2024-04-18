// https://www.acmicpc.net/problem/10775
#include <iostream>
using namespace std;
int G, P, cnt, tmp, ans;
int p[100001];

int find(int x) {
	if (p[x] == x) return p[x];
	return p[x] = find(p[x]);
}

bool uf(int x) {
	x = find(x);
	if (x == 0) return false;
	p[x]--;
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> G >> P;
	for (int i = 0; i <= G; i++) {p[i] = i;}
	for (int i = 1; i <= P; i++) {cin >> tmp; if (!uf(tmp) && !ans) ans = cnt; cnt++;}
	if (!ans) ans = cnt;
	cout << ans << '\n';	
}