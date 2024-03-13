// https://www.acmicpc.net/problem/1655

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int> > save;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (!save.empty() && tmp > save.top()) {
			save.push(tmp);
			tmp = save.top();
			save.pop();
		}
		pq.push(tmp);
		if (i % 2 == 1) {
			save.push(pq.top());
			pq.pop();
		}
		cout << pq.top() << '\n';
	}
}
