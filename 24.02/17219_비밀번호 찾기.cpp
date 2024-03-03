// https://www.acmicpc.net/problem/17219

#include <iostream>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<string, string> m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string addr, pass;
		cin >> addr >> pass;
		m.insert({addr, pass});
	}
	for (int i = 0; i < M; i++) {
		string addr;
		cin >> addr;
		cout << m.at(addr) << '\n';
	}
}