// https://www.acmicpc.net/problem/1700
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
int N, K, cnt;
int use[101];
unordered_set<int> us;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++) cin >> use[i];
	for (int i = 0; i < K; i++) {
		if (us.find(use[i]) != us.end()) continue;
		if (us.size() == N) {
			int mx = -1;
			unordered_set<int>::iterator idx;
			for (auto it = us.begin(); it != us.end(); it++) {
				int *tmp = find(use + i, use + K, *it);
				if (tmp == use + K) {
					if (mx < K) {mx = K; idx = it;}
				} else {
					if (mx < tmp - use) {mx = tmp - use; idx = it;}
				}
			}
			us.erase(*idx);
			cnt++;
		}
		us.insert(use[i]);
	}
	cout << cnt << '\n';
}