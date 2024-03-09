// https://www.acmicpc.net/problem/12851

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int> > v(100001);
int N, K, flag;
queue<pair<int, int> > Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	v[N].second = 1;
	Q.push({N, 0});
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		if (cur.first == K) {
			if (!flag) flag = cur.second;
			continue ;
		}
		if (cur.first - 1 >= 0) {
			if (!v[cur.first - 1].first) {
				v[cur.first - 1].first = cur.second + 1;
				v[cur.first - 1].second += v[cur.first].second;
				if (flag == 0) Q.push({cur.first - 1, cur.second + 1});
			} else if (v[cur.first - 1].first == cur.second + 1) {
				v[cur.first - 1].second += v[cur.first].second;
			}
		}
		if (cur.first + 1 <= 100000) {
			if (!v[cur.first + 1].first) {
				v[cur.first + 1].first = cur.second + 1;
				v[cur.first + 1].second += v[cur.first].second;
				if (flag == 0) Q.push({cur.first + 1, cur.second + 1});
			} else if (v[cur.first + 1].first == cur.second + 1) {
				v[cur.first + 1].second += v[cur.first].second;
			}
		}
		if (cur.first * 2 <= 100000) {
			if (!v[cur.first * 2].first) {
				v[cur.first * 2].first = cur.second + 1;
				v[cur.first * 2].second += v[cur.first].second;
				if (flag == 0) Q.push({cur.first * 2, cur.second + 1});
			} else if (v[cur.first * 2].first == cur.second + 1) {
				v[cur.first * 2].second += v[cur.first].second;
			}
		}
	}
	cout << v[K].first << '\n';
	cout << v[K].second << '\n';
}