// https://www.acmicpc.net/problem/2138
#include <iostream>
#include <cmath>
using namespace std;
string be0, be1, af;
int N, a, b = 1;

void ft0(int i) {
	be0[i - 1] = be0[i - 1] == '0' ? '1' : '0';
	be0[i] = be0[i] == '0' ? '1' : '0';
	if (i != N - 1) be0[i + 1] = be0[i + 1] == '0' ? '1' : '0';
}

void ft1(int i) {
	be1[i - 1] = be1[i - 1] == '0' ? '1' : '0';
	be1[i] = be1[i] == '0' ? '1' : '0';
	if (i != N - 1) be1[i + 1] = be1[i + 1] == '0' ? '1' : '0';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> be0 >> af;
	be1 = be0;
	be1[0] = be1[0] == '0' ? '1' : '0';
	be1[1] = be1[1] == '0' ? '1' : '0';
	for (int i = 1; i < N; i++) {
		if (be0[i - 1] != af[i - 1]) {ft0(i); a++;}
		if (be1[i - 1] != af[i - 1]) {ft1(i); b++;}
	}
	if (be0 != af) a = -1;
	if (be1 != af) b = -1;
	if (a == -1) cout << b << '\n';
	else if (b == -1) cout << a << '\n';
	else cout << min(a, b) << '\n';	
}