// https://www.acmicpc.net/problem/2170

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;
int a, b, N, mn, mx, sum;

bool	cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end(), cmp);
	mn = v[0].first;
	mx = v[0].second;
	for (int i = 1; i < N; i++) {
		if (v[i].first <= mx && v[i].second > mx) mx = v[i].second;
		else if (v[i].first > mx) {
			sum += mx - mn;
			mn = v[i].first;
			mx = v[i].second;
		}
	}
	cout << sum + mx - mn << '\n';
}