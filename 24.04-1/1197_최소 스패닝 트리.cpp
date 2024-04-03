// https://www.acmicpc.net/problem/1197

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

tuple<int, int, int> tu[100001];
vector<int> p(10001, -1);
int N, M, a, b, c, cnt, ans;

int  find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool check_group(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return true;
	if (p[x] == p[y]) p[x]--;
	if (p[x] < p[y]) p[y] = x;
	else p[x] = y;
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		tu[i] = {c, a, b};
	}
	sort(tu, tu + M);
	for (int i = 0; i < M; i++) {
		tie(c, a, b) = tu[i];
		if (check_group(a, b)) continue;
		ans += c; cnt++;
		if (cnt == N - 1) break;
	}
	cout << ans << '\n';
}