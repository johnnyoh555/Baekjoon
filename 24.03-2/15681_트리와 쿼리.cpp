// https://www.acmicpc.net/problem/15681

#include <iostream>
#include <vector>

using namespace std;

int N, R, Q, U, V, tmp;
vector<int>	arr[100001];
int	dp[100001];
bool	vis[100001];

int dfs(int x) {
	if (dp[x]) return dp[x];
	int sum = 1;
	for (int i = 0; i < arr[x].size(); i++) {
		if (vis[arr[x][i]]) continue;
		vis[arr[x][i]] = 1;
		sum += dfs(arr[x][i]);
	} 
	return dp[x] = sum;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		arr[U].push_back(V);
		arr[V].push_back(U);
	}
	vis[R] = 1;
	dfs(R);
	for (int i = 0; i < Q; i++) {
		cin >> tmp;
		cout << dp[tmp] << '\n';
	}
}