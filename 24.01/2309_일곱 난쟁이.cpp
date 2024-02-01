
// https://www.acmicpc.net/problem/2309

#include <iostream>
#include <algorithm>

void	sort_arr(int arr[], int i, int j) {
	int	tmp[7];
	int	flag;

	flag = 0;
	for (int k = 0; k < 9; k++) {
		if (k == i || k == j)
			flag++;
		else
			tmp[k - flag] = arr[k];
	}
	std::sort(tmp, tmp + 7);
	for (int k = 0; k < 7; k++) {
		std::cout << tmp[k] << std::endl;
	}
}

int main(void) {
	int	arr[9];
	int	sum;

	sum = 0;
	for (int i = 0; i < 9; i++) {
		std::cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100)
			{
				sort_arr(arr, i, j);
				return 0;
			}
		}
	}
	return 1;
}