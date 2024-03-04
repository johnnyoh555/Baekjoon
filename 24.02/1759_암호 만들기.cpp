// https://www.acmicpc.net/problem/1759

#include <iostream>
#include <algorithm>

using namespace std;

char letter[16];
char word[16];
int L, C;

void check_print() {
	int v = 0;
	int c = 0;
	for (int i = 0; i < L; i++) {
		if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') v++;
		else c++;
	}
	if (v && c >= 2) {
		for (int i = 0; i < L; i++) {
			cout << word[i];
		}
		cout << '\n';
	}
}

void back(int idx, int s) {
	if (s == L) {
		check_print();
		return ;
	}
	for (int i = idx; i < C; i++) {
		word[s] = letter[i];
		back(i + 1, s + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> letter[i];
	sort(letter, letter + C);
	back(0, 0);
}