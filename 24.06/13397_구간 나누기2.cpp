// https://www.acmicpc.net/problem/13397
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> v;

int ft(int x) {
	int g = 1;
	int mn = v[0], mx = v[0];

	for (int i = 1; i < N; i++) {
		if (v[i] < mn) mn = v[i];
		if (v[i] > mx) mx = v[i];
		if (mx - mn > x) {
			g++;
			mn = v[i]; mx = v[i];
		}
	}
	return g <= M;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	int st = 0, en = 10000;
	while (st < en) {
		int mid = (st + en) / 2;
		if (!ft(mid)) st = mid + 1;
		else en = mid;
	}
	cout << st << '\n';
}