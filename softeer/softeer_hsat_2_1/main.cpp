/*
Garage game
난이도
    
참가자 수
288
제출 수
525
정답률
8.38%
지원 언어
    
언어별 시간/메모리
언어	시간	메모리
C	1초	256MB
C++	1초	256MB
Java	2초	256MB
Python	2초	256MB
Javascript	2초	256MB
문제
자율주행 기술의 발전과 함께 차량 내 인포테인먼트 기술 또한 많은 주목을 받고 있다. 최근 자동차 실내에는 디스플레이의 대형화를 비롯해 새로운 제어 기술이 빠르게 적용되고 있는데, 완전 자율주행 시대가 다가올 수록 이런 변화가 가속화될 전망이다.

개인 맞춤형 인포테인먼트 시스템 역시 핵심 기능 중 하나다. 자율주행 시대에 발맞춰 차량 내 디지털 시스템을 활용한 게임을 개발하고 있다.







게임의 룰은 가로 세로 N칸의 차고(격자)가 있고, 각 차고에는 색깔이 있는 자동차가 하나씩 있다. 한 턴에 한 칸을 선택하며, 선택한 칸과 상하좌우 칸에 들어있는 자동차의 색이 같다면 모두 사라진다. 그리고 사라진 칸들과 연결된 칸들의 상하좌우 칸에 들어있는 자동차의 색이 같다면 함께 사라진다. (문제 하단 예시 참고.)



이때, 획득할 수 있는 점수는 사라진 자동차의 개수와 사라지는 차고 칸을 모두 포함하는 가장 작은 직사각형의 넓이의 합이다.

자동차들이 사라지고 나면 위에 있는 자동차들이 아래로 떨어져 빈 칸을 채운다. 위쪽에는 충분한 자동차들이 더 있어서 위에서 추가적으로 떨어지며 모든 칸을 채운다.



위에서 어떤 자동차들이 떨어질지는 입력으로 주어진다. 위와 같은 게임을 3차례 반복 했을 때, 주어진 조건에서 얻을 수 있는 가장 큰 점수를 계산하라.

제약조건
1 ≤ N ≤ 15

색상 번호는 1 이상 109이하의 자연수이다.

입력형식
입력으로는 차고 격자 칸의 가로, 세로 길이인 N이 첫 줄에 주어진다.

다음 3N개의 줄에 N개의 자연수가 주어진다.

각 자연수는 차고 칸에 있는 자동차의 색상 번호이다.

출력형식
주어진 조건에서 게임을 3차례 시뮬레이션 했을 때 얻을 수 있는 가장 큰 점수를 출력한다.

입력예제1
2
1 1
2 2
1 1
3 3
4 4
1 2
출력예제1
15
입력예제2
3
8 5 1
9 6 1
10 7 1
11 1 3
12 1 3
13 1 3
1 2 2
1 2 2
1 2 2
출력예제2
36
*/
#include <iostream>
#include <queue>

using namespace std;

int	buf[30][15];
int N;

typedef struct s_node
{
	int	val;
	int	is_visited;
}	t_node;

typedef struct s_map
{
	t_node	map[15][15];
	int		buf_end[15];
	int		point;
	int		phase;

	void	copy(const struct s_map *a) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				map[i][j].val = a->map[i][j].val;
				map[i][j].is_visited = a->map[i][j].is_visited;
			}
		}
		for (int i = 0; i < N; ++i)
			buf_end[i] = a->buf_end[i];
		point = a->point;
		phase = a->phase;
	}

	int		BFS(int cur_x, int cur_y, int cur_num) {
		int	next_x, next_y, cnt, l, r, u, d, cur_point;
		queue<pair<int, int>>	q;

		if (map[cur_y][cur_x].is_visited != 0)
			return (-1);
		l = cur_x; r = cur_x; u = cur_y; d = cur_y; cnt = 0;
		map[cur_y][cur_x].is_visited = cur_num;
		q.push({cur_x, cur_y});
		while (q.empty() != true) {
			cur_x = q.front().first;
			cur_y = q.front().second;
			q.pop();
			if (cur_x < l) l = cur_x; if (cur_x > r) r = cur_x;
			if (cur_y < u) u = cur_y; if (cur_y > d) d = cur_y;
			++cnt;
			for (int i = 0; i < 4; ++i) {
				if (i == 0)		 {next_x = cur_x; 		next_y = cur_y - 1;}
				else if (i == 1) {next_x = cur_x - 1;	next_y = cur_y;}
				else if (i == 2) {next_x = cur_x;		next_y = cur_y + 1;}
				else if (i == 3) {next_x = cur_x + 1;	next_y = cur_y;}
				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && \
					map[next_y][next_x].val == map[cur_y][cur_x].val && \
					map[next_y][next_x].is_visited == 0) {
					map[next_y][next_x].is_visited = cur_num;
					q.push({next_x, next_y});
				}
			}
		}
		cur_point = (r - l + 1) * (d - u + 1) + cnt;
		return (cur_point);
	}
	
	void	update(int cur_num, int cur_point) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[j][i].is_visited == cur_num) {
					for (int k = j; k > 0; --k)
						map[k][i].val = map[k - 1][i].val;
					map[0][i].val = buf[buf_end[i]][i];
					--buf_end[i];
				}
				map[j][i].is_visited = 0;
			}
		}
		point += cur_point;
		++phase;
	}

}	t_map;


t_map	maps[3];
int		max_point;

void	run(t_map	*cur_map) {
	int		cur_num = 1, cur_point;
	t_map	*next_map;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cur_point = cur_map->BFS(j, i, cur_num);
			if (cur_point == -1)
				continue ;
			if (cur_map->phase == 2) {
				if (max_point < cur_map->point + cur_point)
					max_point = cur_map->point + cur_point;
			}
			else {
				next_map = &maps[cur_map->phase + 1];
				next_map->copy(cur_map);
				next_map->update(cur_num, cur_point);
				++cur_num;
				run(next_map);
			}
		}
	}
}

int	main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < 2 * N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> buf[i][j];
	for (int i = 0; i < N; ++i)
		maps[0].buf_end[i] = 2 * N - 1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> maps[0].map[i][j].val;
	
	run(&maps[0]);
	cout << max_point << "\n";

	return (0);
}