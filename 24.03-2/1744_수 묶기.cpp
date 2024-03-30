// https://www.acmicpc.net/problem/1744

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> p;
priority_queue<int, vector<int>, greater<int> > m;
long sum;
int N, tmp, a, b;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp > 0) p.push(tmp);
		else m.push(tmp);
	}
	while (!p.empty()) {
		a = p.top();
		p.pop();
		if (!p.empty()) {
			b = p.top();
			p.pop();
			if (a * b > a + b) sum += a * b;
			else sum += a + b;
		} else sum += a;
	}
	while (!m.empty()) {
		a = m.top();
		m.pop();
		if (!m.empty()) {
			b = m.top();
			m.pop();
			if (a * b > a + b) sum += a * b;
			else sum += a + b;
		} else sum += a;
	}
	cout << sum << '\n';
}