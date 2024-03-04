// https://www.acmicpc.net/problem/16165

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string> > mem_name;
unordered_map<string, string> team_name;
int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		string team;
		cin >> team;
		int x;
		cin >> x;
		vector<string> v(x);
		for (int j = 0; j < x; j++) {
			cin >> v[j];
			team_name.insert({v[j], team});
		}
		sort(v.begin(), v.end());
		mem_name.insert({team, v});
	}
	for (int i = 0; i < M; i++) {
		string tmp;
		int x;
		cin >> tmp >> x;
		if (x) {
			cout << team_name.at(tmp) << '\n';
		} else {
			auto a = mem_name.at(tmp);
			for (int j = 0; j < a.size(); j++) {
				cout << a[j] << '\n';
			}
		}
	}
}