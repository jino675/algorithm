#include <unistd.h>
#include <iostream>
#include <climits>
#include <unordered_set>

using namespace std;

template <typename T>
struct t_heap
{
	T 	heap[1000000];
	int	heap_size;

	void	clear(void) {
		heap_size = 0;
	}
	void	swap(T *a, T *b) {
		T	temp;

		temp = *a;
		*a = *b;
		*b = temp;
	}
	void	push(T new_node) {
		int		cur_idx, parent_idx;

		++heap_size;
		heap[heap_size] = new_node;
		cur_idx = heap_size;
		parent_idx = cur_idx / 2;
		while (true) {
			if (parent_idx == 0)
				break ;
			if (heap[cur_idx] > heap[parent_idx]) {
				swap(&heap[cur_idx], &heap[parent_idx]);
				cur_idx = parent_idx;
				parent_idx = cur_idx / 2;
			}
			else
				break ;
		}
	}
	void	pop(void) {
		int	cur_idx, l_child, r_child, next_idx;

		if (heap_size == 0)
			return ;
		heap[1] = heap[heap_size];
		--heap_size;
		cur_idx = 1;
		l_child = cur_idx * 2;
		r_child = cur_idx * 2 + 1;
		while (true) {
			if (r_child <= heap_size) {
				if (heap[l_child] > heap[r_child])
					next_idx = l_child;
				else
					next_idx = r_child;
			}
			else if (l_child <= heap_size)
				next_idx = l_child;
			else
				break ;
			if (heap[cur_idx] < heap[next_idx]) {
				swap(&heap[cur_idx], &heap[next_idx]);
				cur_idx = next_idx;
				l_child = cur_idx * 2;
				r_child = cur_idx * 2 + 1;
			}
			else
				break ;
		}
	}
	T	top(void) {
		return (heap[1]);
	}
	bool	isEmpty(void) {
		if (heap_size == 0)
			return (true);
		else
			return (false);
	}
};

int					N;
int					K;
int					A[10];
t_heap<int>			my_heap;
t_heap<int>			sub_heap;
int					min_cnt;

unordered_set<int>	visited;

void	make_my_heap(int cur_lev, long long cur_val)
{
	long long	mul;

	if (cur_lev == N) {
		my_heap.push(cur_val);
		return ;
	}
	mul = cur_val;
	while (true) {
		make_my_heap(cur_lev + 1, mul);
		mul *= A[cur_lev];
		if (mul > K)
			return ;
	}
}

void	make_sub_heap(int cur_lev, long long cur_val, int ref_val)
{
	long long	mul;

	if (cur_lev == N) {
		sub_heap.push(cur_val);
		visited.insert(cur_val);
		return ;
	}
	mul = cur_val;
	while (true) {
		make_sub_heap(cur_lev + 1, mul, ref_val);
		mul *= A[cur_lev];
		if (ref_val % mul != 0)
			return ;
	}
}

int		is_sub(int leftover, int cur_divisor, int pre_divisor)
{
	if (cur_divisor > leftover)
		return (0);
	if (pre_divisor % cur_divisor != 0)
		return (0);
	return (1);
}

void	find_min(void)
{
	int		leftover, cur_cnt, cur_divisor, pre_divisor, cur_val;

	while (my_heap.isEmpty() != true) {
		cur_val = my_heap.top();
		my_heap.pop();
		auto	iter = visited.find(cur_val);
		if (iter != visited.end())
			continue ;
		leftover = K;
		cur_cnt = 0;
		sub_heap.clear();

		make_sub_heap(0, 1, cur_val);
		pre_divisor = sub_heap.top();
		while (sub_heap.isEmpty() != true) {
			cur_divisor = sub_heap.top();
			sub_heap.pop();
			if (is_sub(leftover, cur_divisor, pre_divisor) == 1) {
				pre_divisor = cur_divisor;
				while (cur_divisor <= leftover) {
					cur_cnt += leftover / cur_divisor;
					leftover = leftover % cur_divisor;
				}
				if (cur_cnt >= min_cnt)
					break ;
				if (leftover == 0) {
					if (cur_cnt < min_cnt)
						min_cnt = cur_cnt;
					break ;
				}
			}
		}
	}
}

int	main(void)
{
	int	tc;

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N;
		for (int j = 0; j < N; ++j)
			cin >> A[j];
		cin >> K;
		min_cnt = INT_MAX;
		my_heap.clear();
		visited.clear();
		make_my_heap(0, 1);
		find_min();
		cout << "#" << i << " " << min_cnt << "\n";
	}
	return (0);
}