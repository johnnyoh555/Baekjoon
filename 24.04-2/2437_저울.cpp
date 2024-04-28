// https://www.acmicpc.net/problem/2437
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001], N, idx = 1;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		if (idx < arr[i]) break;
		else idx += arr[i];
	}
	cout << idx << '\n';
}