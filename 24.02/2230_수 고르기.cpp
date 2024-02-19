// https://www.acmicpc.net/problem/2230

#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];
int N, M, st, en;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int min = 2e9 + 1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	en = 1;
	while (en < N) {
		if (en == st) en++;
		int tmp = a[en] - a[st];
		if (tmp >= M && tmp < min) min = tmp;
		if (tmp < M)
			en++;
		else
			st++;
	}
	cout << min << '\n';
}