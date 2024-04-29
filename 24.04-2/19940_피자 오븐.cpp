// https://www.acmicpc.net/problem/19940
#include <iostream>
#include <deque>
using namespace std;
deque<int> ans;
int T, mn, x;

void	ft3(deque<int>& tmp, int n, int sum) {
	sum += n / 60;
	tmp[0] = n / 60;
	if (sum < mn) {
		mn = sum; ans = tmp;
	} else if (sum == mn) {
		for (int i = 0; i < 5; i++) {
			if (ans[i] < tmp[i]) break;
			else if (ans[i] > tmp[i]) {ans = tmp; break;}
		}
	}
}

void	ft2(deque<int>& tmp, int n, int sum) {
	if (n == 0 || n % 60 == 0) {
		ft3(tmp, n, sum);
	} else {
		int a = n % 60 / 10;
		tmp[2] = 6 - a;
		ft3(tmp, n + (6 - a) * 10, sum + 6 - a);
		tmp[2] = 0;
		tmp[1] = a;
		ft3(tmp, n - a * 10, sum + a);
		tmp[1] = 0;
	}
}

void	ft1(deque<int>& tmp, int n, int sum) {
	int a = n % 10;
	tmp[4] = 10 - a;
	ft2(tmp, n + 10 - a, sum + 10 - a);
	tmp[4] = 0;
	tmp[3] = a;
	ft2(tmp, n - a, sum + a);
	tmp[3] = 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int N; cin >> N;
		mn = 2e9;
		deque<int> tmp(5, 0);
		ft1(tmp, N, 0);
		for (int j = 0; j < 5; j++) cout << ans[j] << ' ';
		cout << '\n';
		ans.clear();
	}
}