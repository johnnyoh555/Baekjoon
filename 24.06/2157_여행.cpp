// https://www.acmicpc.net/problem/2157
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, M, K, ans;
int arr[301][301];
vector<pair<int, int> > v[301];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c; cin >> a >> b >> c; 
		v[a].push_back({b, c});
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < M; j++) {
			if (i == 1 && j != 1) continue;
			if (i > 1 && !arr[i][j]) continue;
			for (auto nxt : v[i]) {
				if (nxt.first < i) continue;
				arr[nxt.first][j + 1] = max(arr[nxt.first][j + 1], arr[i][j] + nxt.second);
			}
		}
	}
	for (int i = 2; i <= M; i++)
		if (ans < arr[N][i]) ans = arr[N][i];
	cout << ans << '\n';
}