// https://www.acmicpc.net/problem/15989

#include <iostream>

using namespace std;

int arr[10001][2];

int t, n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	arr[2][0] = 1;
	arr[3][0] = 1;
	arr[3][1] = 1;
	for (int i = 4; i <= 10000; i++) {
		arr[i][0] = arr[i - 2][0] + 1;
		arr[i][1] = arr[i - 3][0] + arr[i - 3][1] + 1;
	}
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << arr[n][0] + arr[n][1] + 1 << '\n';
	}
}

