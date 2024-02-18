// https://www.acmicpc.net/problem/1253

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v(2001);
int N, cnt;

void solve(int i) {
	for (int j = 0; j < N; j++) {
		if (j == i) continue;
		int l = lower_bound(v.begin(), v.begin() + N, v[i] - v[j]) - v.begin();
		while (l < N && v[l] == v[i] - v[j]) {
			if (l != i && l != j) {
				cnt++;
				return ;
			}
			l++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.begin() + N);
	for (int i = 0; i < N; i++) solve(i);
	cout << cnt << '\n';
}