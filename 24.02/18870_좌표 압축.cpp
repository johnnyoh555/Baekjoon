// https://www.acmicpc.net/problem/18870

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(1000001);
vector<int> b(1000001);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		b[i] = v[i];
	}
	sort(b.begin(), b.begin() + N);
	b.erase(unique(b.begin(), b.begin() + N), b.end());
	for (int i = 0; i < N; i++) {
		cout << lower_bound(b.begin(), b.end(), v[i]) - b.begin() << ' ';
	}
}