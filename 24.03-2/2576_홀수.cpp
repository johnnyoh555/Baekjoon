#include <iostream>

using namespace std;
int sum, mn = 101;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 7; i++) {
		int tmp;
		cin >> tmp;
		if (tmp % 2 ==0) continue;
		sum += tmp;
		if (tmp <= mn) mn = tmp;
	}
	if (!sum) cout << "-1\n";
	else {
		cout << sum << '\n';
		cout << mn << '\n';
	}
}