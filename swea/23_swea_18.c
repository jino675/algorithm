/*
No. 18 [S/W 문제해결 응용] 4일차 - 하나로
참여자 62 제출 101 배점 100
Problem제출이력정답
시간 : 20개 테스트케이스를 합쳐서 C/C++의 경우 10초 / Java의 경우 20초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

당신은 인도네시아 내의 N개의 섬들을 연결하는 교통시스템 설계 프로젝트인 ‘하나로’를 진행하게 되었습니다.

하나로 프로젝트는 천해의 자연을 가진 인도네시아의 각 섬 간 교통이 원활하지 않아 관광 산업의 발전을 저해하는 요소를 줄이고 부가 가치를 창출하고자 진행하는 프로젝트입니다.

본 프로젝트에서는 인도네시아 내의 모든 섬을 해저터널로 연결하는 것을 목표로 합니다.

해저터널은 반드시 두 섬을 선분으로 연결하며, 두 해저 터널이 교차된다 하더라도 물리적으로는 연결되지 않는 것으로 가정합니다.

아래 그림 1과 같은 경우, A섬에서 D섬으로는 연결되었지만 A섬으로부터 B섬, C섬에는 도달 할 수 없기 때문에 연결되지 않은 것입니다.

 


 
다음 두 가지의 경우는 모든 섬이 연결된 것입니다.
 
 

위와 같은 방법을 통해 인도네시아 내의 모든 섬들을 연결해야 하는 프로젝트입니다.

그림 3에서 B와 A처럼 직접적으로 연결된 경우도 있지만, B와 C처럼 여러 섬에 걸쳐 간접적으로 연결된 경우도 있습니다.

다만 인도네시아에서는 해저터널 건설로 인해 파괴되는 자연을 위해 다음과 같은 환경 부담금 정책이 있습니다.

- 환경 부담 세율(E)과 각 해저터널 길이(L)의 제곱의 곱(E * L^2)만큼 지불

총 환경 부담금을 최소로 지불하며, N개의 모든 섬을 연결할 수 있는 교통 시스템을 설계하시오.

64비트 integer 및 double로 처리하지 않을 경우, overflow가 발생할 수 있습니다 (C/C++ 에서 64비트 integer는 long long 으로 선언).

위의 그림 2은 환경 부담금을 최소로 하며 모든 섬을 연결하고 있지만, 그림 3는 그렇지 않음을 알 수 있습니다.

[입력]

가장 첫 줄은 전체 테스트 케이스의 수이다.

각 테스트 케이스의 첫 줄에는 섬의 개수 N이 주어지고 (1≤N≤1,000),

두 번째 줄에는 각 섬들의 정수인 X좌표, 세 번째 줄에는 각 섬들의 정수인 Y좌표가 주어진다 (0≤X≤1,000,000, 0≤Y≤1,000,000).

마지막으로, 해저터널 건설의 환경 부담 세율 실수 E가 주어진다 (0≤E≤1).

[출력]

각 테스트 케이스의 답을 순서대로 출력하며, 각 케이스마다 줄의 시작에 “#C”를 출력하여야 한다. 이때 C는 케이스의 번호이다.

같은 줄에 빈칸을 하나 두고, 주어진 입력에서 모든 섬들을 잇는 최소 환경 부담금을 소수 첫째 자리에서 반올림하여 정수 형태로 출력하라.
입력
10
2
0 0
0 100
1.0
4
0 0 400 400
0 100 0 100
1.0
6
0 0 400 400 1000 2000
0 100 0 100 600 2000
0.3
9
567 5 45674 24 797 29 0 0 0
345352 5464 145346 54764 5875 0 3453 4545 123
0.0005
 

re_sample_input.txt
출력
#1 10000
#2 180000
#3 1125000
#4 27365366
. . .
*/
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

void	push(int cur, int to, double cur_cost);
void	pop(int cur);


typedef struct s_island
{
	int	x;
	int	y;
}	t_island;

typedef struct s_cost
{
	int		to_num;
	double	cost;
}	t_cost;

t_cost		cost[1001][1001];
t_island	island[1001];
int			visited[1001];
int			tc;
int			N;
double		E;
double		res;

void	prim(void)
{
	t_cost	min;
	int		cur_idx;
	int		next_idx;
	int		min_idx;
	int		visited_idx;
	int		is_clear;

	cur_idx = 1;
	visited_idx = 0;
	visited[visited_idx++] = cur_idx;
	for (int i = 0; i < N - 1; ++i) {
		min.cost = DBL_MAX;
		for (int j = 0; j < visited_idx; ++j) {
			cur_idx = visited[j];
			is_clear = 0;
			while (is_clear == 0) {
				for (int k = 0; k < visited_idx; ++k) {
					if (cost[cur_idx][1].to_num == visited[k]) {
						pop(cur_idx);
						break ;
					}
					else if (k == visited_idx - 1)
						is_clear = 1;
				}
			}
			if (cost[cur_idx][1].cost < min.cost) {
				min_idx = cur_idx;
				min = cost[cur_idx][1];
			}
		}
		// printf("min_idx = %d, min_to_num = %d, min_cost = %.0lf\n", min_idx, min.to_num, min.cost);
		// for (int j = 1; j <= N; ++j) {
		// 	printf("%d : ", j);
		// 	for (int k = 1; k < N; ++k) {
		// 		printf("%d, %.0lf ", cost[j][k].to_num, cost[j][k].cost);
		// 	}
		// 	printf("\n\n");
		// }
		
		visited[visited_idx++] = min.to_num;
		res += min.cost;
		pop(min_idx);

	}
}

void	swap_cost(t_cost *a, t_cost *b)
{
	t_cost temp;

	temp.to_num = a->to_num;
	temp.cost = a->cost;
	a->to_num = b->to_num;
	a->cost = b->cost;
	b->to_num = temp.to_num;
	b->cost = temp.cost;
}

void	push(int cur, int to, double cur_cost)
{
	int		new_idx;
	int		parent_idx;

	new_idx = cost[cur][0].to_num + 1;
	cost[cur][new_idx].to_num = to;
	cost[cur][new_idx].cost = cur_cost;
	parent_idx = new_idx / 2;
	while (1) {
		if (parent_idx < 1)
			break ;
		if (cost[cur][parent_idx].cost > cost[cur][new_idx].cost) {
			swap_cost(&cost[cur][parent_idx], &cost[cur][new_idx]);
			new_idx = parent_idx;
			parent_idx = new_idx / 2;
		}
		else
			break ;
	}
	++cost[cur][0].to_num;
}

void	pop(int cur)
{
	int		now_idx;
	int		child_idx_1;
	int		child_idx_2;
	int		next_idx;

	now_idx = cost[cur][0].to_num;
	--cost[cur][0].to_num;
	cost[cur][1].to_num = cost[cur][now_idx].to_num;
	cost[cur][1].cost = cost[cur][now_idx].cost;
	cost[cur][now_idx].to_num = -1;
	cost[cur][now_idx].cost = -1;
	now_idx = 1;
	child_idx_1 = now_idx * 2;
	child_idx_2 = now_idx * 2 + 1;
	while (1) {
		if (child_idx_2 <= cost[cur][0].to_num) {
			if (cost[cur][child_idx_1].cost < cost[cur][child_idx_2].cost)
				next_idx = child_idx_1;
			else
				next_idx = child_idx_2;
		}
		else if (child_idx_1 <= cost[cur][0].to_num) {
			next_idx = child_idx_1;
		}
		else
			break ;
		if (cost[cur][now_idx].cost > cost[cur][next_idx].cost) {
			swap_cost(&cost[cur][now_idx], &cost[cur][next_idx]);
			now_idx = next_idx;
			child_idx_1 = now_idx * 2;
			child_idx_2 = now_idx * 2 + 1;
		}
		else
			break ;
	}
}

// t_cost	top(int cur)
// {
// 	t_cost	top;

// 	if (cost[cur][0].to_num == 0) {
// 		top.to_num = -1;
// 		top.cost = -1;
// 	}
// 	else {
// 		top.to_num = cost[cur][1].to_num;
// 		top.cost = cost[cur][1].cost;
// 	}
// 	return (top);
// }

int	main(void)
{
	double	cur_cost;

	setbuf(stdout, NULL);
	scanf(" %d", &tc);

	for (int i = 0; i < tc; ++i) {
		res = 0;
		for (int j = 1; j <= N; ++j) {
			cost[j][0].to_num = 0;
			visited[j] = -1;
		}
		scanf(" %d", &N);
		for (int j = 1; j <= N; ++j) {
			scanf(" %d", &island[j].x);
		}
		for (int j = 1; j <= N; ++j) {
			scanf(" %d", &island[j].y);
		}
		scanf(" %lf", &E);
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				if (j != k) {
					cur_cost = E * (pow((island[j].x - island[k].x), 2) + \
									pow((island[j].y - island[k].y), 2));
					push(j, k, cur_cost);
				}
			}
		}
		// for (int j = 1; j <= N; ++j) {
		// 	printf("%d : ", j);
		// 	for (int k = 1; k < N; ++k) {
		// 		printf("%d, %.0lf ", cost[j][k].to_num, cost[j][k].cost);
		// 	}
		// 	printf("\n\n");
		// }
		prim();
		printf("#%d %.0lf\n", i + 1, res);
	}
}