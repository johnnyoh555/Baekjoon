// https://www.acmicpc.net/problem/15558
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N;
string str[2];
bool vis[2][100000];
int dx[3] = {1, -1, 0};
int dy[3] = {0, 0, 1};
queue<tuple<int, int, int> > q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> dx[2] >> str[0] >> str[1];
	vis[0][0] = 1;
	q.push({0, 0, 0});
	while (!q.empty()) {
		int x, y, t;
		tie(x, y, t) = q.front(); q.pop();
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = (y + dy[i]) % 2;
			if (nx >= N) {
				cout << "1\n";
				return 0;
			}
			if (nx < 0 || vis[ny][nx] || str[ny][nx] == '0' || t + 1 > nx) continue;
			vis[ny][nx] = 1;
			q.push({nx, ny, t + 1});
		}
	}
	cout << "0\n";
}