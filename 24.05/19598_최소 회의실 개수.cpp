// https://www.acmicpc.net/problem/19598
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > v;
int N, mx, e, cnt;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e; cin >> s >> e;
		v.push_back({s, 1});
		v.push_back({e, -1});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i].second;
		if (cnt > mx) mx = cnt;
	}
	cout << mx << '\n';
}