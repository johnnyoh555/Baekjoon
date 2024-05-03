// https://www.acmicpc.net/problem/2258
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
} 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long N, M;
	vector<pair<int, int> > v;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({b, a});
	}
	sort(v.begin(), v.end(), cmp);
	long sum = 0;
	long price = 0;
	long tmp = 0;
	long mn = 2147483648;
	for (int i = 0; i < N; i++) {
		if (price < v[i].first) {
			price = v[i].first;
			sum += v[i].second;
			tmp = 0;
		} else {
			tmp += v[i].first;
			sum += v[i].second;
		}
		if (sum >= M && mn > price + tmp) {mn = price + tmp;}
	}
	if (mn == 2147483648) mn = -1;
	cout << mn << '\n';
}