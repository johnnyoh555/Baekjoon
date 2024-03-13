// https://www.acmicpc.net/problem/13975

#include <iostream>
#include <queue>

using namespace std;

int N, t, tmp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> N;
		priority_queue<long, vector<long>, greater<long> > pq;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			pq.push(tmp);
		}
		long sum = 0;
		while (pq.size() > 1) {
			long a, b;
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			sum += a + b;
			pq.push(a + b);
		}
		cout << sum << '\n'; 
	}
}