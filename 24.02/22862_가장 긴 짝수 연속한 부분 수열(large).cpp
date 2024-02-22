// https://www.acmicpc.net/problem/22862

#include <iostream>

using namespace std;
 
int arr[1000001];
int N, K, cnt, mn, st, en;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	if (arr[st] % 2 == 1) cnt++;
	while (en < N) {
		if (cnt <= K && en - st + 1 - cnt > mn) mn = en - st - cnt + 1;
		if (st == en) {
			en++;
			if (arr[en] % 2 == 1) cnt++;
			continue;
		}
		if (cnt > K) {
			while (cnt > K) {
				if (arr[st] % 2 == 1) cnt--;
				st++;
			}
			continue;
		}
		if (cnt <= K) {
			en++;
			if (arr[en] % 2 == 1) cnt++;
		}
	}
	cout << mn << '\n';
}