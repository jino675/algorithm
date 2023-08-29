/*
No. 11 [Pro] 로봇청소기3
참여자 33 제출 43 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 3초
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

  ㅇ   A.  2개의 파일을 생성하셔야 합니다. ( main.cpp / solution.cpp 또는 Solution.java / UserSolution.java 또는 main.py / solution.py )

  ㅇ   B.  Main 부분의 코드를 main.cpp 또는 Solution.java 또는 main.py 에 복사해서 사용하시기 바랍니다.

  ㅇ   C.  sample_input.txt 를 사용하시기 위해서는 Main 부분의 코드 내에

  ㅇ   C.  표준 입력을 파일로 전환하는 코드 ( 주석처리 되어 있음 ) 의 주석을 풀어서 사용하시면 됩니다.

  ㅇ   D.  User Code 부분의 코드를 작성하신 후 서버에 제출하실 때,

  ㅇ   D.  디버깅을 위한 표준 입출력 함수를 모두 삭제 또는 주석 처리해 주셔야 합니다.

  ④   문제 내에 제약조건을 모두 명시하지 않으므로 주어지는 코드를 분석하셔야 합니다.

  ⑤   코드는 개발 언어에 따라 상이할 수 있으므로, 작성할 언어를 기준으로 분석하셔야 합니다.

 

※ 본 문제는 임직원의 S/W 문제해결 역량 향상을 위한 Professional 실전형 연습문제이며

함께 제공되는 Testcase 또한 학습을 위한 연습용입니다.

 

N x N 개의 구역을 가지는 평면이 존재한다. (10 ≤ N ≤ 30)

이 평면의 각 구역은 바닥 또는 벽으로 이루어져 있다.

바닥은 로봇이 지나갈 수 있는 구역이고, 벽은 지나갈 수 없는 구역이다.

 

[Fig. 1] 은 N = 10 인 평면을 나타낸다.

이 그림에서 회색 구역은 벽, 흰색 구역은 바닥을 의미한다.



 

당신에게는 로봇 청소기가 1 대 주어진다.

이 로봇은 현재 위치와 진행방향을 기준으로 인접한 구역을 스캔할 수 있으며,

인접 구역으로 1 칸씩 이동가능하다.

 

당신은 Main 에서 제공하는 API를 이용하여, 모든 바닥 구역을 청소하여야 한다

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

void init(int N, int subTaskCount)

각 테스트케이스의 제일 처음 1회 호출된다.

N 은 평면의 크기가 N x N 임을 의미한다.

subtaskCount는 이번 테스트케이스에서 호출되는 cleanHouse() 함수의 호출 횟수이다.

 

Parameter

   N: 평면의 크기 N x N (10 ≤ N ≤ 30)

   subTaskCount : 이 테스트케이스에서 호출되는 cleanHouse() 호출 횟수(10 ≤ subTaskCount ≤ 30)

void cleanHouse(int mLimitMoveCount)

N x N 크기의 랜덤한 평면이 주어진다.

로봇의 위치와 방향 값 역시 랜덤이다.

 

당신은 Main 에서 제공하는 API 를 이용하여 로봇을 조작하여 벽이 아닌 모든 구역을 청소하여야 한다.

어떤 구역을 청소하기 위해서는, 로봇을 조작하여 그 구역에 로봇을 이동시키면 된다.

시작 위치는 청소가 되었다고 가정한다.

 

주어진 평면에서 로봇이 갈 수 없는 바닥은 없다.

 

Main 의 moveRobot() 함수를 mLimitMoveCount를 초과하여 호출 할 경우, 이 테스트케이스는 실격 처리 된다.

 

Parameter

   mLimitMoveCount : 로봇의 최대 이동 횟수(mLimitMoveCount = N * N * N)

 

Main 에서 제공하는 API 는 다음과 같다.

void scanFromRobot(int floorState[3][3])

User 코드에서 이 함수를 호출하면 로봇이 scan 한 주변 정보를 floorState 에 저장하여 반환한다.

0 : 바닥, 1 : 은 벽을 의미한다.

 

[3][3]크기의  배열에는 로봇의 위치와 로봇이 진행 중인 방향을 기준으로,

[0][0] : 왼쪽 앞,

[0][1] : 가운데 앞

[0][2] : 오른쪽 앞

[1][0] : 왼쪽

[1][1] : 가운데

[1][2] : 오른쪽

[2][0] : 왼쪽 뒤

[2][1] : 뒤

[2][2] : 오른쪽 뒤

에 해당하는 구역의 정보가 저장되어 반환된다.

 

[Fig. 2] 은 로봇이 왼쪽 방향으로 진행 중일 때, 이 함수에서 반환하는 값의 예이다.

 



 

 

Return

   floorState: 각 로봇 위치와 진행방향을 기준으로 한 3 x 3 크기의 구역 정보.

int moveRobot(int mCommand)

로봇을 조작한다.

mCommand 에는 로봇을 이동시킬 명령을 전달한다.

전달 가능한 명령어는 4 가지이며 다음과 같다.

 

0 : 현재 진행방향으로 1칸 전진

1 : 현재 진행방향에서 왼쪽으로 90도 회전 후 1칸 전진

2 : 현재 진행방향에서 뒤로 회전 후 1칸 전진

3 : 현재 진행방향에서 오른쪽으로 90도 회전 후 1칸 전진.

 

로봇이 벽을 향해 이동을 할 경우, 명령은 수행되지 않고 0을 반환한다.

0~3 이외의 명령이 들어올 경우 0을 반환한다.

 

Parameter

   mCommand : 로봇에 대한 이동 명령

 

Return

   로봇이 정상적으로 이동 했을 경우 1, 아니면 0

 

[예제]

첫번째 테스트케이스의 첫번째 subtask 에서 주어지는 평면과 로봇의 위치는 [Fig. 3] 과 같다.



이 문제는 정답이 존재하지 않으며, 다양한 방법으로 문제를 해결할 수 있다.

다음으로 주어지는 그림들은 그 중 한가지 예이다.

 

노란색 구역은 로봇이 청소한 구역을 의미하고, 파란 화살표는 로봇의 이동 경로를 의미한다.

 

인접한 구역 중 청소가 안된 구역을 따라가다 보면 [Fig. 4] 와 같은 상황을 맞이 하게 된다.

[Fig. 4] 는 인접한 구역이 모두 청소가 된 경우를 의미한다.

이 경우 탐색 범위를 확장하여, 청소가 안된 구역을 찾는다.

빨간 동그라미로 표시된 구역이 그러한 구역이며, 이 구역을 다음 목적지로 설정한다.



 

빨간색으로 동그라미 친 구역을 목적지로 설정한 후, 인접 구역을 따라 계속 이동하면

[Fig. 5] 와 같은 상태가 된다.



 



[Fig. 6] 에서 모든 구역 청소를 완료하였으며, 총 이동거리는 56 이다.

 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. 주어지는 평면은 벽으로 둘러 쌓여 있음이 보장된다.

3. 주어진 평면에서 로봇이 갈 수 없는 바닥은 없다.
*/
extern void scanFromRobot(int ceilingState[3][3]);
extern int moveRobot(int mCommand);

enum e_state
{
	unknown,
	wall,
	dirty,
	clean
};

typedef struct s_loc
{
	int	x;
	int	y;
	bool	operator==(const struct s_loc &a) const{
		if (x == a.x && y == a.y)
			return (true);
		else
			return (false);
	}
}	t_loc;

typedef struct s_map
{
	int		state;
	int		is_visited;
	t_loc	pre_loc;
}	t_map;

typedef struct s_queue
{
	t_loc	arr[3600];
	int		start;
	int		end;

	void	clear(void) {
		start = 0;
		end = 0;
	}
	void	push(t_loc new_loc) {
		arr[end++] = new_loc;
	}
	void	pop(void) {
		++start;
	}
	t_loc	front(void) {
		return (arr[start]);
	}
	bool	empty(void) {
		if (start == end)
			return (true);
		else
			return (false);
	}
}	t_queue;

t_map	map[59][59];
int		scan[3][3];
int		map_size;
int		dirty_cnt;

t_loc	cur_loc;
int		cur_dir;

t_queue	q;
int		visited_val;

bool	is_move_okay(int cmd)
{
	if (cmd == 0) {
		if ((cur_dir == 0 && map[cur_loc.y - 1][cur_loc.x].state == dirty) || \
			(cur_dir == 1 && map[cur_loc.y][cur_loc.x - 1].state == dirty) || \
			(cur_dir == 2 && map[cur_loc.y + 1][cur_loc.x].state == dirty) || \
			(cur_dir == 3 && map[cur_loc.y][cur_loc.x + 1].state == dirty))
			return (true);
		else
			return (false);
	}
	else if (cmd == 1) {
		if ((cur_dir == 0 && map[cur_loc.y][cur_loc.x - 1].state == dirty) || \
			(cur_dir == 1 && map[cur_loc.y + 1][cur_loc.x].state == dirty) || \
			(cur_dir == 2 && map[cur_loc.y][cur_loc.x + 1].state == dirty) || \
			(cur_dir == 3 && map[cur_loc.y - 1][cur_loc.x].state == dirty))
			return (true);
		else
			return (false);
	}
	else if (cmd == 2) {
		if ((cur_dir == 0 && map[cur_loc.y + 1][cur_loc.x].state == dirty) || \
			(cur_dir == 1 && map[cur_loc.y][cur_loc.x + 1].state == dirty) || \
			(cur_dir == 2 && map[cur_loc.y - 1][cur_loc.x].state == dirty) || \
			(cur_dir == 3 && map[cur_loc.y][cur_loc.x - 1].state == dirty))
			return (true);
		else
			return (false);
	}
	else {
		if ((cur_dir == 0 && map[cur_loc.y][cur_loc.x + 1].state == dirty) || \
			(cur_dir == 1 && map[cur_loc.y - 1][cur_loc.x].state == dirty) || \
			(cur_dir == 2 && map[cur_loc.y][cur_loc.x - 1].state == dirty) || \
			(cur_dir == 3 && map[cur_loc.y + 1][cur_loc.x].state == dirty))
			return (true);
		else
			return (false);
	}
}

int	my_move(int cmd, int mode)
{
	if (mode == 0 && is_move_okay(cmd) == false)
			return (0);
	if (moveRobot(cmd) == 0)
		return (0);
	if (cmd == 0) {
		if (cur_dir == 0) --cur_loc.y;
		else if (cur_dir == 1) --cur_loc.x;
		else if (cur_dir == 2) ++cur_loc.y;
		else if (cur_dir == 3) ++cur_loc.x;
	}
	else if (cmd == 1) {
		if (cur_dir == 0) --cur_loc.x;
		else if (cur_dir == 1) ++cur_loc.y;
		else if (cur_dir == 2) ++cur_loc.x;
		else if (cur_dir == 3) --cur_loc.y;
	}
	else if (cmd == 2) {
		if (cur_dir == 0) ++cur_loc.y;
		else if (cur_dir == 1) ++cur_loc.x;
		else if (cur_dir == 2) --cur_loc.y;
		else if (cur_dir == 3) --cur_loc.x;
	}
	else {
		if (cur_dir == 0) ++cur_loc.x;
		else if (cur_dir == 1) --cur_loc.y;
		else if (cur_dir == 2) --cur_loc.x;
		else if (cur_dir == 3) ++cur_loc.y;
	}
	cur_dir = (cur_dir + cmd) % 4;
	return (1);
}

bool	is_okay(int x, int y)
{
	if (x < 0 && y < 0 && x > 58 && x > 58)
		return (0);
	else if (map[y][x].is_visited == visited_val)
		return (0);
	else if (map[y][x].state == wall || map[y][x].state == unknown)
		return (0);
	else
		return (1);
}

t_loc	BFS(void)
{
	t_loc	temp_cur, temp_next;

	if (dirty_cnt == 0)
		return ((t_loc){0, 0});
	++visited_val;
	map[cur_loc.y][cur_loc.x].is_visited = visited_val;
	q.clear();
	q.push(cur_loc);
	while (q.empty() != true) {
		temp_cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			if (i == 0)
				temp_next = {temp_cur.x, temp_cur.y - 1};
			else if (i == 1)
				temp_next = {temp_cur.x - 1, temp_cur.y};
			else if (i == 2)
				temp_next = {temp_cur.x, temp_cur.y + 1};
			else
				temp_next = {temp_cur.x + 1, temp_cur.y};
			if (is_okay(temp_next.x, temp_next.y) == 1) {
				map[temp_next.y][temp_next.x].pre_loc = temp_cur;
				if (map[temp_next.y][temp_next.x].state == dirty)
					return (temp_next);
				map[temp_next.y][temp_next.x].is_visited = visited_val;
				q.push({temp_next.x, temp_next.y});
			}
		}
	}
	return ((t_loc){0, 0});
}

void	go_dirty_loc(t_loc next_loc)
{
	if (dirty_cnt == 0)
		return ;
	if (next_loc == cur_loc)
		return ;
	else {
		go_dirty_loc(map[next_loc.y][next_loc.x].pre_loc);
		if (next_loc.y - cur_loc.y == -1) {
			if (cur_dir == 0) my_move(0, 1);
			else if (cur_dir == 1) my_move(3, 1);
			else if (cur_dir == 2) my_move(2, 1);
			else if (cur_dir == 3) my_move(1, 1);
		}
		else if (next_loc.y - cur_loc.y == 1) {
			if (cur_dir == 0) my_move(2, 1);
			else if (cur_dir == 1) my_move(1, 1);
			else if (cur_dir == 2) my_move(0, 1);
			else if (cur_dir == 3) my_move(3, 1);
		}
		else if (next_loc.x - cur_loc.x == -1) {
			if (cur_dir == 0) my_move(1, 1);
			else if (cur_dir == 1) my_move(0, 1);
			else if (cur_dir == 2) my_move(3, 1);
			else if (cur_dir == 3) my_move(2, 1);
		}
		else if (next_loc.x - cur_loc.x == 1) {
			if (cur_dir == 0) my_move(3, 1);
			else if (cur_dir == 1) my_move(2, 1);
			else if (cur_dir == 2) my_move(1, 1);
			else if (cur_dir == 3) my_move(0, 1);
		}
	}
}

void init(int N, int subTaskCount)
{
	map_size = N;
}

int		rotate_scan(int x, int y)
{
	if (cur_dir == 0)
		return (scan[y][x]);
	else if (cur_dir == 1) {
		if (y == 0) {
			if (x == 0) return (scan[0][2]);
			else if (x == 1) return (scan[1][2]);
			else return (scan[2][2]);
		}
		else if (y == 1) {
			if (x == 0) return (scan[0][1]);
			else return (scan[2][1]);
		}
		else {
			if (x == 0) return (scan[0][0]);
			else if (x == 1) return (scan[1][0]);
			else return (scan[2][0]);
		}
	}
	else if (cur_dir == 2) {
		if (y == 0) {
			if (x == 0) return (scan[2][2]);
			else if (x == 1) return (scan[2][1]);
			else return (scan[2][0]);
		}
		else if (y == 1) {
			if (x == 0) return (scan[1][2]);
			else return (scan[1][0]);
		}
		else {
			if (x == 0) return (scan[0][2]);
			else if (x == 1) return (scan[0][1]);
			else return (scan[0][0]);
		}
	}
	else {
		if (y == 0) {
			if (x == 0) return (scan[2][0]);
			else if (x == 1) return (scan[1][0]);
			else return (scan[0][0]);
		}
		else if (y == 1) {
			if (x == 0) return (scan[2][1]);
			else return (scan[0][1]);
		}
		else {
			if (x == 0) return (scan[2][2]);
			else if (x == 1) return (scan[1][2]);
			else return (scan[0][2]);
		}
	}
}

void	update_map(void)
{
	map[cur_loc.y][cur_loc.x].state = clean;
	--dirty_cnt;
	scanFromRobot(scan);
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (map[cur_loc.y + i][cur_loc.x + j].state == unknown) {
				if (rotate_scan(j + 1, i + 1) == 0) {
					map[cur_loc.y + i][cur_loc.x + j].state = dirty;
					++dirty_cnt;
				}
				else
					map[cur_loc.y + i][cur_loc.x + j].state = wall;
			}
		}
	}
}

void cleanHouse(int mLimitMoveCount)
{
	for (int i = 0; i < 59; ++i) {
		for (int j = 0; j < 59; ++j) {
			map[i][j].state = unknown;
			map[i][j].is_visited = 0;
		}
	}
	visited_val = 0;
	dirty_cnt = 1;
	cur_loc = {29, 29};
	cur_dir = 0;

	while (dirty_cnt > 0) {
		update_map();
		while (my_move(0, 0) != 0)
			update_map();
		if (my_move(3, 0) == 0) {
			go_dirty_loc(BFS());
			continue ;
		}
		else {
			update_map();
			if (my_move(3, 0) == 0) {
				go_dirty_loc(BFS());
				continue ;
			}
			else {
				update_map();
				while (my_move(0, 0) != 0)
					update_map();
				if (my_move(1, 0) == 0) {
					go_dirty_loc(BFS());
					continue ;
				}
				else {
					update_map();
					if (my_move(1, 0) == 0) {
						go_dirty_loc(BFS());
						continue ;
					}
				}
			}
		}
	}
}
