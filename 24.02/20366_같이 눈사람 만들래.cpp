// https://www.acmicpc.net/problem/20366

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, st, en;
vector<int> v(601);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int max = 2e9 + 1;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.begin() + N);
	for (int i = 0; i < N - 1; i ++) {
		for (int j = i + 1; j < N; j++) {
			st = 0;
			en = N - 1;
			while (st < en) {
				if (st == i || st == j) {st++; continue;}
				if (en == i || en == j) {en--; continue;}
				int tmp = (v[i] + v[j]) - (v[st] + v[en]);
				if (abs(tmp) < abs(max))
					max = tmp;
				if (v[st] + v[en] < v[i] + v[j])
					st++;
				else
					en--; 
			}
		}
	}
	cout << abs(max) << '\n';
}