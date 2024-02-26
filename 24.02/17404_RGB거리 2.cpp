// https://www.acmicpc.net/problem/17404

#include <iostream>
#include <cmath>

int d[1001][3][3];

using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> d[i][j][0];
			d[i][j][1] = d[i][j][0];
			d[i][j][2] = d[i][j][0];
		}
	}
	for(int i = 0; i < 3; i++) {
		d[2][0][i] += d[1][i][i];
		d[2][1][i] += d[1][i][i];
		d[2][2][i] += d[1][i][i];
		d[2][i][i] = 2001;
	}
	for (int j = 0; j < 3; j++) {
		for (int i = 3; i <= N; i++) {
			d[i][0][j] += min(d[i - 1][1][j], d[i - 1][2][j]);
			d[i][1][j] += min(d[i - 1][0][j], d[i - 1][2][j]);
			d[i][2][j] += min(d[i - 1][0][j], d[i - 1][1][j]);
		}
	}
	cout << min(min(d[N][2][0], d[N][1][0]), min(min(d[N][2][1], d[N][0][1]), min(d[N][0][2], d[N][1][2]))) << '\n';
}