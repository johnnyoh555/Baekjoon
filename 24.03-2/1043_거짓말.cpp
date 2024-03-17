// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>

using  namespace std;

vector<int> v[51];
vector<int>	party[51];
vector<int> arr;
bool t[51];
int N, M, True, cnt;

void dfs(int idx) {
	for (int i = 0; i < v[idx].size(); i++) {
		if (t[v[idx][i]]) continue;
		t[v[idx][i]] = 1;
		dfs(v[idx][i]);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cin >> True;
	for (int i = 0; i < True; i++) {
		int tmp;
		cin >> tmp;
		t[tmp] = 1;
		arr.push_back(tmp);
	}
	for (int i = 0; i < M; i++) {
		int p;
		cin >> p;
		for (int j = 0; j < p; j++) {
			int tmp;
			cin >> tmp;
			party[i].push_back(tmp);
		}
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < p; k++) {
				if (j == k) continue;
				v[party[i][j]].push_back(party[i][k]);
			}
		}
	}
	for (int i = 0; i < arr.size(); i++) dfs(arr[i]);
	for (int i = 0; i < M; i++) {
		bool flag = 0;
		for (int j = 0; j < party[i].size(); j++)
			if (t[party[i][j]]) {flag = 1; break;}
		if (!flag) cnt++;
	}
	cout << cnt << '\n';
}