// https://www.acmicpc.net/problem/12852

#include <iostream>

using namespace std;

int d[1000001];
int vis[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int X;
	cin >> X;
	d[1] = 0;
	for (int i = 2; i <= X; i++) {
		d[i] = d[i - 1] + 1;
		vis[i] = i - 1;
		if (i % 2 == 0 && d[i / 2] + 1 < d[i]) {
			d[i] = d[i / 2] + 1;
			vis[i] = i / 2;
		}
		if (i % 3 == 0 && d[i / 3] + 1 < d[i]) {
			d[i] = d[i / 3] + 1;
			vis[i] = i / 3;
		}
	}
	cout << d[X] << '\n';
	int tmp = X;
	while (true) {
		cout << tmp << ' ';
		if (tmp == 1)
			break;
		tmp = vis[tmp];
	}
}