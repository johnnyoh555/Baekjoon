// https://www.acmicpc.net/problem/1202

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

pair<int, int> jewel[300001];
multiset<int> bag;
int N, K;
long sum;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> jewel[i].second >> jewel[i].first;
	sort(jewel, jewel + N);
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		bag.insert(tmp);
	}
	for (int i = N - 1; i >= 0; i--) {
		auto it = bag.lower_bound(jewel[i].second);
		if (it == bag.end()) continue;
		sum += jewel[i].first;
		bag.erase(it);
	}
	cout << sum << '\n';
}