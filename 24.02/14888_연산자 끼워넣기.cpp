// https://www.acmicpc.net/problem/14888

#include <iostream>
#include <queue>

using namespace std;

int arr[12];
int P, M, X, D, N; 

struct info {
	int idx;
	int P;
	int M;
	int X;
	int D;
	int sum;
};

queue<info> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int mx = -1e9 - 1;
	int mn = 1e9 + 1;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> P >> M >> X >> D;
	Q.push({1, 0, 0, 0, 0, arr[0]});
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		if (cur.idx == N) {
			if (cur.sum < mn) mn = cur.sum;
			if (cur.sum > mx) mx = cur.sum;
		}
		if (cur.P < P) Q.push({cur.idx + 1, cur.P + 1, cur.M, cur.X, cur.D, cur.sum + arr[cur.idx]});
		if (cur.M < M) Q.push({cur.idx + 1, cur.P, cur.M + 1, cur.X, cur.D, cur.sum - arr[cur.idx]});
		if (cur.X < X) Q.push({cur.idx + 1, cur.P, cur.M, cur.X + 1, cur.D, cur.sum * arr[cur.idx]});
		if (cur.D < D) Q.push({cur.idx + 1, cur.P, cur.M, cur.X, cur.D + 1, cur.sum / arr[cur.idx]});
	}
	cout << mx << '\n';
	cout << mn << '\n';
}