// https://www.acmicpc.net/problem/1790
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K; cin >> N >> K;
	int x = 1, cnt = 1;
	while (K) {
		int tmp = x * 10;
		if (tmp < N) {
			if (K - (tmp - x) * cnt <= 0) {
				while (K > cnt) {
					K -= cnt;
					x++;
				}
				string str = to_string(x);
				cout << str[K - 1] << '\n';
				break;
			} else {
				K -= (tmp - x) * cnt;
			}
		} else {
			while (x < N && K > cnt) {
				K -= cnt;
				x++;
			}
			if (K > cnt) {
				cout << "-1\n";
				break;
			} else {
				string str = to_string(x);
				cout << str[K - 1] << '\n';
				break;
			}
		}
		x = tmp; cnt++;
	}
}