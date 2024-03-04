// https://www.acmicpc.net/problem/6603

#include <iostream>
#include <vector>

using namespace std;

int arr[14];

void back(vector<int>& v, int idx, int s) {
	if (s == 6) {
		for (int i = 0; i < 6; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = idx; i < v.size(); i++) {
		arr[s] = v[i];
		back(v, i + 1, s + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	while (true) {
		cin >> k;
		if (k == 0) break ;
		vector<int> v;
		for (int i = 0; i < k; i++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		back(v, 0, 0);
		cout << '\n';
	}
}