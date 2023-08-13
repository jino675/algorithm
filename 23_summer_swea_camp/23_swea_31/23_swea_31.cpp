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
#include <cstring>
#include <climits>

using namespace std;

#define MOD INT_MAX

char		picture[2000][2001];
char		pattern[2000][2001];

long long	hash_table_pic_r[2000][2000];
long long	hash_table_pic_c[2000][2000];
long long	hash_table_pat[2000];

long long p_n;

int	N;
int	M;
int	H;
int	W;

int	res;

long long	hash_row(char *str)
{
	long long	c, val, p_i;

	val = 0;
	p_i = 1;
	for (int i = W - 1; i >= 0; --i) {
		if (str[i] == 'o')
			c = 1;
		else
			c = 0;
		val = (val + c * p_i) % MOD;
		if (i == 0)
			p_n = p_i;
		p_i = (p_i * 2) % MOD;
	}
	return (val);
}

long long	hash_col_pat(void)
{
	long long	val, p_i;

	val = 0;
	p_i = 1;
	for (int i = H - 1; i >= 0; --i) {
		val = (val + hash_table_pat[i] * p_i) % MOD;
		if (i == 0)
			p_n = p_i;
		p_i = (p_i * 20011) % MOD;
	}
	return (val);
}

long long	hash_col_pic(int cur_x)
{
	long long	val, p_i;

	val = 0;
	p_i = 1;
	for (int i = H - 1; i >= 0; --i) {
		val = (val + hash_table_pic_r[i][cur_x] * p_i) % MOD;
		if (i == 0)
			p_n = p_i;
		p_i = (p_i * 20011) % MOD;
	}
	return (val);
}

long long	update_hash_row(int cur_x, int cur_y)
{
	long long	c;
	long long	pre_hash = hash_table_pic_r[cur_y][cur_x - 1];

	if (picture[cur_y][cur_x - 1] == 'o')
		c = 1;
	else
		c = 0;
	pre_hash -= (c * p_n) % MOD;
	if (pre_hash < 0)
		pre_hash += MOD;
	pre_hash = (pre_hash * 2) % MOD;
	if (picture[cur_y][cur_x + W - 1] == 'o')
		c = 1;
	else
		c = 0;
	pre_hash = (pre_hash + c) % MOD;
	return (pre_hash);
}


long long	update_hash_col(int cur_x, int cur_y)
{
	long long	c;
	long long	cur_hash = hash_table_pic_c[cur_y - 1][cur_x];

	c = hash_table_pic_r[cur_y - 1][cur_x];
	cur_hash -= (c * p_n) % MOD;
	if (cur_hash < 0)
		cur_hash += MOD;
	cur_hash = (cur_hash * 20011) % MOD;
	c = hash_table_pic_r[cur_y + H - 1][cur_x];
	cur_hash = (cur_hash + c) % MOD;
	return (cur_hash);
}

void	compare_all(int	cur_x, int cur_y)
{
	int	i;

	for (i = 0; i < H; ++i) {
		if (strncmp(pattern[i], &picture[cur_y + i][cur_x], W) != 0)
			break ;
	}
	if (i == H)
		++res;
}

void	count_pattern(void)
{
	int			row, col;
	long long	hash_pat, hash_cur;

	res = 0;
	for (col = 0; col < H; ++col)
		hash_table_pat[col] = hash_row(pattern[col]);
	hash_pat = hash_col_pat();

	for (row = 0; row < N; ++row) {			//i -> x, j -> y
		hash_table_pic_r[row][0] = hash_row(picture[row]);
		for (col = 1; col < M - W + 1; ++col)
			hash_table_pic_r[row][col] = update_hash_row(col, row);
	}

	// for (row = 0; row < N; ++row) {
	// 	for (col = 0; col < M - W + 1; ++col)
	// 		printf("%lld ", hash_table_pic_r[row][col]);
	// 	printf("\n");
	// }

	for (col = 0; col < M - W + 1; ++col) {	//i -> y, j -> x
		hash_table_pic_c[0][col] = hash_col_pic(col);
		for (row = 1; row < N - H + 1; ++row)
			hash_table_pic_c[row][col] = update_hash_col(col, row);
	}
	for (row = 0; row < N - H + 1; ++row) {
		for (col = 0; col < M - W + 1; ++col) {
			hash_cur = hash_table_pic_c[row][col];
			// printf("%lld ", hash_cur);
			if (hash_pat == hash_cur)
				++res;
				// compare_all(col, row);
		}
		// printf("\n");
	}
}

int	main(void)
{
	int	tc;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("temp_in.txt", "r", stdin);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> H >> W >> N >> M;
		// cout << H << " " << W << " " << N << " " << M << " " << "\n";
		for (int j = 0; j < H; ++j)
			cin >> pattern[j];
		for (int j = 0; j < N; ++j) {
			cin >> picture[j];
			// cout << picture[j] << "\n";
		}
		count_pattern();
		cout << "#" << i << " " << res << "\n";
		res = 0;
	}
	return (0);
}