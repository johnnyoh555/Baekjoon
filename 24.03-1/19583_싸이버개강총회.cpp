// https://www.acmicpc.net/problem/19583

#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> ins;
unordered_set<string> outs;

string S, E, Q, t, name;
int cnt;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> S >> E >> Q;
	while (cin >> t >> name) {
		if (S.compare(t) >= 0) ins.insert(name);
		if (E.compare(t) <= 0 && Q.compare(t) >= 0) outs.insert(name);
	}
	for (auto i = ins.begin(); i != ins.end(); i++)
		if (outs.find(*i) != outs.end()) cnt++;
	cout << cnt << '\n';
}