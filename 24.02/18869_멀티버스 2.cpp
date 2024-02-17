// https://www.acmicpc.net/problem/18869

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[101][10001];
int M, N, cnt;

void index(int *b) {
	vector<int> v(b, b + N);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < N; i++) {
		b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
	}
}

void check(int *i, int *j) {
	for (int k = 0; k < N; k++) {
		if (i[k] != j[k]) return;
	}
	cnt++;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
		index(a[i]);
	}
	for (int i = 0; i < M - 1; i++) {
		for (int j = i + 1; j < M; j++) {
			check(a[i], a[j]);
		}
	}
	cout << cnt << '\n';
}