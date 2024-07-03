// https://www.acmicpc.net/problem/3020
#include <iostream>
using namespace std;
int N, H, down[500001], top[500001], ans = 200001, cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		if (i % 2 == 0) down[tmp]++;
		else top[H - tmp + 1]++;
	}
	for (int i = 1; i <= H; i++) {
		top[i] += top[i - 1];
		down[H - i] += down[H - i + 1];
	}
	for (int i = 1; i <= H; i++) {
		if (down[i] + top[i] < ans) {
			cnt = 1;
			ans = down[i] + top[i];
		} else if (down[i] + top[i] == ans) {
			cnt++;
		}
	}
	cout << ans << ' ' << cnt << '\n';
}