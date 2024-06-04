// https://www.acmicpc.net/problem/1689
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, t, mx, cnt;
vector<pair<int, int> > v;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e; cin >> s >> e;
		v.push_back({s, 1});
		v.push_back({e, -1});
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == 1) {cnt++; if (cnt > mx) mx = cnt;}
		else cnt--;
	}
	cout << mx << '\n';
}