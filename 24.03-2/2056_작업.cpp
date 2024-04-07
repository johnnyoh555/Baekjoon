// https://www.acmicpc.net/problem/2056

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<short, short> > q;
vector<short> v[10001];
short id[10001];
short t[10001];
short arr[10001];
short N, M, a, mn;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (short i = 1; i <= N; i++) {
		cin >> t[i];
		cin >> id[i];
		for (short j = 0; j < id[i]; j++) {
			cin >> a;
			v[a].push_back(i);
		}
	}
	for (short i = 1; i <= N; i++) if (!id[i]) q.push({i, t[i]});
	while (!q.empty()) {
		pair<short, short> cur = q.front();
		q.pop();
		if (cur.second > mn) mn = cur.second;
		for (short idx : v[cur.first]) {
			id[idx]--;
			if (arr[idx] < cur.second + t[idx]) arr[idx] = cur.second + t[idx];
			if (id[idx] == 0) q.push({idx, arr[idx]});
		}
	}
	cout << mn << '\n';
}