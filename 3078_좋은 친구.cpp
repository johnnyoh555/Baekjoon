// https://www.acmicpc.net/problem/3078


#include <iostream>
#include <queue>
#include <vector>

int	point[21];
long cnt;

struct comp {
	bool operator() (std::pair<int, int> a, std::pair<int, int> b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	}
};

int	main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;
	int	K;

	std::cin >> N >> K;
	
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, comp >	arr;
	std::string				temp;
	std::pair<int, int>		tmp;
	
	for (int i = 0; i < N; i++) {
		std::cin >> temp;
		point[temp.size()]++;
		tmp.first = temp.size();
		tmp.second = i;
		arr.push(tmp);
	}
	for (int i = 2; i < 21; i++) {
		if (point[i] < 2)
			continue;
		std::queue<int>	lens;
		for (int j = 0; j < point[i]; j++) {
			if (lens.empty()) {
				lens.push(arr.top().second);
				arr.pop();
			}
			else if (lens.front() >= arr.top().second - K) {
				cnt += lens.size();
				lens.push(arr.top().second);
				arr.pop();
			}
			else {
				lens.pop();
				j--;
			}
		}
	}
	std::cout << cnt << std::endl;
}


// #include <iostream>
// #include <queue>
// #include <vector>

// int	point[21];
// long cnt;

// int	main(void) {
// 	std::ios::sync_with_stdio(false);
// 	std::cin.tie(nullptr);
// 	int N;
// 	int	K;

// 	std::cin >> N >> K;
	
// 	std::string				arr[N];
	
// 	for (int i = 0; i < N; i++) {
// 		std::cin >> arr[i];
// 	}
	
// 	std::queue<int>		q[21];
// 	for (int i = 0; i < N; i++) {
// 		int len = arr[i].length();
// 		while (q[len].empty() == false && i - q[len].front() > K)
// 			q[len].pop();
// 		cnt += q[len].size();
// 		q[len].push(i);
// 	}
// 	std::cout << cnt << std::endl;
// }