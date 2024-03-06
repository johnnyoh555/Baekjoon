// https://www.acmicpc.net/problem/9655

#include <iostream>

using namespace std;

int N;
bool arr[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	arr[1] = 1;
	arr[3] = 1;
	for (int i = 4; i <= N; i++) {
		if (!arr[i - 3] || !arr[i - 1]) arr[i] = 1;
	}
	if (arr[N] == 1) cout << "SK\n";
	else cout << "CY\n";
}