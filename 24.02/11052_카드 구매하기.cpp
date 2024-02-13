// https://www.acmicpc.net/problem/11052

#include <iostream>

using namespace std;

int P[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	for (int i = 2; i <= N; i++) {
		int max = 0;
		for (int j = 0; j <= i / 2; j++) {
			if (P[i - j] + P[j] > max)
				max = P[i - j] + P[j];
		}
		P[i] = max;
	}
	cout << P[N] << '\n';
}