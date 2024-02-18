// https://www.acmicpc.net/problem/1822

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A, B;
vector<int> a(500001);
vector<int> b(500001);
vector<int> tmp;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;
	for (int i = 0; i < A; i++) cin >> a[i];
	for (int i = 0; i < B; i++) cin >> b[i];
	sort(a.begin(), a.begin() + A);
	sort(b.begin(), b.begin() + B);
	int k = 0;
	for (int i = 0; i < B; i++) {
		int j = lower_bound(a.begin(), a.begin() + A, b[i]) - a.begin();
		if (a[j] == b[i]) {
			for (int m = k; m < j; m++) tmp.push_back(a[m]);
			k = j + 1;
		}
	}
	for (int m = k; m < A; m++) tmp.push_back(a[m]);
	cout << tmp.size() << '\n';
	for (int i = 0; i < tmp.size(); i++) cout << tmp[i] << ' ';
}