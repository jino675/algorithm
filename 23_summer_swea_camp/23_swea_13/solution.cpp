/*
No. 13 기초 DFS 연습
참여자 31 제출 34 배점 100
Problem제출이력정답
시간 : 50개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 1초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다. 

 




한 나라에 가계도가 있다.

이 나라는 왕위를 계승할 때 장자들 중에서 자기보다 능력이 뛰어난 첫번째 자손에게 왕위를 물려 준다.

각 왕의 능력은 유니크하며 1~99 사이의 값을 가진다.

또한 각 왕들이 가질 수 있는 자식 수는 최대 5명까지이다.

dfs_init()을 통해서 N-1개의 부모자식 관계를 전달 받는다.

첫번째 입력으로 path[0][0]값은 29이고 path[0][1]값이 37이 들어오는데

이것은 능력 29를 가진 왕의 자식이 능력 37을 가지고 있다는 것이다.

이 정보들을 모두 연결하면 tree가 된다.

형제들의 순서는 dfs_init()를 통해서 입력받은 순서이다.

 

다음 예를 보자.

 



 

만약 왕이 10이라면 왕위계승은 7-3-9-16-25-15-8 순으로 검색도중 10보다 큰 첫번째 수가 16이므로 16왕에게 왕위를 계승한다.

다른 예로 왕이 7이라면 3-9-16 순으로 검색하므로 7보다 첫번째 큰 수는 9가 되어 9가 왕위를 계승하게 된다.

그런데 25왕의 경우는 자손이 없으므로 왕위 계승을 할 수 없고 15왕의 경우는 자기보다 큰 능력을 가진 왕이 자손 중에 없으므로 역시 왕위 계승을 할 수 없다.

 

왕위계승을 하지 못하는 경우는 -1을 반환한다.

dfs_init()에 N-1으로 부자 관계 수가 전달되며 i번째 관계는 path[i][0]은 부모, path[i][1]이 자식이 된다.

전달되는 인물 수는 최대 40을 넘지 않는다.

예를 들어 10과 7의 관계일 경우 path[i][0] = 10, paht[i][1] = 7이다.

dfs()를 통해서 k왕의 왕위를 계승받을 자손왕을 반환하라.
 

void dfs_init (int N, int path[100][2])

각 테스트케이스 시작 시 초기화를 위해 1번 호출된다.

 

Parameters

N : 인물 수 (2 ≤ N ≤ 40)
path[][] : 관계도

int dfs(int n)

능력 n을 가지는 인물이 왕이 되었을 경우, 왕위를 계승할 인물의 능력을 반환한다.

왕위를 계승할 인물이 없으면 -1을 반환한다.

 

Parameters

n : 능력 (1 ≤ n ≤ 99)

입력
50
2 1 1406932606
33 69
3 3 1293799192
36 95
61 95
95 -1
4 4 996984527
26 68
68 -1
7 52
52 -1
5 5 1282976734
28 -1
81 -1
87 97
97 -1
30 -1

...	 
dfs_input.txt
출력
#1 : 100
#2 : 100
#3 : 100
#4 : 100

...
*/
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct s_tree
// {
// 	int				num;
// 	int				count;
// 	struct s_tree	**child;
// }	t_tree;

typedef struct s_tree
{
	int	count;
	int	parent;
	int	child[5];
}	t_tree;

t_tree	tree_table[100];
// int		root;

// void	make_children(t_tree *cur)
// {
// 	t_tree	*temp;

// 	for (int i = 1; i <= 99; ++i) {
// 		if (check_table[i] == cur->num) {
// 			temp = (t_tree *)calloc(1, sizeof(t_tree));
// 			temp->num = i;
// 			temp->child = (t_tree **)calloc(5, sizeof(t_tree *));
// 			cur->child[cur->count] = temp;
// 			++cur->count;
// 			make_children(temp);
// 		}
// 	}
// }

void dfs_init(int N, int path[100][2])
{
	int		parent, child;
	int		idx;

	for (int i = 0; i < 100; ++i) {
		tree_table[i].count = 0;
		tree_table[i].parent = 0;
		for (int j = 0; j < 5; ++j)
			tree_table[i].child[j] = 0;
	}
	for (int i = 0; i < N - 1; ++i) {
		parent = path[i][0];
		child = path[i][1];
		// printf("#%d, parent : %d, child : %d\n", i + 1,  parent, child);
		idx = tree_table[parent].count;
		tree_table[parent].child[idx] = child;
		++tree_table[parent].count;
		tree_table[child].parent = parent;
	}
	// for (idx = 1; idx < 100; ++idx) {
	// 	if (tree_table[idx].count != 0 && tree_table[idx].parent == 0)
	// 		break ;
	// }
	// root = idx;
	// parent = check_table[child];
	// while (check_table[parent] != 0)
	// 	parent = check_table[parent];
	// root = (t_tree *)calloc(1, sizeof(t_tree));
	// root->num = parent;
	// root->child = (t_tree **)calloc(5, sizeof(t_tree *));
	// make_children(root);
}

int	run_dfs(int cur, int n)
{
	int	res;

	if (cur > n)
		return (cur);
	for (int i = 0; i < tree_table[cur].count; ++i) {
		res = run_dfs(tree_table[cur].child[i], n);
		if (res != -1)
			return (res);
	}
	return (-1);
}

int dfs(int n)
{
	int		res;

	res = run_dfs(n, n);
	return (res);
}
