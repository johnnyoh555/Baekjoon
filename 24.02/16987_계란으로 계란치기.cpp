// https://www.acmicpc.net/problem/16987

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > V;
int N;

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
	
}