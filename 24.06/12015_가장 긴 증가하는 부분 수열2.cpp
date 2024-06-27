// https://www.acmicpc.net/problem/12015
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, arr[1000001];
vector<int> lis;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	lis.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		if (arr[i] > lis[lis.size() - 1]) {
			lis.push_back(arr[i]);
		} else {
			lis[lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin()] = arr[i];
		}
	}
	cout << lis.size() << '\n';
}