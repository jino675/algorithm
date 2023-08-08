/*
No. 12 Directory
참여자 21 제출 120 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

​​​​​​​ 
제한 조건

실행시간 : 최대 10개의 테스트 케이스를 합쳐서 C, C++ 1 초 이내, Java 2초 이내

 

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

컴퓨터 운영체제는 파일 분류를 위해 ‘디렉터리’라는 개념을 사용한다.

디렉터리는 여러 파일들과 다른 디렉터리를 포함하여, 사용자에게 논리적인 파일 그룹을 제공한다.
 

디렉터리는 ‘/’ 구분 문자를 사용하여, 파일 시스템 내에서 자신의 경로를 표현한다.

‘/’ 는 루트(최상위) 디렉터리를 나타내기도 하며, 상/하위 디렉터리간의 계층 관계를 나타내기도 한다.

예를 들어 “/aa/bb/” 디렉터리 경로는, 루트 디렉터리의 하위에 “aa” 디렉터리가 있고 “aa” 디렉터리의 하위에는 “bb” 디렉터리가 있음을 나타낸다.
 

디렉터리와 관련된 다양한 기능들이 있지만, 이 문제에서는 아래 5가지 기능만을 구현한다.

- 디렉터리 생성
- 디렉터리 삭제
- 디렉터리 복사
- 디렉터리 이동
- 하위 디렉터리 개수 확인
 

각 기능의 세부 동작은 다음의 API 요구사항 및 예제를 참고한다.

위와 같은 디렉터리의 기능을 구현하라.

 

[구현해야 할 API]

※ 아래 함수 signature는 C/C++에 대한 것으로 Java에 대해서는 제공되는 Solution.java와 UserSolution.java를 참고하라.

 

void init(int n)

각 testcase 시작 시, 초기화를 위해 1번 호출되고 루트 디렉터리를 생성한다.

Parameters
n: 이번 testcase에서 루트 디렉터리를 포함하여 생성되는 최대 디렉터리의 개수 (5 ≤ n ≤ 50,000)

void cmd_mkdir(char path[2000], char name[7])

path[] 디렉터리의 하위에 name[] 이름을 가진 새로운 디렉터리를 생성한다.

Parameters
path[2000]: 생성할 디렉터리의 상위 디렉터리의 경로 (1 ≤ length ≤ 1,999)
name[7]: 생성할 디렉터리의 이름 (2 ≤ length ≤ 6)

void cmd_rm(char path[2000])

path[] 디렉터리와 그 모든 하위 디렉터리를 삭제한다.

Parameters
path[2000]: 삭제할 디렉터리의 경로 (1 ≤ length ≤ 1,999)

void cmd_cp(char srcPath[2000], char dstPath[2000])

dstPath[] 디렉터리의 하위에 srcPath[] 의 디렉터리와 그 모든 하위 디렉터리를 복사한다.

Parameters
srcPath[2000]: 복사할 디렉터리의 경로 (1 ≤ length ≤ 1,999)
dstPath[2000]: srcPath[] 디렉터리가 복사 될 위치의 상위 디렉터리 경로 (1 ≤ length ≤ 1,999)

void cmd_mv(char srcPath[2000], char dstPath[2000])

dstPath[] 디렉터리의 하위에 srcPath[] 의 디렉터리와 그 모든 하위 디렉터리를 이동한다.

Parameters
srcPath[2000]: 이동할 디렉터리의 경로 (1 ≤ length ≤ 1,999)
dstPath[2000]: srcPath[] 디렉터리가 이동 될 위치의 상위 디렉터리 경로 (1 ≤ length ≤ 1,999)

int cmd_find(char path[2000])

path[] 디렉터리의 모든 하위 디렉터리 개수를 반환한다.

Parameters
path[2000]: 디렉터리의 경로 (1 ≤ length ≤ 1,999)

Return
path[] 디렉터리의 모든 하위 디렉터리 개수

 

 

[예 제]

아래의 [Table 1] 과 같이 요청이 되는 경우를 살펴보자.

 

Order

Function

return

Figure

1

cmd_mkdir(“/”, “aa”)

 

 

2

cmd_mkdir(“/”, “bb”)

 

 

3

cmd_mkdir(“/aa/”, “cc”)

 

 

4

cmd_mkdir(“/bb/”, “dd”)

 

[Fig. 1]

5

cmd_cp(“/bb/”, “/aa/”)

 

[Fig. 2]

6

cmd_mv(“/aa/cc/”, “/”)

 

[Fig. 3]

7

cmd_find(“/”)

6

 

8

cmd_mv(“/bb/”, “/cc/”)

 

[Fig. 4]

9

cmd_find(“/cc/”)

2

 

10

cmd_rm(“/cc/”)

 

[Fig. 5]

11

cmd_find(“/”)

3

 

[Table 1]

 

 

순서 1 ~ 4 의 cmd_mkdir 함수가 호출되면 디렉터리 구조는 [Fig. 1] 과 같다.

 



[Fig. 1]

 

 

순서 5 의 cmd_cp(srcPath=”/bb/”, dstPath=”/aa/”) 함수가 호출되면 디렉터리 구조는 [Fig. 2] 와 같다.

srcPath 디렉터리와 그 모든 하위 디렉터리를 dstPath 디렉터리의 하위에 복사한다.

 



[Fig. 2]

 

 

순서 6 의 cmd_mv(srcPath=“/aa/cc/”, dstPath=“/”) 함수가 호출되면 디렉터리 구조는 [Fig. 3] 과 같다.

srcPath 디렉터리와 그 모든 하위 디렉터리를 dstPath 디렉터리의 하위로 이동한다.

 



[Fig. 3]

 

 

순서 7 의 cmd_find(path=“/”) 가 호출되면, 루트 디렉터리의 모든 하위 디렉터리 개수인 6 을 반환한다.
 

순서 8 의 cmd_mv(srcPath=“/bb/”, dstPath=“/cc/”) 함수가 호출되면 디렉터리 구조는 [Fig. 4] 와 같다.

 



[Fig. 4]

 

 

순서 9 의 cmd_find(path=“/cc/”) 가 호출되면, “/cc/” 디렉터리의 모든 하위 디렉터리 개수인 2 를 반환한다.
 

순서 10 의 cmd_rm(path=“/cc/”) 이 호출되면 디렉터리 구조는 [Fig. 5] 와 같다.

path 디렉터리와 모든 하위 디렉터리를 삭제한다.

 



[Fig. 5]

 

 

순서 11 의 cmd_find(path=“/”) 가 호출되면, 루트 디렉터리의 모든 하위 디렉터리 개수인 3을 반환한다.

 

[제약사항]

1. 각 testcase에서 생성되는 최대 디렉터리의 개수 n 은 5 이상 50,000 이하의 정수이다. (5 ≤ n ≤ 50,000)

2. 디렉터리의 이름은 알파벳 소문자로 구성되며, 길이는 2 이상 6 이하이다. (2 ≤ length ≤ 6)

3. 모든 디렉터리는 그 경로의 길이가 1,999 를 넘지 않는다. (1 ≤ length ≤ 1,999)

4. API에 파라미터로 전달되는 char 배열은 전달 값 이후에 ‘\0’ 값으로 끝난다.

5. 같은 상위 디렉터리를 가지는 디렉터리 간에는 같은 이름을 가지는 경우는 없다.

6. 같은 상위 디렉터리를 가지는 디렉터리는 30 개 이하이다.

7. cmd_cp, cmd_mv 함수 호출 시 dstPath가 srcPath의 하위 디렉터리인 경우는 없다.

8. 함수 호출 시 전달되는 파라미터의 경로는 유효한 경로임이 보장된다.

9. 각 testcase에서 함수 호출 횟수의 총합은 50,000 회 이하이다.

10. 각 testcase에서 cmd_cp 함수의 호출 횟수는 전체 함수 호출 횟수의 10 % 이내이다.

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

sample input에 대한 정답 출력 결과는 아래와 같은 형태로 보여진다.

 

#1 100

#2 100

#3 100

#4 100

#5 100

 

 

입력
1
7 11
1 / aa
1 / bb
1 /aa/ cc
1 /bb/ dd
3 /bb/ /aa/
4 /aa/cc/ /
5 / 6
4 /bb/ /cc/
5 /cc/ 2
2 /cc/
5 / 3
7 10
1 / du
1 /du/ pan
1 / vibc
4 /du/ /vibc/
4 /vibc/du/ /
1 /du/pan/ mvgbov
1 /du/pan/mvgbov/ zkjsxy
4 /du/pan/ /vibc/
1 /du/ nurw

 
sample_sample_input.txt
출력
#1 100	//첫번째 테스트 케이스 결과
*/

// #include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <unistd.h>

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

// The below commented functions are for your reference. If you want 
// to use it, uncomment these functions.
/*
int mstrcmp(const char *a, const char *b)
{
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return a[i] - b[i];
}

int mstrncmp(const char *a, const char *b, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return 0;
}

int mstrlen(const char *a)
{
	int len = 0;

	while (a[len] != '\0')
		len++;

	return len;
}

void mstrcpy(char *dest, const char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

void mstrncpy(char *dest, const char *src, int len)
{
	for (int i = 0; i<len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
}
*/

typedef struct s_tree
{
	char			name[NAME_MAXLEN + 1];
	struct s_tree	*parent;
	struct s_tree	*prev;
	struct s_tree	*next;
	struct s_tree	*child;
}	t_tree;

t_tree	*root;

void init(int n) {
	n = n + 0;
	root = (t_tree *)calloc(1, sizeof(t_tree));
	strcpy(root->name, "/");
}

t_tree	*find_node(t_tree *cur, char *path)
{
	char	*next;
	t_tree	*ptr;

	if (path[0] == '\0')
		return (cur);
	for (int i = 0; path[i] != '\0'; ++i) {
		if (path[i] == '/') {
			path[i] = '\0';
			next = &path[i + 1];
			break ;
		}
	}
	for (ptr = cur->child; ptr != NULL; ptr = ptr->next) {
		if (strcmp(ptr->name, path) == 0)
			return (find_node(ptr, next));
	}
	return (NULL);
}

void	remove_tree(t_tree *cur)
{
	if (cur == NULL)
		return ;
	remove_tree(cur->child);
	remove_tree(cur->next);
	// printf("%s\n", cur->name);
	free(cur);
}

void	copy_tree(t_tree *cur, t_tree *src)
{
	int		is_first;
	t_tree	*temp;
	t_tree	*prev;
	t_tree	*ptr;

	is_first = 1;
	prev = NULL;
	for (ptr = src->child; ptr != NULL; ptr = ptr->next) {
		temp = (t_tree *)calloc(1, sizeof(t_tree));
		strcpy(temp->name, ptr->name);
		temp->parent = cur;
		temp->prev = prev;
		if (prev != NULL)
			prev->next = temp;
		prev = temp;
		copy_tree(temp, ptr);
		if (is_first == 1) {
			cur->child = temp;
			is_first = 0;
		}
	}
}

int	ttt;

int	count_tree(t_tree *cur)
{
	int	count;

	if (cur == NULL)
	{
	// printf("#%d, cur : NULL\n", ++ttt);
		return (0);
	}
	count = 0;
	// printf("#%d, cur : %s, count : %d\n", ++ttt, cur->name, count);
	// sleep(1);
	count += count_tree(cur->child);
	// printf("#%d, cur : %s, count : %d\n", ++ttt, cur->name, count);
	count += count_tree(cur->next);
	// printf("#%d, cur : %s, count : %d\n", ++ttt, cur->name, count);
	++count;
	// printf("#%d, cur : %s, count : %d\n", ttt, cur->name, count);
	return (count);
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
	t_tree	*cur;
	t_tree	*temp;

	cur = find_node(root, path + 1);
	temp = (t_tree *)calloc(1, sizeof(t_tree));
	strcpy(temp->name, name);
	temp->parent = cur;
	temp->next = cur->child;
	if (cur->child != NULL)
		cur->child->prev = temp;
	cur->child = temp;
	// printf("\nmkdir : %s\n", temp->name);
	// printf("\nmkdir : %s\n", temp->parent->name);
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
	t_tree	*cur;

	cur = find_node(root, path + 1);
	remove_tree(cur->child);
	if (cur->prev != NULL) {
		// printf("\nrm : prev = %s\n", cur->prev->name);
		cur->prev->next = cur->next;
	}
	if (cur->next != NULL) {
		// printf("\nrm : next = %s\n", cur->next->name);
		cur->next->prev = cur->prev;
	}
	if (cur->parent != NULL && cur->parent->child == cur) {
		// printf("\nrm : parent = %s\n", cur->parent->name);
		cur->parent->child = cur->next;
	}
	free(cur);
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	t_tree	*src;
	t_tree	*dst;
	t_tree	*temp;

	src = find_node(root, srcPath + 1);
	dst = find_node(root, dstPath + 1);
	temp = (t_tree *)calloc(1, sizeof(t_tree));
	strcpy(temp->name, src->name);
	temp->parent = dst;
	temp->next = dst->child;
	if (dst->child != NULL)
		dst->child->prev = temp;
	dst->child = temp;
	copy_tree(temp, src);
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	t_tree	*src;
	t_tree	*dst;

	src = find_node(root, srcPath + 1);
	dst = find_node(root, dstPath + 1);
	// printf("\nmv : %s\n", src->name);
	// printf("\nmv : %s\n", src->parent->name);
	if (src->prev != NULL)
		src->prev->next = src->next;
	if (src->next != NULL)
		src->next->prev = src->prev;
	if (src->parent != NULL && src->parent->child == src)
		src->parent->child = src->next;
	src->next = dst->child;
	src->prev = NULL;
	if (dst->child != NULL)
		dst->child->prev = src;
	dst->child = src;
	src->parent = dst;
}

int cmd_find(char path[PATH_MAXLEN + 1]) {
	int		count;
	t_tree	*dst;

	dst = find_node(root, path + 1);
	count = 0;
	count = count_tree(dst->child);
	return (count);
}