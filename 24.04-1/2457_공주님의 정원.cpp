// https://www.acmicpc.net/problem/2457

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {int sd;int ed;};
vector<info> v;
int N, a, b, c, d, cnt, end_time = 301;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		info day;
		cin >> a >> b >> c >> d;
		day.sd = a * 100 + b;
		day.ed = c * 100 + d;
		v.push_back(day);
	}
	while (end_time < 1201) {
		int t = end_time;
		for (int i = 0; i < N; i++)
			if (v[i].sd <= end_time && v[i].ed > t) t = v[i].ed;
		if (t == end_time) break;
		end_time = t;
		cnt++;
	}
	if (end_time < 1201) cnt = 0;
	cout << cnt << '\n';
}