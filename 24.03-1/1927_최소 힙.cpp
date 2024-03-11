// https://www.acmicpc.net/problem/1927

#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	};
};

priority_queue<int, vector<int>, cmp> pq;
int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++ ) {
		int tmp;
		cin >> tmp;
		if (tmp != 0) {
			pq.push(tmp);
		} else if(pq.empty()) {
			cout << "0\n";
		} else {
			cout << pq.top() << '\n';
			pq.pop();
		}
	}
}