/*
No. 34 문자열 암호화
참여자 24 제출 103 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

​​​​​​​  ​​​​​​​
제한 조건

실행시간 : 최대 10개의 테스트 케이스를 합쳐서 C++ 의 경우 1초 / Java 의 경우 2초

 

메 모 리 : Heap, Global, Stack 등을 모두 합해 최대 256MB까지 사용 가능

(단, 스택은 최대 1MB까지 사용 가능)

제출 횟수 제한

99회

채점

답안을 제출하면 제공된 sample_input.txt 에 대한 결과를 판정해서 실시간으로 알려주며

그 의미는 다음과 같다.

 

Accept : sample input에 대하여 정답 또는 부분 점수 획득

 

Fail : sample input에 대하여 오답 또는 런타임 에러, time out 등

 

(※ sample_input.txt 파일 다운로드는 문제 지문 바로 아래에 있습니다)

 

최종결과는 별도의 채점용 input으로 진행되므로 시험 중 판정 결과와 다를 수 있다.

평가

최종 점수는 별도로 제작된 평가용 테스트 케이스로 측정하며,

동점자간에는 실행시간에 따라 점수 차이가 발생할 수 있습니다.

 

따라서 시험이 끝날 때까지 본인의 코드를 최적화 하시기를 권장합니다.

 





[문제 설명]

문자열을 주어진 암호화 규칙에 따라서 변환하는 프로그램을 구현하고자 한다.

이 규칙은 전체 문자열 중 부분 문자열 A 를 B 로 변환하는 규칙이다.

규칙을 적용하는 방법은 다음과 같다.

전체 문자열을 처음 index 부터 탐색하여, 부분 문자열이 A 인지 판단한다.
A 가 아닐 경우 다음 index 의 부분문자열을 탐색한다.
A 일 경우 해당 index 의 부분문자열을 B 로 변환하고, index 를 A 의 길이만큼 증가시킨 후 탐색을 계속한다.
 

당신은 규칙이 주어지는 순서에 따라 문자열을 변환하여 최종 문자열을 구해야 한다.

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 Java에 대해서는 제공되는 Solution.java와 UserSolution.java를 참고하라.

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init(int N, char init_string[])

각 테스트 케이스의 처음에 호출된다.

변환을 할 원본 문자열이 주어진다.

 

Parameters

N : 원본 문자열의 길이

init_string[] : 원본 문자열.

int change(char string_A[], char string_B[])

string_A 와 일치하는 부분문자열을 string_B로 바꾼다.

 

Parameters

string_A : 규칙을 이루는 문자열에서 찾아 변환시킬 문자열이다.

string_B : string_A 를 대체할 문자열

(string_A, string_B) 의 각 길이는 3이다.

Returns

num : 변경한 부분 문자열의 개수를 반환한다.

void result(char ret[])

최종 문자열 상태를 ret 배열에 반환한다.

이 함수는 각 테스트케이스 마지막에 한번만 호출된다.

 

[예제]

Order

Function

Note

Figure

1

init(10, “baaabbbbbb”)

 

 

2

change(“baa”, “aba”)

return 1

 

3

change(“aaa”, “bba”)

return 0

 

4

change(“bbb”, “abb”)

return 2

[Fig. 1]

5

result()

return “abaaabbabb”

 

 

testcase 1번 예제 입력에 대해서 설명하겠다.

초기 문자열은 “baaabbbbbb” 이다.

이 후 3번의 change() 함수가 호출된다.

 

첫번째 change(“baa, “aba”) 함수가 호출되면 파란색으로 표시한 부분문자열 “baa” 가 “aba” 로 변경된다.

“baaabbbbbb” => “abaabbbbbb”

변경 할 부분문자열은 1개이므로 change(“baa”,”aba”) 함수의 반환 값은 1이다.

 

두번째 change(“aaa”, “bba”) 함수가 호출되었을 때 부분문자열 중 “aaa” 가 하나도 존재하지 않으므로,

이 함수의 반환 값은 0 이다.

 

세번 째 change(“bbb”, “abb”) 함수가 호출 되면 부분문자열 “bbb” 의 개수는 4 개이다.

하지만, 변환 규칙에 의해 0 번 index 부터 순차적으로 검사하기 때문에 총 변환되는 부분문자열의 개수는 2 이다.

변환이 되는 index는 [Fig. 1] 과 같다.

 

 

마지막으로 result(char ret[]) 함수가 호출되면 ret 배열에 최종문자열 “abaaabbabb” 를 저장하여 반환한다.

 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. 문자열의 길이는 최대 50,000 이다.

3. 각 테스트 케이스에서 문자열은 영어 소문자로 이루어져 있으며 항상 ’\0’ 으로 끝난다.

4. 변환할 문자열의 길이는 항상 3 이다.

5 각 테스트 케이스에서 change() 함수가 호출되는 횟수는 최대 50,000 이다. result() 함수는 1 번만 호출 된다.

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

 

Sample input 에 대한 정답 출력 결과는 아래와 같은 형태로 보여진다.

#1 100

#2 100

#3 100

#4 100

#5 100    

 

입력
3
80 10 2 3
1
0
2
abaaabbabb
2 20 2 5
1
2
4
3
0
bbaababaabbaabbaabaa
3 30 3 10
0
1
0
0
1
1
1
0
1
0
acabcaabbaaaacabbccccaabcabcaa	//테스트 케이스 갯수























 
sample_input.txt
출력
#1 100
#2 100
#3 100	//첫번째 테스트 케이스 결과
//두번째 테스트 케이스 결과
//세번째 테스트 케이스 결과
*/
#include <iostream>
#include <cstring>
#include <list>

#define HASH_MAX 17576 //26 ^ 3

using namespace std;

typedef struct s_node
{
	int				idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	node_pool[50000];
int		node_pool_cnt;

typedef struct s_list
{
	t_node	head;

	void	clear() {
		head.next = &head;
		head.prev = &head;
	}
	void	push(t_node *node) {
		t_node	*ptr = head.next;
		while (ptr != &head) {
			if (node->idx <= ptr->idx)
				break ;
			ptr = ptr->next;
		}
		node->prev = ptr->prev;
		node->next = ptr;
		ptr->prev->next = node;
		ptr->prev = node;
	}
	t_node	*erase(t_node *node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
		return (node->next);
	}
	t_node *begin(void) {
		return (head.next);
	}
	t_node *end(void) {
		return (&head);
	}
	// void	print(void) {
	// 	t_node	*ptr = head.next;
	// 	while (ptr != &head) {
	// 		printf("%d ", ptr->idx);
	// 		ptr = ptr->next;
	// 	}
	// 	printf("\n");
	// }
}	t_list;

typedef struct s_book
{
	char			c;
	int				hash;
	struct s_node	*ptr;

}	t_book;

t_list	hash_table[HASH_MAX];
t_book	book[50000];
int		book_len;

int my_hash(char a, char b, char c)
{
	int	val;

	val = (c - 'a') * 1;
	val += (b - 'a') * 26;
	val += (a - 'a') * 26 * 26;	
	return (val);
}

int next_hash(int hash, char prev, char next)
{
	hash -= (prev - 'a') * 26 * 26;
	hash *= 26;
	hash += (next - 'a') * 1;
	return (hash);
}

void init(int N, char init_string[])
{
	t_node	*new_node;

	node_pool_cnt = 0;
	for (int i = 0; i < HASH_MAX; ++i)
		hash_table[i].clear();
	for (int i = 0; i < N; ++i) {
		book[i].c = init_string[i];
		if (i < N - 2) {
			new_node = &node_pool[node_pool_cnt++];
			new_node->idx = i;
			if (i == 0)
				book[i].hash = my_hash(init_string[i], init_string[i + 1], init_string[i + 2]);
			else
				book[i].hash = next_hash(book[i - 1].hash, init_string[i - 1], init_string[i + 2]);
			book[i].ptr = new_node;
			hash_table[book[i].hash].push(new_node);
		}
	}
	book_len = N;
}

int change(char string_A[], char string_B[])
{
	int		ppre_idx, pre_idx, cur_idx, cur_hash, new_hash, temp_idx, change_cnt;
	int		hash_A = my_hash(string_A[0], string_A[1], string_A[2]);
	t_node	*cur_node, *next_node;


	// printf("baa table : ");
	// hash_table[my_hash('b', 'a', 'a')].print();
	// printf("bac table : ");
	// hash_table[my_hash('b', 'a', 'c')].print();
	// printf("before_string : ");
	// for (int i = 0; i < book_len; ++i)
	// 	printf("%c", book[i].c);
	// printf("\n");

	change_cnt = 0;
	ppre_idx = -99;
	pre_idx = -99;
	cur_node = hash_table[hash_A].begin();
	while (cur_node != hash_table[hash_A].end()) {
		next_node = cur_node->next;										// 다음 노드 저장
		cur_idx = cur_node->idx;
		if (cur_idx > ppre_idx + 2 && cur_idx > pre_idx + 2) {			// 직전에 변경한 단어와 겹치는지 검사
			for (int i = 0; i < 3; ++i)									// 단어 변경
				book[cur_idx + i].c = string_B[i];
			++change_cnt;
			for (int i = 0; i < 5; ++i) {
				temp_idx = cur_idx - 2 + i;
				if (temp_idx >= 0 && temp_idx < book_len - 2) {		// book 범위를 벗어나는지 검사
					cur_hash = book[temp_idx].hash;
					new_hash = my_hash(book[temp_idx].c, book[temp_idx + 1].c, book[temp_idx + 2].c);
					if (cur_hash != new_hash) {
						if (next_node == book[temp_idx].ptr)			//삭제하려는 노드가 다음 노드라면 다음 노드 갱신
							next_node = hash_table[cur_hash].erase(book[temp_idx].ptr);
						else
							hash_table[cur_hash].erase(book[temp_idx].ptr);
						hash_table[new_hash].push(book[temp_idx].ptr);	//노드 옮기기
						book[temp_idx].hash = new_hash;
					}
				}
			}
			ppre_idx = pre_idx;
			pre_idx = cur_idx;
		}
		cur_node = next_node;
	}

	// printf("after_string  : ");
	// for (int i = 0; i < book_len; ++i)
	// 	printf("%c", book[i].c);
	// printf("\n");

	return (change_cnt);
}

void result(char ret[])
{
	for (int i = 0; i < book_len; ++i)
		ret[i] = book[i].c;
}