/*
뱀
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	64358	26865	17945	39.984%
문제
'Dummy' 라는 도스게임이 있다. 이 게임에는 뱀이 나와서 기어다니는데, 사과를 먹으면 뱀 길이가 늘어난다. 뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.

게임은 NxN 정사각 보드위에서 진행되고, 몇몇 칸에는 사과가 놓여져 있다. 보드의 상하좌우 끝에 벽이 있다. 게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.

뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.

먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.

입력
첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)

다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다. 사과의 위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.

다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)

다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데, 정수 X와 문자 C로 이루어져 있으며. 게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. X는 10,000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.

출력
첫째 줄에 게임이 몇 초에 끝나는지 출력한다.

예제 입력 1 
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
예제 출력 1 
9
예제 입력 2 
10
4
1 2
1 3
1 4
1 5
4
8 D
10 D
11 D
13 L
예제 출력 2 
21
예제 입력 3 
10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L
예제 출력 3 
13
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct s_snake {
	int				x;
	int				y;
	struct s_snake *next;
	struct s_snake *before;
}	t_snake;

t_snake *snake;
t_snake	*tail;
int		**map;
int		**when;
int		idx_w = 0;
int		N;
int		num_a;
int		num_i;

int	run_snake()
{
	int		dir;
	int		x, y;
	t_snake *new;
	t_snake *ptr;

	dir = 0;
	for (int i = 1; 1; ++i) {
		// printf("%d %d %d", i, idx_w < num_i ? when[idx_w][0] : -99, idx_w < num_i ? when[idx_w][1] : -99);
		// printf("  %d %d, %d %d\n", tail->x, tail->y, snake->x, snake->y);
		// for (int i = 0; i < N + 2; ++i) {
		// 	for (int j = 0; j < N + 2; ++j) {
		// 		printf("%d ", map[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		x = snake->x;
		y = snake->y;
		if (dir == 0)
			++x;
		else if (dir == 1)
			++y;
		else if (dir == 2)
			--x;
		else if (dir == 3)
			--y;
		if (map[y][x] == 1 || map[y][x] == 3)
			return (i);
		if (map[y][x] == 2) {
			new = (t_snake *)calloc(1, sizeof(t_snake));
			new->x = x;
			new->y = y;
			new->next = snake;
			snake->before = new;
			snake = new;
			map[y][x] = 3;
		}
		else {
			map[tail->y][tail->x] = 0;
			for (ptr = tail->before; ptr != NULL; ptr = ptr->before) {
				ptr->next->x = ptr->x;
				ptr->next->y = ptr->y;
			}
			snake->x = x;
			snake->y = y;
			map[snake->y][snake->x] = 3;
		}
		// for (ptr = snake; ptr != NULL; ptr = ptr->next)
		// 	printf("%d %d\n", ptr->x, ptr->y);
		if (idx_w < num_i && when[idx_w][0] == i) {
			if (when[idx_w][1] == 1)
				dir = (dir == 3) ? 0 : dir + 1;
			else if (when[idx_w][1] == 2)
				dir = (dir == 0) ? 3 : dir - 1;
			++idx_w;
		}
	}
}

int main(void)
{
	int		x, y;
	int		in1;
	char	in2;

	scanf("%d", &N);
	scanf("%d", &num_a);
	map = (int **)calloc(N + 2, sizeof(int *));
	for (int i = 0; i < N + 2; ++i) {
		map[i] = (int *)calloc(N + 2, sizeof(int));
		for (int j = 0; j < N + 2; ++j) {
			if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
				map[i][j] = 1;
		}
	}
	for (int i = 0; i < num_a; ++i) {
		scanf("%d %d", &x, &y);
		map[x][y] = 2;
	}
	scanf("%d", &num_i);
	when = (int **)calloc(num_i, sizeof(int *));
	for (int i = 0; i < num_i; ++i) {
		when[i] = (int *)calloc(2, sizeof(int));
		scanf("%d %c", &in1, &in2);
		when[i][0] = in1;
		if (in2 == 'D')
			when[i][1] = 1;
		else if (in2 == 'L')
			when[i][1] = 2;
	}
	x = 1;
	y = 1;
	snake = (t_snake *)calloc(1, sizeof(t_snake));
	snake->x = 1;
	snake->y = 1;
	tail = snake;
	map[1][1] = 3;
	printf("%d\n", run_snake());
	return (0);
}