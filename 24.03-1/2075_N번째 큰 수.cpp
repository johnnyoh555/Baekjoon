// https://www.acmicpc.net/problem/2075

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int N, tmp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			pq.push(tmp);
			if (pq.size() > N) pq.pop();
		}
	}
	cout << pq.top() << '\n';
}