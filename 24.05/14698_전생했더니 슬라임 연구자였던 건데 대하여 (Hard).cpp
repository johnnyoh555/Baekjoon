// https://www.acmicpc.net/problem/14698
#include <iostream>
#include <queue>
using namespace std;
int T, N, mod = 1000000007;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		priority_queue<unsigned long, vector<unsigned long>, greater<unsigned long> >	pq;
		cin >> N;
		for (int j = 0; j < N; j++) {
			unsigned long tmp; cin >> tmp;
			pq.push(tmp);
		}
		unsigned long ans = 1;
		while (pq.size() > 1) {
			unsigned long a = pq.top(); pq.pop();
			unsigned long b = pq.top(); pq.pop();
			unsigned long tmp = a * b;
			ans = (ans % mod) * (tmp % mod);
			pq.push(tmp);
		}
		cout << ans % mod << '\n';
	}
}