// https://www.acmicpc.net/problem/21758
#include <iostream>
using namespace std;
int arr[100001];
int d[100001];
int N, ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		d[i] = arr[i] + d[i - 1];
	}
	for (int i = 2; i < N; i++) {
		long mx = d[N - 1] - d[i - 1] + d[i] - d[1];
		if (ans < mx) ans = mx;
	}
	{
		long a = d[N - 1];
		long mx = 0;
		for (int j = N - 1; j > 1; j--) {
			long b = d[j - 1] - arr[j];
			if (b >= mx) mx = b;
		}
		if (ans < mx + a) ans = mx + a;
	}
	{
		long a = 2 * d[N] - d[1];
		long mx = -2e9;
		for (int j = 2; j < N; j++) {
			long b = - d[j] - arr[j];
			if (b >= mx) mx = b;
		}
		if (ans < mx + a) ans = mx + a;
	}
	cout << ans << '\n';
}