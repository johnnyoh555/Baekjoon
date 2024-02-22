// https://www.acmicpc.net/problem/2531

#include <iostream>
#include <cmath>

using namespace std;

int arr[60002];
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

// int arr[30001];
// int N, d, k, c, st, en, cnt, mx;
// bool flag;
// bool b[3001];

// void check() {
// 	int a = 0;
// 	for (int i = st; i <= en; i++) {
// 		if (!b[arr[i % N]]) {
// 			b[arr[i % N]] = 1;
// 			a++;
// 		}
// 	}
// 	for (int i = st; i <= en; i++) b[arr[i % N]] = 0;
// 	if (a > mx) mx = a;
// }

// int main(void) {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	cin >> N >> d >> k >> c;
// 	for (int i = 0; i < N; i++) {
// 		cin >> arr[i];
// 		if (arr[i] == c) flag = 1;
// 		if (i < k && arr[i] == c) cnt++;
// 	}
// 	en = k - 1;
// 	while (st < N) {
// 		if (!cnt && en - st + 1 > k) {
// 			st++;
// 			continue;
// 		}
// 		check();
// 		if (cnt && en - st + 1 > k) {
// 			en++;
// 			if (arr[en % N] == c) cnt++;
// 			if (arr[st % N] == c) cnt--;
// 			st++;
// 		} else {
// 			en++;
// 			if (arr[en % N] == c) cnt++;
// 		}
// 	}
// 	if (!flag) mx++;
// 	cout << mx << '\n';
// }