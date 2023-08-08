/*
No. 15 프로세서 연결하기
참여자 31 제출 61 배점 100
Problem제출이력정답
시간 : 50개 테스트케이스를 합쳐서 C/C++의 경우 2초 / Java의 경우 4초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

삼성에서 개발한 최신 모바일 프로세서 멕시노스는 가로 N개 x 세로 N개의 cell로 구성되어 있다.



1개의 cell에는 1개의 Core 혹은 1개의 전선이 올 수 있다.


멕시노스의 가장 자리에는 전원이 흐르고 있다.

Core와 전원을 연결하는 전선은 직선으로만 설치가 가능하며,


전선은 절대로 교차해서는 안 된다.

초기 상태로는 아래와 같이 전선을 연결하기 전 상태의 멕시노스 정보가 주어진다.


(멕시노스의 가장자리에 위치한 Core는 이미 전원이 연결된 것으로 간주한다.)






▶ 최대한 많은 Core에 전원을 연결하였을 경우, 전선 길이의 합을 구하고자 한다.

   단, 여러 방법이 있을 경우, 전선 길이의 합이 최소가 되는 값을 구하라.

위 예제의 정답은 12가 된다.



[제약 사항]

1. 7 ≤  N ≤ 12

2. Core의 개수는 최소 1개 이상 12개 이하이다.

3. 최대한 많은 Core에 전원을 연결해도, 전원이 연결되지 않는 Core가 존재할 수 있다.



[입력]

입력의 가장 첫 줄에는 총 테스트 케이스의 개수 T가 주어지며 그 다음 줄부터 각 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 줄에는 N값이 주어지며, 다음 N줄에 걸쳐서 멕시노스의 초기 상태가 N x N 배열로 주어진다.

0은 빈 cell을 의미하며, 1은 core를 의미하고, 그 외의 숫자는 주어지지 않는다.



[출력]

각 테스트 케이스마다 '#X'를 찍고, 한 칸 띄고, 정답을 출력한다.

(X는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

 

입력
3  
7    
0 0 1 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 1 0
0 0 0 0 0 0 0
1 1 0 1 0 0 0
0 1 0 0 0 0 0
0 0 0 0 0 0 0
9  
0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0
0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1
11 
0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1
0 0 0 1 0 0 0 0 1 0 0
0 1 0 1 1 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0

sample_input.txt
출력
#1 12
#2 10 
#3 24 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct s_cores
{
	int				x;
	int				y;
	struct s_cores	*next;
}	t_cores;

int		N;
int		**map;
int		max_core;
int		min_line;
int		count_core;
t_cores	*cores;

// int	count;

void	find_res(t_cores *cur, int cur_core, int cur_line)
{
	int i;

	if (cur == NULL) {
		// printf("res #%d\n", ++count);
		// for (int j = 0; j < N; ++j) {
		// 	for (int k = 0; k < N; ++k) {
		// 		printf("%d ", map[j][k]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		if (max_core == -1) {
			max_core = cur_core;
			min_line = cur_line;
		}
		else if (cur_core == max_core) {
			if (cur_line < min_line)
				min_line = cur_line;
		}
		else if (cur_core > max_core) {
			max_core = cur_core;
			min_line = cur_line;
		}
		return ;
	}

	for (i = 0; i <= cur->x; ++i) {
		if (map[cur->y][i] != 0)
			break ;
	}
	if (i == cur->x) {
		for (int j = 0; j < cur->x; ++j)
			map[cur->y][j] = 2;
		find_res(cur->next, cur_core + 1, cur_line + cur->x);
		for (int j = 0; j < cur->x; ++j)
			map[cur->y][j] = 0;
	}

	for (i = N - 1; i >= cur->x; --i) {
		if (map[cur->y][i] != 0)
			break ;
	}
	if (i == cur->x) {
		for (int j = N - 1; j > cur->x; --j)
			map[cur->y][j] = 2;
		find_res(cur->next, cur_core + 1, cur_line + (N - cur->x - 1));
		for (int j = N - 1; j > cur->x; --j)
			map[cur->y][j] = 0;
	}

	for (i = 0; i <= cur->y; ++i) {
		if (map[i][cur->x] != 0)
			break ;
	}
	if (i == cur->y) {
		for (int j = 0; j < cur->y; ++j)
			map[j][cur->x] = 2;
		find_res(cur->next, cur_core + 1, cur_line + cur->y);
		for (int j = 0; j < cur->y; ++j)
			map[j][cur->x] = 0;
	}

	for (i = N - 1; i >= cur->y; --i) {
		if (map[i][cur->x] != 0)
			break ;
	}
	if (i == cur->y) {
		for (int j = N - 1; j > cur->y; --j)
			map[j][cur->x] = 2;
		find_res(cur->next, cur_core + 1, cur_line + (N - cur->y - 1));
		for (int j = N - 1; j > cur->y; --j)
			map[j][cur->x] = 0;
	}

	find_res(cur->next, cur_core, cur_line);
}

int	main(void)
{
	int		tc;
	t_cores	*temp;

	setbuf(stdout, NULL);
	scanf(" %d", &tc);
	for (int i = 0; i < tc; ++i) {
		max_core = -1;
		min_line = 0;
		count_core = 0;
		cores = (t_cores *)calloc(1, sizeof(t_cores));
		scanf(" %d", &N);
		map = (int **)calloc(N, sizeof(int *));
		for (int j = 0; j < N; ++j) {
			map[j] = (int *)calloc(N, sizeof(int));
			for (int k = 0; k < N; ++k) {
				scanf(" %d", &map[j][k]);
				if (map[j][k] == 1) {
					temp = (t_cores *)calloc(1, sizeof(t_cores));
					temp->x = k;
					temp->y = j;
					temp->next = cores->next;
					cores->next = temp;
					++count_core;
				}
			}
		}
		find_res(cores->next, 0, 0);
		printf("#%d %d\n", i + 1, min_line);
	}
}