// https://www.acmicpc.net/problem/1339
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int alp[26];
string	str[11];
vector<pair<int, char> > v;
int N, ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		for (int j = 0; j < str[i].size(); j++)
			alp[str[i][j] - 'A'] += pow(10, str[i].size() - 1 - j);
	}
	for (int i = 0; i < 26; i++)
		if (alp[i]) v.push_back({alp[i], i + 'A'});
	sort(v.begin(), v.end(), greater<pair<int, char> >());
	int a = 9;
	for (int i = 0; i < v.size(); i++) alp[v[i].second - 'A'] = a - i;
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 0; j < str[i].size(); j++) {
			tmp *= 10;
			tmp += alp[str[i][j] - 'A'];
		}
		ans += tmp;
	}
	cout << ans << '\n';
}