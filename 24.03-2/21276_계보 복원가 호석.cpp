// https://www.acmicpc.net/problem/21276

#include <iostream>
#include <map>

using namespace std;

map<string, int> m_n; 
map<int, string>  m_i;
string name;
int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name;
		m_n.insert({name, i});
		m_i.insert({i, name});
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> name;
	}
}