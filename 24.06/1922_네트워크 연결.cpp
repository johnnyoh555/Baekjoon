// https://www.acmicpc.net/problem/1922
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int N, M;
vector<int> p(1001, -1);
tuple<int, int, int> t[100000];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool ft(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		t[i] = {c, a, b};
	}
	sort(t, t + M);
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		tie(c, a, b) = t[i];
		if (!ft(a,b)) continue;
		ans += c;
		cnt++;
		if (cnt == N - 1) break;
	}
	cout << ans << '\n';
}