// https://www.acmicpc.net/problem/20207
#include <iostream>
using namespace std;
int arr[367], N, S, E, ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> E;
		for (int j = S; j <= E; j++) arr[j]++;
	}
	int r = 0, c = 0;
	for (int i = 1; i <= 366; i++) {
		if (!arr[i]) {
			ans += r * c;
			r = 0; c = 0;
		} else {
			r++;
			if (arr[i] > c) c = arr[i];
		}
	}
	cout << ans << '\n';
}