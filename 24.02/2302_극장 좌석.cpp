// https://www.acmicpc.net/problem/2302

#include <iostream>

using namespace std;

unsigned int d[41];
bool vip[41];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		vip[tmp] = 1;
	}
	d[0] = 1;
	d[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (vip[i] || vip[i - 1]) d[i] = d[i - 1];
		else if (vip[i - 2]) d[i] = d[i - 1] * 2;
		else d[i] = d[i - 1] + d[i - 2]; 
	}
	cout << d[N] << '\n';
}