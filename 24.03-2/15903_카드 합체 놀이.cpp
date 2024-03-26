// https://www.acmicpc.net/problem/15903

#include <iostream>
#include <queue>

using namespace std;

priority_queue<long, vector<long>, greater<long> > pq;
long n, m, tmp, a, b;
long sum;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {cin >> tmp; pq.push(tmp);}
	while (m--) {
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		pq.push(a + b); pq.push(a + b);
	}
	while (!pq.empty()) {sum += pq.top(); pq.pop();}
	cout << sum << '\n';
}