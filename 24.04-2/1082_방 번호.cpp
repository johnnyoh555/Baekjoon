// https://www.acmicpc.net/problem/1082
#include <iostream>
#include <algorithm>
using namespace std;
string d[51];
int N, M, a;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a; string tmp = to_string(i);
		if (d[a].size() < tmp.size() || (d[a].size() == tmp.size() && d[a] < tmp)) d[a] = to_string(i);
	}
	cin >> M;
	for (int i = 2; i <= M; i++) {
		for (int j = 1; j <= i - 1; j++) {
			if (!d[j].size() || d[j][0] == '0') continue;
			string tmp = d[j] + d[i - j];
			if (tmp.size() > d[i].size()) d[i] = tmp;
			else if (tmp.size() == d[i].size() && tmp > d[i]) d[i] = tmp;
		}
	}
	if (!d[M].size()) cout << "0\n";
	else cout << d[M] << '\n';
}