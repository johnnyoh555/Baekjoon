// https://www.acmicpc.net/problem/1135
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[51];
int N, a;

int	dfs(int x) {
	int mx = 0;
	vector<int> vv;
	for (int nxt : v[x]) vv.push_back(dfs(nxt));
	sort(vv.begin(), vv.end(), greater<int>());
	for (int i = 0; i < vv.size(); i++)
		if (vv[i] + i > mx) mx = vv[i] + i;
	return mx + 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {cin >> a; if (a != -1) v[a].push_back(i);}
	cout << dfs(0) - 1 << '\n';
}
