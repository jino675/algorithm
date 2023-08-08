/*
No. 21 0/1 Knapsack
참여자 96 제출 188 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

민수에게는 1번부터 N번까지의 번호가 부여된 N(1≤N≤100)개의 물건과 최대 K(1≤K≤1000) 부피만큼을 넣을 수 있는 가방이 있다.

1번 물건부터 N번 물건 각각은 부피  Vi와 가치 Ci 를 가지고 있다. (1≤Vi, Ci≤100)

민수는 물건들 중 몇 개를 선택하여 가방에 넣어서 그 가치의 합을 최대화하려고 한다.

단, 선택한 물건들의 부피 합이 K 이하여야 한다.

민수가 가방에 담을 수 있는 최대 가치를 계산하자.

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫째 줄에 물건의 개수와 가방의 부피인 N K가 주어진다.

다음 N개의 줄에 걸쳐서 i번 물건의 정보를 나타내는 부피  Vi와 가치 Ci가 주어진다.

[출력]

각 테스트 케이스마다 가방에 담을 수 있는 최대 가치를 출력한다.

입력
1
4 5
1 2
3 2
4 4
2 3

sample_input.txt
출력
#1 6
*/
#include <stdio.h>
#include <stdlib.h>

int	N;
int	K;
int	table[101][1001];
int	V[101];
int	C[101];
int	max_value;

void	knapsack(void)
{
	max_value = 0;
	// printf("1 2 3 4 5 6 7 8 9 10\n");
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (i == 1) {
				if (V[i] <= j)
					table[i][j] = C[i];
				else
					table[i][j] = 0;
			}
			else {
				if (V[i] <= j) {
					if (table[i - 1][j] < (table[i - 1][j - V[i]] + C[i]))
						table[i][j] = table[i - 1][j - V[i]] + C[i];
					else
						table[i][j] = table[i - 1][j];
				}
				else
					table[i][j] = table[i - 1][j];
			}
			if (table[i][j] > max_value)
				max_value = table[i][j];
			// printf("%d ", table[i][j]);
		}
		// printf("\n");
	}
}


int	main(void)
{
	int	tc;

	setbuf(stdout, NULL);
	scanf(" %d", &tc);
	for (int i = 0; i < tc; ++i) {
		scanf(" %d %d", &N, &K);
		for (int j = 1; j <= N; ++j) {
			scanf(" %d %d", &V[j], &C[j]);
		}
		knapsack();
		printf("#%d %d\n", i + 1, max_value);
	}
}