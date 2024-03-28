// https://www.acmicpc.net/problem/9657

#include <iostream>

using namespace std;

bool arr[1001];
int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	arr[1] = 1;
	arr[3] = 1;
	arr[4] = 1;
	for (int i = 5; i <= N; i++) if (!arr[i - 1] || !arr[i - 3] || !arr[i - 4]) arr[i] = 1;
	if (arr[N]) cout << "SK\n";
	else cout << "CY\n";
}