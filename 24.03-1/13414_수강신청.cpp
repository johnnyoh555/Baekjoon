// https://www.acmicpc.net/problem/13414

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int K, L;
unordered_map<string, int> m;
vector<pair<int, string> > v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> L;
	for (int i = 0; i < L; i++) {
		string str;
		cin >> str;
		m[str] = i;		
	}
	for (auto i = m.begin(); i != m.end(); i++) v.push_back({i->second, i->first});
	sort(v.begin(), v.end());
	for (int i = 0; i < K && i < v.size(); i++) cout << v[i].second << '\n';
}