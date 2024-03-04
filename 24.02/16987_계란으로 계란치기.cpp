// https://www.acmicpc.net/problem/16987

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > V;
int N, mx;

void check() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (V[i].first <= 0) sum++;
	}
	if (sum > mx) mx = sum;
}

void back(int s) {
	if (s == N) {
		check();
		return;
	}
	if (V[s].first <= 0) {
		back(s + 1);
	} else {
		bool flag = 0;
		for (int i = 0; i < N; i++) {
			if (s == i || V[i].first <= 0) continue;
			flag = 1;
			V[i].first -= V[s].second;
			V[s].first -= V[i].second;
			back(s + 1);
			V[i].first += V[s].second;
			V[s].first += V[i].second;
		}
		if (!flag) back(s + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int S;
		int W;
		cin >> S >> W;
		V.push_back({S, W});
	}
	back(0);
	cout << mx << '\n';
}