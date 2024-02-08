// https://www.acmicpc.net/problem/1149

#include <iostream>

int d[1001][3];

using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> d[i][j];
		}
	}

	for (int i = 2; i <= N; i++) {
		d[i][0] += min(d[i - 1][1], d[i - 1][2]);
		d[i][1] += min(d[i - 1][0], d[i - 1][2]);
		d[i][2] += min(d[i - 1][0], d[i - 1][1]);
	}
	cout << min(d[N][0], min(d[N][1], d[N][2])) << '\n';
}