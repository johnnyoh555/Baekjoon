// https://www.acmicpc.net/problem/17071

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int sub[500001][2];
int N, K, sum;
queue<pair<int, int> > Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(sub, -1, sizeof(sub));
	cin >> N >> K;
	Q.push({N, 0});
	while (!Q.empty()) {
		int x = Q.front().first;
		int time = Q.front().second;
		Q.pop();
		if (0 <= x && x <= 500000 && sub[x][time % 2] == -1) {
			sub[x][time % 2] = time;
			Q.push({x - 1, time + 1});
			Q.push({x + 1, time + 1});
			Q.push({x * 2, time + 1});
		}
	}
	while (1) {
		K += sum;
		if (K > 500000) break ;
		if (sub[K][sum % 2] != -1 && sum >= sub[K][sum % 2]) {cout << sum << '\n'; return 0;}
		sum++;
	}
	cout << "-1\n";
}