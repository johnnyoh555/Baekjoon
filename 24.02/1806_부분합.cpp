// https://www.acmicpc.net/problem/1806

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long sum;
int N, S, st, en;
vector<int> v(100001);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int min = 100001;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] >= S) {
			cout << "1\n";
			return 0;
		}
	}
	en = 1;
	sum = v[st] + v[en];
	while (en < N) {
		if (sum >= S && en - st + 1 < min) min = en - st + 1;
		if (sum < S) {
			en++;
			sum += v[en];
		} else {
			sum -= v[st];
			st++;
		}
	}
	if (min == 100001)
		cout << "0\n";
	else
		cout << min << '\n';
}