//	https://www.acmicpc.net/problem/10845

#include <iostream>
#include <list>

class Queue {
	private:
		std::list<int>	lst;

	public:
		void	q_push(int x);
		void	q_pop();
		void	q_size();
		void	q_empty();
		void	q_front();
		void	q_back();
};

void	Queue::q_push(int x) {lst.push_back(x);}

void	Queue::q_pop() {
	if (lst.empty()) {
		std::cout << "-1" << std::endl;
		return ;
	}
	std::cout << lst.front() << std::endl;
	lst.pop_front();
}

void	Queue::q_size() {std::cout << lst.size() << std::endl;}

void	Queue::q_empty() {
	if (lst.empty())
		std::cout << "1" << std::endl;
	else
		std::cout << "0" << std::endl;
}

void	Queue::q_front() {
	if (lst.empty())
		std::cout << "-1" << std::endl;
	else
		std::cout << lst.front() << std::endl;
}

void	Queue::q_back() {
	if (lst.empty())
		std::cout << "-1" << std::endl;
	else
		std::cout << lst.back() << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	Queue		q;
	std::string	str;
	int			N;
	int			tmp;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		if (str == "push") {
			std::cin >> tmp;
			q.q_push(tmp);
		}
		else if (str == "pop")
			q.q_pop();
		else if (str == "front")
			q.q_front();
		else if (str == "back")
			q.q_back();
		else if (str == "size")
			q.q_size();
		else if (str == "empty")
			q.q_empty();
	}
}