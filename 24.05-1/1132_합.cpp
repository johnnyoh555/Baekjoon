// https://www.acmicpc.net/problem/1132
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
bool z[26];
int num[26];
string s[50];
pair<long, char> arr[26];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < 26; i++) arr[i].second = 'A' + i;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			if (j == 0) z[s[i][j] - 'A'] = 1;
			arr[s[i][j] - 'A'].first += pow(10, s[i].size() - 1 - j);
		}
	}
	fill(num, num + 26, -1);
	sort(arr, arr + 26, greater<pair<long, char>>());
	for (int i = 0; i < 10; i++) {
		if (!i) {
			for (int j = 0; j < 10; j++)
				if (!z[arr[9 - j].second - 'A']) {num[arr[9 - j].second - 'A'] = i; break;}
		} else {
			for (int j = 0; j < 10; j++)
				if (num[arr[9 - j].second - 'A'] == -1) {num[arr[9 - j].second - 'A'] = i; break;}
		}
	}
	long ans = 0;
	for (int i = 0; i < N; i++) {
		long tmp = 0;
		for (int j = 0; j < s[i].size(); j++) {
			tmp *= 10;
			tmp += num[s[i][j] - 'A'];
		}
		ans += tmp;
	}
	cout << ans << '\n';
}