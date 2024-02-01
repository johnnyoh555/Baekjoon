// https://www.acmicpc.net/problem/5014

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int vis[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	int dx[2] = {U, -D};
	queue<int>	Q;
	vis[S] = 1;
	Q.push(S);
	int flag = 0;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for(int i = 0; i < 2; i++) {
			int nx = dx[i] + cur;
			if (nx <= 0 || nx > F)
				continue ;
			if (vis[nx])
				continue ;
			vis[nx] = vis[cur] + 1;
			Q.push(nx);
			if (nx == G)
				flag = 1;
		}
		if (flag)
			break ;
	}
	if (flag)
		cout << vis[G] - 1 << '\n';
	else if (S == G)
		cout << "0\n";
	else
		cout << "use the stairs\n";
}