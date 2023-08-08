/*
No. 27 Social Media
참여자 27 제출 88 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

​​​​​​​  ​​​​​​​

제한 조건

실행시간 : 최대 50개의 테스트 케이스를 합쳐서 3 초 이내

 

메 모 리 : Heap, Global, Stack 등을 모두 합해 최대 256MB까지 사용 가능

(단, 스택은 최대 1MB까지 사용 가능)

제출 횟수 제한

10회

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

Social media 에서 사용되는 몇 가지 기능을 구현해보자.

 

1. 게시글을 등록한다. 각 게시글들은 등록되는 시점의 timestamp 를 가지고 있다.

2. 다른 사용자를 “follow” 한다. “follow”를 하게 되면, 그 사용자의 게시글을 볼 수 있다.

3. 특정 게시글에 “like”를 추가한다.

4. 특정 사용자를 기준으로 자신이 게시한 글과 자신이 “follow” 한 사용자의 게시글 중 우선 순위가 높은 글부터 내림차순으로 최대 10 개의 게시글을 보여준다.

 

 

각 게시글의 우선순위를 계산하는 방법은 다음과 같다.

1. 게시된 지 1,000 초 이내인 게시글이 그렇지 않은 게시글보다 우선순위가 높다.

2. 게시된 지 1,000 초 이내인 게시글들 중에는 “like” 가 많은 게시글의 우선순위가 높다.

3. 게시된 지 1,000 초 이내이면서 “like” 의 개수가 같은 게시글들 중에는 “timestamp” 가 높은 게시글의 우선순위가 높다.

4. 게시된 지 1,000 초를 초과한 게시글의 경우, “timestamp” 가 높은 게시글의 우선순위가 높다.

 

간단한 예시를 통해 각 게시글들의 우선순위가 어떻게 결정되는지 확인 해보자.

서로 “follow” 중인 uID 가 각각 1, 2 인 2 명의 사용자가 있고, uID가 1 인 사용자의 게시글이 [Table 1] 과 같다고 가정하자.

 

pID

timestamp

like

1

99

10

2

100

2

3

300

5

4

400

1

[Table 1]

 

 

현재 “timestamp” 가 500 일 경우 uID 가 2 인 사용자에게 보여지는 게시글의 우선 순위는

pID 1, 3, 2, 4 번 순이고 이 4 개의 값을 반환하면 된다.

현재 “timestamp” 가 1,100 일 경우 uID 가 2 인 사용자에게 보여지는 게시글의 우선 순위는

pID 3, 2, 4, 1 번 순이고 이 4 개의 값을 반환하면 된다.

현재 “timestamp” 가 1,100 일 경우 pID 1 인 게시글은 게시된 후 1,000 초를 초과했으므로, pID 2, 3, 4 의 게시글들 보다 우선순위가 낮다.

 

다음은 구현해야 할 API이다.

※ 아래 함수 signature는 C/C++에 대한 것으로 Java에 대해서는 제공되는 Solution.java와 UserSolution.java를 참고하라.

 

void init(int N)

각 testcase 시작 시 초기화를 위해 1번 호출된다.

 

Parameters

N: 사용자 수 (2 ≤ N ≤ 1,000)

void follow(int uID1, int uID2, int timestamp)

“uID1” 사용자가 “uID2” 사용자를 “follow” 한다.

“uID1” 사용자는 “uID2” 사용자의 모든 게시글을 볼 수 있다.

 

Parameters

uID1, uID2 : 사용자의 id (1 ≤ uID1, uID2 ≤ N)

timestamp : 현재 시점의 “timestamp” (1 ≤ timestamp ≤ 100,000)

void makePost(int uID, int pID, int timestamp)

“uID” 사용자가 “pID” 게시글을 게시한다.

 

Parameters

uID : 사용자의 ID (1 ≤ uID ≤ N)

pID : 게시글의 ID ( 1 부터 오름차순으로 주어진다. )

timestamp : 현재 시점의 “timestamp” (1 ≤ timestamp ≤ 100,000)

void like(int pID, int timestamp)

“pID” 게시글에 “like” 를 1 번 추가 한다.

“pID” 는 makePost() 에서 전달되었던 값으로만 주어 진다.

 

Parameters

pID : “like” 를 추가할 게시글의 pID

timestamp : 현재 시점의 “timestamp” (1 ≤ timestamp ≤ 100,000)

void getFeed(int uID, int timestamp, int pIDList[])

현재 “timestamp” 를 기준으로 “uID” 사용자에게 보여지는 최대 10 개의 게시글의 “pID” 들을 찾아 우선순위의 내림차순으로 “pIDList[]” 배열에 저장하여 반환 한다.

 

Parameters

uID : 사용자의 id (1 ≤ uID ≤ N)

timestamp : 현재 시점의 timestamp (1 ≤ timestamp ≤ 100,000)

pIDList[] : 보여지는 게시글의 pID 들을 저장하는 배열

 

 

 

[예제]

아래 [Table 2] 와 같이 함수가 호출되는 경우를 생각해보자.

아래 [Table 2] 는 테스트케이스 1 번 에서 호출되는 함수들의 일부분이다.

 

순번

함수

timestamp

return value

Table number

1

follow(1, 2, 1)

1

 

 

2

follow(2, 1, 1)

1

 

 

3

getFeed(2, 534)

534

{}

 

4

getFeed(2, 766)

766

{}

 

5

getFeed(1, 1088)

1088

{}

 

6

makePost(1, 1, 1752)

1752

 

 

7

like(1, 1861)

1861

 

 

8

makePost(1, 2, 2027)

2027

 

 

9

makePost(2, 3, 2117)

2117

 

 

10

makePost(1, 4, 2163)

2163

 

 

11

getFeed(2, 2476)

2476

{1, 4, 3, 2}

[Table 3]

12

like(2, 2494)

2494

 

 

13

like(1, 2542)

2542

 

 

14

makePost(1, 5, 2666)

2666

 

 

15

getFeed(2, 2853)

2853

{2, 5, 4, 3, 1}

[Table 4]

16

like(3, 2944)

2944

 

 

17

getFeed(2, 3033)

3033

{3, 5, 4, 2, 1}

[Table 5]

[Table 2]

 

 

순번 11의 getFeed(2, 2476) 함수 호출 뒤 존재하는 게시글은 4 개이며, 이 시점에 존재하는 게시글의 상태는 [Table 3] 과 같다.

 

pID

uID

like

timestamp

1

1

1

1752

2

1

0

2027

3

2

0

2117

4

1

0

2163

[Table 3]

 

 

이 게시물들의 우선순위는 {1, 4, 3, 2} 이다.

게시된 지 1,000 초 이내이면서 like 가 1인 pID 1 번 게시글의 우선순위가 가장 높고, like가 0인 게시물들 중 timestamp 가 높은 게시물의 우선순위가 그 다음으로 높다.

따라서 이 함수에서 반환해야 할 값은 1, 4, 3, 2 이다.

 

순번 15의 getFeed(2, 2853) 함수 호출 뒤 존재하는 게시글은 5 개이며, 이 시점에 존재하는 게시글의 상태는 [Table 4] 과 같다.

 

pID

uID

like

timestamp

1

1

2

1752

2

1

1

2027

3

2

0

2117

4

1

0

2163

5

1

0

2666

[Table 4]

 

 

이 게시물들 중 uID 2 번 사용자에게 보여지는 게시물의 순서는 {2, 5, 4, 3, 1} 이다.

1번 게시물이 게시된 지 1,000 초가 지났으므로 가장 우선순위가 낮다.

 

순번 17의 getFeed(2, 3033) 함수 호출 뒤 존재하는 게시글은 5 개이며, 이 시점에 존재하는 게시글의 상태는 [Table 5] 과 같다.

 

pID

uID

like

timestamp

1

1

2

1752

2

1

1

2027

3

2

1

2117

4

1

0

2163

5

1

0

2666

[Table 5]

 

 

이 게시물들 중 uID 2 번 사용자에게 보여지는 게시물의 순서는 {3, 5, 4, 2, 1} 이다.

pID 1, 2 번의 게시물이 게시된 지 1,000 초가 지났으므로 4, 5 번 게시물보다 우선순위가 낮다.

그리고 게시된 지 1,000 초가 지난 게시물들은 timestamp 가 높은 게시물의 우선순위가 높다.

 

[제약사항]

1.     사용자 수 N 은 2 이상 1,000 이하의 정수이다. (2 ≤ N ≤ 1,000)

2.     timestamp 는 1 에서 시작하고 최대 100,000 까지 증가한다.

3.     모든 함수들은 timestamp 오름차순으로 호출된다.

4.     모든 게시물들의 timestamp 는 서로 다르다.

5.     follow(), makePost(), like() 함수의 호출 횟수는 각각 100,000 회 이하이다.

6.     getFeed() 함수의 호출 횟수는 5,000 회 이하이다.

7.     특정 사용자가 한번 “follow” 한 사용자를 다시 “follow” 하는 호출은 발생하지 않는다.

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

sample input에 대한 정답 출력 결과는 아래와 같은 형태로 보여진다.

 

 

#1 100

#2 100

#3 100

#4 100

#5 100          

입력
1 100
114 2 10000 5 20 30 20
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 4 3 2 0 0 0 0 0 0
2 5 4 3 1 0 0 0 0 0
3 5 4 2 1 0 0 0 0 0
5 4 3 2 1 0 0 0 0 0
6 5 4 3 2 1 0 0 0 0
6 7 5 4 3 2 1 0 0 0
6 7 5 4 3 2 1 0 0 0
6 7 5 4 3 2 1 0 0 0
7 8 6 5 4 3 2 1 0 0
8 7 6 5 4 3 2 1 0 0
8 7 6 5 4 3 2 1 0 0
8 7 6 5 4 3 2 1 0 0
9 8 7 6 5 4 3 2 1 0
11 10 9 8 7 6 5 4 3 2
13 12 11 10 9 8 7 6 5 4
13 12 11 10 9 8 7 6 5 4
13 14 12 11 10 9 8 7 6 5
13 14 12 11 10 9 8 7 6 5	//테스트 케이스 갯수 1 TC=1





















 
sample_sample_input.txt
출력
#1 100	//첫번째 테스트 케이스 결과
*/
#include <stdio.h>

typedef struct s_post
{
	int	pID;
	int	uID;
	int	like;
	int	timestamp;
}	t_post;

typedef struct s_user
{
	bool	follow[1001];
}	t_user;

t_post	post[100001];
int		post_count;
t_user	*user;

int		heap[100001];
int		heap_size;


void init(int N)
{
	post_count = 0;
	if (user != NULL)
		delete user;
	user = new t_user[1001]();
}

void follow(int uID1, int uID2, int timestamp)
{
	user[uID1].follow[uID2] = true;
	// printf("%d : %d followed %d\n", timestamp, uID1, uID2);
}

void makePost(int uID, int pID, int timestamp)
{
	++post_count;
	post[post_count].uID = uID;
	post[post_count].pID = pID;
	post[post_count].like = 0;
	post[post_count].timestamp = timestamp;
	// printf("%d : %d makePost %d\n", timestamp, uID, pID);
}

void like(int pID, int timestamp)
{
	++post[pID].like;
	// printf("%d : post %d liked\n", timestamp, pID);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

bool	is_high_priority(int cur_pID, int next_pID, int cur_time)
{
	if (cur_time - post[cur_pID].timestamp <= 1000 && \
		cur_time - post[next_pID].timestamp > 1000)		// 1000 sec rule
		return (1);
	else if (cur_time - post[cur_pID].timestamp > 1000 && \
			cur_time - post[next_pID].timestamp <= 1000)
		return (0);
	else if (cur_time - post[cur_pID].timestamp > 1000 && \
			cur_time - post[next_pID].timestamp > 1000) {	//  both 1000 over
		if (post[cur_pID].timestamp > post[next_pID].timestamp)
			return (1);
		else
			return (0);
	}
	else {
		if (post[cur_pID].like > post[next_pID].like)
			return (1);
		else if (post[cur_pID].like < post[next_pID].like)
			return (0);
		else {
			if (post[cur_pID].timestamp > post[next_pID].timestamp)
				return (1);
			else
				return (0);
		}
	}
}

void	push(int pID, int cur_time)
{
	int	cur_idx;
	int	parent_idx;

	cur_idx = heap_size + 1;
	heap[cur_idx] = pID;
	parent_idx = cur_idx / 2;
	while (1) {
		if (parent_idx == 0)
			break ;
		if (is_high_priority(heap[cur_idx], heap[parent_idx], cur_time) == 1) {
			swap(&heap[cur_idx], &heap[parent_idx]);
			// printf("cur_pID = %d, cur_idx = %d, next_idx = %d\n", pID, cur_idx, parent_idx);
			cur_idx = parent_idx;
			parent_idx = cur_idx / 2;
		}
		else
			break ;
	}
	++heap_size;
	// printf("now heap_size = %d\n", heap_size);
}

int	pop(int cur_time)
{
	int	res;
	int	cur_idx;
	int	next_idx;
	int	child_idx_1;
	int	child_idx_2;

	res = heap[1];
	heap[1] = heap[heap_size];
	--heap_size;
	cur_idx = 1;
	child_idx_1 = cur_idx * 2;
	child_idx_2 = cur_idx * 2 + 1;
	while (1) {
		if (child_idx_2 <= heap_size) {
			if (is_high_priority(heap[child_idx_1], heap[child_idx_2], cur_time) == 1)
				next_idx = child_idx_1;
			else
				next_idx = child_idx_2;
		}
		else if (child_idx_1 <= heap_size)
			next_idx = child_idx_1;
		else
			break ;
		if (is_high_priority(heap[cur_idx], heap[next_idx], cur_time) == 0) {
			swap(&heap[cur_idx], &heap[next_idx]);
			cur_idx = next_idx;
			child_idx_1 = cur_idx * 2;
			child_idx_2 = cur_idx * 2 + 1;
		}
		else
			break ;
	}
	return (res);
}


void getFeed(int uID, int timestamp, int pIDList[])
{
	int	pID;
	int	count;

	user[uID].follow[uID] = true;
	pID = post_count;
	count = 0;
	heap_size = 0;
	while (pID > 0) {
		// printf("pID : %d, uID : %d, like : %d, timestamp : %d\n", post[pID].pID, post[pID].uID, post[pID].like, post[pID].timestamp);
		if (count >= 10 && timestamp - post[pID].timestamp > 1000)
			break ;
		if (user[uID].follow[post[pID].uID] == true) {
			// printf("pID %d is pushed, cur_heap_size = %d\n", pID, heap_size);
			push(pID, timestamp);
			++count;
		}
		--pID;
	}
	if (count > 10)
		count = 10;
	for (int i = 0; i < count; ++i) {
		pIDList[i] = pop(timestamp);
		// printf("%d ", pIDList[i]);
	}
	// for (int j = count; j < 10; ++j) {
	// 	printf("0 ");
	// }
	// printf("******uID(%d)\n", uID);
}