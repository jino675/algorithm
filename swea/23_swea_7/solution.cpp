/*
No. 7 기초 Double Linked List 연습
참여자 119 제출 164 배점 100
Problem제출이력정답
시간 : 3개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 1초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다. 

 




주어진 구조체와 함수를 사용하여, Double Linked List 를 만들어 보자.

 






 

아래의 함수들을 구현해야 한다.
새로운 노드의 할당은 주어진 getNode()를 이용하라.
리스트에 추가되는 data의 값은 중복되지 않는다.




 
입력
3
1 5
6
1 4
6
1 3
6
1 2
6
2 7
6
3 1 1
6
3 6 6
6
3 8 8
6
5 1
6
2 9
3 10 9
3 1 1
6
7
99
1 5
1 3
2 9
3 7 3
3 2 1
4 9
5 9
4 2
6
7
99
1 100
1 99
1 85
2 204
2 303
3 123 4
3 125 5
5 77
5 85
3 888 7
1 85
2 999
3 77 1
5 100
3 111 4
1 11
6
7
99	 
dll_input.txt
출력
#1
5
4 5
3 4 5
2 3 4 5
2 3 4 5 7
1 2 3 4 5 7
1 2 3 4 5 6 7
1 2 3 4 5 6 7 8
2 3 4 5 6 7 8
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1

#2
5
1
2 3 5 7
7 5 3 2

#3
11 77 85 99 111 123 125 204 303 888 999
999 888 303 204 125 123 111 99 85 77 11
*/
#include <stdlib.h>
#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = NULL;
	node[nodeCnt].next = NULL;
	return &node[nodeCnt++];
}

void init()
{
	head = getNode(0);
}

void addNode2Head(int data) 
{
	Node	*temp;

	temp = getNode(data);
	temp->next = head->next;
	temp->prev = head;
	if (head->next != NULL)
		head->next->prev = temp;
	head->next = temp;
}

void addNode2Tail(int data) 
{
	Node	*temp;
	Node	*ptr;

	temp = getNode(data);
	ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	temp->prev = ptr;
	ptr->next = temp;
}

void addNode2Num(int data, int num) 
{
	int		i;
	Node	*temp;
	Node	*ptr;

	temp = getNode(data);
	ptr = head;
	i = 1;
	while (i < num && ptr->next != NULL) {
		ptr = ptr->next;
		++i;
	}
	if (i == num) {
		temp->next = ptr->next;
		temp->prev = ptr;
		if (ptr->next != NULL)
			ptr->next->prev = temp;
		ptr->next = temp;
	}
}

int findNode(int data) 
{
	int		cur_data;
	int 	i;
	Node	*ptr;

	ptr = head;
	i = 1;
	while (ptr->next != NULL) {
		cur_data = ptr->next->data;
		if (cur_data == data) {
			return (i);
			break ;
		}
		ptr = ptr->next;
		++i;
	}
	return (-1);
}

void removeNode(int data) 
{
	Node	*ptr;
	int		cur_data;

	ptr = head->next;
	while (ptr != NULL) {
		cur_data = ptr->data;
		if (cur_data == data) {
			if (ptr->next != NULL)
				ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
			break ;
		}
		ptr = ptr->next;
	}
}

int getList(int output[MAX_NODE]) 
{
	int		i;
	Node	*ptr;

	i = -1;
	ptr = head->next;
	while (ptr != NULL) {
		output[++i] = ptr->data;
		ptr = ptr->next;
	}
	++i;
	return (i);
}

int getReversedList(int output[MAX_NODE]) 
{
	int		i;
	Node	*ptr;

	ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	i = -1;
	while (ptr != head) {
		output[++i] = ptr->data;
		ptr = ptr->prev;
	}
	++i;
	return (i);
}