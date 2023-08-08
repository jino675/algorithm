/*
No. 22 기초 Partial Sort 연습
참여자 55 제출 77 배점 100
Problem제출이력정답
시간 : 5개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 1초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다. 

 




MAX 10만명의 User에 대해 수입이 주어진다.
수입이 가장 큰 user 10명의 uID를 수입에 대해 내림차순으로 구하라.
void init ()

각 테스트케이스 처음에 호출되는 초기화 함수이다.

void addUser (int uID, int income)

user을 추가하는 함수이다.

 

Parameters:

uID: user id, 0부터 시작해서 순차적으로 증가한다 (0 ≤ uID < 100000)

income: user의 수입, 클수록 우선순위가 높다. 만약 수입이 동일한 경우 uID가 작은 user의 우선순위가 높다.

int getTop10 (int result[MAX_CANDI])

수입이 가장 큰 user 10명의 uID를 수입에 대해 내림차순으로 구하는 함수이다.

총 user의 수가 10명이 되지 않으면 존재하는 user의 uID를 수입에 대해 내림차순으로 구한다.

result의 개수를 반환한다.

 

Parameters:

result[]: 수입이 큰 순서대로 10개의 uID를 저장한다. (1 ≤ result 개수 ≤ 10)

입력
partial_sort_input.txt
출력
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct s_info
{
	int	id;
	int	income;
}	t_info;

t_info	max_heap[100001];
int		size;

void	my_swap(t_info *a, t_info *b)
{
	t_info	temp;

	temp.id = a->id;
	temp.income = a->income;
	a->id = b->id;
	a->income = b->income;
	b->id = temp.id;
	b->income = temp.income;
}

void	push(int id, int income)
{
	int	cur_idx;
	int	parent_idx;

	cur_idx = size + 1;
	max_heap[cur_idx].id = id;
	max_heap[cur_idx].income = income;
	parent_idx = cur_idx / 2;
	while (1) {
		if (parent_idx < 1)
			break ;
		else {
			if ((max_heap[parent_idx].income < max_heap[cur_idx].income) || \
				(max_heap[parent_idx].income == max_heap[cur_idx].income && \
					max_heap[parent_idx].id > max_heap[cur_idx].id)) {
				my_swap(&max_heap[parent_idx], &max_heap[cur_idx]);
				cur_idx = parent_idx;
				parent_idx = cur_idx / 2;
			}
			else
				break ;
		}
	}
	++size;
}

t_info	pop(void)
{
	t_info	temp;
	int		cur_idx;
	int		next_idx;
	int		child_idx_1;
	int		child_idx_2;

	temp = max_heap[1];
	max_heap[1] = max_heap[size];
	cur_idx = 1;
	child_idx_1 = cur_idx * 2;
	child_idx_2 = cur_idx * 2 + 1;
	while (1) {
		if (child_idx_2 <= size) {
			if ((max_heap[child_idx_1].income > max_heap[child_idx_2].income) || \
				(max_heap[child_idx_1].income == max_heap[child_idx_2].income && \
				max_heap[child_idx_1].id < max_heap[child_idx_2].id))
				next_idx = child_idx_1;
			else
				next_idx = child_idx_2;
		}
		else if (child_idx_1 <= size) {
			next_idx = child_idx_1;
		}
		else
			break ;
		if ((max_heap[next_idx].income > max_heap[cur_idx].income) || \
			(max_heap[next_idx].income == max_heap[cur_idx].income && \
			max_heap[next_idx].id < max_heap[cur_idx].id)) {
			my_swap(&max_heap[next_idx], &max_heap[cur_idx]);
			cur_idx = next_idx;
			child_idx_1 = cur_idx * 2;
			child_idx_2 = cur_idx * 2 + 1;
		}
		else
			break ;
	}
	--size;
	return (temp);
}

// int	idx;

void init()
{
	size = 0;
	// idx = 0;
}

void addUser(int uID, int height) 
{
	// printf("##%d : %d %d\n", ++idx, uID, height);
	push(uID, height);
}

int getTop10(int result[10])
{
	int 	i;
	int		res;
	t_info	top[10];

	// idx = 0;
	for (i = 0; i < 10 && size > 0; ++i) {
		top[i] = pop();
		result[i] = top[i].id;
		// printf("###%d : %d %d\n", ++idx, top[i].id, top[i].income);
	}
	res = i;
	for (i = 0; i < res; ++i) {
		push(top[i].id, top[i].income);
	}
	// idx = 0;
	return (i);
}