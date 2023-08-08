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

using namespace std;

list<int> hash_table[26 * 26 * 26];

char	*book;
int		len;
char	*A;
int		A_count;
char	*B;
int		res;

int my_hash(char *str)
{
	int	val;
	int	p_i;

	val = 0;
	p_i = 1;
	for (int i = 2; i >= 0; --i) {
		// printf("c : %c\n", str[i]);
		val += (str[i] - 'a') * p_i;
		p_i *= 26;
	}
	// printf("val : %d\n", val);
	return (val);
}

void	make_table(void)
{
	int	cur_idx;
	int	pre_idx;
	int	pre_pre_idx;

	pre_idx = -1;
	pre_pre_idx = -1;
	for (int i = 0; i < len - 2; ++i) {
		cur_idx = my_hash(&book[i]);
		if ((pre_idx > 0 && cur_idx == pre_idx) || ( pre_pre_idx > 0 && cur_idx == pre_pre_idx))
			cur_idx = -1;
		else
			hash_table[cur_idx].push_back(i);
		pre_pre_idx = pre_idx;
		pre_idx = cur_idx;
	}
}

void	modify_table(int cur_book_idx)
{
	int					pre_pre_hash_idx;
	int					cur_hash_idx;
	int					new_hash_idx;
	list<int>::iterator	cur_iter;
	list<int>::iterator	new_iter;
	char				cur_new[8];
	int					pre_hash_idx[8];


	if (cur_book_idx - 2 >= 0)
		cur_new[0] = book[cur_book_idx - 2];
	else
		cur_new[0] = -1;
	if (cur_book_idx - 1 >= 0)
		cur_new[1] = book[cur_book_idx - 1];
	else
		cur_new[1] = -1;
	cur_new[2] = B[0];
	cur_new[3] = B[1];
	cur_new[4] = B[2];
	if (cur_book_idx + 3 < len)
		cur_new[5] = book[cur_book_idx + 3];
	else
		cur_new[5] = -1;
	if (cur_book_idx + 4 < len)
		cur_new[6] = book[cur_book_idx + 4];
	else
		cur_new[6] = -1;
	if (cur_book_idx + 5 < len)
		cur_new[7] = book[cur_book_idx + 5];
	else
		cur_new[7] = -1;


	if (cur_book_idx - 4 >= 0)
		pre_hash_idx[0] = my_hash(&book[cur_book_idx - 4]);
	else
		pre_hash_idx[0] = -1;
	if (cur_book_idx - 3 >= 0)
		pre_hash_idx[1] = my_hash(&book[cur_book_idx - 3]);
	else
		pre_hash_idx[1] = -1;
	if (cur_book_idx - 2 >= 0)
		pre_hash_idx[2] = my_hash(&cur_new[0]);
	else
		pre_hash_idx[2] = -1;
	if (cur_book_idx - 1 >= 0)
		pre_hash_idx[3] = my_hash(&cur_new[1]);
	else
		pre_hash_idx[3] = -1;
	pre_hash_idx[4] = my_hash(&cur_new[2]);
	if (cur_book_idx + 3 < len)
		pre_hash_idx[5] = my_hash(&cur_new[3]);
	else
		pre_hash_idx[5] = -1;
	if (cur_book_idx + 4 < len)
		pre_hash_idx[6] = my_hash(&cur_new[4]);
	else
		pre_hash_idx[6] = -1;
	if (cur_book_idx + 5 < len)
		pre_hash_idx[7] = my_hash(&cur_new[5]);
	else
		pre_hash_idx[7] = -1;


	for (int i = -2; i <= 2; ++i) {
		if (cur_book_idx + i < 0)
			continue ;
		if (cur_book_idx + i == len - 2)
			break ;

		cur_hash_idx = my_hash(&book[cur_book_idx + i]);
		new_hash_idx = my_hash(&cur_new[2 + i]);
		for (cur_iter = hash_table[cur_hash_idx].begin(); cur_iter != hash_table[cur_hash_idx].end(); ++cur_iter) {
			if (*cur_iter == cur_book_idx + i) {
				hash_table[cur_hash_idx].erase(cur_iter);
				break ;
			}
		}
		if (new_hash_idx != pre_hash_idx[2 + i] && new_hash_idx != pre_hash_idx[2 + i + 1])
			hash_table[new_hash_idx].push_back(cur_book_idx + i);
	}

	cur_hash_idx = my_hash(&book[cur_book_idx]);
	if (cur_book_idx + 5 < len) {
		new_hash_idx = my_hash(&book[cur_book_idx + 3]);
		if (cur_hash_idx != new_hash_idx) {
			if (new_hash_idx == pre_hash_idx[5] || new_hash_idx == pre_hash_idx[6]) {
				for (cur_iter = hash_table[new_hash_idx].begin(); cur_iter != hash_table[new_hash_idx].end(); ++cur_iter) {
					if (*cur_iter == cur_book_idx + 3) {
						hash_table[new_hash_idx].erase(cur_iter);
						break ;
					}
				}
			}
		}
	}
	if (cur_book_idx + 6 < len) {
		new_hash_idx = my_hash(&book[cur_book_idx + 4]);
		if (cur_hash_idx != new_hash_idx) {
			if (new_hash_idx == pre_hash_idx[6] || new_hash_idx == pre_hash_idx[7]) {
				for (cur_iter = hash_table[new_hash_idx].begin(); cur_iter != hash_table[new_hash_idx].end(); ++cur_iter) {
					if (*cur_iter == cur_book_idx + 4) {
						hash_table[new_hash_idx].erase(cur_iter);
						break ;
					}
				}
			}
		}
	}

	book[cur_book_idx] = B[0];
	book[cur_book_idx + 1] = B[1];
	book[cur_book_idx + 2] = B[2];
}

// void	find_modify(void)
// {
// 	int	cur_val;
// 	int	pat_val;

// 	cur_val = my_hash(book);
// 	pat_val = my_hash(A);
// 	for (int i = 0; i < len - 2; ++i) {
// 		// printf("\nbook : %s, cur : %c%c%c, val : %d, pat_val : %d\n", book, book[i], book[i+1], book[i+2], cur_val, pat_val);
// 		if (cur_val == pat_val) {
// 			for (int j = 0; j < 3; ++j)
// 				book[i + j] = B[j];
// 			++res;
// 			if (i + 5 < len) {
// 				cur_val = my_hash(&book[i + 3]);
// 				i += 2;
// 			}
// 			else
// 				break ;
// 		}
// 		else {
// 			if (i + 3 < len) {
// 				cur_val -= (book[i] - 'a') * (26 * 26);
// 				cur_val *= 26;
// 				cur_val += book[i + 3] - 'a';
// 			}
// 		}
// 	}
// }

void init(int N, char init_string[])
{
	book = init_string;
	len = N;
	for (int i = 0; i < 26 * 26 * 26; ++i)
		hash_table[i].clear();
	make_table();
}
int lll;
int change(char string_A[], char string_B[])
{
	int					A_hash_idx;
	list<int>::iterator	A_iter;


	A = string_A;
	B = string_B;
	A_hash_idx = my_hash(A);
	A_count = hash_table[A_hash_idx].size();

	// printf("\n#%d book : %s\n", ++lll, book);
	// printf("A : %s\n", A);
	// printf("B : %s\n", B);
	for (int i = 0; i < A_count; ++i) {
	// printf("\ntable : ");
	// 	for (list<int>::iterator temp = hash_table[A_hash_idx].begin(); temp != hash_table[A_hash_idx].end(); ++temp) {
	// 		printf("%d ", *temp);
	// 	}
	// printf("\n");

	// printf("\ndbd table : ");
	// char	kkk[4];
	// strcpy(kkk, "dbd");
	// 	for (list<int>::iterator temp = hash_table[my_hash(kkk)].begin(); temp != hash_table[my_hash(kkk)].end(); ++temp) {
	// 		printf("%d ", *temp);
	// 	}
	// printf("\n");

		A_iter = hash_table[A_hash_idx].begin();
		modify_table(*A_iter);
	
	// printf("cur_book : %s\n", book);
	}
	// printf("\ncur_book : %s\n", book);

	// get_pi(A);
	// kmp();
	// find_modify();
	res = A_count;
	// printf("res : %d\n", res);
	return (res);
}

void result(char ret[])
{
	strcpy(ret, book);
	// printf("ret : %s\n", ret);
}
// 1
// 80 10 2 3
// 1
// 0
// 2
// abaaabbabb


// int	pi_table[3];

// void	get_pi(char *str)
// {
// 	int	cur_idx;
// 	int	count;

// 	cur_idx = -1;
// 	count = 0;
// 	while (str[++cur_idx] != '\0') {
// 		if (cur_idx == 0) {
// 			pi_table[cur_idx] = 0;
// 			continue ;
// 		}
// 		while (count > 0 && str[count] != str[cur_idx])
// 			count = pi_table[count - 1];
// 		if (str[count] == str[cur_idx])
// 			pi_table[cur_idx] = ++count;
// 		else
// 			pi_table[cur_idx] = 0;
// 	}
// 	// pi_table[0] = 0;
// 	// if (str[0] == str[1])
// 	// 	pi_table[1] = 1;
// 	// else
// 	// 	pi_table[1] = 0;
// 	// if (str[0] == str[1] && str[1] == str[2])
// 	// 	pi_table[2] = 2;
// 	// else if (str[0] == str[2])
// 	// 	pi_table[2] = 1;
// 	// else
// 	// 	pi_table[2] = 0;
// }

// void	kmp(void)
// {
// 	int	book_idx;
// 	int	pat_idx;

// 	book_idx = -1;
// 	pat_idx = 0;
// 	while (book[++book_idx] != '\0') {
// 		while (pat_idx > 0 && book[book_idx] != A[pat_idx])
// 			pat_idx = pi_table[pat_idx - 1];
// 		if (book[book_idx] == A[pat_idx]) {
// 			++pat_idx;
// 			if (A[pat_idx] == '\0') {
// 				for (int i = 0; i < 3; ++i)
// 					book[book_idx - 2 + i] = B[i];
// 				++res;
// 				pat_idx = 0;
// 			}
// 		}
// 	}
// }