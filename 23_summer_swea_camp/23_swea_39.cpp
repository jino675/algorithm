/*
No. 39 사탕 가방
참여자 50 제출 163 배점 100
Problem제출이력정답
시간 : 200개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다. 

N종류의 사탕이 있고, 각 종류마다 A1,A2,…,AN개의 사탕이 있다. 이 사탕을 가방에 잘 나눠 넣고 싶은데 다음과 같은 조건을 만족해야 한다.

- 가방 안에 정확히 M개의 사탕이 들어 있어야 한다.
- 모든 가방에 들어 있는 사탕 종류의 구성이 같아야 한다.

최대 몇 개의 사탕 가방을 만들 수 있는지 구하는 프로그램을 작성하라.

 

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 두 정수 N, M (1 ≤ N ≤ 100, 1 ≤ M ≤ 1018)가 공백 하나로 구분되어 주어진다.
두 번째 줄에는 N개의 정수 A1,A2,…,AN (1 ≤ Ai ≤ 1018)이 공백 하나로 구분되어 주어진다.

[출력]
각 테스트 케이스마다 최대 몇 개의 사탕 가방을 만들 수 있는지 출력한다.

입력
4
1 100
1
3 3
5 6 7
1 9
100
4 10
6894 3441 4999 2771	 
sample_input.txt
출력
#1 0
#2 5
#3 11
#4 1666
*/
#include <iostream>
#include <climits>

using namespace std;

int			N;
unsigned long long	M;

unsigned long long	A[101];
unsigned long long	A_max;

unsigned long long	res;

void	find_max(void)
{
	unsigned long long	left, mid, right;
	unsigned long long	max_val;
	unsigned long long	cur_val;

	left = 1;
	right = A_max;
	max_val = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		// printf("cur_left : %lld, cur_mid : %lld, cur_right : %lld\n", left, mid, right);
		cur_val = 0;
		for (int i = 1; i <= N; ++i)
			cur_val += A[i] / mid;
		if (cur_val < M)
			right = mid - 1;
		else if (cur_val >= M) {				// M = 7, A = {1, 10} 이 경우 cur_val == M 인 경우 없이,
			if (mid > max_val)					// cur_val < M or cur_val > M 만 존재할 수 있다.
				max_val = mid;					// cur_val > M 인 경우는 몇 개를 버림으로써 조건을 충족시킬 수 있으므로
			left = mid + 1;						// 이 또한 정답인 경우가 된다.
		}
	}
	res = max_val;
}

int	main(void)
{
	int			tc;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N >> M;
		res = 0;
		A_max = 0;
		for (int j = 1; j <= N; ++j) {
			cin >> A[j];
			if (A[j] > A_max)
				A_max = A[j];
		}
		find_max();
		cout << "#" << i << " " << res << "\n";
	}
	return (0);
}