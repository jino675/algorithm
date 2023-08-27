/*
No. 8 [Pro] 공지방송
참여자 4 제출 6 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 1초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
﻿﻿[제한 사항]

 

시간

 25개 테스트케이스를 합쳐서 C++ 의 경우 3초 / Java 의 경우 3초

메모리

 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내

 

 

※ 본 문제는 임직원의 S/W 문제해결 역량 향상을 위한 Professional 실전형 연습문제이며

 

함께 제공되는 Testcase 또한 학습을 위한 연습용입니다.

 

  ①   C 또는 C++로 답안을 작성하시는 응시자께서는 검정시스템에 제출 시, Language 에서 C++ 를 선택하신 후 제출하시기 바랍니다.

  ②   Main 과 User Code 부분으로 구성되어 있습니다.

  ㅇ   A.  Main         : 수정할 수 없는 코드이며, 채점 시 비 정상적인 답안 검출 등 평가를 위한 로직이 추가 될 수 있습니다.

  ㅇ   B.  User Code  : 실제 응시자가 작성해야 하는 코드이며, 제출 시에는 표준 입출력 함수가 포함되어 있으면 안 됩니다.

  ③   Local PC 에서 프로그래밍 시 유의 사항

  ㅇ   A.  2개의 파일을 생성하셔야 합니다. ( main.cpp / solution.cpp 또는 Solution.java / UserSolution.java )

  ㅇ   B.  Main 부분의 코드를 main.cpp 또는 Solution.java 에 복사해서 사용하시기 바랍니다.

  ㅇ   C.  sample_input.txt 를 사용하시기 위해서는 Main 부분의 코드 내에

  ㅇ   C.  표준 입력을 파일로 전환하는 코드 ( 주석처리 되어 있음 ) 의 주석을 풀어서 사용하시면 됩니다.

  ㅇ   D.  User Code 부분의 코드를 작성하신 후 서버에 제출하실 때,

  ㅇ   D.  디버깅을 위한 표준 입출력 함수를 모두 삭제 또는 주석 처리해 주셔야 합니다.

  ④   문제 내에 제약조건을 모두 명시하지 않으므로 주어지는 코드를 분석하셔야 합니다.

  ⑤   코드는 개발 언어에 따라 상이할 수 있으므로, 작성할 언어를 기준으로 분석하셔야 합니다.

 

[문제 설명]

사원의 출퇴근 시각이 주어진다.

회사에서 M명 이상이 공지 방송을 들을 수 있도록 방송 시작 시각을 정하고자 한다.
 

[Fig. 1]은 5명의 출퇴근 시각이 주어진 예이다. 1번 사원은 0초에 출근하고 4초에 퇴근한다.
2번 사원은 3초에 출근하고 13초에 퇴근한다.



[Fig. 1]

공지 방송의 시간이 2초이고, 2명 이상이 공지 방송을 들어야 한다면, 가장 빠른 시작 시각은 3초이다.

공지 방송의 시간이 2초이고, 3명 이상이 공지 방송을 들어야 한다면, 가장 빠른 시작 시각은 8초이다.

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init()

각 테스트 케이스의 처음에 호출된다.

등록된 출퇴근 시각이 없다.

int add(int mId, int mStart, int mEnd)

ID가 mId인 사원의 출근 시각 mStart과 퇴근 시각 mEnd을 추가한다.

각 시각은 초단위로 주어진다.

만약에 이미 존재하는 ID라면, 추가하지 않고 기존의 출퇴근 시각을 변경한다.

삭제되었던 사원이 다시 추가될 수도 있다.

 

Parameters

  mId: 사원 ID ( 1 ≤ mId ≤ 1,000,000,000 )

  mStart: 출근 시각 ( 0 ≤ mStart < 85,400 )

  mEnd: 퇴근 시각 ( mStart < mEnd < 86,400 )

 

Returns

  출퇴근 시각이 등록된 사원 수를 반환한다.

int remove(int mId)

ID가 mId인 사원의 출퇴근 시각을 삭제한다.

이미 삭제된 사원의 ID가 주어질 수도 있다.

 

Parameters

  mId: 사원 ID ( 1 ≤ mId ≤ 1,000,000,000 )

 

Returns

  출퇴근 시각이 등록된 사원 수를 반환한다.

int announce(int mDuration, int M)

공지 방송의 시간이 mDuration이고, 방송을 들어야 하는 최소 인원 수가 M명으로 주어진다.

M명 이상이 방송을 모두 들을 수 있는 가장 빠른 방송 시작 시각을 반환한다.

가능한 방송 시작 시각이 없다면 -1을 반환한다.

 

Parameters

  mDuration: 공지 방송 시간 ( 2 ≤ mDuration ≤ 3,600 )

  M: 방송을 들어야 하는 최소 인원 수 ( 2 ≤ M ≤ 2,500 )

 

Returns

  M명 이상이 방송을 들을 수 있다면, 가장 빠른 방송 시작 시각을 반환한다.
  그렇지 않을 경우, -1을 반환한다.

 

[예제]

아래의 [Table 1]과 같이 요청이 되는 경우를 살펴보자.

Order

Function

return

Figure

1

init()

 

 

2

add(1, 0, 4)

1

 

3

add(2, 3, 13)

2

 

4

add(3, 4, 10)

3

 

5

add(4, 11, 23)

4

 

6

add(5, 8, 18)

5

Fig. 1

7

announce(2, 2)

3

 

8

announce(2, 3)

8

 

9

announce(3, 3)

8

 

10

remove(3)

4

Fig. 2

11

announce(3, 3)

11

 

[Table 1]

(순서 1) 초기에 출퇴근 시각이 등록된 사원이 없다.

(순서 2) ID가 1이고, 출근 시각이 0초, 퇴근 시각이 4초인 사원이 추가된다. 등록된 총 사원 수로 1을 반환한다.

(순서 3) ID가 2이고, 출근 시각이 3초, 퇴근 시각이 13초인 사원이 추가된다. 등록된 총 사원 수로 2를 반환한다.

(순서 4) ID가 3이고, 출근 시각이 4초, 퇴근 시각이 10초인 사원이 추가된다. 등록된 총 사원 수로 3을 반환한다.

(순서 5) ID가 4이고, 출근 시각이 11초, 퇴근 시각이 23초인 사원이 추가된다. 등록된 총 사원 수로 4를 반환한다.

(순서 6) ID가 5이고, 출근 시각이 8초, 퇴근 시각이 18초인 사원이 추가된다. 등록된 총 사원 수로 5를 반환한다.
함수 호출의 결과는 [Fig. 1]과 같다.

(순서 7) 공지 방송의 시간이 2초이고, 2명 이상이 공지 방송을 들어야 한다. 가장 빠른 방송 시작 시각은 3초이다.

(순서 8) 공지 방송의 시간이 2초이고, 3명 이상이 공지 방송을 들어야 한다. 가장 빠른 방송 시작 시각은 8초이다.

(순서 9) 공지 방송의 시간이 3초이고, 3명 이상이 공지 방송을 들어야 한다. 가장 빠른 방송 시작 시각은 8초이다.

(순서 10) ID가 3인 사원을 삭제한다. 함수 호출의 결과는 [Fig. 2]와 같다.



[Fig. 2]

(순서 11) 공지 방송의 시간이 3초이고, 3명 이상이 공지 방송을 들어야 한다. 가장 빠른 방송 시작 시각은 11초이다.

 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. 각 테스트 케이스에서 add() 함수의 호출 횟수는 8,000 이하이다.

3. 각 테스트 케이스에서 remove() 함수의 호출 횟수는 1,700 이하이다.

4. 각 테스트 케이스에서 announce() 함수의 호출 횟수는 300 이하이다.
*/
#include <iostream>
#include <unordered_map>

#define	TIME_MAX 86399

using namespace std;

typedef struct s_employee
{
	int	start;
	int	end;
	int	is_hired;
}	t_employee;

t_employee	employee_pool[8000];
int			employee_pool_cnt;

typedef struct s_node
{
	int				start;
	int				end;
	int				cnt;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	node_pool[40000];
int		node_pool_cnt;

typedef struct s_list
{
	t_node	head;

	void	clear(void) {
		t_node	*new_node = &node_pool[node_pool_cnt++];

		new_node->start = 0;
		new_node->end = TIME_MAX;
		new_node->cnt = 0;
		new_node->prev = &head;
		new_node->next = &head;
		head.next = new_node;
		head.prev = new_node;
	}
	void	insert(t_node *cur_node, t_node *new_node) {
		new_node->prev = cur_node->prev;
		new_node->next = cur_node;
		cur_node->prev->next = new_node;
		cur_node->prev = new_node;
	}
	void	erase(t_node *cur_node) {
		cur_node->prev->next = cur_node->next;
		cur_node->next->prev = cur_node->prev;
	}
	t_node	*begin(void) {
		return (head.next);
	}
	t_node	*end(void) {
		return (&head);
	}
	bool	isEmpry(void) {
		if (head.next == &head)
			return (true);
		else
			return (false);
	}
	void	print_all(void) {
		t_node	*cur_node = begin();

		printf("[list]\n");
		while (cur_node != end()) {
			printf("{s : %d, e : %d, cnt : %d}\n", cur_node->start, cur_node->end, cur_node->cnt);
			cur_node = cur_node->next;
		}
		printf("\n");
	}
}	t_list;

t_list	time_list;
int		cur_employee_cnt;

unordered_map<int, t_employee *>	id_table;

int	check_left(t_node *cur_node, int cur_left_cnt)
{
	if (cur_node->prev != time_list.end())
		if (cur_node->prev->cnt == cur_left_cnt)
			return (1);
	return (0);
}

int	check_right(t_node *cur_node, int cur_right_cnt)
{
	if (cur_node->next != time_list.end())
		if (cur_node->next->cnt == cur_right_cnt)
			return (1);
	return (0);
}

t_node	*make_new_node(int start, int end, int cnt)
{
	t_node	*new_node = &node_pool[node_pool_cnt++];

	new_node->start = start;
	new_node->end = end;
	new_node->cnt = cnt;
	return (new_node);
}

void	update(int a, int b, int val)
{
	t_node	*cur_node, *new_node;

	cur_node = time_list.begin();
	while (cur_node != time_list.end()) {
		if (a <= cur_node->start && cur_node->start <= b && b < cur_node->end) {
			// if (check_left(cur_node, cur_node->cnt + val) == 1) {
			// 	cur_node->prev->end = b;
			// }
			// else {
				new_node = make_new_node(cur_node->start, b, cur_node->cnt + val);
				time_list.insert(cur_node, new_node);
			// }
			cur_node->start = b + 1;
			return ;
		}
		else if (cur_node->start < a && b < cur_node->end) {
			new_node = make_new_node(cur_node->start, a - 1, cur_node->cnt);
			time_list.insert(cur_node, new_node);
			new_node = make_new_node(a, b, cur_node->cnt + val);
			time_list.insert(cur_node, new_node);
			cur_node->start = b + 1;
			return ;
		}
		else if (cur_node->start < a && a <= cur_node->end && cur_node->end <= b) {
			if (cur_node->end == b) {
				// if (check_right(cur_node, cur_node->cnt + val) == 1) {
				// 	cur_node->next->start = a;
				// 	cur_node->end = a - 1;
				// }
				// else {
					new_node = make_new_node(cur_node->start, a - 1, cur_node->cnt);
					time_list.insert(cur_node, new_node);
					cur_node->start = a;
					cur_node->cnt = cur_node->cnt + val;
				// }
				return ;
			}
			else {
				new_node = make_new_node(cur_node->start, a - 1, cur_node->cnt);
				time_list.insert(cur_node, new_node);
				cur_node->start = a;
				cur_node->cnt = cur_node->cnt + val;
			}
		}
		else if (a <= cur_node->start && cur_node->end <= b) {
			if (cur_node->end == b) {
				// if (check_left(cur_node, cur_node->cnt + val) == 1) {
				// 	if (check_right(cur_node, cur_node->cnt + val) == 1) {
				// 		cur_node->prev->end = cur_node->next->end;
				// 		time_list.erase(cur_node->next);
				// 	}
				// 	else
				// 		cur_node->prev->end = cur_node->end;
				// 	time_list.erase(cur_node);
				// }
				// else {
				// 	if (check_right(cur_node, cur_node->cnt + val) == 1) {
				// 		cur_node->next->start = cur_node->start;
				// 		time_list.erase(cur_node);
				// 	}
					// else
						cur_node->cnt = cur_node->cnt + val;
				// }
				return ;
			}
			else {
				// if (check_left(cur_node, cur_node->cnt + val) == 1) {
				// 	cur_node->prev->end = cur_node->end;
				// 	time_list.erase(cur_node);
				// }
				// else
					cur_node->cnt = cur_node->cnt + val;
			}
		}
		cur_node = cur_node->next;
	}
}

void init()
{
	employee_pool_cnt = 0;
	node_pool_cnt = 0;
	cur_employee_cnt = 0;
	time_list.clear();
	id_table.clear();
}

int add(int mId, int mStart, int mEnd)
{
	t_employee	*cur_employee;

	auto	iter = id_table.find(mId);
	if (iter != id_table.end()) {
		cur_employee = (*iter).second;
		if (cur_employee->is_hired == 1) {
			update(cur_employee->start, cur_employee->end, -1);
			time_list.print_all();
			--cur_employee_cnt;
		}
	}
	else {
		cur_employee = &employee_pool[employee_pool_cnt++];
		id_table[mId] = cur_employee;
	}
	cur_employee->start = mStart;
	cur_employee->end = mEnd;
	cur_employee->is_hired = 1;
	++cur_employee_cnt;
	update(cur_employee->start, cur_employee->end, 1);
	time_list.print_all();
	return (cur_employee_cnt);
}

int remove(int mId)
{
	t_employee	*cur_employee;

	auto	iter = id_table.find(mId);
	if (iter != id_table.end()) {
		cur_employee = (*iter).second;
		if (cur_employee->is_hired == 1) {
			printf("start : %d, end : %d\n", cur_employee->start, cur_employee->end);
			update(cur_employee->start, cur_employee->end, -1);
			time_list.print_all();
			cur_employee->is_hired = 0;
			--cur_employee_cnt;
		}
	}
	return (cur_employee_cnt);
}

int announce(int mDuration, int M)
{
	int		cur_duration, cur_start;
	t_node	*cur_node;

	time_list.print_all();
	cur_start = 0;
	cur_duration = 0;
	cur_node = time_list.begin();
	while (cur_node != time_list.end()) {
		if (cur_node->cnt >= M) {
			if (cur_duration == 0)
				cur_start = cur_node->start;
			cur_duration += cur_node->end - cur_node->start + 1;
			if (cur_duration >= mDuration)
				return (cur_start);
		}
		else if (cur_node->cnt < M && cur_duration > 0)
			cur_duration = 0;
		cur_node = cur_node->next;
	}
	return (-1);
}