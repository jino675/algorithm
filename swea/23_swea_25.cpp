/*
No. 25 중간값 구하기
참여자 79 제출 244 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 10초 / Java의 경우 20초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

심심해하던 홍준이에게 어떤 문제를 줄 지 고민하던 경근이는 다음과 같은 문제를 생각하였다.

경근이가 처음에 한 개의 자연수를 공책에 적는다.

그 후, N번에 걸쳐서 자연수 2개씩을 추가적으로 공책에 적는다.

이 때, 홍준이는 경근이가 수 2개를 추가적으로 적을 때마다 지금까지 적은 수 중에 크기가 중간인 수를 알려주어야 한다.

예를 들어, 처음에 경근이가 5를 공책에 쓰고, 1과 3, 2와 6, 8과 9를 공책에 썼다고 가정하자.

자연수 1과 3을 공책에 썼을 때에는, 이전까지 적은 수가 [1, 3, 5]이고, 이 중 크기가 중간인 수는 3이다.

자연수 2과 6을 공책에 썼을 때에는, 이전까지 적은 수가 [1, 2, 3, 5, 6]이고, 이 중 크기가 중간인 수는 3이다.

자연수 8과 9를 공책에 썼을 때에는, 이전까지 적은 수가 [1, 2, 3, 5, 6, 8, 9]이고, 이 중 크기가 중간인 수는 5이다.

N개의 중간값들을 매번 출력하면 출력양이 너무 많기 때문에, 그 수들의 합을 20171109로 나눈 나머지를 출력하는 프로그램을 작성하시오.


[입력]

첫 줄에 테스트케이스의 개수 T가 주어진다. (1 ≤ T ≤ 10)

각 테스트 케이스의 첫 번째 줄에 N(1 ≤ N ≤ 200,000)과 경근이가 처음에 공책에 쓴 자연수 A가 주어진다.

이후 N개의 줄에 걸쳐서, 경근이가 공책에 쓴 자연수 2개를 나타내는 X와 Y가 순서대로 주어진다.

경근이가 공책에 쓰는 자연수는 1 이상 109 이하이다.


[출력]

각 테스트케이스마다 한 줄에 걸쳐, 테스트케이스 수 “#(테스트케이스 번호) “를 출력하고, N개의 중간값을 모두 더한 값을 20171109로 나눈 나머지를 출력한다.


[힌트]

1. N개의 중간값들을 더하는 과정에서 32bit 정수 자료형의 최대 범위를 벗어날 수 있음에 주의합니다.

따라서 중간값을 더할 때마다, 20171109로 나눈 나머지를 변수에 기록하는 것이 좋습니다.

2. 최대 힙과 최소 힙을 이용하여 문제를 해결할 수 있습니다.

입력
1
3 5
1 3
2 6
8 9

sample_input.txt
출력
#1 11
*/
#include <iostream>

using namespace std;

int	max_heap[100100];
int	max_size;
int	min_heap[100100];
int	min_size;
int	mid;

int	N;
int	res;

void	my_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	max_push(int x)
{
	int	cur_idx;
	int	parent_idx;

	cur_idx = max_size + 1;
	max_heap[cur_idx] = x;
	parent_idx = cur_idx / 2;
	while (1) {
		if (parent_idx == 0)
			break ;
		if (max_heap[cur_idx] > max_heap[parent_idx]) {
			my_swap(&max_heap[cur_idx], &max_heap[parent_idx]);
			cur_idx = parent_idx;
			parent_idx = cur_idx / 2;
		}
		else
			break ;
	}
	++max_size;
}

int	max_pop(void)
{
	int	top;
	int	cur_idx;
	int	next_idx;
	int	child_idx_1;
	int	child_idx_2;

	top = max_heap[1];
	max_heap[1] = max_heap[max_size];
	cur_idx = 1;
	child_idx_1 = cur_idx * 2;
	child_idx_2 = cur_idx * 2 + 1;
	while (1) {
		if (child_idx_2 <= max_size) {
			if (max_heap[child_idx_1] > max_heap[child_idx_2])
				next_idx = child_idx_1;
			else
				next_idx = child_idx_2;
		}
		else if (child_idx_1 <= max_size) {
			next_idx = child_idx_1;
		}
		else
			break ;
		if (max_heap[cur_idx] < max_heap[next_idx]) {
			my_swap(&max_heap[cur_idx], &max_heap[next_idx]);
			cur_idx = next_idx;
			child_idx_1 = cur_idx * 2;
			child_idx_2 = cur_idx * 2 + 1;
		}
		else
			break ;
	}
	--max_size;
	return (top);
}

void	min_push(int x)
{
	int	cur_idx;
	int	parent_idx;

	cur_idx = min_size + 1;
	min_heap[cur_idx] = x;
	parent_idx = cur_idx / 2;
	while (1) {
		if (parent_idx == 0)
			break ;
		if (min_heap[cur_idx] < min_heap[parent_idx]) {
			my_swap(&min_heap[cur_idx], &min_heap[parent_idx]);
			cur_idx = parent_idx;
			parent_idx = cur_idx / 2;
		}
		else
			break ;
	}
	++min_size;
}

int	min_pop(void)
{
	int	top;
	int	cur_idx;
	int	next_idx;
	int	child_idx_1;
	int	child_idx_2;

	top = min_heap[1];
	min_heap[1] = min_heap[min_size];
	cur_idx = 1;
	child_idx_1 = cur_idx * 2;
	child_idx_2 = cur_idx * 2 + 1;
	while (1) {
		if (child_idx_2 <= min_size) {
			if (min_heap[child_idx_1] < min_heap[child_idx_2])
				next_idx = child_idx_1;
			else
				next_idx = child_idx_2;
		}
		else if (child_idx_1 <= min_size) {
			next_idx = child_idx_1;
		}
		else
			break ;
		if (min_heap[cur_idx] > min_heap[next_idx]) {
			my_swap(&min_heap[cur_idx], &min_heap[next_idx]);
			cur_idx = next_idx;
			child_idx_1 = cur_idx * 2;
			child_idx_2 = cur_idx * 2 + 1;
		}
		else
			break ;
	}
	--min_size;
	return (top);
}

int	main(void)
{
	int	tc;
	int	input_1;
	int	input_2;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		res = 0;
		max_size = 0;
		min_size = 0;
		cin >> N >> mid;
		// printf("\nmid = %d\n\n", mid);
		for (int j = 1; j <= N; ++j) {
			cin >> input_1 >> input_2;
			if (input_1 > mid && input_2 > mid) {
				min_push(input_1);
				min_push(input_2);
				max_push(mid);
				mid = min_pop();
			}
			else if (input_1 > mid && input_2 <= mid) {
				min_push(input_1);
				max_push(input_2);
			}
			else if (input_1 > mid && input_2 < mid) {
				min_push(input_1);
				max_push(input_2);
			}
			else if (input_1 == mid && input_2 > mid) {
				min_push(input_2);
				max_push(input_1);
			}
			else if (input_1 == mid && input_2 == mid) {
				min_push(input_2);
				max_push(input_1);
			}
			else if (input_1 == mid && input_2 < mid) {
				min_push(input_1);
				max_push(input_2);
			}
			else if (input_1 < mid && input_2 > mid) {
				min_push(input_2);
				max_push(input_1);
			}
			else if (input_1 < mid && input_2 == mid) {
				min_push(input_2);
				max_push(input_1);
			}
			else if (input_1 < mid && input_2 < mid) {
				max_push(input_1);
				max_push(input_2);
				min_push(mid);
				mid = max_pop();
			}
			res = (res + mid) % 20171109;
			// printf("max_heap : ");
			// for (int k = 1; k <= max_size; ++k)
			// 	printf("%d ", max_heap[k]);
			// printf("\n");
			// printf("min_heap : ");
			// for (int k = 1; k <= min_size; ++k)
			// 	printf("%d ", min_heap[k]);
			// printf("\n");
			// printf("mid = %d\n\n", mid);
		}
		cout << "#" << i << " " << res << "\n";
	}
	return (0);
}