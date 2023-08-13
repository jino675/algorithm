/*
No. 33 메일서버
참여자 34 제출 338 배점 100
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

메일을 주고받는 기능을 제공하는 메일서버 프로그램을 작성하려고 한다.

메일서버 프로그램에는 메일 전송, 받은 메일 삭제, 받은 메일 검색 등의 기능이 있다. 

 

메일서버에는 각각의 유저에게 받은 메일을 저장할 수 있는 받은 메일함이 주어진다.

받은 메일함은 일정한 개수의 메일만 저장된다.

 

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 Java에 대해서는 제공되는 Solution.java와 UserSolution.java를 참고하라. 

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init(int N, int K)

각 테스트 케이스의 처음에 호출된다.

 

N 명의 유저가 메일서버를 이용한다.

 

유저 한 명당 받은 메일함에 저장할 수 있는 메일의 개수는 K 개이다.

 

각각의 인자 값의 범위는 아래와 같다.

 3 ≤ N ≤ 1,000

 3 ≤ K ≤ 300

 

Parameters

   N : 메일 서버 이용자의 수

   K : 받은 메일함에 저장할 수 있는 메일의 개수

void sendMail(char subject[], int uID, int cnt, int rIDs[])

uID 유저가 subject[] 제목의 메일 전송을 메일 서버에 요청한다.

 

메일 서버는 subject[] 제목의 메일을 rIDs[] 수신인들의 받은 메일함에 저장한다.

 

수신인들의 받은 메일함에 있는 메일의 개수가 K 개일 경우, 가장 오래된 메일이 삭제되고 subject[] 제목의 메일이 저장된다.

 

subject[] 는 1개 이상 10개 이하의 단어로 구성되며, 단어가 2개 이상일 경우 각 단어의 사이는 빈 칸(‘ ‘) 하나로 이루어져 있다.

 

subject[] 에 포함되는 각 단어는 영어 소문자로 구성되며, 길이는 3 이상 10 이하이다.

 

subject[] 는 ‘\0’ 으로 끝나는 문자열이다.

 

rIDs[] 는 모두 서로 다른 사용자의 id 이다.

 

각각의 인자 값의 범위는 아래와 같다.

 1 ≤ subject[] 에 있는 단어의 개수 ≤ 10

 0 ≤ uID ≤ ( N - 1 )

 1 ≤ cnt ≤ 50

 0 ≤ rIDs[] ≤ ( N - 1 )

 

 

Parameters

   subject[] : 메일 제목

   uID : 메일을 보내는 유저의 id

   cnt : 메일을 받는 사람들의 수

   rIDs[] : 메일을 받는 유저들의 id

int getCount(int uID)

uID 유저의 받은 메일함에 있는 메일의 수를 반환한다.

 

반환되는 메일의 개수에 삭제된 메일은 포함되지 않는다.

 

각각의 인자 값의 범위는 아래와 같다.

 0 ≤ uID ≤ ( N - 1 )

 

Parameters

   uID : 받은 메일함을 확인하는 유저의 id

 

Returns

   uID 유저의 받은 메일함에 있는 메일 개수

int deleteMail(int uID, char subject[])

uID 유저의 받은 메일함에서 subject[] 와 일치하는 제목을 가진 메일을 삭제하고, 삭제한 메일의 개수를 리턴한다.

 

subject[] 는 영어 소문자와 빈칸으로 구성되며, ‘\0’ 으로 끝나고 ‘\0’ 을 포함한 전체 길이는 200 이하이다.

 

각각의 인자 값의 범위는 아래와 같다.

 0 ≤ uID ≤ ( N - 1 )

 

Parameters

   uID : 메일을 삭제하려는 유저의 id

   subject[] : 삭제할 메일의 제목

 

Returns

   삭제한 메일의 개수

int searchMail(int uID, char text[])

uID 유저의 받은 메일함에서 메일 제목에 text[] 단어가 포함되어 있는 메일을 찾고, 찾은 메일의 개수를 리턴한다.

 

메일 제목에 포함되어 있는 단어 중 하나와 text[] 단어가 일치해야만 검색이 되며, 일부분만 같을 경우 검색이 되지 않아 찾은 메일 개수에 포함되지 않는다.

 

예를 들어, 메일 제목이 “aaaa bbbb cccc” 이고, text[] = “aaa” 일 경우 해당 메일은 찾은 메일 개수에 포함되지 않는다.

 

text[] 는 영어 소문자로 구성되며, ‘\0’ 으로 끝나고 ‘\0’ 을 포함한 전체 길이는 11 이하이다.

 

각각의 인자 값의 범위는 아래와 같다.

 0 ≤ uID ≤ ( N - 1 )

 

Parameters

   uID : 받은 메일함에서 단어를 검색하려는 유저의 id

   text[] : 검색할 단어

 

Returns

   검색된 메일의 개수

 



[예제]

아래 [Table 1] 같이 함수가 호출되는 경우를 살펴보자.

Order

Function

Note

Figure

1

init(10, 3)

 

 

2

sendMail(“test email abcd”, 0, 3, {0, 1, 2})

 

 

3

sendMail(“test email abcd”, 0, 2, {2, 3})

 

 

4

sendMail(“test key test aaa”, 1, 2, {0, 2})

 

 

5

getCount(2)

return 3

[Fig. 1]

6

searchMail(2, “test”)

return 3

 

7

deleteMail(2, “test email abcd”)

return 2

[Fig. 2]

8

sendMail(“key subject”, 3, 2, {0, 1})

 

 

9

searchMail(0, “abcd”)

return 1

[Fig. 3]

10

sendMail(“subject email”, 2, 2, {0, 3})

 

 

11

searchMail(0, “sub”)

return 0

[Fig. 4]

12

deleteMail(2, “dummy age”)

return 0

 

13

searchMail(0, “goto”)

return 0

 

[Table 1]

 

 

순서 5 의 getCount(2) 함수 호출 시, 받은 메일함은 [Fig. 1] 과 같고 리턴 값은 3 이 된다.



 

 

순서 7 의 deleteMail(2, “test email abcd”) 함수 호출 시, 유저 id = 2 의 받은 메일함에서 2개의 메일이 삭제되어 [Fig. 2] 와 같이 된다.



 

 

순서 9 의 searchMail(0, “abcd”) 함수 호출 시, 받은 메일함은 [Fig. 3] 과 같고 리턴 값은 1 이 된다.



 

 

순서 11 의 searchMail(0, “sub”) 함수 호출 시, 받은 메일함은 [Fig. 4] 과 같고 리턴 값은 0 이 된다.



 


 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. sendMail() 함수에서 수신인들의 받은 메일함에 있는 메일의 개수가 K 개일 경우, 가장 오래된 메일이 삭제되고 subject[] 제목의 메일이 저장된다.

3. 각 테스트 케이스에서 메일서버를 이용하는 유저의 수는 최대 1,000 이다.

4. 각 테스트 케이스에서 사용되는 서로 다른 단어의 종류는 최대 10,000 개이다.

5. 각 테스트 케이스에서 sendMail() 함수의 호출 횟수는 최대 10,000 이다.

6. 각 테스트 케이스에서 모든 함수의 호출 횟수 총합은 최대 30,000 이다.

 

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

Sample input 에 대한 정답 출력 결과는 아래와 같은 형태로 보여진다.

#1 100

#2 100

#3 100

#4 100

#5 100

 
입력
1 100
13 1 10 3
1 test_email_abcd 0 3 0 1 2
1 test_email_abcd 0 2 2 3
1 test_key_test_aaa 1 2 0 2
2 2 3
4 2 test 3
3 2 test_email_abcd 2
1 key_subject 3 2 0 1
4 0 abcd 1
1 subject_email 2 2 0 3
4 0 sub 0
3 2 dummy_age 0
4 0 goto 0	//테스트 케이스 갯수 정답 시 점수












 
sample_input.txt
출력
#1 100	//첫번째 테스트 케이스 결과
*/
// #include <iostream>
// #include <unistd.h>
#include <climits>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;

typedef struct s_mail
{
	char			*word_list[10];
	int				word_cnt;
	int				hash;
}	t_mail;

typedef struct s_node
{
	t_mail			*mail_ptr;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	node_pool[500000];
int		node_pool_cnt;

typedef struct s_mailbox
{
	t_node	head;
	int		mail_cnt;

	void	clear(void) {
		head.next = &head;
		head.prev = &head;
		mail_cnt = 0;
	}
	void	push_back(t_mail *mail) {
		t_node	*new_node = &node_pool[node_pool_cnt++];
		new_node->mail_ptr = mail;
		new_node->prev = head.prev;
		new_node->next = &head;
		head.prev->next = new_node;
		head.prev = new_node;
		++mail_cnt;
	}
	void	pop_front(void) {
		if (mail_cnt == 0)
			return ;
		head.next->next->prev = &head;
		head.next = head.next->next;
		--mail_cnt;
	}
	t_node	*erase(t_node *mail) {
		if (mail_cnt == 0)
			return (NULL);
		mail->prev->next = mail->next;
		mail->next->prev = mail->prev;
		--mail_cnt;
		return (mail->next);
	}
	t_node	*begin(void) {
		return (head.next);
	}
	t_node	*end(void) {
		return (&head);
	}
	// void	print_all(void) {
	// 	t_node	*cur_node = begin();
	// 	printf("mail_cnt : %d, head address : %p\n", mail_cnt, &head);
	// 	while (cur_node != end()) {
	// 		t_mail	*cur_mail = cur_node->mail_ptr;
	// 		printf("cur address : %p, word_cnt (%d) :", cur_mail, cur_mail->word_cnt);
	// 		for (int i = 0; i < cur_mail->word_cnt; ++i)
	// 			printf(" %s", cur_mail->word_list[i]);
	// 		printf("\n");
	// 		cur_node = cur_node->next;
	// 		sleep(1);
	// 	}
	// }
}	t_mailbox;

char	word_pool[10000][11];
int		word_pool_cnt;

t_mail	mail_pool[10000];
int		mail_pool_cnt;

t_mailbox	mail_box[1000];

unordered_map<string, char *>	word_table;

int	k;

void	init(int N, int K)
{
	word_pool_cnt = 0;
	mail_pool_cnt = 0;
	node_pool_cnt = 0;
	for (int i = 0; i < N; ++i)
		mail_box[i].clear();
	word_table.clear();
	k = K;
}

int	temp_cnt;

void	sendMail(char subject[], int uID, int cnt, int rIDs[])
{
	int		start, mail_hash, p_i;
	char	*cur_word;
	t_mail	*new_mail;

	new_mail = &mail_pool[mail_pool_cnt++];
	new_mail->word_cnt = 0;
	new_mail->hash = 0;
	p_i = 1;
	start = 0;
	for (int i = 0; ; ++i) {
		new_mail->hash = ((long long)new_mail->hash + (long long)subject[i] * p_i) % INT_MAX;
		p_i = ((long long)p_i * 26) % INT_MAX;
		if (subject[i] == ' ' || subject[i] == '\0') {
			string	temp(subject + start, subject + i);
			auto	iter = word_table.find(temp);
			if (iter == word_table.end()) {
				cur_word = word_pool[word_pool_cnt++];
				strncpy(cur_word, &subject[start], i - start);
				cur_word[i - start] = '\0';
				word_table[temp] = cur_word;
			}
			else
				cur_word = (*iter).second;
			start = i + 1;
			new_mail->word_list[new_mail->word_cnt++] = cur_word;
			if (subject[i] == '\0')
				break ;
		}
	}	//메일 생성 완료
	for (int i = 0; i < cnt; ++i) {
		mail_box[rIDs[i]].push_back(new_mail);
		if (mail_box[rIDs[i]].mail_cnt > k) {
			mail_box[rIDs[i]].pop_front();
		}
		// printf("\nsend to %d : %s\n", rIDs[i], subject);
		// mail_box[rIDs[i]].print_all();
	}	//전송 완료
	// printf("%d : %s\n", ++temp_cnt, subject);
}

int	getCount(int uID)
{
	return (mail_box[uID].mail_cnt);
}

int	is_same_mail(t_mail *cur_mail, char subject[])
{
	char	*cur_word;
	int		cur_idx;

	cur_idx = 0;
	for (int i = 0; i < cur_mail->word_cnt; ++i) {
		cur_word = cur_mail->word_list[i];
		for (int j = 0; cur_word[j] != '\0'; ++j) {
			if (cur_word[j] != subject[cur_idx])
				return (0);
			++cur_idx;
		}
		if (subject[cur_idx] != ' ' && subject[cur_idx] != '\0')
			return (0);
		else if (i != cur_mail->word_cnt - 1 && subject[cur_idx] == '\0')
			return (0);
		else if (i == cur_mail->word_cnt - 1 && subject[cur_idx] != '\0')
			return (0);
		++cur_idx;
	}
	return (1);
}

int	deleteMail(int uID, char subject[]) {

	int	mail_hash, p_i, res;
	t_node	*cur_node;

	res = 0;
	mail_hash = 0;
	p_i = 1;
	for (int i = 0; ; ++i) {
		mail_hash = ((long long)mail_hash + (long long)subject[i] * p_i) % INT_MAX;
		p_i = ((long long)p_i * 26) % INT_MAX;
		if (subject[i] == '\0')
			break ;
	}
	// mail_box[uID].print_all();
	cur_node = mail_box[uID].begin();
	while (cur_node != mail_box[uID].end()) {
		t_mail	*cur_mail = cur_node->mail_ptr;
		if (cur_mail->hash == mail_hash && is_same_mail(cur_mail, subject) == 1) {
				cur_node = mail_box[uID].erase(cur_node);
				++res;
		}
		else
			cur_node = cur_node->next;
	}
	return (res);
}

int	searchMail(int uID, char text[])
{
	int		res;
	char	*src_word;
	t_node	*cur_node;

	res = 0;
	auto	iter = word_table.find((string)text);
	if (iter == word_table.end())
		return (0);
	else
		src_word = (*iter).second;
	// src_word = word_table[(string)text]; // 극도로 위험!
	// printf("\nsearch, uID : %d, word : %s\n", uID, text);
	cur_node = mail_box[uID].begin();
	while (cur_node != mail_box[uID].end()) {
		t_mail	*cur_mail = cur_node->mail_ptr;
		// printf("cur_mail =");
		for (int i = 0; i < cur_mail->word_cnt; ++i) {
			// printf(" %s", cur_mail->word_list[i]);
			if (src_word == cur_mail->word_list[i]) {
				++res;
				break ;
			}
		}
		// printf("\n");
		cur_node = cur_node->next;
	}
	return (res);
}