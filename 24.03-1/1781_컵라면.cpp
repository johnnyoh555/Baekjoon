// https://www.acmicpc.net/problem/1781

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int> > v(200001);
priority_queue<int> pq;
int N, t;
long sum;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 200000; i > 0; i--) {
		for (int j = 0; j < v[i].size(); j++) {
			pq.push(v[i][j]);
		}
		if (pq.empty()) continue;
		sum += pq.top();
		pq.pop();
	}
	cout << sum << '\n';
}