// https://www.acmicpc.net/problem/2467

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>

using namespace std;

vector<int> v(100001);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, a, b;
	a = 1e9 + 1;
	b = 1e9 + 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N; i++) {
		vector<int>::iterator tmp = upper_bound(v.begin(), v.begin() + N, v[i] * -1);
		if (&(*tmp) == &v[i]) tmp++;
		if (tmp != v.begin() + N && abs(v[i] + *tmp) < abs(a + b)) {
			a = v[i];
			b = *tmp;
		}
		if (tmp != v.begin() && &(*(tmp - 1)) != &v[i] && abs(v[i] + *(tmp - 1)) < abs(a + b)) {
			a = v[i];
			b = *(tmp - 1);
		}
	}
	cout << a << ' ' << b << '\n';
}

// int main(void) {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	int N, a, b;
// 	a = 1e9 + 1;
// 	b = 1e9 + 1;
// 	cin >> N;
// 	for (int i = 0; i < N; i++) cin >> v[i];
// 	for (int i = 0; i < N; i++) {
// 		vector<int>::iterator tmp = upper_bound(v.begin(), v.begin() + N, v[i] * -1);
// 		if (tmp + 1 < v.begin() + N && &(*(tmp + 1)) != &v[i] && abs(v[i] + *(tmp + 1)) < abs(a + b)) {
// 			a = v[i];
// 			b = *(tmp + 1);
// 		}
// 		if (tmp != v.begin() + N && &(*tmp) != &v[i] && abs(v[i] + *tmp) < abs(a + b)) {
// 			a = v[i];
// 			b = *tmp;
// 		}
// 		if (tmp > v.begin() && &(*(tmp - 1)) != &v[i] && abs(v[i] + *(tmp - 1)) < abs(a + b)) {
// 			a = v[i];
// 			b = *(tmp - 1);
// 		}
// 	}
// 	cout << a << ' ' << b << '\n';
// }