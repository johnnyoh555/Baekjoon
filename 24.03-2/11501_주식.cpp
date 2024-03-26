// https://www.acmicpc.net/problem/11501

#include <iostream>
#include <vector>

using namespace std;

int N, T, tmp;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<int> v;
		long sum = 0;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		int mx = v[v.size() - 1];
		for (int j = v.size() - 2; j >= 0; j--) {
			if (v[j] > mx) mx = v[j];
			else sum += mx - v[j];
		}
		cout << sum << '\n';
	}
}