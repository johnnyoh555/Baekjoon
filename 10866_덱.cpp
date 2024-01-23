//https://www.acmicpc.net/problem/10866

#include <iostream>
#include <list>

struct t_lst {
	int		i;
	t_lst	*next;
};

class Deque {
	private:
		int 	size;
		t_lst	*lst;

	public:
		Deque();
		
		void	push_front(const int x);
		void	push_back(const int x);
		void	pop_front(void);
		void	pop_back(void);
		void	getsize(void) const;
		void	empty(void) const;
		void	front(void) const;
		void	back(void) const;
};

Deque::Deque() {
	size = 0;
	lst = 0;
}

void	Deque::push_front(const int x) {
	t_lst *tmp = new t_lst;

	tmp->i = x;
	tmp->next = lst;
	lst = tmp;
	size++;
}

void	Deque::push_back(const int x) {
	t_lst *tmp = new t_lst;
	t_lst *p;

	tmp->i = x;
	tmp->next = 0;
	p = lst;
	if (lst == 0) {
		lst = tmp;
	}
	else {
		while (p->next)
			p = p->next;
		p->next = tmp;
	}
	size++;
}

void	Deque::pop_front(void) {
	t_lst *p;

	if (size == 0) {
		std::cout << "-1" << std::endl;
		return ;
	}
	p = lst;
	lst = lst->next;
	std::cout << p->i << std::endl;
	delete p;
	size--;
}

void	Deque::pop_back(void) {
	t_lst *p;

	if (size == 0) {
		std::cout << "-1" << std::endl;
		return ;
	}
	p = lst;
	if (size == 1) {
		std::cout << lst->i << std::endl;
		delete lst;
		lst = 0;
		size--;
	}
	else {
		for (int i = 1; i < size - 1; i++) {
			p = p->next;
		}
		std::cout << p->next->i << std::endl;
		delete p->next;
		p->next = 0;
		size--;
	}
}

void	Deque::getsize(void) const {
	std::cout << size << std::endl;
}

void	Deque::empty(void) const {
	if (size == 0)
		std::cout << "1" << std::endl;
	else
		std::cout << "0" << std::endl;
}

void	Deque::front(void) const {
	if (size == 0)
		std::cout << "-1" << std::endl;
	else
		std::cout << lst->i << std::endl;
}

void	Deque::back(void) const {
	t_lst *p;

	p = lst;
	if (size == 0)
		std::cout << "-1" << std::endl;
	else {
		while (p->next)
			p = p->next;
		std::cout << p->i << std::endl;
	}
}

int main() {
	Deque		dq;
	std::string	str;
	int			N;
	int			tmp;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		if (str == "push_front") {
			std::cin >> tmp;
			dq.push_front(tmp);
		}
		else if (str == "push_back") {
			std::cin >> tmp;
			dq.push_back(tmp);
		}
		else if (str == "pop_front")
			dq.pop_front();
		else if (str == "pop_back")
			dq.pop_back();
		else if (str == "size")
			dq.getsize();
		else if (str == "empty")
			dq.empty();
		else if (str == "front")
			dq.front();
		else if (str == "back")
			dq.back();
	}
}