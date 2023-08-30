/*
순서대로 방문하기
난이도
    
참가자 수
69
제출 수
76
정답률
77.63%
지원 언어
    
언어별 시간/메모리
언어	시간	메모리
C	1초	1024MB
C++	1초	1024MB
Java	1초	1024MB
Python	1초	1024MB
Javascript	1초	1024MB
문제
Sam은 팀장님으로부터 차량이 이동 가능한 시나리오의 수를 찾으라는 업무 지시를 받았습니다. 이동은 숫자 0과 1로만 이루어져 있는 n x n 크기의 격자 위에서 일어납니다. 숫자 0은 빈 칸을 의미하며, 숫자 1은 해당 칸이 벽으로 막혀 있음을 의미합니다. 아래는 n이 3인 경우의 예시입니다.



0 0 0
0 0 0
0 0 1



차량은 n x n 격자 내에서 m개의 지점을 순서대로 방문하려고 합니다. 이 때 이동은 항상 상하좌우 중 인접한 칸으로만 이동하되 벽은 지나갈 수 없으며, 한 번 지났던 지점은 다시는 방문해서는 안 됩니다. 이러한 조건 하에서 차량이 이동 가능한 서로 다른 가지 수를 구하는 프로그램을 작성해보세요.



방문해야 하는 지점의 첫 지점이 출발점이며, 마지막 지점이 도착점임에 유의합니다.



위의 예에서 m = 3, 방문해야 하는 지점이 순서대로 (3행, 1열), (1행, 2열), (2행, 3열)이라면, 다음과 같이 5가지의 시나리오가 가능합니다.



1. (3행, 1열) → (3행, 2열) → (2행, 2열) → (1행, 2열) → (1행, 3열) → (2행, 3열)





2. (3행, 1열) → (3행, 2열) → (2행, 2열) → (2행, 1열) → (1행, 1열) → (1행, 2열) → (1행, 3열) → (2행, 3열)





3. (3행, 1열) → (2행, 1열) → (2행, 2열) → (1행, 2열) → (1행, 3열) → (2행, 3열)





4. (3행, 1열) → (2행, 1열) → (1행, 1열) → (1행, 2열) → (1행, 3열) → (2행, 3열)





5. (3행, 1열) → (2행, 1열) → (1행, 1열) → (1행, 2열) → (2행, 2열) → (2행, 3열)





제약조건
[조건 1] 2 ≤ n ≤ 4

[조건 2] 2 ≤ m ≤ n2

입력형식
첫 번째 줄에는 격자의 크기를 나타내는 n과 순서대로 방문해야 하는 칸의 수 m이 공백을 사이에 두고 주어집니다.



두 번째 줄부터는 n개의 줄에 걸쳐 각 행에 해당하는 n개의 수가 공백을 사이에 두고 주어집니다. 주어지는 수는 0 또는 1이며, 0은 빈 칸을 1은 벽을 의미합니다.



n + 2 번째 줄부터는 m개의 줄에 방문해야 할 m개의 칸의 위치 (x, y) 쌍이 공백을 사이에 두고 한 줄에 하나씩 순서대로 주어집니다. 주어지는 칸에 벽이 있는 경우는 없으며, 동일한 칸이 여러 번 주어지는 경우는 없다고 가정해도 좋습니다.

출력형식
차량이 m개의 지점을 순서대로 방문할 수 있는 서로 다른 방법의 수를 출력합니다. 만약 가능한 방법이 없다면 0을 출력합니다.

입력예제1
3 3
0 0 0
0 0 0
0 0 1
3 1
1 2
2 3
출력예제1
5
입력예제2
3 3
0 0 1
0 0 0
0 0 1
3 1
1 2
2 3
출력예제2
1
*/
#include <iostream>

using namespace std;

int	map[4][4];

int	n;
int	m;

int	res;

bool	is_okay(int x, int y, int next_num)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return (false);
	else if (map[y][x] == 0 || map[y][x] == next_num)
		return (true);
	else
		return (false);
}

void	find_res(int cur_x, int cur_y, int next_num)
{
	int	next_x, next_y, original_val;

	if (map[cur_y][cur_x] == next_num) {
		if (next_num == m) {
			++res;
			return ;
		}
		else
			++next_num;
	}
	original_val = map[cur_y][cur_x];
	map[cur_y][cur_x] = -1;
	if (is_okay(cur_x, cur_y - 1, next_num) == true)
		find_res(cur_x, cur_y - 1, next_num);
	if (is_okay(cur_x - 1, cur_y, next_num) == true)
		find_res(cur_x - 1, cur_y, next_num);
	if (is_okay(cur_x, cur_y + 1, next_num) == true)
		find_res(cur_x, cur_y + 1, next_num);
	if (is_okay(cur_x + 1, cur_y, next_num) == true)
		find_res(cur_x + 1, cur_y, next_num);
	map[cur_y][cur_x] = original_val;
	return ;
}

int	main(void)
{
	int	input, x, y, start_x, start_y;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> input;
			if (input == 0)
				map[i][j] = 0;
			else
				map[i][j] = -1;
		}
	}
	for (int i = 1; i <= m; ++i) {
		cin >> y >> x;
		map[y - 1][x - 1] = i;
		if (i == 1) {
			start_x = x - 1;
			start_y = y - 1;
		}
	}
	res = 0;
	find_res(start_x, start_y, 1);
	cout << res << "\n";
}
