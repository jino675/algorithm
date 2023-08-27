#include <set>
#include <unordered_map>

using namespace std;

typedef struct s_heap
{
	int	heap[8000];
	int	heap_size;

	void	clear(void) {
		heap_size = 0;
	}
	void	swap(int *a, int *b) {
		int	temp;

		temp = *a;
		*a = *b;
		*b = temp;
	}
	void	push(int val) {
		int	cur_idx, parent_idx;

		++heap_size;
		heap[heap_size] = val;
		cur_idx = heap_size;
		parent_idx = cur_idx / 2;
		while (true) {
			if (parent_idx == 0)
				break ;
			if (heap[cur_idx] < heap[parent_idx]) {
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

		heap[1] = heap[heap_size];
		--heap_size;
		cur_idx = 1;
		l_child = cur_idx * 2;
		r_child = cur_idx * 2 + 1;
		while (true) {
			if (r_child <= heap_size) {
				if (heap[l_child] < heap[r_child])
					next_idx = l_child;
				else
					next_idx = r_child;
			}
			else if (l_child <= heap_size)
				next_idx = l_child;
			else
				break ;
			if (heap[cur_idx] > heap[next_idx]) {
				swap(&heap[cur_idx], &heap[next_idx]);
				cur_idx = next_idx;
				l_child = cur_idx * 2;
				r_child = cur_idx * 2 + 1;
			}
			else
				break ;
		}
	}
	int	top(void) {
		if (isEmpty() != true)
			return (heap[1]);
		else
			return (0);
	}
	bool	isEmpty(void) {
		if (heap_size == 0)
			return (true);
		else
			return (false);
	}
}	t_heap;

typedef struct s_employee
{
	int	id;
	int	start;
	int	end;
	int	is_hired;

	bool	operator()(const struct s_employee *a, const struct s_employee *b) const {
		if (a->start != b->start)
			return (a->start < b->start);
		else if (a->end != b->end)
			return (a->end < b->end);
		else
			return (a->id < b->id);
	}
}	t_employee;

t_employee	employee_pool[8000];
int			employee_pool_cnt;

int	cur_employee_cnt;

set<t_employee *, t_employee>		schedule_list;
unordered_map<int, t_employee *>	id_table;
t_heap	min_heap;

void init()
{
	schedule_list.clear();
	id_table.clear();
	min_heap.clear();
	employee_pool_cnt = 0;
	cur_employee_cnt = 0;
}

int add(int mId, int mStart, int mEnd)
{
	t_employee	*cur_employee;

	auto	iter = id_table.find(mId);
	if (iter != id_table.end()) {
		cur_employee = (*iter).second;
		if (cur_employee->is_hired == 1) {
			schedule_list.erase(cur_employee);
			--cur_employee_cnt;
		}
	}
	else {
		cur_employee = &employee_pool[employee_pool_cnt++];
		cur_employee->id = mId;
		id_table[mId] = cur_employee;
	}
	cur_employee->start = mStart;
	cur_employee->end = mEnd;
	cur_employee->is_hired = 1;
	++cur_employee_cnt;
	schedule_list.insert(cur_employee);
	return (cur_employee_cnt);
}

int remove(int mId)
{
	t_employee	*cur_employee;

	auto	iter = id_table.find(mId);
	if (iter != id_table.end()) {
		cur_employee = (*iter).second;
		if (cur_employee->is_hired == 1) {
			schedule_list.erase(cur_employee);
			cur_employee->is_hired = 0;
			--cur_employee_cnt;
		}
	}
	return (cur_employee_cnt);
}

int announce(int mDuration, int M)
{
	int			cur_M, min_end;
	t_employee	*cur_employee;

	cur_M = 0;
	min_heap.clear();
	auto	iter = schedule_list.begin();
	while (iter != schedule_list.end()) {
		cur_employee = *iter;
		// printf("start : %d, end : %d, need_end : %d", \
					cur_employee->start, cur_employee->end, cur_employee->start + mDuration - 1);
		min_heap.push(cur_employee->end);
		min_end = min_heap.top();
		while (min_heap.isEmpty() != true && min_end - cur_employee->start + 1 < mDuration) {
			min_heap.pop();
			if (cur_M > 0)
				--cur_M;
			min_end = min_heap.top();
		}
		// printf(", min_end : %d", min_end);
		if (min_heap.isEmpty() != true && min_end - cur_employee->start + 1 >= mDuration) {
			++cur_M;
			// printf(", cur_M : %d\n", cur_M);
			if (cur_M == M)
				return (cur_employee->start);
		}
		++iter;
	}
	return (-1);
}