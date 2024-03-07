// https://www.acmicpc.net/problem/2565

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int> > v;
int d[101];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int idx, num;
		cin >> idx >> num;
		v.push_back({idx, num});
	}
	sort(v.begin(), v.end());
	d[0] = 1;
	for (int i = 1; i < N; i++) {
		int mx = 0;
		for (int j = 0; j < i; j++) {
			if (((v[i].first < v[j].first && v[i].second < v[j].second)
				|| (v[i].first > v[j].first && v[i].second > v[j].second)) && d[j] > mx)
				mx = d[j];
		}
		d[i] = mx + 1;
	}
	int mx = 0;
	for (int i = 0; i < N; i++) {
		if (d[i] > mx) mx = d[i];
	}
	cout << N - mx << '\n';
}