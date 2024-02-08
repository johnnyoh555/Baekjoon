// https://www.acmicpc.net/problem/2011

#include <iostream>

using namespace std;

int d[5001];
int mod = 1000000;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	std::string str;
	cin >> str;
	if (str[0] == '0') {
		cout << "0\n";
		return 0;
	}
	d[1] = 1;
	if (str[1] != '0')
		d[2]++;
	int tmp = 10 * (str[0] - '0') + str[1] - '0';
	if (10 <= tmp && tmp <= 26)
		d[2]++;
	if (!d[2]) {
		cout << "0\n";
		return 0;
	}
	for (int i = 3; i <= str.size(); i++){
		if (str[i - 1] != '0')
			d[i] = (d[i] + d[i - 1]) % mod;
		int t = 10 * (str[i - 2] - '0') + str[i - 1] - '0';
		if (t >= 10 && t <= 26) {
			d[i] = (d[i] + d[i - 2]) % mod; 
		}
		if (!d[i]) {
			cout << "0\n";
			return 0;
		}
	}
	cout << d[str.size()] << '\n';
}
