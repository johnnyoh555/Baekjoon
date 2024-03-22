// https://www.acmicpc.net/problem/1991 

#include <iostream>

using namespace std;

char tree[27][2];
int N;
char c;

void	postorder(int x) {
	if (tree[x][0] != '.') postorder(tree[x][0] - 'A');
	if (tree[x][1] != '.') postorder(tree[x][1] - 'A');
	cout << (char)('A' + x);
}

void	inorder(int x) {
	if (tree[x][0] != '.') inorder(tree[x][0] - 'A');
	cout << (char)('A' + x);
	if (tree[x][1] != '.') inorder(tree[x][1] - 'A');
}

void	preorder(int x) {
	cout << (char)('A' + x);
	if (tree[x][0] != '.') preorder(tree[x][0] - 'A');
	if (tree[x][1] != '.') preorder(tree[x][1] - 'A');
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c;
		cin >> tree[c - 'A'][0] >> tree[c - 'A'][1];
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
}