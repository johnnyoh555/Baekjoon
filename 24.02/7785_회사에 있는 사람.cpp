// https://www.acmicpc.net/problem/7785

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

unordered_set<string> s;
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp, name;
		cin >> name >> tmp;
		if (tmp == "enter") s.insert(name);
		else if (tmp == "leave") s.erase(name);
	}
	vector<string> v(s.begin(), s.end());
	sort(v.begin(), v.end(), greater<string>());
	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
}