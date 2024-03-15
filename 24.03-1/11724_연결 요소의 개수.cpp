// https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<short> arr[1001];
bool vis[1001];
short N, cnt;
int M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		short a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (short i = 1; i <= N; i++) {
		if (vis[i]) continue ;
		queue<short> Q;
		Q.push(i);
		cnt++;
		while (!Q.empty()) {
			short cur = Q.front();
			Q.pop();
			vis[cur] = 1;
			while (!arr[cur].empty()) {
				Q.push(arr[cur].back());
				arr[cur].pop_back();
			}
		}
	}
	cout << cnt << '\n';
}