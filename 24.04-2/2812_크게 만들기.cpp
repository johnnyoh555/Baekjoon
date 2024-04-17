// https://www.acmicpc.net/problem/2812
#include <iostream>
using namespace std;
int N, K, cnt;
string str;
string ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K >> str;
	for (int i = 0; i < str.size(); i++) {
		if (ans.empty() || str[i] <= ans.back()) {
			ans.push_back(str[i]);
		} else {
			while (!ans.empty() && ans.back() < str[i] && cnt < K) {
				ans.pop_back(); cnt++;
			}
			ans.push_back(str[i]);
		}
	}
	while (cnt < K) {ans.pop_back(); cnt++;}
	cout << ans << '\n';
}