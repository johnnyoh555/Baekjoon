// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <deque>

using namespace std;

int vis[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	deque<int> DQ;
	vis[N] = 1;
	DQ.push_back(N);
	
	while (!DQ.empty()) {
		int tmp = DQ.front();
		DQ.pop_front();
		if (tmp == K)
			break ;
		if (tmp * 2 < 100001 && vis[tmp * 2] == 0) {
			vis[tmp * 2] = vis[tmp];
			DQ.push_front(tmp * 2);
		}
		if (tmp - 1 >= 0 && vis[tmp - 1] == 0) {
			vis[tmp - 1] = vis[tmp] + 1;
			DQ.push_back(tmp - 1);
		}
		if (tmp + 1 < 100001 && vis[tmp + 1] == 0) {
			vis[tmp + 1] = vis[tmp] + 1;
			DQ.push_back(tmp + 1);
		}
	}
	cout << vis[K] - 1 << '\n';
}