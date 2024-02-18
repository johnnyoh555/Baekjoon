// https://www.acmicpc.net/problem/3151

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a(10001);
int N;
long cnt;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a.begin(), a.begin() + N);
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int tmp =	a[i] + a[j];
			int l = lower_bound(a.begin(), a.begin() + N, -tmp) - a.begin();
			if (l != N && a[l] == -tmp) {
				int u = upper_bound(a.begin(), a.begin() + N, -tmp) - a.begin();
				int k = u - l;
				if (a[i] == -tmp)
					k--;
				if (a[j] == -tmp)
					k--;
				cnt += k;
			}
		}
	}
	cout << cnt / 3 << '\n';
}