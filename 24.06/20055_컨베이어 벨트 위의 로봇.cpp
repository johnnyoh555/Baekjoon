// https://www.acmicpc.net/problem/20055
#include <iostream>
using namespace std;
int belt[201], N, NN, K, cnt, ans, flag;
bool vis[201];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	NN = 2 * N;
	for (int i = 0; i < 2 * N; i++) cin >> belt[i];
	while (cnt < K) {
		ans++;
		flag = (flag + NN - 1) % NN;
		if (vis[(flag + N - 1) % NN]) vis[(flag + N - 1) % NN] = 0;
		for (int i = flag + N - 1; i >= flag; i--) {
			if (vis[(i % NN)] && !vis[((i + 1) % NN)] && belt[((i + 1) % NN)]) {
				vis[(i % NN)] = 0;
				vis[((i + 1) % NN)] = 1;
				belt[((i + 1) % NN)]--;
				if (!belt[((i + 1) % NN)]) cnt++;
			}
		}
		if (vis[(flag + N - 1) % NN]) vis[(flag + N - 1) % NN] = 0;
		if (!vis[flag] && belt[flag]) {
			vis[flag] = 1;
			belt[flag]--;
			if (!belt[flag]) cnt++;
		}
	}
	cout << ans << '\n';
}