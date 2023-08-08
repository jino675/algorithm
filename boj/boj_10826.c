/*
피보나치 수 4
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	19449	6739	5763	39.635%
문제
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 10,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 n번째 피보나치 수를 출력한다.

예제 입력 1 
10
예제 출력 1 
55
*/
#include <stdio.h>

#define BUF_SIZE 10000

char	buf_1[BUF_SIZE];
char	buf_2[BUF_SIZE];
char	buf_3[BUF_SIZE];

typedef struct s_fibo
{
	char	*nbr;
	int		len;
}	t_fibo;

t_fibo	f_1;
t_fibo	f_2;
t_fibo	f_n;

void	plus_nbr(t_fibo *res, t_fibo *src_1, t_fibo *src_2)
{
	int	sum_len;
	int	up;
	int	sum;
	int	cur_idx;
	int i;

	sum_len = (src_1->len > src_2->len) ? src_1->len : src_2->len;
	up = 0;
	sum = 0;
	for (i = 0; i < sum_len; ++i) {
		cur_idx = BUF_SIZE - 1 - i;
		char n1 = src_1->nbr[cur_idx];
		char n2 = src_2->nbr[cur_idx];
		if (i < src_1->len && i < src_2->len)
			sum = src_1->nbr[cur_idx] - '0' + src_2->nbr[cur_idx] - '0' + up;
		else if (i < src_1->len)
			sum = src_1->nbr[cur_idx] - '0' + up;
		else if (i < src_2->len)
			sum = src_2->nbr[cur_idx] - '0' + up;
		if (sum >= 10) {
			up = 1;
			sum -= 10;
		}
		res->nbr[cur_idx] = sum + '0';
	}
	if (up == 1) {
		cur_idx = BUF_SIZE - 1 - i;
		res->nbr[cur_idx] = '1';
	}
	res->len = i;
}

int	main(void)
{
	int	N;
	int	idx;

	scanf("%d", &N);
	f_1.nbr = buf_1;
	f_1.nbr[BUF_SIZE - 1] = '0';
	f_1.len = 1;
	f_2.nbr = buf_2;
	f_2.nbr[BUF_SIZE - 1] = '1';
	f_2.len = 1;
	f_n.nbr = buf_3;
	if (N == 0) {
		f_n.nbr[BUF_SIZE - 1] = '0';
		f_n.len = 1;
	}
	if (N == 1) {
		f_n.nbr[BUF_SIZE - 1] = '1';
		f_n.len = 1;
	}
	for (int i = 2; i <= N; ++i) {
		plus_nbr(&f_n, &f_1, &f_2);
		f_1.nbr = f_2.nbr;
		f_1.len = f_2.len;
		f_2.nbr = f_n.nbr;
		f_2.len = f_n.len;
	}
	for (int i = 0; i < f_n.len; ++i) {
		idx = BUF_SIZE - f_n.len + i;
		printf("%c", f_n.nbr[idx]);
	}
	printf("\n");
	return (0);
}