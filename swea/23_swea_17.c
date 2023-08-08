/*
No. 17 영준이의 진짜 BFS
참여자 27 제출 134 배점 100
Problem제출이력정답
시간 : 61개 테스트케이스를 합쳐서 C/C++의 경우 4초 / Java의 경우 8초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

영준이는 루트가 있는 트리에서 BFS(Breadth First Search)를 하려고 한다.

트리는 1에서 N까지의 번호가 붙은 N개의 노드로 이루어져 있으며, 1이 루트이자 동시에 탐색 시작점이다.

BFS는 큐를 이용하여 탐색을 하는데, 큐의 가장 앞에 있는 노드를 뽑아 탐색을 하고, 탐색을 하는 노드의 자식들을 작은 번호부터 순서대로 큐의 뒤쪽에 넣는 방식으로 탐색이 진행된다.

이것은 컴퓨터에서 실제로 진행되는 방식이 아니고 영준이가 직접 노드를 방문해야 하기 때문에, BFS를 한다면 노드를 방문하는 순서가 정해질 것이고 영준이는 그 순서를 따라 최단거리로 트리를 이동하여 모든 노드를 탐색한다.

영준이는 과연 몇 개의 간선을 지나고 나서야 탐색을 끝 마칠 수 있을까?


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 자연수 N(1 ≤ N ≤ 105)이 주어진다.

두 번째 줄에는 각 노드의 부모정점을 의미하는 N-1개의 자연수가 공백으로 구분되어 주어진다. 1번 노드는 루트이므로 부모가 없어 생략된다.

i-1(2 ≤ i ≤ N)번째로 주어지는 수는 i번 노드의 부모 pi (1 ≤ pi < i)이다. 즉 i번 노드의 부모의 번호는 i보다 작다.


[출력]

각 테스트 케이스마다 ‘#x ’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

직접 BFS를 하였을 때 지나게 되는 총 간선의 개수를 출력한다.


[예제 풀이]

아래 그림은 첫 번째 테스트 케이스에서 각 노드를 BFS로 방문할 때의 이동 거리를 나타낸다.
 


입력
3
4
1 1 2
4
1 1 3
11
1 1 3 3 2 4 1 3 2 9
 

sample_input.txt
출력
#1 6
#2 4
#3 25
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_tree
{
	int				num;
	int				level;
	struct s_tree	*parent;
	struct s_tree	*child;
	struct s_tree	*next;
	struct s_tree	*last_child;
}	t_tree;

// typedef struct s_queue
// {
// 	int				num;
// 	struct s_queue	*next;
// 	struct s_queue	*prev;
// }	t_queue;

int	parent_table[100010][20];
int	parent_table_size;

int	my_queue[100010];
int	top;
int	bottom;
// t_queue	*queue_pool;
// int		queue_count;
t_tree	tree_pool[100010];
t_tree	*root;

int		N;
int		total_distance;

void	push(int num)
{
	my_queue[top] = num;
	++top;
	// t_queue	*temp;

	// temp = (t_queue *)calloc(1, sizeof(t_queue));
	// temp = &queue_pool[++queue_count];
	// temp->num = num;
	// my_queue->next->prev = temp;
	// temp->next = my_queue->next;
	// temp->prev = my_queue;
	// my_queue->next = temp;
}

int	pop(void)
{
	int	res;

	if (bottom == top)
		return (-1);
	res = my_queue[bottom];
	++bottom;
	return (res);
	// t_queue	*temp;

	// temp = my_queue->prev;
	// if (temp == my_queue)
	// 	return (NULL);
	// my_queue->prev = temp->prev;
	// temp->prev->next = my_queue;
	// temp->next = NULL;
	// temp->prev = NULL;
	// return (temp);
}

int	find_nth_ancestor(int level_dif, int cur)
{
	for (int i = 0; level_dif > 0; ++i) {
		if ((level_dif & 1) == 1) {
			cur = parent_table[cur][i];
		}
		level_dif >>= 1;
	}
	return (cur);
}

void	calculate_distance(int cur, int next)
{
	int		level_dif;
	int		max_dif;
	int		mid_dif;
	int		min_dif;
	int		ancestor_cur;
	int		ancestor_next;

	if (tree_pool[next].parent->child != &tree_pool[next]) { // 서로 형제인 경우
		total_distance += 2;
		return ;
	}
	if (tree_pool[cur].level != tree_pool[next].level) { // 사실 최대 레벨 차이가 1이라 큰 의미 없음
		level_dif = tree_pool[next].level - tree_pool[cur].level;
		total_distance += level_dif;
		next = find_nth_ancestor(level_dif, next);
	}
	if (&tree_pool[cur] == &tree_pool[next])	//부모 자식인 경우
		return ;
	max_dif = tree_pool[cur].level;
	min_dif = 1;
	do {	//최종 2개 중에서 중간값은 무조건 낮은 쪽이므로, 최종 미드에서 같거나 바로 위에서 같다.
		mid_dif = (max_dif + min_dif) / 2;
		ancestor_cur = find_nth_ancestor(mid_dif, cur);
		ancestor_next = find_nth_ancestor(mid_dif, next);
		if (ancestor_cur == ancestor_next)
			max_dif = mid_dif;
		else
			min_dif = mid_dif + 1;
	} while (min_dif != max_dif);
	if (ancestor_cur == ancestor_next)
		total_distance += mid_dif * 2;
	else
		total_distance += (mid_dif + 1) * 2;
}
// int temp;

void	bfs(int cur)
{
	t_tree	*ptr;
	// t_queue	*next;
	int		next;

	while (1) {
		for (ptr = tree_pool[cur].child; ptr != NULL; ptr = ptr->next)
			push(ptr->num);
		next = pop();
		if (next == -1)
			return ;
		calculate_distance(cur, next);
		// printf("try #%d : total_distance = %d, cur = %d, next = %d\n", ++temp, total_distance, cur, next);
		// free(next);
		cur = next;
	}
}

void	make_parent_table(void)
{
	int	temp;

	for (int i = 0; i < parent_table_size; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == 0) {
				if (j == 1)
					parent_table[j][i] = 0;
				else
					parent_table[j][i] = tree_pool[j].parent->num;
			}
			else {
				temp = parent_table[j][i - 1];
				if (temp == 0)
					parent_table[j][i] = 0;
				else
					parent_table[j][i] = parent_table[temp][i - 1];
			}
		}
	}
}

int	main(void)
{
	int		tc;
	int		parent_idx;
	int		max_level;
	t_tree	*parent;
	t_tree	*child;
	t_tree	*ptr;

	setbuf(stdout, NULL);
	scanf(" %d", &tc);
	for (int i = 0; i < tc; ++i) {
		scanf(" %d", &N);
		total_distance = 0;
		max_level = 0;
		// my_queue = (int *)calloc(N, sizeof(int));
		top = 0;
		bottom = 0;
		// queue_count = -1;
		// queue_pool = (t_queue *)calloc(N, sizeof(t_queue));
		// my_queue = (t_queue *)calloc(1, sizeof(t_queue));
		// my_queue = &queue_pool[++queue_count];
		// my_queue->next = my_queue;
		// my_queue->prev = my_queue;
		// tree_pool = (t_tree *)calloc(N + 1, sizeof(t_tree));
		root = &tree_pool[1];
		root->num = 1;
		root->level = 0;
		root->child = NULL;
		root->last_child = NULL;
		root->next = NULL;
		root->parent = NULL;
		for (int j = 2; j <= N; ++j) {
			scanf(" %d", &parent_idx);
			child = &tree_pool[j];
			parent = &tree_pool[parent_idx];
			child->num = j;
			child->level = parent->level + 1;
			child->parent = parent;
			child->last_child = NULL;
			child->child = NULL;
			child->next = NULL;
			if (parent->last_child != NULL) {
				parent->last_child->next = child;
				parent->last_child = child;
			}
			else {
				parent->child = child;
				parent->last_child = child;
			}
			if (child->level > max_level)
				++max_level;
			// 시간 잡아먹는 괴물
			// if (parent->child != NULL) {
			// 	ptr = parent->child;
			// 	while (ptr->next != NULL)
			// 		ptr = ptr->next;
			// 	ptr->next = child;
			// }
			// else
			// 	parent->child = child;
		}
		for (parent_table_size = 0; max_level > 0; ++parent_table_size) {
			max_level >>= 1;
		}
		make_parent_table();
		bfs(1);
		printf("#%d %d\n", i + 1, total_distance);
		// free(tree_pool);
		// free(my_queue);
		// free(queue_pool);
	}
	return (0);
}