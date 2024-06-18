// https://www.acmicpc.net/problem/2110
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, C, st, en, ans;
vector<int> v;

bool ft(int x) {
	int cnt = 1;
	int f = v[0];
	for (int i = 1; i < N; i++) {
		if (v[i] - f >= x) {
			f = v[i];
			cnt++;
		}
	}
	return cnt >= C;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
		if (en < tmp) en = tmp;
	}
	sort(v.begin(), v.end());
	st = 1; en = v[N - 1] - v[0] + 1;
	while (st < en) {
		int mid = (st + en) / 2;
		if (ft(mid)) {
			ans = max(ans, mid);
			st = mid + 1;
		}
		else en = mid;
	}
	cout << ans << '\n';
}