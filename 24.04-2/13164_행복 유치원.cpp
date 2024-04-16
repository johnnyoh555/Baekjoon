// https://www.acmicpc.net/problem/13164
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > v;
int arr[300001];
int N, K;
long ans;

bool cmp(pair<int, int>& a, pair<int, int>& b) {return a.second < b.second;}

bool cmp2(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	 	if (i > 0) v.push_back({arr[i] - a, i - 1});
		a = arr[i];
	}
	sort(v.begin(), v.end(), cmp2);
	v.erase(v.begin() + K - 1, v.end());
	sort(v.begin(), v.end(), cmp);
	int idx = 0;
	int tmp = -1;
	for (int i = 0; i < N; i++) {
		if (tmp == -1) tmp = arr[i];
		if (idx < v.size() && i == v[idx].second) {
			idx++;
			ans += arr[i] - tmp;
			tmp = -1;
		}
	}
	if (tmp != -1) ans += arr[N - 1] - tmp;
	cout << ans << '\n';
}