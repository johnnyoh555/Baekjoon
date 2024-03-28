// https://www.acmicpc.net/problem/4883

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[300001];
int vis[300001];
int n, idx = 1;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (idx) {
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n * 3; i++) cin >> arr[i];
		fill(vis, vis + n * 3, 2e9);
		vis[1] = arr[1];
		for (int i = 1; i < n * 3 - 2; i++) {
			if (i % 3 == 0) {
				vis[i + 1] = min(vis[i + 1], arr[i + 1] + vis[i]);
				vis[i + 3] = min(vis[i + 3], arr[i + 3] + vis[i]);
				vis[i + 4] = min(vis[i + 4], arr[i + 4] + vis[i]);
			} else if (i % 3 == 1) {
				vis[i + 1] = min(vis[i + 1], arr[i + 1] + vis[i]);
				vis[i + 2] = min(vis[i + 2], arr[i + 2] + vis[i]);
				vis[i + 3] = min(vis[i + 3], arr[i + 3] + vis[i]);
				vis[i + 4] = min(vis[i + 4], arr[i + 4] + vis[i]);
			} else {
				vis[i + 2] = min(vis[i + 2], arr[i + 2] + vis[i]);
				vis[i + 3] = min(vis[i + 3], arr[i + 3] + vis[i]);
			}
		}
		cout << idx << ". " << vis[n * 3 - 2] << '\n';
		idx++;
	}
}