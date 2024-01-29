// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>

using namespace std;

int vis[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	queue<int> Q;

	Q.push(N);

	while (true) {
		int tmp = Q.front();
		if (Q.front() == K)
			break ;
		Q.pop();
		if (tmp + 1 < 100001 && vis[tmp + 1] == 0) {
			vis[tmp + 1] = vis[tmp] + 1;
			Q.push(tmp + 1);
		}
		if (tmp - 1 >= 0 && vis[tmp - 1] == 0) {
			vis[tmp - 1] = vis[tmp] + 1;
			Q.push(tmp - 1);
		}
		if (tmp * 2 < 100001 && vis[tmp * 2] == 0) {
			vis[tmp * 2] = vis[tmp] + 1;
			Q.push(tmp * 2);
		}
	}
	cout << vis[K] << '\n';
}