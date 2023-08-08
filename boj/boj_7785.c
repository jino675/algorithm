/*
회사에 있는 사람
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	33685	13722	10156	41.538%
문제
상근이는 세계적인 소프트웨어 회사 기글에서 일한다. 이 회사의 가장 큰 특징은 자유로운 출퇴근 시간이다. 따라서, 직원들은 반드시 9시부터 6시까지 회사에 있지 않아도 된다.

각 직원은 자기가 원할 때 출근할 수 있고, 아무때나 퇴근할 수 있다.

상근이는 모든 사람의 출입카드 시스템의 로그를 가지고 있다. 이 로그는 어떤 사람이 회사에 들어왔는지, 나갔는지가 기록되어져 있다. 로그가 주어졌을 때, 현재 회사에 있는 모든 사람을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 로그에 기록된 출입 기록의 수 n이 주어진다. (2 ≤ n ≤ 106) 다음 n개의 줄에는 출입 기록이 순서대로 주어지며, 각 사람의 이름이 주어지고 "enter"나 "leave"가 주어진다. "enter"인 경우는 출근, "leave"인 경우는 퇴근이다.

회사에는 동명이인이 없으며, 대소문자가 다른 경우에는 다른 이름이다. 사람들의 이름은 알파벳 대소문자로 구성된 5글자 이하의 문자열이다.

출력
현재 회사에 있는 사람의 이름을 사전 순의 역순으로 한 줄에 한 명씩 출력한다.

예제 입력 1 
4
Baha enter
Askar enter
Baha leave
Artem enter
예제 출력 1 
Askar
Artem
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
	char			name[6];
	int				status;
	struct s_list	*next;
}	t_list;

int		N;
t_list	employee[52];

int main(void)
{
	int		cmp_res;
	int		no_existed;
	int		idx_1;
	int		idx_2;
	char	in_name[6];
	char	in_status[6];
	t_list	*cur;
	t_list	*new_before;
	t_list	*new;

	for (int i = 0; i < 52; ++i)
		employee[i].next = (t_list *)calloc(52, sizeof(t_list));
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s %s", in_name, in_status);
		if (in_name[0] >= 'A' && in_name[0] <= 'Z')
			idx_1 = in_name[0] - 'A';
		else if (in_name[0] >= 'a' && in_name[0] <= 'z')
			idx_1 = in_name[0] - 'a' + 26;
		else
			idx_1 = 0;
		if (in_name[1] >= 'A' && in_name[1] <= 'Z')
			idx_2 = in_name[1] - 'A';
		else if (in_name[1] >= 'a' && in_name[1] <= 'z')
			idx_2 = in_name[1] - 'a' + 26;
		else
			idx_2 = 0;

		no_existed = -1;
		cmp_res = -1;
		new_before = &(employee[idx_1].next[idx_2]);
		for (cur = new_before->next; cur != NULL; cur = cur->next) {
			cmp_res = strcmp(cur->name, in_name);
			if (cmp_res == 0)
				break ;
			else if (cmp_res < 0) {
				no_existed = 1;
				break ;
			}
			new_before = cur;
		}
		if (cur == NULL || no_existed == 1) {
			new = (t_list *)calloc(1, sizeof(t_list));
			strcpy(new->name, in_name);
			new->next = new_before->next;
			new_before->next = new;
			cur = new;
		}
		if (in_status[0] == 'e')
			cur->status = 1;
		else if (in_status[0] == 'l')
			cur->status = 0;
	}
	for (int i = 51; i >= 0; --i) {
		for (int j = 51; j >= 0; --j) {
			for (cur = employee[i].next[j].next; cur != NULL; cur = cur->next) {
				if (cur->status == 1)
					printf("%s\n", cur->name);
			}
		}
	}
	return (0);
}