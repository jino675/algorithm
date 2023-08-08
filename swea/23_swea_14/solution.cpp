/*
No. 14 기초 BFS 연습
참여자 32 제출 34 배점 100
Problem제출이력정답
시간 : 1개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 1초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다. 

 


 

void bfs_init (int map_size, int map[10][10])

행과 열의 크기가 map_size(1 <= map_size <= 10) 인 지도가 주어진다.

지도는 0-base인 배열로 표현되며 map[10][10] 으로 주어진다. 

배열의 각 값들은 0 또는 1이며 '0'은 길을, '1'은 벽을 의미한다.

 

int bfs(int x1, int y1, int x2, int y2)

시작점 x1, y1 좌표가 주어지고 도착점 x2, y2가 주어지면 시작점에서 도착점까지 가는데 최단 거리로 갈 경우 몇 번을 이동하면 되는지 이동 횟수를 계산해서 return해야 한다.

x는 열이고 y는 행임을 주의해야 한다. 그리고 좌상 좌표는 x=1, y=1 이다.

만약 만약 갈 수 있는 방법이 없을 경우 -1을 return해야 한다.

시작점과 도착점이 같은 경우는 없다.

 

입력
10
0 0 0 1 0 0 0 1 1 0
0 1 0 0 0 1 0 0 0 1
0 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0
1 0 1 1 1 1 1 0 1 0
1 0 0 0 1 0 0 0 0 0
1 0 1 0 1 0 1 1 1 1
0 0 1 0 1 0 0 0 0 0
0 1 1 0 1 0 1 1 1 0
0 0 0 0 0 0 1 0 0 0
5
1 10 2 10 1
1 1 10 10 22
10 1 9 2 -1
5 4 6 6 7
9 2 8 10 35	 
bfs_sample_input.txt
출력
#total score : 100
*/
#include <stdlib.h>

typedef struct s_queue
{
	int				x;
	int				y;
	int				level;
	struct s_queue	*next;
	struct s_queue	*prev;
}	t_queue;

t_queue	*my_queue;
int		my_map[11][11];
int		temp_map[11][11];
int		my_size;
int		res;

void	push(int x, int y, int level)
{
	t_queue	*temp;

	temp = (t_queue *)calloc(1, sizeof(t_queue));
	temp->x = x;
	temp->y = y;
	temp->level = level;
	my_queue->next->prev = temp;
	temp->next = my_queue->next;
	temp->prev = my_queue;
	my_queue->next = temp;
}

t_queue	*pop(void)
{
	t_queue	*temp;

	temp = my_queue->prev;
	if (temp == my_queue)
		return (NULL);
	my_queue->prev = temp->prev;
	temp->prev->next = my_queue;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

void bfs_init(int map_size, int map[10][10]) {
	my_size = map_size;
	for (int i = 0; i < my_size; ++i) {
		for (int j = 0; j < my_size; ++j) {
			my_map[i + 1][j + 1] = map[i][j];
		}
	}
	my_queue = (t_queue *)calloc(1, sizeof(t_queue));
	my_queue->next = my_queue;
	my_queue->prev = my_queue;
}

int	run_bfs(int dst_x, int dst_y) {
	t_queue	*cur;

	cur = pop();
	if (cur == NULL)
		return (-1);
	if (cur->x == dst_x && cur->y == dst_y)
		return (cur->level);
	temp_map[cur->y][cur->x] = 1;
	if (cur->x + 1 <= my_size && temp_map[cur->y][cur->x + 1] == 0)
		push(cur->x + 1, cur->y, cur->level + 1);
	if (cur->y + 1 <= my_size && temp_map[cur->y + 1][cur->x] == 0)
		push(cur->x, cur->y + 1, cur->level + 1);
	if (cur->x - 1 >= 1 && temp_map[cur->y][cur->x - 1] == 0)
		push(cur->x - 1, cur->y, cur->level + 1);
	if (cur->y - 1 >= 1 && temp_map[cur->y - 1][cur->x] == 0)
		push(cur->x, cur->y - 1, cur->level + 1);
	free(cur);
	return (run_bfs(dst_x, dst_y));
}

int bfs(int x1, int y1, int x2, int y2) {
	int		res;

	for (int i = 1; i <= my_size; ++i) {
		for (int j = 1; j <= my_size; ++j) {
			temp_map[i][j] = my_map[i][j];
		}
	}
	push(x1, y1, 0);
	res = run_bfs(x2, y2);
	while (my_queue->next != my_queue)
		free(pop());
    return (res);
}