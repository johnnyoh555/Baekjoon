// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <cmath>

using namespace std;

int d[100001];
int N, K, w, v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
 		cin >> w >> v;
 		for (int j = K; j >= w; j--) d[j] = max(d[j], d[j - w] + v);
	}
	cout << d[K] << '\n';
}

// #include <vector>


// int d[101][100001];
// vector<pair<int, int> > v(100);
// int	N, K;

// int main(void) {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	cin >> N >> K;
// 	for (int i = 1; i <= N; i++) {
// 		cin >> v[i].first >> v[i].second;
// 	}
// 	for (int i = 1; i <= N; i++) {
// 		for (int j = 1; j <= K; j++) {
// 			if (j >= v[i].first)
// 				d[i][j] = max(d[i - 1][j], d[i - 1][j - v[i].first] + v[i].second);
// 			else
// 				d[i][j] = d[i - 1][j];	
// 		}
// 	}
// 	cout << d[N][K] << '\n';
// }