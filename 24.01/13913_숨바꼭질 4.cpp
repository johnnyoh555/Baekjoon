// https://www.acmicpc.net/problem/13913

#include <iostream>
#include <queue>
#include <utility>
#include <stack>

using namespace std;

int board[100001];
int vis[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K;

	cin >> N >> K;

	queue<int> Q;
	Q.push(N);
	vis[N] = 1;
	while (Q.front() != K) {
		int cur = Q.front();
		Q.pop();
		if (cur - 1 >= 0 && !vis[cur - 1]) {
			vis[cur - 1] = 1;
			board[cur - 1] = cur;
			Q.push(cur - 1);
		}
		if (cur + 1 <= 100000 && !vis[cur + 1]) {
			vis[cur + 1] = 1;
			board[cur + 1] = cur;
			Q.push(cur + 1);
		}
		if (cur * 2 <= 100000 && !vis[cur * 2]) {
			vis[cur * 2] = 1;
			board[cur * 2] = cur;
			Q.push(cur * 2);
		}
	}
	stack<int> sk;
	int i = K;
	while (i != N) {
		sk.push(i);
		i = board[i];
	}
	cout << sk.size() << '\n';
	if (N == K) {
		cout << N << '\n';
		return 0;
	}
	cout << N << ' ';
	while (!sk.empty()) {
		cout << sk.top();
		if (sk.size() != 1)
			cout << ' ';
		sk.pop();
	}
	cout << '\n';
}