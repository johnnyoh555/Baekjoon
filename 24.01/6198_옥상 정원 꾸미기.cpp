// https://www.acmicpc.net/problem/6198

#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	stack<int> sk;
	int	tmp[80000] = {0,};
	int cnt[80000] = {0,};

	for (int i = 0; i < N; i++) {
		cin >> tmp[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		if (sk.empty() || tmp[i] <= tmp[sk.top()])
			sk.push(i);
		else {
			while (!sk.empty() && tmp[i] > tmp[sk.top()]) {
				cnt[i]++;
				cnt[i] += cnt[sk.top()];
				sk.pop();
			}
			sk.push(i);
		}
	}
	long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += cnt[i];
	}
	cout << sum << '\n';
}
