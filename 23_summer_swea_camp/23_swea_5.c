/*
No. 5 수열 편집
참여자 131 제출 268 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


N개의 10억 이하 자연수로 이뤄진 수열이 주어진다. 이 수열은 완성된 것이 아니라 M번의 편집을 거쳐 완성된다고 한다.

완성된 수열에서 인덱스 L의 데이터를 출력하는 프로그램을 작성하시오.

다음은 미완성 수열과 편집의 예이다.
 
인덱스			 수열
				
0				1
				
1				2
				
2				3
				
3				4
				
4				5

I 2 7 -> 2번 인덱스 앞에 7을 추가하고, 한 칸 씩 뒤로 이동한다.
 
인덱스			 수열
				
0				1
				
1				2
				
2				7
				
3				3
				
4				4
				
5				5

D 4 -> 4번 인덱스 자리를 지우고, 한 칸 씩 앞으로 이동한다.
 
인덱스

0

1

2

3

4

수열

1

2

7

3

5



C 3 8 -> 3번 인덱스 자리를 8로 바꾼다.
 
인덱스

0

1

2

3

4

수열

1

2

7

8

5



만약 편집이 끝난 후 L이 존재하지 않으면 -1을 출력한다.


[입력]

첫 줄에 테스트케이스의 수 T가 주어진다. 1<=T<=50

다음 줄부터 테스트 케이스의 별로 첫 줄에 수열의 길이 N, 추가 횟수 M, 출력할 인덱스 번호 L이 주어지고, 다음 줄에 수열이 주어진다.

그 다음 M개의 줄에 걸쳐 추가할 인덱스와 숫자 정보가 주어진다. 5<=N<=1000, 1<=M<=1000, 6<=L<=N+M

각 I, D, C 명령에서 입력 받는 인덱스의 위치가 존재하지 않는 불가능한 경우는 입력으로 들어오지 않는다.


[출력]

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다.
 

입력
3
5 3 4
1 2 3 4 5
I 2 7
D 4
C 3 8
5 5 2
15171 7509 20764 13445 10239
C 3 18707
C 1 20250
D 2
D 2
C 0 7158
10 10 8
27454 29662 2491 1819 10118 15441 7357 23618 972 398
D 7
D 1
D 6
I 3 2906
C 1 27121
D 3
D 2
D 1
D 2
C 2 20794	 
sample_input.txt
출력
#1 5
#2 10239
#3 -1
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

t_list	*head;

void	insert_list(void)
{
	int		cur;
	int		x;
	int		y;
	t_list	*ptr;
	t_list	*temp;

	scanf(" %d %d", &x, &y);
	cur = 0;
	ptr = head;
	while (ptr != NULL) {
		if (cur == x)
			break ;
		ptr = ptr->next;
		++cur;
	}
	temp = (t_list *)calloc(1, sizeof(t_list));
	temp->data = y;
	temp->next = ptr->next;
	ptr->next = temp;
}

void	delete_list(void)
{
	int		cur;
	int		x;
	t_list	*ptr;
	t_list	*temp;

	scanf(" %d", &x);
	cur = 0;
	ptr = head;
	while (ptr != NULL) {
		if (cur == x)
			break ;
		ptr = ptr->next;
		++cur;
	}
	temp = ptr->next;
	ptr->next = temp->next;
	free(temp);
}

void	change_list(void)
{
	int		cur;
	int		x;
	int		y;
	t_list	*ptr;

	scanf(" %d %d", &x, &y);
	cur = 0;
	ptr = head->next;
	while (ptr != NULL) {
		if (cur == x)
			break ;
		ptr = ptr->next;
		++cur;
	}
	ptr->data = y;
}

void	print_node(int idx)
{
	int		cur;
	t_list	*ptr;

	cur = 0;
	ptr = head->next;
	while (ptr != NULL) {
		if (cur == idx)
			break ;
		ptr = ptr->next;
		++cur;
	}
	if (ptr != NULL)
		printf("%d\n", ptr->data);
	else
		printf("-1\n");
}

int main(void)
{
	int		N;
	int		M;
	int		L;
	int		tc;
	int		input;
	char	cmd;
	t_list	*ptr;

	setbuf(stdout, NULL);
	scanf(" %d", &tc);
	// freopen("input.txt", "r", stdin);
	for (int i = 0; i < tc; ++i) {
		scanf(" %d %d %d", &N, &M, &L);
		head = (t_list *)calloc(1, sizeof(t_list));
		ptr = head;
		for (int j = 0; j < N; ++j) {
			scanf(" %d", &input);
			ptr->next = (t_list *)calloc(1, sizeof(t_list));
			ptr = ptr->next;
			ptr->data = input;
		}
		for (int j = 0; j < M; ++j) {
			scanf(" %c", &cmd);
			if (cmd == 'I')
				insert_list();
			else if (cmd == 'D')
				delete_list();
			else if (cmd == 'C')
				change_list();
		}
		printf("#%d ", i + 1);
		print_node(L);
	}
	return (0);
}