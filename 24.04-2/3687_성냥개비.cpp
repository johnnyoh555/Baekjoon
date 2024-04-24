// https://www.acmicpc.net/problem/3687
#include <iostream>
using namespace std;
int T;
string d[101];

void getMax(int N) {
	string tmp;
	if (N % 2 == 1) {N -= 3; tmp.push_back('7');}
	while (N) {
		N -= 2;
		tmp.push_back('1');
	}
	cout << tmp << '\n';
}

void getMin(int N) {
	for (int i = 8; i <= N; i++) {
		if (d[i].size()) continue;
		string mn = "9999999999999999";
		for (int j = 2; j <= i - 2; j++) {
			string tmp = d[j] + d[i - j];
			if (j == 6) tmp[0] = '6';
			if (mn.size() == tmp.size() && mn > tmp) mn = tmp;
			else if (mn.size() > tmp.size()) mn = tmp;
		}
		d[i] = mn;
	}
	if (N == 6) cout << "6\n";
	else cout << d[N] << ' ';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	d[2] = '1';
	d[3] = '7';
	d[4] = '4';
	d[5] = '2';
	d[6] = '0';
	d[7] = '8';
	for (int i = 0; i < T; i++) {
		int N; cin >> N;
		getMin(N);
		getMax(N);
	}
}