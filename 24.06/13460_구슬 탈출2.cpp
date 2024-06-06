// https://www.acmicpc.net/problem/13460
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N, M, rx, ry, bx, by;
char map[10][10];

struct info {
	int ry;
	int rx;
	int by;
	int bx;
	int cnt;
	int be;
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < M; j++) {
			map[i][j] = tmp[j];
			if (map[i][j] == 'R') {ry = i; rx = j; map[i][j] = '.';}
			if (map[i][j] == 'B') {by = i; bx = j; map[i][j] = '.';}
		}
	}
	queue<info> q;
	q.push({ry, rx, by, bx, 0, -1});

}