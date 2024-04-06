// https://www.acmicpc.net/problem/16398

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<int> p(1001, -1);
tuple<int, int, int> tu[1000001];
int N, x, a, b, c, cnt, tmp;
long sum;

int find(int i) {
	if (p[i] < 0) return i;
	return p[i] = find(p[i]);
}

bool is_group(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return true;
	if (p[u] == p[v]) p[u]--;
	if (p[u] > p[v]) p[v] = u;
	else p[u] = v;
	return false; 
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp; if (tmp == 0) continue;
			tu[x] = {tmp, i, j}; x++;
		}
	}
	sort(tu, tu + x);
	for (int i = 0; i < x; i++) {
		tie(c, a, b) = tu[i];
		if (is_group(a, b)) continue;
		sum += c; cnt++;
		if (cnt == N) break;
	}
	cout << sum << '\n';
}