/*
No. 12 [Pro] 호텔방문
참여자 36 제출 180 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 1초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
[제한 사항]

 

시간

 25개 테스트케이스를 합쳐서 C++ 의 경우 3초 / Java 의 경우 3초 

메모리

 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내

 

 

  ①   C 또는 C++로 답안을 작성하시는 응시자께서는 검정시스템에 제출 시, Language 에서 C++ 를 선택하신 후 제출하시기 바랍니다.

  ②   Main 과 User Code 부분으로 구성되어 있습니다.

  ㅇ   A.  Main         : 수정할 수 없는 코드이며, 채점 시 비 정상적인 답안 검출 등 평가를 위한 로직이 추가 될 수 있습니다.

  ㅇ   B.  User Code  : 실제 응시자가 작성해야 하는 코드이며, 제출 시에는 표준 입출력 함수가 포함되어 있으면 안 됩니다.

  ③   Local PC 에서 프로그래밍 시 유의 사항

  ㅇ   A.  2개의 파일을 생성하셔야 합니다. ( main.cpp / solution.cpp 또는 Solution.java / UserSolution.java )

  ㅇ   B.  Main 부분의 코드를 main.cpp 또는 Solution.java 에 복사해서 사용하시기 바랍니다.

  ㅇ   C.  sample_input.txt 를 사용하시기 위해서는 Main 부분의 코드 내에

  ㅇ   C.  표준 입력을 파일로 전환하는 코드 ( 주석처리 되어 있음 ) 의 주석을 풀어서 사용하시면 됩니다.

  ㅇ   D.  User Code 부분의 코드를 작성하신 후 서버에 제출하실 때,

  ㅇ   D.  디버깅을 위한 표준 입출력 함수를 모두 삭제 또는 주석 처리해 주셔야 합니다.

  ④   문제 내에 제약조건을 모두 명시하지 않으므로 주어지는 코드를 분석하셔야 합니다.

  ⑤   코드는 개발 언어에 따라 상이할 수 있으므로, 작성할 언어를 기준으로 분석하셔야 합니다.

 

※ 본 문제는 임직원의 S/W 문제해결 역량 향상을 위한 Professional 실전형 연습문제이며

함께 제공되는 Testcase 또한 학습을 위한 연습용입니다.

 
 
[문제 설명]

신도시가 건설되고 있다.
이 도시는 N개의 지역으로 나뉘어져 있고, 각 지역마다 하나의 호텔이 건설된다.
호텔을 운영하는 회사들이 여러 개 존재하며 각각 자체 브랜드를 사용하여 호텔을 운영한다.
이 도시 내 각각의 호텔들은 위 회사들 중 하나에 속하게 된다.
도시는 성장하면서 지역간 도로가 건설되기도 하고, 호텔들을 소유한 회사 간에 합병도 일어난다.
 

호텔을 운영하는 회사들은 호텔 비즈니스를 성장시키기 위해
호텔에서 숙박을 무료로 할 수 있는 경품을 제공하기로 하였다.
경품에는 숙박할 수 있는 호텔의 브랜드 2개가 적혀있다.(브랜드A, 브랜드B)
경품 당첨자가 브랜드A에 속한 호텔들 중 하나와 브랜드B에 속한 호텔들 중 하나를 선택하면,
다음 사항을 무료로 제공한다.
- 선택한 브랜드A인 호텔에서 체크인 후 숙박
- 선택한 브랜드A인 호텔에서 선택된 브랜드B인 호텔로 이동
- 선택된 브랜드B인 호텔에서 숙박 후 체크아웃
 

당신은 경품 당첨자이다. 경품으로 선택할 수 있는 호텔의 브랜드A와 브랜드B가 주어진다.
당첨자가 여행을 위해 필요한 비용은 출발지에서 선택한 브랜드A의 호텔까지 이동하는 비용과
선택한 브랜드B의 호텔에서 출발지로 다시 돌아오는 비용 뿐이다.
이들 비용을 최소로 하는 호텔들을 선택하고 싶다. 이동 비용은 거리에 비례하기 때문에
최소 이동 거리를 구하면 비용을 최소화 시킬 수 있다.

 

7개의 지역이 있는 신도시를 예로 들어보자.
[Fig. 1]은 각 지역 내의 7개의 호텔을 보여준다.
원 안의 수는 호텔의 ID를 의미하고 옆의 사각형 내의 수는 브랜드 ID를 의미한다.
다시 말하면, 0부터 6까지의 호텔이 존재하고, 0번과 6번 호텔은 2번 브랜드, 1번과 4번 호텔은 1번 브랜드가 소유한 호텔 임을 보여준다.



                              [Fig. 1]

 

처음에는 도시 내에 도로가 없지만 점차 도로가 추가된다.
[Fig. 2]는 지역 간에 도로들과 도로의 길이가 추가된 것을 보여준다. 예를 들어, 0번 호텔에서 3번 호텔까지 가는 거리는 5이다.


                               [Fig. 2]

 

3번 호텔이 있는 지역에 사는 사람이 당첨이 되었다.
경품은 3번 브랜드와 2번 브랜드에 해당하는 호텔을 선택하도록 하고 있다.
3번 브랜드에 해당하는 호텔은 2번과 5번 호텔이 있고, 당첨자 위치에서의 최단 거리는 각각 8과 7이다.
2번 브랜드에 해당하는 호텔은 0번과 6번 호텔이며, 당첨자 위치로 돌아가는 최단 거리는 각각 4와 6이다.
따라서 당첨자가 5번 호텔과 0번 호텔을 선택하면 최소 비용으로 여행을 할 수 있으며,
이 때 최단 이동 거리의 합은 7+4=11가 된다.
5번 호텔에서 0번 호텔까지의 이동거리는 멀더라도 비용이 들지 않는다.


                                      [Fig. 3]

 

[Fig. 4]은 2번 브랜드와 1번 브랜드가 합병해서 2번 브랜드가 된 경우를 보여준다.
2번 브랜드가 소유한 호텔은 모두 4개가 된다.


                                   [Fig. 4]

 

이후, 경품에서 지정된 브랜드A와 브랜드B가 모두 2번 브랜드로 동일하게 주어지면
해당 경품의 당첨자가 3번에서 출발하는 경우,
1번 호텔에서 체크인하고 0번 호텔에서 체크 아웃을 했을 때 최소 비용이 들며 거리의 합은 2+4=6이다.
브랜드 2개가 동일하더라도 선택되는 호텔들은 달라야 하며, 가고 오는 경로는 겹칠 수 있다.
[Fig. 5]는 최소 비용이 드는 이동 경로를 보여준다.


                                        [Fig. 5]

 

경품에 선택할 호텔들의 브랜드 2개가 주어졌을 때 최소 비용으로 이동할 수 있는 호텔을 선택할 수 있는 프로그램을 작성하라.

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init(int N, int mBrands[])

각 테스트 케이스의 처음에 호출된다.
N개의 지역에 호텔이 건설되며, 각 호텔의 ID는 0부터 N-1가 부여된다.
그리고, 해당 호텔을 소유한 회사의 브랜드의 ID가 호텔 ID 순서대로 주어진다.
다시 말해 호텔 ID의 i인 경우 이 호텔의 브랜드의 ID는 mBrands[i]가 된다.
브랜드의 ID는 0 ~ 49로 주어진다.
초기에는 지역 간에 연결된 도로가 전혀 없다.

 

Parameters

    N: 지역의 개수 (5 ≤ N ≤ 5,000)
    mBrands[i]: 호텔 ID가 i인 호텔의 브랜드ID (0≤mBrands[i]≤49 , 0≤i≤N-1)

void connect(int mHotelA, int mHotelB, int mDistance)

호텔 mHotelA가 있는 지역과 호텔 mHotelB가 있는 지역을 연결하는 도로를 설치한다.
도로의 길이는 mDistance이다.
두 지역에는 이전에 설치된 도로가 없음을 보장한다.
mHotelA와 mHotelB가 다름을 보장한다.
설치된 도로는 양쪽 방향으로 이동이 모두 가능하다.
 

Parameters

   mHotelA: 도로를 설치하는 지역의 호텔ID (0 ≤ mHotelA ≤ N-1)
   mHotelB: 도로를 설치하는 지역의 호텔ID (0 ≤ mHotelB ≤ N-1)
   mDistance: 도로의 길이 (1 ≤ mDistance ≤ 10)

int merge(int mHotelA, int mHotelB)

호텔 mHotelA가 속한 브랜드의 회사가 호텔 mHotelB가 속한 브랜드의 회사를 흡수 합병한다.
따라서 호텔 mHotelB가 속한 브랜드의 호텔들은 모두 mHotelA가 속한 브랜드로 변경된다.
합병 후, 호텔 mHotelA가 속한 브랜드를 가진 호텔의 개수를 반환한다.

 

mHotelA와 mHotelB가 다름을 보장한다.

mHotelA가 속한 브랜드와 mHotelB가 속한 브랜드가 동일한 경우 합병은 이루어지지 않고
해당 브랜드의 호텔 수만 반환한다.

 

Parameters

   mHotelA: 합병할 브랜드를 가진 호텔ID (0 ≤ mHotelA ≤ N-1)
   mHotelB: 합병될 브랜드를 가진 호텔ID (0 ≤ mHotelB ≤ N-1)
 

Return

   mHotelA가 속한 브랜드를 가진 호텔의 개수

int move(int mStart, int mBrandA, int mBrandB)

경품에 당첨되어 투숙할 브랜드 mBrandA와 mBrandB가 주어진다.
호텔ID가 mStart인 호텔이 위치한 지역에서 당첨자는 출발한다.
 

가장 이동 비용이 적게 드는 해당 브랜드의 호텔들을 찾은 후,
비용을 발생시키는 이동거리의 최소 합을 반환한다.

 

mBrandA와 mBrandB는 동일할 수 있으나, 선택되는 호텔들은 모두 달라야 한다.
선택되는 호텔들의 지역은 mStart가 있는 지역과 달라야 한다.
위에서 언급한 조건들을 만족하지 않아 이동거리의 최소 합을 구할 수 없는 경우는 주어지지 않는다.
 

Parameters

   mStart: 경품 당첨자의 출발할 지역에 있는 호텔ID (0 ≤ mStart ≤ N-1)
   mBrandA: 투숙할 첫번째 호텔 브랜드 (0 ≤ mBrandA ≤ 49)
   mBrandB: 투숙할 두번째 호텔 브랜드 (0 ≤ mBrandB ≤ 49)
 

Return

   비용을 발생시키는 이동거리의 최소 합

 

[예제]

아래에는 테스트케이스 1번을 처음부터 순서대로 보여준다. 

Order

Function

Return

Fig.

1

init(7, {2, 1, 3, 4, 1, 3, 2})

 

Fig. 6 (a)

2

connect(0, 1, 2)

 

 

3

connect(3, 1, 2)

 

 

4

connect(3, 1, 2)

 

 

5

connect(6, 5, 1)

 

 

6

connect(2, 5, 4)

 

 

7

connect(2, 5, 4)

 

 

8

connect(0, 3, 5)

 

Fig. 6 (b)

9

move(3, 3, 2)

7+4=11

Fig. 6 (c)

10

merge(0, 4)

4

Fig. 6 (d)

11

move(3, 2, 2)

2+4=6

Fig. 7 (a)

12

move(2, 5)

2

Fig. 7 (b)

13

move(1, 2, 2)

2+8=10

Fig. 7 (c)

14

connect(4, 3, 1)

 

Fig. 7 (d)

15

move(3, 3, 2)

7+1=8

Fig. 8 (a)

16

merge(2, 6)

6

Fig. 8 (b)

17

move(2, 4, 3)

8+4=12

Fig. 8 (c)

 


                                                            [Fig. 6]

 


                                                       [Fig. 7]

 


                                                     [Fig. 8]

 [제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.
2. 각 테스트 케이스에서 connect() 함수의 호출 횟수는 10,000 이하이다.
3. 각 테스트 케이스에서 merge() 함수의 호출 횟수는 100 이하이다.
4. 각 테스트 케이스에서 move() 함수의 호출 횟수는 1,000 이하이다.
*/
#include <iostream>
#include <climits>


typedef struct s_road
{
	int				hid;
	int				distance;
	struct s_road	*next;
}	t_road;

t_road	road_pool[20000];
int		road_pool_cnt;

typedef struct s_hotel
{
	t_road	head;
	int		min_cost;
	int		is_visited;
	int		bid;

	void	clear(int new_bid) {
		head.next = NULL;
		bid = new_bid;
	}
	void	push(int hid, int distance) {
		t_road	*new_road = &road_pool[road_pool_cnt++];

		new_road->hid = hid;
		new_road->distance = distance;
		new_road->next = head.next;
		head.next = new_road;
	}
	t_road	*begin(void) {
		return (head.next);
	}
	t_road	*end(void) {
		return (NULL);
	}
}	t_hotel;

t_hotel	hotel[5000];
int		hotel_cnt;

typedef struct s_branch
{
	int				hid;
	struct s_branch	*next;
	struct s_branch	*prev;
}	t_branch;

t_branch	branch_pool[5000];
int			branch_pool_cnt;

typedef struct s_brand
{
	t_branch		head;
	int				branch_cnt;

	void	clear(void) {
		head.next = &head;
		head.prev = &head;
		branch_cnt = 0;
	}
	void	push(int hid) {
		t_branch	*new_branch = &branch_pool[branch_pool_cnt++];

		new_branch->hid = hid;
		new_branch->next = head.next;
		new_branch->prev = &head;
		head.next->prev = new_branch;
		head.next = new_branch;
		++branch_cnt;
	}
	t_branch	*begin(void) {
		return (head.next);
	}
	t_branch	*end(void) {
		return (&head);
	}
}	t_brand;

t_brand	brand[50];

typedef struct s_heap
{
	typedef struct s_node
	{
		int	hid;
		int	min_cost;
	}	t_node;

	t_node	heap[10000];
	int		heap_size;

	void	clear(void) {
		heap_size = 0;
	}
	void	swap(t_node *a, t_node *b) {
		t_node	temp;

		temp = *a;
		*a = *b;
		*b = temp;
	}
	void	push(int hid, int min_cost) {
		int	cur_idx, parent_idx;

		++heap_size;
		heap[heap_size] = {hid, min_cost};
		cur_idx = heap_size;
		parent_idx = cur_idx / 2;
		while (true) {
			if (parent_idx == 0)
				return ;
			if (heap[cur_idx].min_cost < heap[parent_idx].min_cost) {
				swap(&heap[cur_idx], &heap[parent_idx]);
				cur_idx = parent_idx;
				parent_idx = cur_idx / 2;
			}
			else
				return ;
		}
	}
	void	pop(void) {
		int	cur_idx, lchild, rchild, next_idx;

		heap[1] = heap[heap_size];
		--heap_size;
		cur_idx = 1;
		lchild = cur_idx * 2;
		rchild = cur_idx * 2 + 1;
		while (true) {
			if (rchild <= heap_size) {
				if (heap[lchild].min_cost < heap[rchild].min_cost)
					next_idx = lchild;
				else
					next_idx = rchild;
			}
			else if (lchild <= heap_size)
				next_idx = lchild;
			else
				return ;
			if (heap[cur_idx].min_cost > heap[next_idx].min_cost) {
				swap(&heap[cur_idx], &heap[next_idx]);
				cur_idx = next_idx;
				lchild = cur_idx * 2;
				rchild = cur_idx * 2 + 1;
			}
			else
				return ;
		}
	}
	int	top(void) {
		return (heap[1].hid);
	}
	bool	isEmpty(void) {
		if (heap_size == 0)
			return (true);
		else
			return (false);
	}
}	t_heap;

t_heap	my_heap;

void init(int N, int mBrands[])
{
	road_pool_cnt = 0;
	branch_pool_cnt = 0;
	hotel_cnt = N;
	for (int i = 0; i < 50; ++i)
		brand[i].clear();
	for (int i = 0; i < N; ++i) {
		hotel[i].clear(mBrands[i]);
		brand[mBrands[i]].push(i);
	}
}

void connect(int mHotelA, int mHotelB, int mDistance)
{
	hotel[mHotelA].push(mHotelB, mDistance);
	hotel[mHotelB].push(mHotelA, mDistance);
}

int merge(int mHotelA, int mHotelB)
{
	int			bid_a = hotel[mHotelA].bid;
	int			bid_b = hotel[mHotelB].bid;
	t_brand		*a = &brand[bid_a];
	t_brand		*b = &brand[bid_b];
	t_branch	*cur_branch = b->begin();

	if (a != b) {
		while (cur_branch != b->end()) {
			hotel[cur_branch->hid].bid = bid_a;
			cur_branch = cur_branch->next;
		}
		a->head.prev->next = b->head.next;
		b->head.next->prev = a->head.prev;
		b->head.prev->next = &a->head;
		a->head.prev = b->head.prev;
		a->branch_cnt += b->branch_cnt;
	}
	return (a->branch_cnt);
}

void	update(int cur_hid)
{
	t_road	*cur_road = hotel[cur_hid].begin();

	while (cur_road != hotel[cur_hid].end()) {
		if (hotel[cur_road->hid].is_visited == 0) {
			if (hotel[cur_road->hid].min_cost > hotel[cur_hid].min_cost + cur_road->distance) {
				hotel[cur_road->hid].min_cost = hotel[cur_hid].min_cost + cur_road->distance;
				my_heap.push(cur_road->hid, hotel[cur_road->hid].min_cost);
			}
		}
		cur_road = cur_road->next;
	}
}

int move(int mStart, int mBrandA, int mBrandB)
{
	int			cur_hid, min_cost_1 = INT_MAX, min_cost_2 = INT_MAX;
	t_branch	*cur_branch;

	for (int i = 0; i < hotel_cnt; ++i) {
		hotel[i].min_cost = INT_MAX;
		hotel[i].is_visited = 0;
	}
	hotel[mStart].min_cost = 0;
	my_heap.clear();
	my_heap.push(mStart, 0);
	while (my_heap.isEmpty() != true) {
		cur_hid = my_heap.top();
		my_heap.pop();
		if (hotel[cur_hid].is_visited == 0) {
			hotel[cur_hid].is_visited = 1;
			if (cur_hid != mStart && hotel[cur_hid].bid == mBrandA && hotel[cur_hid].min_cost < min_cost_1) {
				if (mBrandA == mBrandB)
					min_cost_2 = min_cost_1;
				min_cost_1 = hotel[cur_hid].min_cost;
			}
			else if (cur_hid != mStart && hotel[cur_hid].bid == mBrandB && hotel[cur_hid].min_cost < min_cost_2)
				min_cost_2 = hotel[cur_hid].min_cost;
			if (min_cost_1 != INT_MAX && min_cost_2 != INT_MAX)
				break ;
			update(cur_hid);
		}
	}
    return (min_cost_1 + min_cost_2);
}