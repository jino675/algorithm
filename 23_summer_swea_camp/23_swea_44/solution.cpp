/*
No. 44 [Pro] 물류허브
참여자 55 제출 112 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 3초 / Java의 경우 3초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
[제한 사항]

 

시간

 25개 테스트케이스를 합쳐서 C++ 의 경우 3초 / Java 의 경우 3초
메모리

 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
 

 

※ 본 문제는 임직원의 S/W 문제해결 역량 향상을 위한 Professional 실전형 연습문제이며

함께 제공되는 Testcase 또한 학습을 위한 연습용입니다.

 

 

 

  ①   C 또는 C++로 답안을 작성하시는 응시자께서는 검정시스템에 제출 시, Language 에서 C++ 를 선택하신 후 제출하시기 바랍니다.

  ②   Main 과 User Code 부분으로 구성되어 있습니다.

  ㅇ   A.  Main         : 수정할 수 없는 코드이며, 채점 시 비 정상적인 답안 검출 등 평가를 위한 로직이 추가 될 수 있습니다.

  ㅇ   B.  User Code  : 실제 응시자가 작성해야 하는 코드이며, 제출 시에는 표준 입출력 함수가 포함되어 있으면 안 됩니다.

  ③   Local PC 에서 프로그래밍 시 유의 사항

  ㅇ   A.  2개의 파일을 생성하셔야 합니다. ( main.cpp / solution.cpp 또는 Solution.java / UserSolution.java)

  ㅇ   B.  Main 부분의 코드를 main.cpp 또는 Solution.java에 복사해서 사용하시기 바랍니다.

  ㅇ   C.  sample_input.txt 를 사용하시기 위해서는 Main 부분의 코드 내에

  ㅇ   C.  표준 입력을 파일로 전환하는 코드 ( 주석처리 되어 있음 ) 의 주석을 풀어서 사용하시면 됩니다.

  ㅇ   D.  User Code 부분의 코드를 작성하신 후 서버에 제출하실 때,

  ㅇ   D.  디버깅을 위한 표준 입출력 함수를 모두 삭제 또는 주석 처리해 주셔야 합니다.

  ④   문제 내에 제약조건을 모두 명시하지 않으므로 주어지는 코드를 분석하셔야 합니다.

  ⑤   코드는 개발 언어에 따라 상이할 수 있으므로, 작성할 언어를 기준으로 분석하셔야 합니다.

 

 

[문제 설명]

여러 도시를 연결하는 단방향의 도로 N개가 운송 비용과 함께 주어진다.

이 도시 중에서, 한 곳에 물류 허브를 설치했을 때, 총 운송 비용을 계산하고자 한다.

총 운송 비용은 각 도시에서 허브 도시까지 왕복에 필요한 최소 비용을 모두 합한 값이다.

허브 도시의 운송 비용은 0이다. 그리고 도로는 단방향이기 때문에 허브 도시까지 가는 최소 비용과 돌아오는 최소 비용은 다를 수 있다.

예를 들어, [Fig. 1]과 같이 도시와 도로의 정보가 주어진 경우를 살펴 보자.
원 안의 숫자는 도시를 나타내는 번호이고, 화살표는 각 도시를 연결하는 단방향의 도로이고 그 위의 숫자가 운송 비용이다.
5번 도시에 허브를 설치할 경우 각 도시에서 허브 도시까지 왕복에 필요한 최소 비용은 [Fig. 1]의 표와 같다.
따라서, 총 운송 비용은 83 + 102 + 53 + 44 = 282가 된다.



[Fig. 1]

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

int init(int N, int sCity[], int eCity[], int mCost[])

각 테스트 케이스의 처음에 호출된다.

N개의 도로 정보가 주어진다. 각 도로의 출발 도시와 도착 도시, 운송 비용이 주어진다.

도로 정보로 주어지는 도시의 총 개수를 반환한다.

단방향 도로이기 때문에 출발 도시에서 도착 도시로만 갈 수 있다.

출발 도시와 도착 도시의 순서쌍이 동일한 도로는 없다.

출발 도시와 도착 도시가 서로 같은 경우는 없다.

 

Parameters

 N: 도로의 개수 ( 10 ≤ N ≤ 1400 )

 

 (0 ≤ i ＜ N)인 모든 i에 대해,

 sCity[i]: 도로 i의 출발 도시 ( 1 ≤ sCity[i] ≤ 1,000,000,000 )

 eCity[i]: 도로 i의 도착 도시 ( 1 ≤ eCity[i] ≤ 1,000,000,000 )

 mCost[i]: 도로 i의 운송 비용 ( 1 ≤ mCost[i] ≤ 100 )

 

Returns

 도시의 총 개수를 반환한다.

void add(int sCity, int eCity, int mCost)

출발 도시가 sCity이고, 도착 도시가 eCity이고, 운송 비용이 mCost인 도로를 추가한다.

init()에 없던 새로운 도시는 주어지지 않는다.

sCity에서 eCity로 가는 도로가 이미 존재하는 경우는 입력으로 주어지지 않는다.

 

Parameters

 sCity: 도로 i의 출발 도시 ( 1 ≤ sCity ≤ 1,000,000,000 )

 eCity: 도로 i의 도착 도시 ( 1 ≤ eCity ≤ 1,000,000,000 )

 mCost: 도로 i의 운송 비용 ( 1 ≤ mCost ≤ 100 )

int cost(int mHub)

mHub 도시에 물류 허브를 설치할 경우, 총 운송 비용을 계산하여 반환한다.

mHub 도시의 운송 비용은 0으로 계산한다.

각 도시에서 mHub 도시까지 왕복이 불가능한 경우는 입력으로 주어지지 않는다.

 

Parameters

 mHub: 허브를 설치할 도시 ( 1 ≤ mHub ≤ 1,000,000,000 )

 

Returns

 총 운송 비용, 다시 말해 각 도시에서 허브 도시까지 왕복에 필요한 최소 비용을 모두 합한 값을 반환한다.

 

[예제]

아래의 [Table 1]과 같이 요청이 되는 경우를 살펴보자.

Order

Function

return

Figure

1

init(10, {3,1,5,5,3,5,1,4,2,4}, {2,4,3,4,5,2,5,1,3,5}, {46,15,30,31,23,47,35,24,32,13})

5

Fig. 1

2

cost(5)

282

Fig. 1

3

add(5, 1, 24)

 

Fig. 2

4

cost(5)

251

Fig. 2

5

add(2, 1, 11)

 

Fig. 3

6

cost(4)

266

Fig. 3

[Table 1]

(순서 1) 초기에 10개의 도로 정보가 주어진다.
첫 번째 도로는 3번 도시에서 출발해서 2번 도시에 도착할 수 있는 도로이며 운송 비용이 46이다.
[Fig. 1]의 그림과 같이 도시들이 연결된다. 도로 정보로 주어진 도시의 총 개수 5를 반환한다.

(순서 2) 5번 도시에 물류 허브를 설치할 경우에 총 운송 비용을 계산한다.
[Fig. 1]의 표와 같이, 총 운송 비용으로 83 + 102 + 53 + 44 = 282를 반환한다.

(순서 3) 5번 도시에서 출발해서 1번 도시에 도착할 수 있는 도로가 추가된다. 해당 도로의 운송 비용은 24이다.
함수 호출의 결과는 [Fig. 2]의 그림과 같다.

 

[Fig. 2]

(순서 4) 5번 도시에 물류 허브를 설치할 경우에 총 운송 비용을 계산한다.
[Fig. 2]의 표와 같이, 총 운송 비용으로 52 + 102 + 53 + 44 = 251을 반환한다.

(순서 5) 2번 도시에서 출발해서 1번 도시에 도착할 수 있는 도로가 추가된다. 해당 도로의 운송 비용은 11이다.
함수 호출의 결과는 [Fig. 3]의 그림과 같다.

 

[Fig. 3]

(순서 6) 4번 도시에 물류 허브를 설치할 경우에 총 운송 비용을 계산한다.
[Fig. 3]의 표와 같이, 총 운송 비용으로 39 + 86 + 97 + 44 = 266을 반환한다.

 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. 각 테스트 케이스에서 도시의 최대 개수는 600 이하이다.

3. 각 테스트 케이스에서 모든 함수의 호출 횟수 총합은 50 이하이다.

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

Sample input 에 대한 정답 출력 결과는 “#TC번호 결과” 의 포맷으로 보여지며 결과가 100 일 경우 정답, 0 일 경우 오답을 의미한다.
*/
#include <unordered_map>
#include <climits>

using namespace std;

typedef struct s_edge
{
	int				city_idx;
	int				cost;
	struct s_edge	*next;
	struct s_edge	*prev;
}	t_edge;

t_edge	edge_pool[1450];
int		edge_pool_cnt;

typedef struct s_city
{
	t_edge	head;

	void	clear() {
		head.next = &head;
		head.prev = &head;
	}
	void	push_front(int city_idx, int cost) {
		t_edge *new_edge = &edge_pool[edge_pool_cnt++];
		new_edge->city_idx = city_idx;
		new_edge->cost = cost;
		new_edge->prev = &head;
		new_edge->next = head.next;
		head.next->prev = new_edge;
		head.next = new_edge;
	}
	t_edge	*begin(void) {
		return (head.next);
	}
	t_edge	*end(void) {
		return (&head);
	}
}	t_city;

typedef struct s_heap
{
	typedef struct s_node
	{
		int	city_idx;
		int	cost;
	}	t_node;
	t_node	heap[1400];
	int		heap_size;

	void	clear() {
		heap_size = 0;
	}
	void	swap(t_node *a, t_node *b) {
		t_node	temp;

		temp = *a;
		*a = *b;
		*b = temp;
	}
	void	push(int city_idx, int cost) {
		int	cur_idx, parent_idx;

		++heap_size;
		heap[heap_size] = {city_idx, cost};
		cur_idx = heap_size;
		parent_idx = cur_idx / 2;
		while (true) {
			if (parent_idx == 0)
				break ;
			if (heap[cur_idx].cost < heap[parent_idx].cost) {
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
				if (heap[l_child].cost < heap[r_child].cost)
					next_idx = l_child;
				else
					next_idx = r_child;
			}
			else if (l_child <= heap_size)
				next_idx = l_child;
			else
				break ;
			if (heap[cur_idx].cost > heap[next_idx].cost) {
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
		if (heap_size == 0)
			return (-1);
		else
			return (heap[1].city_idx);
	}
	bool	isEmpty(void) {
		return (heap_size == 0);
	}
}	t_heap;

t_city	city[600];
int		city_cnt;
int		city_status;
int		table_status;

int		cost_table[600][600];
t_heap	min_heap;
int		visited[600];

unordered_map<int, int>	city_table;

int	find_idx(int city_ID)
{
	auto	iter = city_table.find(city_ID);
	if (iter == city_table.end()) {
		city_table[city_ID] = city_cnt++;
		return (city_cnt - 1);
	}
	else
		return ((*iter).second);
}

void	update_table(int cur_city, int *cur_table)
{
	int		next_city, next_cost;
	t_edge	*cur_edge;

	cur_edge = city[cur_city].begin();
	while (cur_edge != city[cur_city].end()) {
		next_city = cur_edge->city_idx;
		next_cost = cur_edge->cost;
		if (visited[next_city] == 0) {
			if (cur_table[next_city] > next_cost + cur_table[cur_city]) {
				cur_table[next_city] = next_cost + cur_table[cur_city];
				min_heap.push(next_city, cur_table[next_city]);
			}
		}
		cur_edge = cur_edge->next;
	}
}

void	dijkstra(int start_city, int *cur_table)
{
	int	cur_city;

	for (int i = 0; i < 600; ++i) {
		cur_table[i] = INT_MAX;
		visited[i] = 0;
	}
	cur_table[start_city] = 0;
	min_heap.clear();
	min_heap.push(start_city, 0);
	while (min_heap.isEmpty() != true) {
		cur_city = min_heap.top();
		min_heap.pop();
		if (visited[cur_city] == 0) {
			visited[cur_city] = 1;
			update_table(cur_city, cur_table);
		}
	}
}

int init(int N, int sCity[], int eCity[], int mCost[])
{
	int	s_idx, e_idx;

	city_status = -1;
	table_status = -1;
	edge_pool_cnt = 0;
	city_cnt = 0;
	// city_cnt = 5;
	city_table.clear();
	for (int i = 0; i < 600; ++i)
		city[i].clear();
	for (int i = 0; i < N; ++i) {
		s_idx = find_idx(sCity[i]);
		e_idx = find_idx(eCity[i]);
		// s_idx = sCity[i] - 1;
		// e_idx = eCity[i] - 1;
		city[s_idx].push_front(e_idx, mCost[i]);
	}
	for (int i = 0; i < city_cnt; ++i)
		dijkstra(i, cost_table[i]);


	// printf("===== cost table =====\n");
	// for (int i = 0; i < city_cnt; ++i) {
	// 	printf("%d : ", i + 1);
	// 	for (int j = 0; j < city_cnt; ++j)
	// 		printf("%3d ", cost_table[i][j]);
	// 	printf("\n");
	// }
	// printf("\n");

	return (city_cnt);
}

void add(int sCity, int eCity, int mCost)
{
	int	s_idx, e_idx;

	s_idx = find_idx(sCity);
	e_idx = find_idx(eCity);
	// s_idx = sCity - 1;
	// e_idx = eCity - 1;
	city[s_idx].push_front(e_idx, mCost);
	for (int i = 0; i < city_cnt; ++i) {
		for (int j = 0; j < city_cnt; ++j) {
			if (i == s_idx && j == e_idx) {
				if (cost_table[i][j] > mCost)
					cost_table[i][j] = mCost;
			}
			else if (i == s_idx && j != e_idx) {
				if (cost_table[i][j] > mCost + cost_table[e_idx][j])
					cost_table[i][j] = mCost + cost_table[e_idx][j];
			}
			else if (i != s_idx && j == e_idx) {
				if (cost_table[i][j] > cost_table[i][s_idx] + mCost)
					cost_table[i][j] = cost_table[i][s_idx] + mCost;
			}
			else if (i != s_idx && i != e_idx && j != s_idx && j != e_idx) {
				if (cost_table[i][j] > cost_table[i][s_idx] + mCost + cost_table[e_idx][j])
					cost_table[i][j] = cost_table[i][s_idx] + mCost + cost_table[e_idx][j];
			}
		}
	}
	// printf("===== cost table =====\n");
	// for (int i = 0; i < city_cnt; ++i) {
	// 	printf("%d : ", i + 1);
	// 	for (int j = 0; j < city_cnt; ++j)
	// 		printf("%3d ", cost_table[i][j]);
	// 	printf("\n");
	// }
	// printf("\n");
}

int cost(int mHub)
{
	int	h_idx, total_cost;

	auto	iter = city_table.find(mHub);
	if (iter == city_table.end())
		return (-1);
	else
		h_idx = (*iter).second;
	total_cost = 0;
	for (int i = 0; i < city_cnt; ++i)
		total_cost += cost_table[i][h_idx] + cost_table[h_idx][i];
	return (total_cost);
}