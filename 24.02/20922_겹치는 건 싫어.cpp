// https://www.acmicpc.net/problem/20922

#include <iostream>

using namespace std;

int arr[200001];
int v[100001];
int N, K , st, en, flag, mx;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	v[arr[st]]++;
	while (en < N) {
		if (en - st + 1 > mx) mx = en - st + 1;
		en++;
		v[arr[en]]++;
		while (v[arr[en]] > K) {
			v[arr[st]]--;
			st++;
		}
	}
	cout << mx << '\n';
}