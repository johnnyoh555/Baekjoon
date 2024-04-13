// https://www.acmicpc.net/problem/1041
#include <iostream>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
long dice[6];
long mx[3];
long N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < 6; i++) cin >> dice[i];
	if (N == 1) {cout << accumulate(dice, dice + 6, 0) - *max_element(dice, dice + 6) << '\n'; return 0;}
	mx[0] = min(dice[0], dice[5]);
	mx[1] = min(dice[1], dice[4]);
	mx[2] = min(dice[2], dice[3]);
	sort(mx, mx + 3);
	long long a = (mx[0] + mx[1] + mx[2]) * 4;
	long long b = ((N - 2) * 4 + (N - 1) * 4) * (mx[0] + mx[1]);
	long long c = (pow(N - 2, 2) + (N - 2) * (N - 1) * 4) * mx[0];
	cout << a + b + c << '\n';
}