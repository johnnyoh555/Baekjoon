// https://www.acmicpc.net/problem/2283

#include <iostream>
#include <algorithm>

using namespace std;

int N, K, st, en, mn, mx;
int arr[1001][2];

long check() {
	long sum = 0;
	for (int i = 0; i < N; i++) {
		if (st <= arr[i][0] && en <= arr[i][1] && en > arr[i][0]) sum += en - arr[i][0];
		else if (st > arr[i][0] && en <= arr[i][1]) sum += en - st;
		else if (st <= arr[i][0] && en > arr[i][1]) sum += arr[i][1] - arr[i][0];
		else if (st > arr[i][0] && en > arr[i][1] && st < arr[i][1]) sum += arr[i][1] - st;
	}
	return (sum);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	mn = 1e9 + 1;
 	mx = 1e9 + 1;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1];
		if (arr[i][0] < mn) mn = arr[i][0];
		if (arr[i][1] < mx) mx = arr[i][1];
	}
	while (en <= 1000000) {
		if (st == en) {en++; continue;}
		long m = check();
		if (m == K) {
			cout << st << ' ' << en << '\n';
			return 0;
		}
		if (m < K) {
			en++;
		} else {
			st++;
		}
	}
	cout << "0 0\n";
}