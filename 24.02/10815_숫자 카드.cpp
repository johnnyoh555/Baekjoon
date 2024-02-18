// https://www.acmicpc.net/problem/10815

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v(500001);
int 				N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.begin() + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		cout << binary_search(v.begin(), v.begin() + N, tmp) << ' ';
	}
}