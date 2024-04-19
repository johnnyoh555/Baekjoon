// https://www.acmicpc.net/problem/2109
#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> arr[10001];
int p[10001];
int n, ans;

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

bool uf(int x) {
	x = find(x);
	if (x == 0) return false;
	p[x]--;
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i <= 10000; i++) p[i] = i;
	for (int i = 0; i < n; i++) {
		int p, d; cin >> p >> d;
		arr[i] = {p, d};
	}
	sort(arr, arr + n, greater<pair<int, int> >());
	for (int i = 0; i < n; i++)
		if (uf(arr[i].second)) ans += arr[i].first;
	cout << ans << '\n';
}