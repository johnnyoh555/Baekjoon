// https://www.acmicpc.net/problem/2295

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v(1001);
vector<int> sum;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			sum.push_back(v[i] + v[j]);
		}
	}
	sort(v.begin(), v.begin() + N);
	sort(sum.begin(), sum.end());
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			int tmp = v[i] - v[j];
			if (binary_search(sum.begin(), sum.end(), tmp)) {
				cout << v[i] << '\n';
				return 0;
			}
		}	
	}
}