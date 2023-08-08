/*
No. 16 파핑파핑 지뢰찾기
참여자 33 제출 48 배점 100
Problem제출이력정답
시간 : 20개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

‘파핑 파핑 지뢰 찾기’라는 유명한 게임이 있다. 이 게임은 RXC 크기의 표를 이용하는 게임인데,

표의 각 칸에는 지뢰가 있을 수도 있고 없을 수도 있다.

표의 각 칸을 클릭했을 때, 그 칸이 지뢰가 있는 칸이라면 ‘파핑 파핑!’이라는 소리와 함께 게임은 끝난다.

지뢰가 없는 칸이라면 변이 맞닿아 있거나 꼭지점이 맞닿아 있는 최대 8칸에 대해 몇 개의 지뢰가 있는지가 0에서 8사이의 숫자로 클릭한 칸에 표시된다.

만약 이 숫자가 0이라면 근처의 8방향에 지뢰가 없다는 것이 확정된 것이기 때문에 그 8방향의 칸도 자동으로 숫자를 표시해 준다.

실제 게임에서는 어떤 위치에 지뢰가 있는지 알 수 없지만, 이 문제에서는 특별히 알 수 있다고 하자.

지뢰를 ‘*’로, 지뢰가 없는 칸을 ‘.’로, 클릭한 지뢰가 없는 칸을 ‘c’로 나타냈을 때 표가 어떻게 변화되는지 나타낸다.
 



세 번째 예에서는 0으로 표시 될 칸들과 이와 인접한 칸들이 한 번의 클릭에 연쇄적으로 숫자가 표시된 것을 볼 수 있다.

파핑 파핑 지뢰 찾기를 할 때 표의 크기와 표가 주어질 때, 지뢰가 있는 칸을 제외한 다른 모든 칸의 숫자들이 표시되려면 최소 몇 번의 클릭을 해야 하는지 구하는 프로그램을 작성하라.


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에 하나의 정수 N(1 ≤ N ≤ 300) 이 주어진다. 이는 지뢰 찾기를 하는 표의 크기가 N*N임을 나타낸다.

다음 N개의 줄의 i번째 줄에는 길이가 N인 문자열이 주어진다.

이 중 j번째 문자는 표에서 i번째 행 j번째 열에 있는 칸이 지뢰가 있는 칸인지 아닌지를 나타낸다.

‘*’이면 지뢰가 있다는 뜻이고, ‘.’이면 지뢰가 없다는 뜻이다. ‘*’와 ‘.’외의 다른 문자는 입력으로 주어지지 않는다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

최소 몇 번의 클릭을 해야 지뢰가 없는 모든 칸에 숫자가 표시될 것인지 출력한다.
입력
2
3
..*
..*
**.
5
..*..
..*..
.*..*
.*...
.*...
 

input.txt
출력
#1 2
#2 8
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct s_zero
{
	int				x;
	int				y;
	struct s_zero	*next;
	struct s_zero	*prev;
}	t_zero;

typedef struct s_map
{
	char			key;
	struct s_zero	*zero;
}	t_map;

void	click_zeros(t_zero *cur, int is_serial);

t_map	**map;
int		N;
int		count_click;
t_zero	*zeros;

int	sub_find_num(int y, int x)
{
	if (x >= 0 && y >= 0 && x <= N - 1 && y <= N - 1)
		if (map[y][x].key == '*')
			return (1);
	return (0);
}

void	find_num(int x, int y)
{
	int		count_bomb;
	t_zero	*temp;

	count_bomb = 0;
	count_bomb += sub_find_num(y - 1, x - 1);
	count_bomb += sub_find_num(y - 1, x);
	count_bomb += sub_find_num(y - 1, x + 1);
	count_bomb += sub_find_num(y, x + 1);
	count_bomb += sub_find_num(y + 1, x + 1);
	count_bomb += sub_find_num(y + 1, x);
	count_bomb += sub_find_num(y + 1, x - 1);
	count_bomb += sub_find_num(y, x - 1);
	map[y][x].key = count_bomb + '0';
	if (map[y][x].key == '0') {
		temp = (t_zero *)calloc(1, sizeof(t_zero));
		temp->x = x;
		temp->y = y;
		if (zeros->next != NULL)
			zeros->next->prev = temp;
		temp->next = zeros->next;
		temp->prev = zeros;
		zeros->next = temp;
		map[y][x].zero = temp;
	}
	++count_click;
}

void	sub_click_zeros(t_zero *cur, int y, int x)
{
	if (x >= 0 && y >= 0 && x <= N - 1 && y <= N - 1) {
		if (map[y][x].key >= '0' && map[y][x].key <= '8') {
			if (map[y][x].key == '0') {
				click_zeros(map[y][x].zero, 1);
				return ;
			}
			map[y][x].key = '!';
			--count_click;
			// printf("cur_count : %d, x : %d, y : %d\n", count_click, x, y);
			// for (int j = 0; j < N; ++j) {
			// 	for (int k = 0; k < N; ++k) {
			// 		printf("%c ", map[j][k]);
			// 	}
			// 	printf("\n");
			// }
		}
	}
}

void	click_zeros(t_zero *cur, int is_serial)
{
	if (cur == NULL)
		return ;
	// if (map[cur->y][cur->x].key == '!') {
	// 	click_zeros(cur->next, 0);
	// 	return ;
	// }
	map[cur->y][cur->x].key = '!';
	// printf("cur_count : %d, x : %d, y : %d\n", count_click, cur->x, cur->y);
	// for (int j = 0; j < N; ++j) {
	// 	for (int k = 0; k < N; ++k) {
	// 		printf("%c ", map[j][k]);
	// 	}
	// 	printf("\n");
	// }
	sub_click_zeros(cur, cur->y - 1, cur->x - 1);
	sub_click_zeros(cur, cur->y - 1, cur->x);
	sub_click_zeros(cur, cur->y - 1, cur->x + 1);
	sub_click_zeros(cur, cur->y, cur->x + 1);
	sub_click_zeros(cur, cur->y + 1, cur->x + 1);
	sub_click_zeros(cur, cur->y + 1, cur->x);
	sub_click_zeros(cur, cur->y + 1, cur->x - 1);
	sub_click_zeros(cur, cur->y, cur->x - 1);
	if (is_serial == 1) {
		--count_click;
		if (cur->next != NULL)
			cur->next->prev = cur->prev;
		if (cur->prev != NULL)
			cur->prev->next = cur->next;
		free(cur);
		return ;
	}
	click_zeros(cur->next, 0);
}

int	main(void)
{
	int	tc;

	setbuf(stdout, NULL);
	scanf(" %d", &tc);
	for (int i = 0; i < tc; ++i) {
		count_click = 0;
		zeros = (t_zero *)calloc(1, sizeof(t_zero));
		scanf(" %d", &N);
		map = (t_map **)calloc(N, sizeof(t_map *));
		for (int j = 0; j < N; ++j) {
			map[j] = (t_map *)calloc(N, sizeof(t_map));
			for (int k = 0; k < N; ++k) {
				scanf(" %c", &map[j][k].key);
			}
		}
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (map[j][k].key == '.')
					find_num(k, j);
			}
		}
		// printf("cur_count : %d\n", count_click);
		// for (int j = 0; j < N; ++j) {
		// 	for (int k = 0; k < N; ++k) {
		// 		printf("%c ", map[j][k]);
		// 	}
		// 	printf("\n");
		// }
		click_zeros(zeros->next, 0);
		printf("#%d %d\n", i + 1,  count_click);
	}
	return (0);
}

// ..*..
// ..*..
// .*..*
// .*...
// .*...


	// if (x > 0 && y > 0 && map[y - 1][x - 1] == '*')
	// 	++count_bomb;
	// if (y > 0 && map[y - 1][x] == '*')
	// 	++count_bomb;
	// if (y > 0 && x < N - 1 && map[y - 1][x + 1] == '*')
	// 	++count_bomb;
	// if (x < N - 1 && map[y][x + 1] == '*')
	// 	++count_bomb;
	// if (x < N - 1 && y < N - 1 && map[y + 1][x + 1] == '*')
	// 	++count_bomb;
	// if (y < N - 1 && map[y + 1][x] == '*')
	// 	++count_bomb;
	// if (x > 0 && y < N - 1 && map[y + 1][x - 1] == '*')
	// 	++count_bomb;
	// if (x > 0 && map[y][x - 1] == '*')
	// 	++count_bomb;


	// if (cur->x > 0 && cur->y > 0 && (map[cur->y - 1][cur->x - 1] >= '0' ||\
	// 								map[cur->y - 1][cur->x - 1] <= '8')) {
	// 	if (map[cur->y - 1][cur->x - 1] == '0')
	// 		click_zeros(cur->next);
	// 	map[cur->y - 1][cur->x - 1] = '!';
	// 	--count_click;
	// }
	// if (cur->y > 0 && (map[cur->y - 1][cur->x] >= '0' ||\
	// 					map[cur->y - 1][cur->x] <= '8')) {
	// 	if (map[cur->y - 1][cur->x] == '0')
	// 		click_zeros(cur->next);
	// 	map[cur->y - 1][cur->x] = '!';
	// 	--count_click;
	// }
	// if (cur->y > 0 && cur->x < N - 1 && (map[cur->y - 1][cur->x + 1] >= '0' ||\
	// 									map[cur->y - 1][cur->x + 1] <= '8')) {
	// 	if (map[cur->y - 1][cur->x + 1] == '0')
	// 		click_zeros(cur->next);
	// 	map[cur->y - 1][cur->x + 1] = '!';
	// 	--count_click;
	// }
	// if (cur->x < N - 1 && (map[cur->y][cur->x + 1] >= '0' ||\
	// 						map[cur->y][cur->x + 1] <= '8')) {
	// 	if (map[cur->y][cur->x + 1] == '0')
	// 		click_zeros(cur->next);
	// 	map[cur->y][cur->x + 1] = '!';
	// 	--count_click;
	// }

	// if (cur->x < N - 1 && cur->y < N - 1 && (map[cur->y + 1][cur->x + 1] >= '0' ||\
	// 									map[cur->y + 1][cur->x + 1] <= '8')) {
	// 	if (map[cur->y + 1][cur->x + 1] == '0')
	// 		click_zeros(cur->next);
	// 	map[cur->y + 1][cur->x + 1] = '!';
	// 	--count_click;
	// }
	// if (cur->y < N - 1 && (map[cur->y + 1][cur->x] >= '0' ||\
	// 						map[cur->y + 1][cur->x] <= '8')) {
	// 	if (map[cur->y + 1][cur->x] == '0')
	// 		click_zeros(cur->next);
	// 	map[cur->y + 1][cur->x] = '!';
	// 	--count_click;
	// }
	// if (cur->x > 0 && cur->y < N - 1 && (map[cur->y + 1][cur->x - 1] >= '0' ||\
	// 									map[cur->y + 1][cur->x - 1] <= '8')) {
	// 	if (map[cur->y + 1][cur->x - 1] == '0')
	// 		click_zeros(cur->next);
	// 	map[cur->y + 1][cur->x - 1] = '!';
	// 	--count_click;
	// }
	// if (cur->x > 0 && (map[cur->y][cur->x - 1] >= '0' ||\
	// 						map[cur->y][cur->x - 1] <= '8')) {
	// 	if (map[cur->y][cur->x - 1] == '0')
	// 		click_zeros(cur->next);
	// 	map[cur->y][cur->x - 1] = '!';
	// 	--count_click;
	// }