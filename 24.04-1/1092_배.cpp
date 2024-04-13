// https://www.acmicpc.net/problem/1092
#include <iostream>
#include <algorithm>
using namespace std;
int box[10001];
int crane[51];
int N, M, t, moved;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> crane[i];
	cin >> M;
	for (int i = 0; i < M; i++) cin >> box[i];
	sort(crane, crane + N, greater<int>());
	sort(box, box + M, greater<int>());
	while (true) {
		int j = 0, cnt = 0;
		for (int i = 0; i < N; i++) {
			for (; j < M; j++) {
				if (box[j] >= 0 && box[j] <= crane[i]) {
					box[j] = -1; cnt++;
					break;
				}
			}
		}
		if (cnt == 0) break;
		moved += cnt;
		t++;
	}
	if (moved != M) cout << "-1\n";
	else cout << t << '\n';
}