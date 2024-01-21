// https://www.acmicpc.net/problem/17509

#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	std::vector<int>	D(11);
	std::vector<int>	V(11);

	for (int i = 0; i < 11; i++) {
		std::cin >> D[i] >> V[i];
	}
	sort(D.begin(), D.end());

	int	sum_d = 0;
	int	sum_v = 0;
	int time = 0;

	for (int i = 0; i < 11; i++) {
		time += D[i];
		sum_d += time;
		sum_v += V[i] * 20;
	}
	std::cout << sum_d + sum_v << std::endl;
}