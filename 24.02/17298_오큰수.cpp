// https://www.acmicpc.net/problem/17298

#include <iostream>
#include <stack>

using namespace std;

int arr[1000001];
stack<int> out;
stack<int> s;
int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= arr[i]) s.pop();
		if (s.empty())
			out.push(-1);
		else
			out.push(s.top());
		s.push(arr[i]);
	}
	while (!out.empty()) {
		cout << out.top() << ' ';
		out.pop();
	}
	cout << '\n';
}