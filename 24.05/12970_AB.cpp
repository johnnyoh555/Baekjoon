// https://www.acmicpc.net/problem/12970
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;

	cin >> N >> K;
	int a = N - 1;
	int b = 1;
	while (a * b < K) {
		a--; b++;
		if (!a) {cout << "-1\n"; return 0;}
	}
	int c = a * b;
	string s;
	while (a--) s.push_back('A');
	while (b--) s.push_back('B');
	while (c > K) {
		for (int i = 1; i < N; i++)
			if (s[i] == 'B' && s[i - 1] == 'A') {swap(s[i - 1], s[i]); break;}
		c--;
	}
	cout << s << '\n';
}