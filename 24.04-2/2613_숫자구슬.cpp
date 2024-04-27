// https://www.acmicpc.net/problem/2613
#include <iostream>
#include <deque>
using namespace std;
int N, M, ans = 2e9;
deque<int> dq[301];
int s[301];
int d[301];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int tmp; cin >> tmp;
		if (i < M) {dq[i].push_back(tmp); s[i] += tmp;}
		else {dq[M].push_back(tmp); s[M] += tmp;}
	}
	while (true) {
		int mx = 0;
		int idx = 0;
		for (int i = 1; i <= M; i++) {
			if (s[i] >= mx) {mx = s[i]; idx = i;}
		}
		if (mx < ans) {
			ans = mx;
			for (int i = 1; i <= M; i++) d[i] = dq[i].size();
		}
		if (idx == 1) break;
		dq[idx - 1].push_back(dq[idx].front()); s[idx] -= dq[idx].front();
		s[idx - 1] += dq[idx].front(); dq[idx].pop_front();
	}
	cout << ans << '\n';
	for (int i = 1; i <= M; i++) cout << d[i] << ' ';
	cout << '\n';
}