/*
No. 6 기초 Single Linked List 연습
참여자 131 제출 190 배점 100
Problem제출이력정답
시간 : 3개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 1초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다. 

 




주어진 구조체와 함수를 사용하여,
Single Linked List 를 만들어 보자.


 


 

아래의 함수들을 구현해야 한다.
 

(조건)
 

새로운 노드를 할당은 주어진 getNode()를 이용하라.
리스트에 추가되는 data의 값은 중복되지 않는다.

입력
3
1 5
5
1 4
5
1 3
5
1 2
5
2 7
5
3 1 1
5
3 6 6
5
3 8 8
5
...	 
sll_input.txt
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

#2
2 3 5 7

#3
11 77 85 99 111 123 125 204 333
*/
#include <malloc.h>

#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
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
		ptr->next = temp;
	}
}

void removeNode(int data) 
{
	Node	*ptr;
	int		cur_data;

	ptr = head;
	while (ptr->next != NULL) {
		cur_data = ptr->next->data;
		if (cur_data == data) {
			ptr->next = ptr->next->next;
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