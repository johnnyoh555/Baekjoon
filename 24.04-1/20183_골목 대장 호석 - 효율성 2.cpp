// https://www.acmicpc.net/problem/20183
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>
using namespace std;
priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>> > pq;
vector<pair<long, long> > v[100001];
long d[100001];
long arr[100001];
long N, M, A, B, C;
const long INF = 0x3f3f3f3f3f3f3f3f;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> A >> B >> C;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({c, b});
		v[b].push_back({c, a});
	}
	fill(d, d + N + 1, INF);
	fill(arr, arr + N + 1, INF);
	d[A] = 0;
	arr[A] = 0;
	pq.push({d[A], A});
	while (!pq.empty()) {
		pair<long, long> cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (pair<long, long> nxt : v[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			if (d[cur.second] + nxt.first > C) continue;
			if (arr[nxt.second] < max(arr[cur.second], nxt.first)) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			arr[nxt.second] = max(arr[cur.second], nxt.first);
			pq.push({d[nxt.second], nxt.second});
		}
	}
	if (arr[B] == INF) cout << "-1\n";
	else cout << arr[B] << '\n';
}

/*
#define X first
#define Y second
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF_TOTAL = 0x3f3f3f3f3f3f3f3f;
long long total_cost[2][100001];
int max_cost[100001];
vector<pair<int, int>> adj[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, a, b;
  long long c;
  cin >> n >> m >> a >> b >> c;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  {
    priority_queue<tuple<long long, int>, vector<tuple<long long, int>>, greater<tuple<long long, int>> > pq;
    fill(total_cost[0], total_cost[0] + 1 + n, INF_TOTAL);
    total_cost[0][b] = 0;
    pq.push({total_cost[0][b], b});
    while (!pq.empty()) {
      int u; long long w;
      tie(w, u) = pq.top(); pq.pop();
      if (total_cost[0][u] != w) continue;
      for (pair<int, int> nxt : adj[u]) {
        if (total_cost[0][nxt.second] <= w + nxt.first) continue;
        total_cost[0][nxt.second] = w + nxt.first;
        pq.push({total_cost[0][nxt.second], nxt.second});
      }
    }
  }
  if (total_cost[0][a] > c) {cout << "-1\n"; return 0;}
  {
    priority_queue < tuple<int, long long, int>, vector< tuple<int, long long, int>>, greater< tuple<int, long long, int>> > pq;
    fill(total_cost[1], total_cost[1] + 1 + n, INF_TOTAL);
    fill(max_cost, max_cost + 1 + n, INF);
    total_cost[1][a] = 0;
    max_cost[a] = 0;
    pq.push({max_cost[a], total_cost[1][a], a});
    while (!pq.empty()) {
      int mx, u; long long w;
      tie(mx, w, u) = pq.top(); pq.pop();
      if (max_cost[u] != mx) continue;
      for (pair<int, int> nxt : adj[u]) {
        if (max_cost[nxt.Y] < max(mx, nxt.X)) continue;
        if (max_cost[nxt.Y] == max(mx, nxt.X) && total_cost[1][nxt.Y] <= w + nxt.X) continue;
        if (w + nxt.X + total_cost[0][nxt.Y] > c) continue;
        max_cost[nxt.Y] = max(mx, nxt.X);
        total_cost[1][nxt.Y] = w + nxt.X;
        pq.push({max_cost[nxt.Y], w + nxt.X, nxt.Y});
      }
    }
  }
  cout << max_cost[b] << '\n';
}


using namespace std;
using ll = long long;

const int NMX = 100'000;
const int MMX = 500'000;

vector<pair<ll, int>> adj[MMX + 2]; // adj[cur] = {cost, nxt}
ll dist[NMX + 2];

ll lo = 1, hi;
int n, m, st, en; ll c;

bool solve(ll lim) {
  priority_queue < pair<ll, int>,
      vector<pair<ll, int>>,
      greater<pair<ll, int>> > pq;

  memset(dist, 0x3f, sizeof(dist));

  dist[st] = 0;
  pq.push({0, st});
  while(!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if(dist[cur] != co) continue;
    for(auto [d, nxt] : adj[cur]) {
      if(d > lim) continue;
      d += co;
      if(dist[nxt] <= d) continue;
      dist[nxt] = d;
      pq.push({d, nxt});
    }
  }

  if(dist[en] > c) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> st >> en >> c;

  while(m--) {
    int u, v; ll cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
    hi = max(hi, cost);
  }

  while(lo < hi) {
    ll mid = (lo + hi) / 2;
    if(solve(mid)) hi = mid;
    else lo = mid + 1;
  }

  if(solve(lo)) cout << lo;
  else cout << -1;
}
*/
