/*
No. 4 [S/W 문제해결 기본] 8일차 - 암호문3
참여자 75 제출 120 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

0 ~ 999999 사이의 수를 나열하여 만든 암호문이 있다.

암호문을 급히 수정해야 할 일이 발생했는데, 이 암호문은 특수 제작된 처리기로만 수정이 가능하다.

이 처리기는 다음과 같이 3개의 기능을 제공한다.
 
1. I(삽입) x, y, s : 앞에서부터 x의 위치 바로 다음에 y개의 숫자를 삽입한다. s는 덧붙일 숫자들이다.[ ex) I 3 2 123152 487651 ]

2. D(삭제) x, y : 앞에서부터 x의 위치 바로 다음부터 y개의 숫자를 삭제한다.[ ex) D 4 4 ]

3. A(추가) y, s : 암호문의 맨 뒤에 y개의 숫자를 덧붙인다. s는 덧붙일 숫자들이다. [ ex) A 2 421257 796813 ]

위의 규칙에 맞게 작성된 명령어를 나열하여 만든 문자열이 주어졌을 때, 암호문을 수정하고, 수정된 결과의 처음 10개 숫자를 출력하는 프로그램을 작성하여라.

[입력]

첫 번째 줄 : 원본 암호문의 길이 N ( 2000 ≤ N ≤ 4000 의 정수)

두 번째 줄 : 원본 암호문

세 번째 줄 : 명령어의 개수 ( 250 ≤ M ≤ 500 의 정수)

네 번째 줄 : 명령어

위와 같은 네 줄이 한 개의 테스트 케이스이며, 총 10개의 테스트 케이스가 주어진다.

[출력]

#기호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 수정된 암호문의 처음 10개 항을 출력한다.

[제약 사항]

실행 시간 60ms 이하

입력
3198
801199 482510 422184 242474 876697 940126 116534 339876 247263 458098 825098 223019 514111 303365 893555 243643 601338 454353 574796 689563 658854 865075 999888 791926 506889 150144 881247 837754 384870 933366 151318 687639 496390 595628 735176 968833 750368...
425
I 3186 6 111702 108909 437791 460849 808743 573893 A 6 902149 801457 885061 112389 207283 358796 A 1 989955 D 1100 5 D 613 9 D 998 1 D 2199 8 D 587 6 D 143 8 D 1945 6 I 5 1 362947 I 7 4 625354 271596 881263 415567 D 2452 10 A 6 351214 252282 334858 374262 106813 994606 I 1511 6 620092 829075 862184 856364 360195 511867 D 1320 6 A 8 871822 227120 817588 231183 650912 326064 820579 435543 D 2700 9 D 2175 9...
2480
462938 344563 399723 402947 549987 412958 420530 303429 692228 880290 950090 345253 201473 654529 200533 208289 931176 689125 751855 263503 586373 771415 616316 329388 671296 159465 930131 534966 554443 543621 857436 778109 367173 183314 320579 535313 592073...
486
A 3 901476 874927 362782 I 2368 7 286743 531172 693997 463259 976783 950242 673417 I 1466 3 145128 911981 664388 A 6 297281 402815 844393 472552 109416 648820 A 7 204996 777689 213612 161950 105193 439798 213002 D 142 8 I 330 3 803653 583330 161345...

input.txt
출력
#1 471034 815406 542284 170257 228297 740370 785047 677617 834173 648732
#2 364373 466241 450661 237978 437060 679163 812457 727955 262600 218437
...
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
	for (int i = 0; i < y; ++i) {
		temp = (t_list *)calloc(1, sizeof(t_list));
		scanf(" %d", &temp->data);
		temp->next = ptr->next;
		ptr->next = temp;
		ptr = ptr->next;
	}
}

void	delete_list(void)
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
	for (int i = 0; i < y; ++i) {
		if (ptr->next == NULL)
			break ;
		temp = ptr->next;
		ptr->next = temp->next;
		free(temp);
	}
}

void	append_list(void)
{
	int		y;
	t_list	*ptr;
	t_list	*temp;

	scanf(" %d", &y);
	ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	for (int i = 0; i < y; ++i) {
		temp = (t_list *)calloc(1, sizeof(t_list));
		scanf(" %d", &temp->data);
		ptr->next = temp;
		ptr = ptr->next;
	}
}

int main(void)
{
	int		N;
	int		M;
	int		input;
	char	cmd;
	t_list	*ptr;

	setbuf(stdout, NULL);
	// freopen("input.txt", "r", stdin);
	for (int i = 0; i < 10; ++i) {
		scanf(" %d", &N);
		head = (t_list *)calloc(1, sizeof(t_list));
		ptr = head;
		for (int j = 0; j < N; ++j) {
			scanf(" %d", &input);
			ptr->next = (t_list *)calloc(1, sizeof(t_list));
			ptr = ptr->next;
			ptr->data = input;
		}
		scanf(" %d", &M);
		for (int j = 0; j < M; ++j) {
			scanf(" %c", &cmd);
			if (cmd == 'I')
				insert_list();
			else if (cmd == 'D')
				delete_list();
			else if (cmd == 'A')
				append_list();
		}
		ptr = head->next;
		for (int j = 0; j < 10; ++j) {
			if (j == 0)
				printf("#%d ", i + 1);
			printf("%d", ptr->data);
			if (j != 9)
				printf(" ");
			else if (j == 9)
				printf("\n");
			ptr = ptr->next;
		}
	}
	return (0);
}