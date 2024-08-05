// https://www.acmicpc.net/problem/15961
#include <iostream>
#include <cmath>

using namespace std;

int arr[6000002];
int N, d, k, c, st, en, cnt, mx;
int b[3001];

void take(int i) {
	if (b[arr[i]] == 0) {
		cnt++;
		mx = max(mx, cnt);
	}
	b[arr[i]]++;
}

void put(int i) {
	b[arr[i]]--;
	if (!b[arr[i]]) cnt--;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> d >> k >> c;
	b[c]++;
	cnt++;
	mx++;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[N + i] = arr[i];
	}
	for (int i = 0; i < N + k; i++) {
		if (i >= k) put(i - k);
		take(i);
	}
	cout << mx << '\n';
}
