// https://www.acmicpc.net/problem/2262
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans;
vector<int> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {int tmp; cin >> tmp; v.push_back(tmp);}
	while (n > 1) {
		int idx = find(v.begin(), v.end(), n) - v.begin();
		int b = 2e9, c = 2e9;
		if (idx != 0) b = v[idx] - v[idx - 1];
		if (idx != v.size() - 1) c = v[idx] - v[idx + 1];
		ans += min(b, c);
		v.erase(v.begin() + idx);
		n--;
	}
	cout << ans << '\n';
}