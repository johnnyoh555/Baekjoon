// https://www.acmicpc.net/problem/1715

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int N, tmp, sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		pq.push(tmp);
	}
	while (pq.size() > 1) {
		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		cout << a << ' ' << b << '\n';
		sum += a + b;
		pq.push(a + b);
	}
	cout << sum << '\n'; 
}