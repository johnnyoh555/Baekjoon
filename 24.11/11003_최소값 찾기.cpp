// https://www.acmicpc.net/problem/11003
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
int N, L;
priority_queue<int, vector<int>, greater<int>> pq, save;
deque<int> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		pq.push(tmp); dq.push_back(tmp);
		if (dq.size() > L) {save.push(dq.front()); dq.pop_front();}
		while (pq.size() > L && pq.top() == save.top()) {
			pq.pop(); save.pop();
		}
		cout << pq.top() << ' ';
	}
	cout << '\n';
}
