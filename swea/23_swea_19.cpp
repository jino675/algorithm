/*
No. 19 [Professional] 고속도로 건설 2
참여자 99 제출 273 배점 100
Problem제출이력정답
시간 : 8개 테스트케이스를 합쳐서 C/C++의 경우 3초 / Java의 경우 5초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


모든 도시를 잇는 고속도로를 건설하려 한다.

그러나 비싼 비용의 문제에 부딪혀, 정부는 최소 비용으로 모든 도시 간을 이동할 수 있게 하고 싶어한다.

또한 하나의 제약이 더 있는데, 언덕 등을 깎지 않는 친환경 건설을 위해 어떤 도시끼리는 직접 도로를 이을 수 없다.

친환경 건설을 위해 이을 수 있는 도로의 목록이 주어질 때, 정부를 도와 모든 도시 간을 잇는 고속도로를 건설하는 최소 비용을 알아내자.


[입력]

첫 줄에 테스트케이스의 개수 T가 주어진다. (1 ≤ T ≤ 8)

각 테스트 케이스의 첫 번째 줄에 도시의 수 N이 주어진다. (2 ≤ N ≤ 50,000)

각 테스트 케이스의 두 번째 줄에 도로 후보의 수 M이 주어진다. (1 ≤ M ≤ 200,000)

각 테스트 케이스의 세 번째 줄부터 M개의 줄에 걸쳐 각 도로 후보의 정보 s, e, c가 주어진다.

s와 e는 도로 후보가 잇는 각 도시의 번호이고, c는 그 도로를 건설하는데 드는 비용이다. (1 ≤ c ≤ 10,000)

항상 모든 도시를 잇는 고속도로를 건설할 수 있는 입력만 주어진다.

[출력]

각 테스트케이스마다 한 줄에 걸쳐, 테스트케이스 수 “#(TC) “를 출력하고, 모든 도시를 잇는 고속도로를 건설하는데 드는 최소 비용을 출력한다.
 

입력
1
5
8
1 2 4
1 3 9
1 4 21
2 3 8
2 4 17
3 4 16
5 2 20
5 4 30	






 
sample_input.txt
출력
#1 48
*/
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

typedef struct s_edge
{
	int	a;
	int	b;
	int	cost;
}	t_edge;

struct cmp
{
	bool	operator()(t_edge *a, t_edge *b) {
		return (a->cost > b->cost);
	}
};

priority_queue<t_edge *, vector<t_edge *>, cmp>	pq;

t_edge	edge[200001];
int		edge_count;
int		table[50001];

int	N;
int	M;

int	total_cost;
int	total_count;

int	find_first(int cur)
{
	if (table[cur] == cur)
		return (cur);
	else {
		table[cur] = find_first(table[cur]);
		return (table[cur]);
	}
}

void	check_and_union(t_edge *cur)
{
	int	p_a;
	int	p_b;

	p_a = find_first(cur->a);
	p_b = find_first(cur->b);
	if (p_a < p_b) {
		table[p_b] = p_a;
		table[cur->b] = p_a;
		total_cost += cur->cost;
		++total_count;
	}
	else if (p_a > p_b) {
		table[p_a] = p_b;
		table[cur->a] = p_b;
		total_cost += cur->cost;
		++total_count;
	}
}

void	Kruskal(void)
{
	t_edge *cur;

	while (pq.empty() != true && total_count < N) {
		cur = pq.top();
		pq.pop();
		check_and_union(cur);
	}
}

int	main(void)
{
	int	tc;
	int	s;
	int	e;
	int	c;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N >> M;
		for (int j = 1; j <= N; ++j)
			table[j] = j;
		for (int j = 1; j <= M; ++j) {
			cin >> s >> e >> c;
			edge[edge_count].a = s;
			edge[edge_count].b = e;
			edge[edge_count].cost = c;
			pq.push(&edge[edge_count]);
			++edge_count;
		}
		Kruskal();
		cout << "#" << i << " " << total_cost << "\n";

		edge_count = 0;
		total_count = 0;
		total_cost = 0;
		pq = priority_queue<t_edge *, vector<t_edge *>, cmp>();
	}
	return (0);
}


// typedef struct s_node
// {
// 	int	city;
// 	int	cost;
// }	t_node;

// struct cmp
// {
// 	bool	operator()(t_node *a, t_node *b) {
// 		return (a->cost > b->cost);
// 	}
// };

// typedef struct s_city
// {
// 	int	is_visited;
// 	priority_queue<t_node *, vector<t_node *>, cmp>	pq;
// }	t_city;


// t_node	node[400001];
// int		node_count;
// t_city	city[50001];
// int		visited[50001];
// int		visited_idx;

// int	N;
// int	M;

// int	total_cost;

// void	prim(void)
// {
// 	t_node	*temp;
// 	int		cur_city;
// 	int		min_cur;
// 	int		min_next;
// 	int		min_cost;
// 	int		is_not_empty;

// 	visited[++visited_idx] = 1;
// 	city[1].is_visited = 1;
// 	for (int i = 2; i <= N; ++i) {
// 		min_cost = INT_MAX;
// 		for (int j = 1; j <= visited_idx; ++j) {
// 			cur_city = visited[j];
// 			is_not_empty = 0;
// 			while (city[cur_city].pq.empty() != true) {
// 				temp = city[cur_city].pq.top();
// 				if (city[temp->city].is_visited == 1)
// 					city[cur_city].pq.pop();
// 				else {
// 					is_not_empty = 1;
// 					break ;
// 				}
// 			}
// 			if (is_not_empty == 1 && temp->cost < min_cost) {
// 				min_cost = temp->cost;
// 				min_next = temp->city;
// 				min_cur = cur_city;
// 			}
// 		}
// 		visited[++visited_idx] = min_next;
// 		city[min_next].is_visited = 1;
// 		total_cost += min_cost;
// 		city[min_cur].pq.pop();
// 	}
// }

// int	main(void)
// {
// 	int	tc;
// 	int	s;
// 	int	e;
// 	int	c;

// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	cin >> tc;
// 	for (int i = 1; i <= tc; ++i) {
// 		cin >> N >> M;
// 		for (int j = 1; j <= M; ++j) {
// 			cin >> s >> e >> c;
// 			++node_count;
// 			node[node_count].city = e;
// 			node[node_count].cost = c;
// 			city[s].pq.push(&node[node_count]);
// 			++node_count;
// 			node[node_count].city = s;
// 			node[node_count].cost = c;
// 			city[e].pq.push(&node[node_count]);
// 		}
// 		prim();
// 		cout << "#" << i << " " << total_cost << "\n";

// 		node_count = 0;
// 		visited_idx = 0;
// 		total_cost = 0;
// 		for (int j = 1; j <= N; ++j) {
// 			city[j].is_visited = 0;
// 			city[j].pq = priority_queue<t_node *, vector<t_node *>, cmp>();
// 		}
// 	}
// 	return (0);
// }