/*
No. 9 [Pro] 미생물가계도
참여자 14 제출 43 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 3초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
[제한 사항]

시간

 25개 테스트케이스를 합쳐서 C++ 의 경우 3초 / Java 의 경우 3초 / Python의 경우 5초
메모리

 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
 

①   C 또는 C++로 답안을 작성하시는 응시자께서는 검정시스템에 제출 시, Language 에서 C++ 를 선택하신 후 제출하시기 바랍니다.

  ②   Main 과 User Code 부분으로 구성되어 있습니다.

  ㅇ   A.  Main         : 수정할 수 없는 코드이며, 채점 시 비 정상적인 답안 검출 등 평가를 위한 로직이 추가 될 수 있습니다.

  ㅇ   B.  User Code  : 실제 응시자가 작성해야 하는 코드이며, 제출 시에는 표준 입출력 함수가 포함되어 있으면 안 됩니다.

  ③   Local PC 에서 프로그래밍 시 유의 사항

  ㅇ   A.  2개의 파일을 생성하셔야 합니다. ( main.cpp / solution.cpp 또는 Solution.java / UserSolution.java)

  ㅇ   B.  Main 부분의 코드를 main.cpp 또는 Solution.java 에 복사해서 사용하시기 바랍니다.

  ㅇ   C.  sample_input.txt 를 사용하시기 위해서는 Main 부분의 코드 내에

  ㅇ   C.  표준 입력을 파일로 전환하는 코드 ( 주석처리 되어 있음 ) 의 주석을 풀어서 사용하시면 됩니다.

  ㅇ   D.  User Code 부분의 코드를 작성하신 후 서버에 제출하실 때,

  ㅇ   D.  디버깅을 위한 표준 입출력 함수를 모두 삭제 또는 주석 처리해 주셔야 합니다.

  ④   문제 내에 제약조건을 모두 명시하지 않으므로 주어지는 코드를 분석하셔야 합니다.

  ⑤   코드는 개발 언어에 따라 상이할 수 있으므로, 작성할 언어를 기준으로 분석하셔야 합니다.

 

※ 본 문제는 임직원의 S/W 문제해결 역량 향상을 위한 Professional 실전형 연습문제이며

함께 제공되는 Testcase 또한 학습을 위한 연습용입니다.

 
[문제 설명]

한 마리의 미생물에서 증식하는 실험 기록을 관리하는 프로그램을 작성하려고 한다.

실험 기록에는 각 개체의 부모, 생존 기간이 적혀 있으며. 이를 통해 개체들 간의 가계도 거리와 특정 날짜에 생존해 있던 개체 수를 알아내려 한다.



실험 기록의 예시가 [Fig. 1] 처럼 주어져 있다고 하자. 선조가 되는 개체인 “ancestor”는 부모가 기록되어 있지 않고, 다른 개체들은 모두 그의 후손으로 부모가 기록되어 있다.

미생물이 생존했던 기간을 통해 날짜에 따른 미생물의 증식 정도를 알아보자. 100일에는 “ancestor” 1 개체이고, 200일에는 “childA”가 추가되어 2 개체, 300일에는 “childB”와 “grandchildA”가 추가되어 4 개체가 된다.

1000일에는 기록에 있는 모든 개체가 태어났었지만, “childA”와 “grandchildA”는 사망하여 4 개체만 생존해 있다.

 

가계도 거리를 다음과 같이 정의하자.

1) 부모 – 자식 관계를 한번 거치는 것을 가계도 거리 1이라 한다.

2) 두 개체 간의 가계도 거리는 부모 – 자식 관계를 통해 한 개체에서 다른 개체로 도달할 수 있는 최단거리이다.

 



[Fig. 1] 의 실험 기록으로 가계도를 그리면 [Fig. 2]와 같다. “grandchildA”와 “grandchildC" 간의 가계도 거리는, 그 최단 경로가 [Fig. 2] 에서 주황색으로 표시된 바와 같이 “grandchildA” – “childA” – “ancestor” – “childB” – “grandchildC” 이므로 4가 된다.

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init(char mAncestor[], int mLastday)

각 테스트 케이스의 처음에 호출된다.

기존의 기록들은 모두 삭제된다.

mAncestor는 선조의 이름이며, 선조의 생존 기간의 시작은 항상 0이다.

 

Parameters

    mAncestor : 선조의 이름 ( 3 ≤ |mAncestor| ≤ 11, |A|는 A 문자열의 길이를 의미한다 )

    mLastday : 선조의 마지막 생존일 ( 0 ≤ mLastDay ≤ 1,000,000 )

int add(char mName[], char mParent[], int mFirstday, int mLastday)
이름이 mName인 새로운 미생물 개체의 정보가 추가된다. 기존에 중복된 이름이 없다는 것이 보장된다.

부모의 이름은 mParent이고, 개체의 생존 기간의 시작은 mFirstday, 마지막은 mLastday 이다.

이름이 mParent인 개체가 앞서 입력된 기록에 존재한다.

추가된 개체와 선조의 가계도 거리를 반환한다.

 

Parameters

    mName: 개체의 이름 ( 3 ≤ |mName| ≤ 11 )

    mParent: 개체의 부모의 이름 ( 3 ≤ |mParent| ≤ 11 )

    mFirstday: 개체의 첫 생존일 ( 부모의 Firstday ≤ mFirstday ≤ 부모의 Lastday )

    mLastday: 개체의 마지막 생존일 ( mFirstday ≤ mLastday ≤ 1,000,000 )

 

Returns

    추가된 개체와 선조의 가계도 거리를 반환한다.

int distance(char mName1[], char mName2[])
이름이 mName1인 개체와 mName2인 개체 간의 가계도 거리를 반환한다.

이름이 mName1, mName2인 개체가 앞서 입력된 기록에 존재한다.

 

Parameters

    mName1, mName2: 가계도 거리를 알아내려는 두 개체의 이름 ( 3 ≤ |mName1|, |mName2| ≤ 11 )

 

Returns

두 개체 간의 가계도 거리를 반환한다.

int count(int mDay)
지금까지 기록된 미생물 중 생존 기간에 mDay일이 포함되는 개체 수를 반환한다.

 

Parameters

    mDay: 생존한 개체 수를 조사하는 날짜 ( 0 ≤ mDay ≤ 1,000,000 )

 

Returns

생존 기간에 mDay일이 포함되는 개체 수를 반환한다.

 

[예제]

order

Function

Return

Fig.

1

init(“ancestor”, 1000)

 

Fig. 3

2

add(“childA”, “ancestor”, 200, 800)

1

Fig. 3

3

add(“childB”, “ancestor”, 300, 1200)

1

Fig. 3

4

add(“grandchildA”, “childA”, 250, 700)

2

Fig. 3

5

distance(“childB”, “grandchildA”)

3

Fig. 3

 



6

add(“grandchildB”, “childA”, 700, 1500)

2

Fig. 4

7

add(“grandchildC”, “childB”, 800, 2000)

2

Fig. 4

8

distance(“ancestor”, “grandchildC”)

2

Fig. 4

9

distance(“childB”, “childB”)

0

Fig. 4

 

 



10

count(900)

4

Fig. 5

11

count(700)

5

Fig. 5

 



 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. 각 테스트 케이스에서 add() 함수의 호출 횟수는 12,000 이하이다.

3. 각 테스트 케이스에서 distance() 함수의 호출 횟수는 50,000 이하이다.

4. 각 테스트 케이스에서 count() 함수의 호출 횟수는 30,000 이하이다.

5. 모든 후손의 선조로부터의 가계도 거리는 2,000 이하이다.

6. 개체의 이름으로 주어지는 문자열은 영문 대소문자와 마지막 ‘＼0’로 이루어져 있다.
*/
#include <cstring>
#include <unordered_map>
#include <string>

using namespace std;

#define	TREE_SIZE (1 << 21)
#define	LEAF_SIZE (1 << 20)

typedef struct s_segment
{
	int	tree[TREE_SIZE];

	void	clear(void) {
		memset(tree, 0, sizeof(int) * TREE_SIZE);
	}
	void	sub_push(int cur_idx, int a, int b) {
		int	cur_lev, cur_len, left, right, mid;

		for (cur_lev = 0; (cur_idx >> cur_lev) > 1; ++cur_lev);
		cur_len = LEAF_SIZE >> cur_lev;
		left = cur_len * (cur_idx - (1 << cur_lev));
		right = left + cur_len - 1;
		mid = left + cur_len / 2;

		if (left == a && right == b)
			++tree[cur_idx];
		else if (left <= a && b <= mid - 1)
			sub_push(cur_idx * 2, a, b);
		else if (mid <= a && b <= right) {
			sub_push(cur_idx * 2 + 1, a, b);
		}
		else if (a <= mid - 1 && mid <= b) {
			sub_push(cur_idx * 2, a, mid - 1);
			sub_push(cur_idx * 2 + 1, mid, b);
		}
	}
	void	push(int a, int b) {
		sub_push(1, a, b);
	}
	int		sub_find(int cur_idx, int day, int cur_cnt) {
		int	cur_lev, cur_len, left, right, mid;

		for (cur_lev = 0; (cur_idx >> cur_lev) > 1; ++cur_lev);
		cur_len = LEAF_SIZE >> cur_lev;
		left = cur_len * (cur_idx - (1 << cur_lev));
		right = left + cur_len - 1;
		mid = left + cur_len / 2;
		
		cur_cnt += tree[cur_idx];
		if (left == right)
			return (cur_cnt);
		else if (day <= mid - 1)
			return (sub_find(cur_idx * 2, day, cur_cnt));
		else
			return (sub_find(cur_idx * 2 + 1, day, cur_cnt));
	}
	int		find(int day) {
		return (sub_find(1, day, 0));
	}
}	t_segment;

typedef struct s_bacteria
{
	int	lev;
}	t_bacteria;

t_bacteria	bacteria_pool[12001];
int			bacteria_pool_cnt;

t_segment	my_segment;

unordered_map<string, int>		name_table;
int								ancestor_table[12001][14];

void init(char mAncestor[], int mDeathday)
{
	t_bacteria	*new_bacteria;

	bacteria_pool_cnt = 0;
	name_table.clear();
	my_segment.clear();
	for (int i = 0; i < 12000; ++i) {
		for (int j = 0; j < 14; ++j) {
			ancestor_table[i][j] = -1;
		}
	}
	new_bacteria = &bacteria_pool[bacteria_pool_cnt++];
	new_bacteria->lev = 0;
	name_table[(string)mAncestor] = 0;
	my_segment.push(0, mDeathday);
}

int add(char mName[], char mParent[], int mBirthday, int mDeathday)
{
	t_bacteria	*new_bacteria = &bacteria_pool[bacteria_pool_cnt++];
	int			parent_idx, new_idx, ancestor_1, ancestor_2;

	parent_idx = name_table[(string)mParent];
	new_bacteria->lev = bacteria_pool[parent_idx].lev + 1;
	new_idx = bacteria_pool_cnt - 1;
	name_table[(string)mName] = new_idx;
	my_segment.push(mBirthday, mDeathday);
	ancestor_table[new_idx][0] = parent_idx;
	for (int i = 1; ;++i) {
		ancestor_1 = ancestor_table[new_idx][i - 1];
		ancestor_2 = ancestor_table[ancestor_1][i - 1];
		if (ancestor_2 != -1)
			ancestor_table[new_idx][i] = ancestor_2;
		else
			break ;
	}
	return (new_bacteria->lev);
}

int	get_ancestor(int cur_idx, int lev_dif)
{
	for (int i = 0; (1 << i) <= lev_dif; ++i) {
		if ((lev_dif & (1 << i)) != 0)
			cur_idx = ancestor_table[cur_idx][i];
	}
	return (cur_idx);
}

int distance(char mName1[], char mName2[])
{
	int	idx_1, idx_2, lev_dif, lower_idx, higher_idx, left, right, mid, distance, anc_1, anc_2, min_ancestor;

	idx_1 = name_table[(string)mName1];
	idx_2 = name_table[(string)mName2];
	lev_dif = bacteria_pool[idx_1].lev - bacteria_pool[idx_2].lev;
	if (lev_dif >= 0) {
		lower_idx = idx_1;
		higher_idx = idx_2;
	}
	else {
		higher_idx = idx_1;
		lower_idx = idx_2;
		lev_dif *= -1;
	}
	distance = lev_dif;
	idx_1 = higher_idx;
	idx_2 = get_ancestor(lower_idx, lev_dif);
	left = 0;									//left, mid, right 는 모두 level_difference.
	right = bacteria_pool[idx_1].lev;
	while (left <= right) {
		mid = left + (right - left) / 2;
		anc_1 = get_ancestor(idx_1, mid);
		anc_2 = get_ancestor(idx_2, mid);
		if (anc_1 == anc_2) {
			min_ancestor = anc_1;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	distance += (bacteria_pool[idx_1].lev - bacteria_pool[min_ancestor].lev) * 2;
	return (distance);
}

int count(int mDay)
{
	return (my_segment.find(mDay));
}
