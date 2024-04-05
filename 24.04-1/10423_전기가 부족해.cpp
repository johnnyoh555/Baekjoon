// https://www.acmicpc.net/problem/10423

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

tuple<int, int, int> tu[100001];
vector<int> p(1001, -1);
int N, M, K, a, b, c, cnt, ans;

int  find(int x) {
	if (p[x] < 0 || p[x] > 1000) return x;
	return p[x] = find(p[x]);
}

bool check_group(int x, int y) {
	x = find(x); y = find(y);
	if (x == y || (p[x] > 1000 && p[y] > 1000)) return true;
	if (p[x] == p[y]) p[x]--;
	if (p[x] > p[y]) p[y] = x;
	else p[x] = y;
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int tmp; cin >> tmp;
		p[tmp] = tmp + 1000;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		tu[i] = {c, a, b};
	}
	sort(tu, tu + M);
	for (int i = 0; i < M; i++) {
		tie(c, a, b) = tu[i];
		if (check_group(a, b)) continue;
		ans += c;
		cnt++;
		if (cnt == N - K) break;
	}
	cout << ans << '\n';
}