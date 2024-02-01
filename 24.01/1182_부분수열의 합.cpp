// https://www.acmicpc.net/problem/1182

#include <vector>
#include <iostream>

int cnt;

void	algo(std::vector<int> &arrs, int sum, int idx, int n, int s) {
	if (idx == n)
		return ;
	sum += arrs[idx];
	if (sum == s)
		cnt++;
	algo(arrs, sum, idx + 1, n, s);
	sum -= arrs[idx];
	algo(arrs, sum, idx + 1, n, s);
}

int main(void) {
	int n;
	int s;

	std::cin >> n;
	std::cin >> s;
	int tmp;
	std::vector<int> arrs;

	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		arrs.push_back(tmp);;
	}
	algo(arrs, 0, 0, n, s);
	std::cout << cnt << std::endl;
	return 0;
}