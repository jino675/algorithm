/*
No. 26 수 만들기
참여자 49 제출 104 배점 100
Problem제출이력정답
시간 : 100개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

N개의 수 A1,A2,…,AN 과 K가 주어진다. 처음에 X=0, D=1이고, 다음과 같은 작업을 몇 번 반복해서, X의 값을 K로 만들어야 한다.

1. X에 D를 더한다.

2. D에 A1,A2,…,AN 중 하나를 곱한다.

예를 들어, N=2, A=[2,3], K=7 이면, 다음과 같은 방식으로 X=K로 만들 수 있다.

 

1. X=0, D=1이고 X에 D를 더해 X=1이 된다.

2. D에 A1=2를 곱해 D=2이 된다.

3. D에 A2=3을 곱해 D=6이 된다.

4. X=1, D=6이고 X에 D를 더해 X=7이 된다.

 

이 때, D에 수를 몇 번 곱하는지는 관계없이, X에 D를 더하는 횟수를 최소화하면 몇 번이 되는지 구하는 프로그램을 작성하라.

 

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N(1 <= N <=10)이 주어진다.

두 번째 줄에는 N개의 정수 A1,A2,…,AN (2 <= Ai <= 109)이 공백 하나로 구분되어 주어진다.

세 번째 줄에는 하나의 정수 K(1 <= K <= 109)가 주어진다.

 

[출력]

각 테스트 케이스마다 X의 값을 K로 만들기 위해 X에 D를 더하는 횟수의 최솟값을 출력한다.

입력
3
2
2 3
7
1
3
16
5
9 124 62 32 563
987654321	// 전체 테스트 케이스 수
// 첫 번째 테스트 케이스의 N= 2

// 첫 번째 테스트 케이스의 K= 7





 
input.txt
출력
#1 2
#2 4
#3 19	// 첫 번째 테스트 케이스의 답
*/
#include <iostream>
using namespace std;


typedef struct s_info
{
	char	a[11];
	int		val;
}	t_info;

t_info		heap[10000000];
int			heap_size;
long long	A[11][31];

int	N;
int	K;
int	res;

void	my_swap(t_info *a, t_info *b)
{
	t_info	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	push(t_info *x)
{
	int	cur_idx;
	int	parent_idx;

	cur_idx = heap_size + 1;
	heap[cur_idx] = *x;
	parent_idx = cur_idx / 2;
	while (1) {
		if (parent_idx == 0)
			break ;
		if (heap[cur_idx].val > heap[parent_idx].val) {
			my_swap(&heap[cur_idx], &heap[parent_idx]);
			cur_idx = parent_idx;
			parent_idx = cur_idx / 2;
		}
		else
			break ;
	}
	++heap_size;
}

void pop(void)
{
	int		cur_idx;
	int		next_idx;
	int		child_idx_1;
	int		child_idx_2;

	if (heap_size == 0)
		return ;
	heap[1] = heap[heap_size];
	cur_idx = 1;
	child_idx_1 = cur_idx * 2;
	child_idx_2 = cur_idx * 2 + 1;
	while (1) {
		if (child_idx_2 <= heap_size) {
			if (heap[child_idx_1].val > heap[child_idx_2].val)
				next_idx = child_idx_1;
			else
				next_idx = child_idx_2;
		}
		else if (child_idx_1 <= heap_size)
			next_idx = child_idx_1;
		else
			break ;
		if (heap[cur_idx].val < heap[next_idx].val) {
			my_swap(&heap[cur_idx], &heap[next_idx]);
			cur_idx = next_idx;
			child_idx_1 = cur_idx * 2;
			child_idx_2 = cur_idx * 2 + 1;
		}
		else
			break ;
	}
	--heap_size;
}

void	dfs(int cur, t_info mul)
{
	int	mul_pre;

	if (cur > N) {
		push(&mul);
		for (int i = 1; i <= N; ++i)
			printf("%d:(%d), ", i, mul.a[i]);
		printf("\nval : (%d)\n", mul.val);
		return ;
	}
	mul.a[cur] = 0;
	dfs(cur + 1, mul);

	mul_pre = mul.val;
	for (int i = 1; i <= A[cur][0]; ++i) {
		if (mul.val * A[cur][i] > 1000000000)
			return ;
		else {
			mul.a[cur] = i;
			mul.val *= A[cur][i];
			dfs(cur + 1, mul);
			mul.val = mul_pre;
		}
	}
}

void	make_heap(void)
{
	t_info	temp;

	for (int i = 1; i <= N; ++i) {
		for (int j = 2; ; ++j) {
			if (A[i][j - 1] * A[i][1] > 1000000000)
				break ;
			else {
				A[i][j] = A[i][j - 1] * A[i][1];
				++A[i][0];
			}
		}
	}
	temp.val = 1;
	dfs(1, temp);
}

void	find_min(void)
{
	int		flag;
	t_info	cur;
	t_info	pre;

	for (int i = 1; i <= N; ++i)
		pre.a[i] = A[i][0];
	while (K > 0) {
		cur = heap[1];
		while (K < cur.val) {
			pop();
			cur = heap[1];
		}
		flag = 1;
		while (flag == 1) {
			for (int i = 1; i <= N; ++i) {
				if (cur.a[i] > pre.a[i]) {
					flag = 1;
					pop();
					cur = heap[1];
					break ;
				}
				else if (i == N)
					flag = 0;
			}
		}

		while (K >= cur.val) {
			printf("K = %d, cur = %d\n", K, cur.val);
			K -= cur.val;
			++res;
		}
		pre = cur;
	}
}

int	main(void)
{
	int	tc;

	// ios::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		res = 0;
		heap_size = 0;
		cin >> N;
		for (int j = 1; j <= N; ++j) {
			A[j][0] = 1;
			cin >> A[j][1];
		}
		cin >> K;

		make_heap();

		for (int i = 1; i <= N; ++i) {
			printf("%d : ", i);
			for (int j = 1; j <= A[i][0]; ++j) {
				printf("%lld ", A[i][j]);
			}
			printf("\n");
		}
		printf("\n\nheap : ");
		for (int i = 1; i <= heap_size; ++i) {
			printf("%d ", heap[i].val);
		}
		printf("\n");

		find_min();
		cout << "#" << i << " " << res << "\n";
	}
	return (0);
}