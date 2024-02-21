// https://www.acmicpc.net/problem/1644

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, st, en, cnt;
vector<int> p;

void prime(int num) {
	if (num <= 1) return ;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return ;
	}
	p.push_back(num);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) prime(i);
	if (!p.size()) {
		cout << "0\n";
		return 0;
	}
	int sum = p[st];
	while (en < p.size() && p[en] <= N) {
		if (sum == N) cnt++;
		if (sum < N) {
			en++;
			sum += p[en];
		} else {
			sum -= p[st];
			st++;
		}
	}
	cout << cnt << '\n';
}