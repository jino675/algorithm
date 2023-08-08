/*
No. 31 은기의 아주 큰 그림
참여자 33 제출 124 배점 100
Problem제출이력정답
시간 : 11개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


바쁜 일정이 지난 은기는 새로운 취미로 미술 학원을 다니기로 하였다.

마우스가 아닌 붓을 잡은 은기는, 미술 실력이 많이 부족하였다.

그래서 선생님이 그린 N×M 크기의 흑백 그림을 따라 그리며 실력을 쌓고 있다.


그러던 어느 날, 은기는 꿈을 꾸었다. 꿈에서 H×W 크기의 흑백 그림 하나를 보았다.

은기는 다음 날, 선생님의 그림 안에 꿈에서 보았던 그림이 몇 번 등장하는지 궁금하였다.

다음의 예시를 보자. 왼쪽은 은기가 꿈에서 본 그림이고, 오른쪽은 선생님이 그린 그림이다.


 
oo
xx
ooo
xxx
ooo

 선생님이 그린 그림에서 은기가 꿈에서 본 그림이 등장하는 경우의 수는 다음과 같이 2가지이다.

  
ooo
xxx
ooo
ooo
xxx
ooo

은기가 꿈에서 본 그림과 선생님의 그림 정보가 주어질 때,

선생님의 그림에 은기가 꿈에서 본 그림이 등장하는 횟수를 계산하는 프로그램을 작성하라.


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 네 개의 정수 H, W, N, M ( 1 ≤ H ≤ N ≤ 2000, 1 ≤ W ≤ M ≤ 2000 )가 공백으로 구분되어 주어진다.

다음 H개의 줄에 은기가 꿈에서 본 그림의 정보가 주어진다.

다음 N개의 줄에 선생님이 그린 그림의 정보가 주어진다.

그림은 ‘x’ 또는 ‘o’로만 이루어져 있다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 답을 한 줄에 하나씩 출력한다.
 

입력
2
2 2 3 3
oo
oo
ooo
ooo
ooo
4 4 10 10
oxxo
xoox
xoox
oxxo
xxxxxxoxxo
oxxoooxoox
xooxxxxoox
xooxxxoxxo
oxxoxxxxxx
ooooxxxxxx
xxxoxxoxxo
oooxooxoox
oooxooxoox
xxxoxxoxxo	// 테스트 케이스 개수
// 첫 번째 테스트 케이스, H = 2, W = 2, N = 3, M = 3





// 두 번째 테스트 케이스













 
sample_input.txt
출력
#1 4
#2 4	// 첫 번째 테스트 케이스 결과
 
*/

#include <iostream>
#include <time.h>
#include <cstring>
#include <list>

using namespace std;

#define MOD 10000000019LL

// typedef struct s_list
// {
// 	long long		val;
// 	struct s_list	*next;
// 	struct s_list	*prev;
// }	t_list;

char		picture[2000][2001];
char		pattern[2000][2001];
// long long	val_table[2000];

// t_list	list_pool[2000];
// int		pool_count;
// t_list	*val_table;

list<long long>	val_table;
long long	random_table[2000];

int	N;
int	M;
int	H;
int	W;

int			res;
long long	p_n;

void	make_random_value(void)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < H; ++i) {
		random_table[i] = rand() % MOD
	}
}

long long	my_hash(char str[2000][2001], int height, int width, int is_pic)
{
	long long	val;
	long long	cur_val;
	long long	p_i;

	val = 0;
	for (int i = 0; i < H; ++i) {
		p_i = 1;
		cur_val = 0;
		for (int j = width - 1; j >= 0; --j) {
			cur_val = (cur_val + (long long)str[i][j] * p_i) % MOD;
			if (j > 0)
				p_i = (p_i * 2) % MOD;
		}
		if (is_pic == 1)
			val_table.push_back(cur_val);
		val = (val + cur_val) % MOD;
	}
	p_n = p_i;

	return (val);
}

long long	update_hash_right(long long cur_val, int next_x, int next_y)
{
	for (int i = 0; i < H; ++i) {
		//(V + b) % x => V + m * x + Vb = (m + (1 or 0)) * x + Vnew (최대)
		//어차피 V 와 Vb 모두 x를 넘을 수는 없으므로...
		//Vnew + x = V + Vb 
		//V = Vnew + x - Vb
		//Vnew = V + Vb or V + Vb - x 인데
		//Vnew - Vb = 0 이상 or 음수
		val_table[0] -= (picture[next_y - H + i][next_x - W] * p_n) % MOD;
		if (val_table[0] < 0)
			val_table[0] += MOD;
		//(a + b + c) % x = V
		//(p * a + p * b + p * c) % x = Vp
		//V = (Va + Vb + Vc) % x
		//Vp = (p*Va + p*Vb + p*Vc) % x
		//(Va + Vb + Vc) = mx + V
		//(p*Va + p*Vb + p*Vc) = p * (mx + V) = p*m*x + p*V
		//Vp = (p * V) % x
		cur_val = (cur_val * 2) % MOD;
		//(V + b) % x = (V + Vb) % x
		cur_val = (cur_val + picture[next_y - H + i][next_x] * 1) % MOD;
	}
	return (cur_val);
}


long long	update_hash_down(long long cur_val, int next_y)
{
	long long p_i;

	p_i = 1;
	for (int i = W - 1; i >= 0; ++i) {
		//(V + b) % x => V + m * x + Vb = (m + (1 or 0)) * x + Vnew (최대)
		//어차피 V 와 Vb 모두 x를 넘을 수는 없으므로...
		//Vnew + x = V + Vb 
		//V = Vnew + x - Vb
		//Vnew = V + Vb or V + Vb - x 인데
		//Vnew - Vb = 0 이상 or 음수
		cur_val -= (picture[next_y - H][i] * p_i) % MOD;
		if (cur_val < 0)
			cur_val += MOD;
		//(V + b) % x = (V + Vb) % x
		cur_val = (cur_val + picture[next_y][i] * p_i) % MOD;
		p_i = (p_i * 2) % MOD;
	}
	return (cur_val);
}

void	find_pattern(void)
{
	int			i;
	int			next_x, next_y;
	long long	cur_val;
	long long	cur_first_val;
	long long	pattern_val;

	pattern_val = my_hash(pattern, H, W, 0);
	cur_val = my_hash(picture, H, W, 1);
	next_y = H;
	while (1) {
		cur_first_val = cur_val;
		next_x = W;
		while (1) {
			for (int j = 0; j < H; ++j) {
				for (int k = 0; k < W; ++k) {
					printf("%c", picture[next_y - H + j][next_x - W + k]);
				}
				printf("\n");
			}
			printf("cur_val : %lld, pattern_val : %lld\n", cur_val, pattern_val);
			if (pattern_val == cur_val) {
				for (i = 0; i < H; ++i) {
					if (strncmp(&picture[next_y - H + i][next_x - W], pattern[i], W) != 0) {
						break ;
					}
				}
				if (i == H)
					++res;
			}
			if (next_x == M) {
				if (next_y == N)
					return ;
				else
					break ;
			}
			cur_val = update_hash_right(cur_val, next_x, next_y);
			++next_x;
		}
		printf("*******\n");
		cur_val = update_hash_down(cur_first_val, next_y);
		++next_y;
	}
}

int	main(void)
{
	int	tc;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> H >> W >> N >> M;
		for (int j = 0; j < H; ++j)
			cin >> pattern[j];
		for (int j = 0; j < N; ++j)
			cin >> picture[j];
		find_pattern();
		cout << "#" << i << " " << res << "\n";
		res = 0;
	}
	return (0);
}