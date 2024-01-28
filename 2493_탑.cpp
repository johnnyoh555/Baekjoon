// https://www.acmicpc.net/problem/2493

#include <iostream>
#include <stack>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	stack<pair<int, int> > sk;
	stack<pair<int, int> > q;
	int	arr[500000] = {0, };

	for (int i = 0; i < N; i++) {
		pair<int, int> tmp;
		cin >> tmp.first;
		tmp.second = i;
		sk.push(tmp);
	}
	while (!sk.empty()) {
		if (q.empty() || sk.top().first < q.top().first) {
			q.push(sk.top());
			sk.pop();
		}
		else if (sk.top().first >= q.top().first) {
			arr[q.top().second] = sk.size();
			q.pop();
		}
	}
	for (int i = 0; i < N; i++) {
		if (i)
			cout << ' ';
		cout << arr[i];
	}
	cout << '\n';
}