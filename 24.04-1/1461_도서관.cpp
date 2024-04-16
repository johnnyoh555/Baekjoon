// https://www.acmicpc.net/problem/1461
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> p;
vector<int> m;
int N, M, tmp, ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp < 0) m.push_back(tmp);
		else p.push_back(tmp);
	}
	sort(m.begin(), m.end());
	sort(p.begin(), p.end(), greater<int>());
	int i = 0, j = 0, a = 0, b = 0;
	if (m.size()) a = -m[0];
	if (p.size()) b = p[0];
	if (a > b) {ans += a; i += M;}
	else {ans += b; j += M;}
	while (i < m.size()) {
		ans += m[i] * -2;
		i += M;
	}
	while (j < p.size()) {
		ans += p[j] * 2;
		j += M;
	}
	cout << ans << '\n';
}