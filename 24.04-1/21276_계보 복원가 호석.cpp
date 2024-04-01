// https://www.acmicpc.net/problem/21276

#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, x, y;
int id[1001];
string tmp, a, b;
priority_queue<int, vector<int>, greater<int> > ans[1001];
priority_queue<int, vector<int>, greater<int> > q;
vector<string> name;
vector<int> v[1001];
queue<int> g;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {cin >> tmp; name.push_back(tmp);}
	sort(name.begin(), name.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		x = lower_bound(name.begin(), name.end(), a) - name.begin();
		y = lower_bound(name.begin(), name.end(), b) - name.begin();
		id[x]++; v[y].push_back(x);
	}
	for (int i = 0; i < N; i++) if(!id[i]) {g.push(i); q.push(i);}
	cout << g.size() << '\n';
	while (!g.empty()) {cout << name[g.front()] << ' '; g.pop();}
	cout << '\n';
	while (!q.empty()) {
		int cur = q.top(); q.pop();
		for (int nxt : v[cur]) {
			id[nxt]--;
			if (!id[nxt]) {ans[cur].push(nxt); q.push(nxt);}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << name[i] << ' ' << ans[i].size();
		while (!ans[i].empty()) {cout << ' ' << name[ans[i].top()]; ans[i].pop();}
		cout << '\n';
	}
}