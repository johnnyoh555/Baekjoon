// https://www.acmicpc.net/problem/2141
#include <iostream>
#include <algorithm>
using namespace std;
int N;
pair<int, int> X[100001];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long sum = 0, cur = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i].first >> X[i].second;
		sum += X[i].second;
	}
	sort(X, X + N);
	for (int i = 0; i < N; i++) {
		cur += X[i].second;
		if (cur >= (sum + 1) / 2) {
			cout << X[i].first << '\n';
			break;
		}
	}
}
