// https://www.acmicpc.net/problem/11478

#include <iostream>
#include <unordered_set>

using namespace std;

string	str;
int cnt;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	for (int i = 1; i <= str.size(); i++) {
		unordered_set<string> s;
		for (int j = 0; j < str.size() - i + 1; j++) {
			s.insert(str.substr(j, i));
		}
		cnt += s.size();
	}
	cout << cnt << '\n';
}