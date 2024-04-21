// https://www.acmicpc.net/problem/11509
#include <iostream>
using namespace std;
int d[1000001];
int N, t, a;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while(N--) {
		cin >> t;
		if (d[t]) {d[t]--; d[t - 1]++;}
		else {d[t - 1]++; a++;}
	}
	cout << a;
}