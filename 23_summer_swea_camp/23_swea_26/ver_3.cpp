#include <iostream>
#include <queue>

using namespace std;

int					N;
int					K;
int					A[10];

typedef struct s_node
{
	int x;
	int cnt;

	bool operator() (const struct s_node &a, const struct s_node &b) const{
		if (a.cnt != b.cnt)
			return (a.cnt > b.cnt);
		else
			return (a.x > b.x);
	}
}	t_node;

template <typename T, typename Compare>
struct t_heap
{
	T 		heap[1000000];
	Compare	comp;
	int		heap_size;

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
			if (comp(heap[cur_idx], heap[parent_idx]) == false) {
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
				if (comp(heap[l_child], heap[r_child]) == false)
					next_idx = l_child;
				else
					next_idx = r_child;
			}
			else if (l_child <= heap_size)
				next_idx = l_child;
			else
				break ;
			if (comp(heap[cur_idx], heap[next_idx]) == true) {
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

t_heap<t_node, t_node>	pq;

int	find_min()
{
	t_node 		cur, next;

	pq.clear();
	pq.push({K, 0});
	while (pq.top().x != 0) {
		cur = pq.top();
		pq.pop();
		for (int i = 0; i < N; ++i) {
			next.x = cur.x / A[i];
			next.cnt = cur.cnt + cur.x % A[i];
			pq.push(next);
		}
		pq.push({0, cur.x + cur.cnt});
	}
	return (pq.top().cnt);
}

int	main(void)
{
	int	tc;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N;
		for (int j = 0; j < N; ++j)
			cin >> A[j];
		cin >> K;

		cout << "#" << i << " " << find_min() << "\n";
	}
	return (0);
}