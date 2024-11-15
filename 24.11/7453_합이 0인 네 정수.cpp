// https://www.acmicpc.net/problem/7453
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long N, arr[4][4000], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[j][i];

	vector<long> v1, v2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long tmp1 = arr[0][i] + arr[1][j];
			long tmp2 = arr[2][i] + arr[3][j];
			v1.push_back(tmp1);
			v2.push_back(tmp2);
		}
	}
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++) {
		auto [lo, up] = equal_range(v2.begin(), v2.end(), -v1[i]);
		ans += up - lo;
	}
	cout << ans << '\n';
}