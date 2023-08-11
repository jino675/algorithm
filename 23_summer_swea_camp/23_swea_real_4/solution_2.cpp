// #include <iostream>
// #include <unistd.h>
#include <climits>

#define BUCKET_SIZE 450

using namespace std;

typedef struct s_bucket
{
	int				arr[BUCKET_SIZE];
	int				cnt;
	int				min;
	int				max;
	struct s_bucket	*next;
	struct s_bucket	*prev;
}	t_bucket;

t_bucket	bucket_pool[1000];
int			bucket_pool_cnt;

typedef struct s_list
{
	t_bucket	head;

	void	clear(void) {
		head.next = &head;
		head.prev = &head;
	}
	void	push_back(int val) {
		if (head.prev == &head || head.prev->cnt == BUCKET_SIZE) {
			t_bucket	*new_bucket = &bucket_pool[bucket_pool_cnt++];
			new_bucket->arr[0] = val;
			new_bucket->cnt = 1;
			new_bucket->max = val;
			new_bucket->min = val;
			new_bucket->prev = head.prev;
			new_bucket->next = &head;
			head.prev->next = new_bucket;
			head.prev = new_bucket;
		}
		else {
			t_bucket	*cur_bucket = head.prev;
			cur_bucket->arr[cur_bucket->cnt++] = val;
			if (val > cur_bucket->max)
				cur_bucket->max = val;
			if (val < cur_bucket->min)
				cur_bucket->min = val;
		}
	}
	void	update_min_max(t_bucket *cur_bucket) {
		int	cur_max = -1, cur_min = INT_MAX;
		for (int i = 0; i < cur_bucket->cnt; ++i) {
			if (cur_bucket->arr[i] > cur_max)
				cur_max = cur_bucket->arr[i];
			if (cur_bucket->arr[i] < cur_min)
				cur_min = cur_bucket->arr[i];
		}
		cur_bucket->max = cur_max;
		cur_bucket->min = cur_min;
	}
	void	erase(int from, int to) { //index
		t_bucket	*cur_bucket = head.next;
		int			total_idx = 0, inner_idx, cur_cnt = 0, remove_cnt = to - from;
		while (!(total_idx <= from && from <= total_idx + cur_bucket->cnt - 1)) {
			total_idx += cur_bucket->cnt;
			cur_bucket = cur_bucket->next;
		}	//전체 인덱스 (버켓 내부 첫 원소 기준)
		inner_idx = from - total_idx;	//버켓 내부 인덱스
		while (cur_cnt < remove_cnt) {
			if (inner_idx == 0 && cur_bucket->cnt > remove_cnt - cur_cnt) {
				for (int i = 0; i < cur_bucket->cnt - (remove_cnt - cur_cnt); ++i)
					cur_bucket->arr[i] = cur_bucket->arr[i + (remove_cnt - cur_cnt)];
				cur_bucket->cnt -= remove_cnt - cur_cnt;
				update_min_max(cur_bucket);
				// printf("1\n");
				break ;
			}
			else if (inner_idx != 0 && cur_bucket->cnt - inner_idx > remove_cnt - cur_cnt) {
				for (int i = 0; i < (cur_bucket->cnt - inner_idx) - (remove_cnt - cur_cnt); ++i)
					cur_bucket->arr[inner_idx + i] = \
						cur_bucket->arr[inner_idx + i + (remove_cnt - cur_cnt)];
				cur_bucket->cnt -= remove_cnt - cur_cnt;
				update_min_max(cur_bucket);
				// printf("2\n");
				break ;
			}
			else if (inner_idx == 0 && cur_bucket->cnt <= remove_cnt - cur_cnt) {
				cur_bucket->prev->next = cur_bucket->next;
				cur_bucket->next->prev = cur_bucket->prev;
				cur_cnt += cur_bucket->cnt;
				// printf("3\n");
			}
			else if (inner_idx != 0 && cur_bucket->cnt - inner_idx <= remove_cnt - cur_cnt) {
				cur_cnt += cur_bucket->cnt - inner_idx;
				cur_bucket->cnt -= cur_bucket->cnt - inner_idx;
				inner_idx = 0;
				update_min_max(cur_bucket);
				// printf("4\n");
			}
			cur_bucket = cur_bucket->next;
		}
	}
	int	find_val(int K) { //index
		t_bucket	*cur_bucket = head.prev;
		int			total_idx = 0, inner_idx, cur_max = -1, cur_min = INT_MAX;
		while (!(total_idx <= K && K <= total_idx + cur_bucket->cnt - 1)) {
			total_idx += cur_bucket->cnt;
			if (cur_bucket->max > cur_max)
				cur_max = cur_bucket->max;
			if (cur_bucket->min < cur_min)
				cur_min = cur_bucket->min;
			cur_bucket = cur_bucket->prev;
		}	//전체 인덱스 (버켓 내부 첫 원소 기준)
		inner_idx = K - total_idx;
		for (int i = 0; i <= inner_idx; ++i) {
			if (cur_bucket->arr[cur_bucket->cnt - 1 - i] > cur_max)
				cur_max = cur_bucket->arr[cur_bucket->cnt - 1 - i];
			if (cur_bucket->arr[cur_bucket->cnt - 1 - i] < cur_min)
				cur_min = cur_bucket->arr[cur_bucket->cnt - 1 - i];
		}
		return (cur_max - cur_min);
	}
	// void	print_all(void) {
	// 	t_bucket	*cur_bucket = head.next;
	// 	int	bucket_idx = 0;
	// 	while (cur_bucket != &head) {
	// 		printf("\nbucket #%d (cnt : %d, max : %d, min : %d)\n", bucket_idx++, cur_bucket->cnt, \
	// 		cur_bucket->max, cur_bucket->min);
	// 		for (int i = 0; i < cur_bucket->cnt; ++i)
	// 			printf("%d ", cur_bucket->arr[i]);
	// 		printf("|");
	// 		cur_bucket = cur_bucket->next;
	// 		// sleep(1);
	// 	}
	// 	printf("\n");
	// }
}	t_list;

t_list	num_list;

void	init(int N, int mValue[])
{
	num_list.clear();
	bucket_pool_cnt = 0;
	for (int i = 0; i < N; ++i)
		num_list.push_back(mValue[i]);
	// printf("\n=====init=====");
	// num_list.print_all();
	// printf("\n");
}

void	add(int M, int mValue[])
{
	for (int i = 0; i < M; ++i)
		num_list.push_back(mValue[i]);
	// printf("\n=====add=====");
	// num_list.print_all();
	// printf("\n");
}

void	erase(int mFrom, int mTo)
{
	num_list.erase(mFrom - 1, mTo);
	// printf("\n=====erase=====");
	// num_list.print_all();
	// printf("\n");
}

int	find(int K)
{
	// printf("\n=====find=====");
	// num_list.print_all();
	// printf("my_ret : %d\n\n", num_list.find_val(K - 1));
	return (num_list.find_val(K - 1));
}