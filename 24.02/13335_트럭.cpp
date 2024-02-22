// https://www.acmicpc.net/problem/13335

#include <iostream>
#include <deque>

using namespace std;

deque<short> st;
deque<pair<short, int> > b;
int n, w, L, t, sum;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		st.push_back(tmp);
	}
	while (st.size() || b.size()) {
		if (b.size() && t - b.front().second >= w) {
			sum -= b.front().first;
			b.pop_front();
		}
		if (st.size() && sum + st.front() <= L) {
			b.push_back({st.front(), t});
			sum += st.front();
			st.pop_front();
		}
		t++;
	}
	cout << t << '\n';
}