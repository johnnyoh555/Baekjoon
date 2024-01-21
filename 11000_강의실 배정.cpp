// https://www.acmicpc.net/problem/11000

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>

int main(void) {
	int N;

	scanf("%d", &N);

	std::vector<std::pair<int, int> >	arr(N);
	std::priority_queue<int, std::vector<int>, std::greater<int> > q;

	for (int i = 0; i < N; i++) {
		 scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		q.push(arr[i].second);
		if (arr[i].first >= q.top())
			q.pop();
	}
	printf("%lu\n", q.size());
}