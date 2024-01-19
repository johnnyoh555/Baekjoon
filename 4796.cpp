// https://www.acmicpc.net/problem/4796

#include <iostream>
#include <vector>

struct	info {
	int	L;
	int	P;
	int	V;
};

void	greedy(struct info &info, int idx) {
	int	sum;

	sum = 0;
	sum += (info.V / info.P) * info.L;
	info.V = info.V % info.P;
	if (info.V > info.L)
		sum += info.L;
	else
		sum += info.V;
	std::cout << "Case " << idx << ": " << sum << std::endl;
}

int	main(void) {
	std::vector<info>	info;
	struct info			tmp;

	while (true) {
		std::cin >> tmp.L >> tmp.P >> tmp.V;
		if (tmp.L == 0 && tmp.P == 0 && tmp.V == 0)
			break ;
		info.push_back(tmp);
	}
	for(int i = 0; i < info.size(); i++) {
		greedy(info[i], i + 1);
	}
}