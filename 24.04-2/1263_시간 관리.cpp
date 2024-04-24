// https://www.acmicpc.net/problem/1263
#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int>	arr[1001];
int N, ans = 2e9;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].second >> arr[i].first;
	sort(arr, arr + N, greater<pair<int, int>>());
	for (int i = 0; i < N; i++) {
		if (ans > arr[i].first) ans = arr[i].first;
		ans -= arr[i].second;
	}
	if (ans < 0) ans = -1;
	cout << ans << '\n';
}

