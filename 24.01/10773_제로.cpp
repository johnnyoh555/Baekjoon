// https://www.acmicpc.net/problem/10773

#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int>	sk;
	int	K;
	int tmp;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		if (tmp == 0 && !sk.empty())
			sk.pop();
		else
			sk.push(tmp);
	}
	int sum = 0;
	while (!sk.empty()) {
		sum += sk.top();
		sk.pop();
	}
	cout << sum << '\n';
}
