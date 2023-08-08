/*
No. 11 [S/W 문제해결 응용] 3일차 - 공통조상
참여자 31 제출 35 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 10초 / Java의 경우 20초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

이진 트리에서 임의의 두 정점의 가장 가까운 공통 조상을 찾고, 그 정점을 루트로 하는 서브 트리의 크기를 알아내는 프로그램을 작성하라.
 





예를 들어, 위의 이진 트리에서 정점 8과 13의 공통 조상은 정점 3과 1 두 개가 있다.

이 중 8, 13에 가장 가까운 것은 정점 3이고, 정점 3을 루트로 하는 서브 트리의 크기(서브 트리에 포함된 정점의 수)는 8이다.

[입력]

가장 첫 번째 줄에 테스트케이스의 수가 주어진다.

각 케이스의 첫 번째 줄에는 정점의 개수 V(10 ≤ V ≤ 10000)와 간선의 개수 E, 공통 조상을 찾는 두 개의 정점 번호가 주어진다.

각 케이스의 두 번째 줄에는 E개 간선이 나열된다. 간선은 항상 “부모 자식” 순서로 표기된다.

위에서 예로 든 트리에서 정점 5와 8을 잇는 간선은 “5 8”로 표기된다.

정점의 번호는 1부터 V까지의 정수이며, 루트 정점은 항상 1번이다.

[출력]

각 테스트케이스마다 '#t'(t는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 가장 가까운 공통 조상의 번호와 그것을 루트로 하는 서브 트리의 크기를 공백으로 구분하여 출력하라.
입력
10
13 12 8 13
1 2 1 3 2 4 3 5 3 6 4 7 7 12 5 9 5 8 6 10 6 11 11 13
10 9 2 10
1 2 1 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10
...

input.txt
출력
#1 3 8
#2 1 10
...
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct s_tree
{
	int				num;
	int				state;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*pool;
int		pool_idx;
t_tree	*root;
int		tc;
int		V;
int		E;
int		v1, v2;

t_tree	*find_node(t_tree *cur, int num)
{
	t_tree	*res;

	if (cur == NULL)
		return (NULL);
	if (cur->num == num)
		return (cur);
	res = find_node(cur->left, num);
	if (res != NULL)
		return (res);
	res = find_node(cur->right, num);
	if (res != NULL)
		return (res);
	return (NULL);
}

void	add_tree(int idx_1, int idx_2)
{
	t_tree	*parent;
	t_tree	*child;

	parent = &pool[idx_1];
	child = &pool[idx_2];
	child->num = idx_2;
	if (parent->left == NULL)
		parent->left = child;
	else if (parent->right == NULL)
		parent->right = child;
}

int	find_two(t_tree *cur)
{
	if (cur == NULL)
		return (0);
	cur->state += find_two(cur->left);
	cur->state += find_two(cur->right);
	if (cur->num == v1 || cur->num == v2)
		++cur->state;
	return (cur->state);
}

int	find_sub_root(t_tree *cur)
{
	int	res;

	if (cur->left != NULL && cur->left->state == 2)
		res = find_sub_root(cur->left);
	else if (cur->right != NULL && cur->right->state == 2)
		res = find_sub_root(cur->right);
	else
		return (cur->num);
	return (res);
}

int	find_size(t_tree *cur)
{
	int count;

	if (cur == NULL)
		return (0);
	count = 1;
	count += find_size(cur->left);
	count += find_size(cur->right);
	return (count);
}

int	main(void)
{
	int	idx_1;
	int	idx_2;
	int	sub_root_num;
	int	sub_size;

	// freopen("input (4).txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf(" %d", &tc);
	for (int i = 0; i < tc; ++i) {
		scanf(" %d %d %d %d", &V, &E, &v1, &v2);
		pool = (t_tree *)calloc(V + 1, sizeof(t_tree));
		root = &pool[1];
		root->num = 1;
		for (int j = 0; j < E; ++j) {
			scanf(" %d %d", &idx_1, &idx_2);
			add_tree(idx_1, idx_2);
		}
		find_two(root);
		sub_root_num = find_sub_root(root);
		sub_size = find_size(find_node(root, sub_root_num));
		printf("#%d %d %d\n", i + 1, sub_root_num, sub_size);
		free(pool);
	}
}