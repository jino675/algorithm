/*
No. 20 최장 공통 부분 수열
참여자 98 제출 196 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

주어진 두 문자열의 최대 공통 부분 수열(Longest Common Sequence)의 길이를 계산하는 프로그램을 작성하시오.

예를 들어 "acaykp"와 "capcak"의 경우, 두 문자열의 최대 공통 부분 수열은 "acak"로 길이가 4이다.

최장 공통 부분문자열(Longest Common Substring)을 계산하는 것이 아님에 주의한다.

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫째 줄에 두 문자열이 공백을 사이에 두고 주어진다.

각 문자열은 알파벳 소문자로만 구성되어 있음이 보장된다.

각 문자열의 길이는 1,000 이하의 자연수이다.

[출력]

각 테스트 케이스마다 ‘#T’(T는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 최대 공통 부분 수열의 길이를 출력한다.

입력
1
acaykp capcak

sample_input.txt
출력
#1 4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	str_1[1002];
char	str_2[1002];
int		table[1001][1001];
int		max[1001];
int		size_1;
int		size_2;
int		res;

void	lcs(void)
{
	res = 0;
	for (int i = 0; i <= size_1; ++i) {
		for (int j = 0; j <= size_2; ++j) {
			if (i == 0)
				max[j] = 0;
			else if (j > 2 && max[j - 1] < max[j - 2])
				max[j - 1] = max[j - 2];

			if (i > 0 && j > 0 && table[i - 1][j - 1] > max[j - 1])
				max[j - 1] = table[i - 1][j - 1];

			if (i == 0 || j == 0)
				table[i][j] = 0;
			else if (str_1[i] == str_2[j]) {
				table[i][j] = max[j - 1] + 1;
				if (table[i][j] > res)
					res = table[i][j];
			}
			else
				table[i][j] = 0;

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
		scanf(" %s %s", str_1 + 1, str_2 + 1);
		size_1 = strlen(str_1 + 1);
		size_2 = strlen(str_2 + 1);
		lcs();
		printf("#%d %d\n", i + 1, res);
	}
	return (0);
}