/*
No. 1 [Pro] 병사관리
참여자 0 제출 0 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 3초 / Java의 경우 3초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
[제한 사항]

시간

25개 테스트케이스를 합쳐서 C++ 의 경우 3초 / Java 의 경우 3초
메모리

힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ 본 문제는 임직원의 S/W 문제해결 역량 향상을 위한 Professional 실전형 연습문제이며

함께 제공되는 Testcase 또한 학습을 위한 연습용입니다.

 



[문제 설명]

병사들을 관리하는 프로그램을 작성하고자 한다.

병사들은 각각 고유번호, 소속팀, 평판 점수를 가지고 있다.

프로그램은 아래의 기능들을 수행할 수 있어야 한다.

병사 고용
병사 해고
병사의 평판 점수 변경
특정 팀에 속한 병사들의 평판 점수를 일괄 변경
특정 팀 안에서 가장 평판 점수가 높은 병사를 검색
아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 Java에 대해서는 제공되는 Solution.java와 UserSolution.java를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init()

각 테스트 케이스의 처음에 호출된다.

테스트 케이스의 시작 시 고용된 병사는 없다.

void hire(int mID, int mTeam, int mScore)

고유번호가 mID, 소속팀이 mTeam, 평판 점수가 mScore인 병사를 고용한다.

한 테스트 케이스 내에서 동일한 mID를 가진 병사가 여러 번 고용되는 경우는 없음이 보장된다.

 

Parameters

mID : 고유번호 (1 ≤ mID ≤ 100,000)

mTeam : 소속팀 (1 ≤ mTeam ≤ 5)

mScore : 평판 점수 (1 ≤ mScore ≤ 5)

void fire(int mID)

고유번호가 mID인 병사를 해고한다.

fire() 함수 호출 시, 고유번호가 mID인 병사가 고용되어 있음이 보장된다.

 

Parameters

mID : 고유번호 (1 ≤ mID ≤ 100,000)

void updateSoldier(int mID, int mScore)

고유번호가 mID인 병사의 평판 점수를 mScore로 변경한다.

고유번호가 mID인 병사가 고용되어 있음이 보장된다.

 

Parameters

mID : 고유번호 (1 ≤ mID ≤ 100,000)

mScore : 평판 점수 (1 ≤ mScore ≤ 5)

void updateTeam(int mTeam, int mChangeScore)

소속팀이 mTeam인 병사들의 평판 점수를 모두 변경한다.

소속팀이 mTeam인 병사가 한 명 이상 고용되어 있음이 보장된다.

 

updateTeam() 함수에서의 평판 점수 변경은 아래의 규칙에 따른다.

‘변경 전 평판 점수 + mChangeScore’가 5보다 클 경우, 평판 점수를 5로 변경한다.

‘변경 전 평판 점수 + mChangeScore’가 1보다 작을 경우, 평판 점수를 1로 변경한다.

그 외의 경우, 평판 점수를 ‘변경 전 평판 점수 + mChangeScore’로 변경한다.

 

Parameters

mTeam : 소속팀 (1 ≤ mTeam ≤ 5)

mChangeScore : 평판 점수의 변화량 (-4 ≤ mChangeScore ≤ 4)

int bestSoldier(int mTeam)

소속팀이 mTeam인 병사들 중 평판 점수가 가장 높은 병사의 고유번호를 반환한다.

평판 점수가 가장 높은 병사가 여러 명일 경우, 고유번호가 가장 큰 병사의 고유번호를 반환한다.

소속팀이 mTeam인 병사가 한 명 이상 고용되어 있음이 보장된다.

 

Parameters

mTeam : 소속팀 (1 ≤ mTeam ≤ 5)

 

Returns

평판 점수가 가장 높은 병사의 고유번호

 

[예제]

아래 표에서 [a, b, c]는 고유번호가 a, 소속팀이 b, 평판 점수가 c인 병사를 의미한다.

Order

Function

Status

Return

1

init()

 

 

2

hire(16, 1, 5)

[16, 1, 5]

 

3

hire(21, 1, 5)

[16, 1, 5], [21, 1, 5]

 

4

bestSoldier(1)

[16, 1, 5], [21, 1, 5]

21

5

fire(21)

[16, 1, 5]

 

6

bestSoldier(1)

[16, 1, 5]

16

7

hire(25, 1, 4)

[16, 1, 5], [25, 1, 4]

 

8

hire(30, 1, 2)

[16, 1, 5], [25, 1, 4], [30, 1, 2]

 

9

updateTeam(1, 1)

[16, 1, 5], [25, 1, 5], [30, 1, 3]

 

10

bestSoldier(1)

[16, 1, 5], [25, 1, 5], [30, 1, 3]

25

11

updateTeam(1, 2)

[16, 1, 5], [25, 1, 5], [30, 1, 5]

 

12

bestSoldier(1)

[16, 1, 5], [25, 1, 5], [30, 1, 5]

30

13

updateSoldier(30, 2)

[16, 1, 5], [25, 1, 5], [30, 1, 2]

 

14

bestSoldier(1)

[16, 1, 5], [25, 1, 5], [30, 1, 2]

25

15

updateTeam(1, -4)

[16, 1, 1], [25, 1, 1], [30, 1, 1]

 

16

hire(1, 1, 3)

[16, 1, 1], [25, 1, 1], [30, 1, 1], [1, 1, 3]

 

17

updateTeam(1, -1)

[16, 1, 1], [25, 1, 1], [30, 1, 1], [1, 1, 2]

 

18

bestSoldier(1)

[16, 1, 1], [25, 1, 1], [30, 1, 1], [1, 1, 2]

1

19

hire(100000, 5, 1)

[16, 1, 1], [25, 1, 1], [30, 1, 1], [1, 1, 2]

[100000, 5, 1]

 

20

bestSoldier(5)

[16, 1, 1], [25, 1, 1], [30, 1, 1], [1, 1, 2]

[100000, 5, 1]

100000

 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. 각 테스트 케이스에서 hire() 함수의 호출 횟수는 100,000 이하이다.

3. 각 테스트 케이스에서 fire() 함수의 호출 횟수는 100,000 이하이다.

4. 각 테스트 케이스에서 updateSoldier() 함수의 호출 횟수는 100,000 이하이다.

5. 각 테스트 케이스에서 updateTeam() 함수의 호출 횟수는 100,000 이하이다.

6. 각 테스트 케이스에서 bestSoldier() 함수의 호출 횟수는 100 이하이다.

 

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

Sample input 에 대한 정답 출력 결과는 “#TC번호 결과” 의 포맷으로 보여지며 결과가 100 일 경우 정답, 0 일 경우 오답을 의미한다.


*/
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_info
{
	char	mTeam;
	char	mScore;
	int		idx;
	int		start;
}	t_info;

t_info	soldier[100001];
int		team[6][100001];
int		team_score[6][100001];

double	hire_time;
double	fire_time;
double	update_one_time;
double	update_team_time;
double	best_time;
int		hire_count;
int		fire_count;
int		update_one_count;
int		update_team_count;
int		best_count;

// void	print_team(int mTeam)
// {
// 	printf("\nteam %d : ", mTeam);
// 	for (int i = 1; i <= team[mTeam][0]; ++i)
// 		printf("%d ", team[mTeam][i]);
// 	printf("\n");
// }

void	lazy_update(int mID, int *heap)
{
	int	mTeam;

	mTeam = soldier[mID].mTeam;

	// printf("**********start = %d, count = %d\n", soldier[mID].start, team_score[mTeam][0]);
	if (soldier[mID].start > team_score[mTeam][0])
		return ;
	// printf("(lazy_update) mID : %d, pre_score = %d ", mID, soldier[mID].mScore);

	for (int j = soldier[mID].start; j <= team_score[mTeam][0]; ++j) {
		soldier[mID].mScore += team_score[mTeam][j];
		if (soldier[mID].mScore > 5)
			soldier[mID].mScore = 5;
		else if (soldier[mID].mScore < 1)
			soldier[mID].mScore = 1;
		// printf("now = %d, ", soldier[mID].mScore);
	}
	// printf("\n");
	soldier[mID].start = team_score[mTeam][0] + 1;
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	push(int mID, int *heap)
{
	int	size;
	int	cur_idx;
	int	parent_idx;

	size = heap[0];
	cur_idx = size + 1;
	heap[cur_idx] = mID;
	soldier[heap[cur_idx]].idx = cur_idx;
	parent_idx = cur_idx / 2;
	while (1) {
		if (parent_idx == 0)
			break ;
		lazy_update(heap[parent_idx], heap);
		if (soldier[heap[cur_idx]].mScore > soldier[heap[parent_idx]].mScore) {
			swap(&heap[cur_idx], &heap[parent_idx]);
			soldier[heap[cur_idx]].idx = cur_idx;
			soldier[heap[parent_idx]].idx = parent_idx;
			cur_idx = parent_idx;
			parent_idx = cur_idx / 2;
		}
		else
			break ;
	}
	++heap[0];
}

void	remove(int mID, int *heap)
{
	int	size;
	int	cur_idx;
	int	next_idx;
	int	child_idx_1;
	int	child_idx_2;

	--heap[0];
	size = heap[0];
	cur_idx = soldier[mID].idx;
	heap[cur_idx] = heap[size + 1];
	soldier[heap[cur_idx]].idx = cur_idx;
	child_idx_1 = cur_idx * 2;
	child_idx_2 = cur_idx * 2 + 1;
	while (1) {
		if (child_idx_2 <= size) {
			lazy_update(heap[child_idx_1], heap);
			lazy_update(heap[child_idx_2], heap);
			if (soldier[heap[child_idx_1]].mScore > soldier[heap[child_idx_2]].mScore)
				next_idx = child_idx_1;
			else
				next_idx = child_idx_2;
		}
		else if (child_idx_1 <= size) {
			lazy_update(heap[child_idx_1], heap);
			next_idx = child_idx_1;
		}
		else
			break ;
		if (soldier[heap[cur_idx]].mScore < soldier[heap[next_idx]].mScore) {
			swap(&heap[cur_idx], &heap[next_idx]);
			soldier[heap[cur_idx]].idx = cur_idx;
			soldier[heap[next_idx]].idx = next_idx;
			cur_idx = next_idx;
			child_idx_1 = cur_idx * 2;
			child_idx_2 = cur_idx * 2 + 1;
		}
		else
			break ;
	}
}

void	change(int mID, int *heap)
{
	int	size;
	int	cur_idx;
	int	next_idx;
	int	parent_idx;
	int	child_idx_1;
	int	child_idx_2;

	size = heap[0];
	cur_idx = soldier[mID].idx;
	parent_idx = cur_idx / 2;
	lazy_update(heap[parent_idx], heap);
	if (parent_idx > 0 && \
			soldier[heap[cur_idx]].mScore > soldier[heap[parent_idx]].mScore) {
		while (1) {
			if (parent_idx == 0)
				break ;
			if (soldier[heap[cur_idx]].mScore > soldier[heap[parent_idx]].mScore) {
				swap(&heap[cur_idx], &heap[parent_idx]);
				soldier[heap[cur_idx]].idx = cur_idx;
				soldier[heap[parent_idx]].idx = parent_idx;
				cur_idx = parent_idx;
				parent_idx = cur_idx / 2;
			}
			else
				break ;
		}
	}
	else {
		child_idx_1 = cur_idx * 2;
		child_idx_2 = cur_idx * 2 + 1;
		while (1) {
			if (child_idx_2 <= size) {
				lazy_update(heap[child_idx_1], heap);
				lazy_update(heap[child_idx_2], heap);
				if (soldier[heap[child_idx_1]].mScore > soldier[heap[child_idx_2]].mScore)
					next_idx = child_idx_1;
				else
					next_idx = child_idx_2;
			}
			else if (child_idx_1 <= size) {
				lazy_update(heap[child_idx_1], heap);
				next_idx = child_idx_1;
			}
			else
				break ;
			if (soldier[heap[cur_idx]].mScore < soldier[heap[next_idx]].mScore) {
				swap(&heap[cur_idx], &heap[next_idx]);
				soldier[heap[cur_idx]].idx = cur_idx;
				soldier[heap[next_idx]].idx = next_idx;
				cur_idx = next_idx;
				child_idx_1 = cur_idx * 2;
				child_idx_2 = cur_idx * 2 + 1;
			}
			else
				break ;
		}
	}
	soldier[heap[cur_idx]].idx = cur_idx;
}

void	find_highest(int cur_idx, int *max_idx, int *heap)
{
	int	size;
	int	next_idx;
	int	child_idx_1;
	int	child_idx_2;


	if (heap[cur_idx] > heap[*max_idx])
		*max_idx = cur_idx;
	size = heap[0];
	child_idx_1 = cur_idx * 2;
	child_idx_2 = cur_idx * 2 + 1;
	if (child_idx_1 <= size) {
		if (soldier[heap[cur_idx]].mScore == soldier[heap[child_idx_1]].mScore)
			find_highest(child_idx_1, max_idx, heap);
	}
	if (child_idx_2 <= size) {
		if (soldier[heap[cur_idx]].mScore == soldier[heap[child_idx_2]].mScore)
			find_highest(child_idx_2, max_idx, heap);
	}
}

void init()
{
	for (int i = 1; i <= 5; ++i) {
		team[i][0] = 0;
		team_score[i][0] = 0;
	}
	hire_time = 0;
	fire_time = 0;
	update_one_time = 0;
	update_team_time = 0;
	best_time = 0;
	hire_count = 0;
	fire_count = 0;
	update_one_count = 0;
	update_team_count = 0;
	best_count = 0;
}

void hire(int mID, int mTeam, int mScore)
{
	double	start;
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	start = tv.tv_sec * 1000 + tv.tv_usec / 1000;

	soldier[mID].mTeam = mTeam;
	soldier[mID].mScore = mScore;
	soldier[mID].start = team_score[mTeam][0] + 1;

	// if (mTeam <= 5) {
	// 	int	id;
	// 	int	score;
	// 	int	idx;
	// 	printf("\npre hire\n");
	// 	for (int i = 1; i <= team[mTeam][0]; ++i) {
	// 		id = team[mTeam][i];
	// 		score = soldier[id].mScore;
	// 		idx = soldier[id].idx;
	// 		printf("mID = %d, mScore = %d, idx = %d\n", id, score, idx);
	// 	}	
	// }

	push(mID, team[mTeam]);

	// if (mTeam <= 5) {
	// 	int	id;
	// 	int	score;
	// 	int	idx;
	// 	printf("after hire\n");
	// 	for (int i = 1; i <= team[mTeam][0]; ++i) {
	// 		id = team[mTeam][i];
	// 		score = soldier[id].mScore;
	// 		idx = soldier[id].idx;
	// 		printf("mID = %d, mScore = %d, idx = %d\n", id, score, idx);
	// 	}	
	// }


	double	end;
	gettimeofday(&tv, NULL);
	end = tv.tv_sec * 1000 + tv.tv_usec / 1000;

	hire_time += (end - start) / 1000;
	++hire_count;
}

void fire(int mID)
{
	char	mTeam;
	double	start;
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	start = tv.tv_sec * 1000 + tv.tv_usec / 1000;


	mTeam = soldier[mID].mTeam;

	// if (mTeam <= 5) {
	// 	int	id;
	// 	int	score;
	// 	int	idx;
	// 	printf("\npre fire \n");
	// 	for (int i = 1; i <= team[mTeam][0]; ++i) {
	// 		id = team[mTeam][i];
	// 		score = soldier[id].mScore;
	// 		idx = soldier[id].idx;
	// 		printf("mID = %d, mScore = %d, idx = %d\n", id, score, idx);
	// 	}
	// }

	remove(mID, team[mTeam]);


	// if (mTeam <= 5) {
	// 	int	id;
	// 	int	score;
	// 	int	idx;
	// 	printf("after fire \n");
	// 	for (int i = 1; i <= team[mTeam][0]; ++i) {
	// 		id = team[mTeam][i];
	// 		score = soldier[id].mScore;
	// 		idx = soldier[id].idx;
	// 		printf("mID = %d, mScore = %d, idx = %d\n", id, score, idx);
	// 	}
	// }


	double	end;
	gettimeofday(&tv, NULL);
	end = tv.tv_sec * 1000 + tv.tv_usec / 1000;

	fire_time += (end - start) / 1000;
	++fire_count;
}

void updateSoldier(int mID, int mScore)
{
	char	mTeam;
	double	start;
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	start = tv.tv_sec * 1000 + tv.tv_usec / 1000;


	mTeam = soldier[mID].mTeam;

	// if (mTeam <= 5) {
	// 	int	id;
	// 	int	score;
	// 	int	idx;
	// 	printf("\npre update soldier\n");
	// 	for (int i = 1; i <= team[mTeam][0]; ++i) {
	// 		id = team[mTeam][i];
	// 		score = soldier[id].mScore;
	// 		idx = soldier[id].idx;
	// 		printf("mID = %d, mScore = %d, idx = %d\n", id, score, idx);
	// 	}
	// }

	soldier[mID].mScore = mScore;
	soldier[mID].start = team_score[mTeam][0] + 1;
	change(mID, team[mTeam]);

	// if (mTeam <= 5) {
	// 	int	id;
	// 	int	score;
	// 	int	idx;
	// 	printf("after update soldier\n");
	// 	for (int i = 1; i <= team[mTeam][0]; ++i) {
	// 		id = team[mTeam][i];
	// 		score = soldier[id].mScore;
	// 		idx = soldier[id].idx;
	// 		printf("mID = %d, mScore = %d, idx = %d\n", id, score, idx);
	// 	}
	// }


	double	end;
	gettimeofday(&tv, NULL);
	end = tv.tv_sec * 1000 + tv.tv_usec / 1000;

	update_one_time += (end - start) / 1000;
	++update_one_count;
}

void updateTeam(int mTeam, int mChangeScore)
{
	int	score_idx;
	double	start;
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	start = tv.tv_sec * 1000 + tv.tv_usec / 1000;


	// if (mTeam <= 5) {
	// 	int	id;
	// 	int	score;
	// 	int	idx;
	// 	printf("\npre update team\n");
	// 	for (int i = 1; i <= team[mTeam][0]; ++i) {
	// 		id = team[mTeam][i];
	// 		score = soldier[id].mScore;
	// 		idx = soldier[id].idx;
	// 		printf("mID = %d, mScore = %d, idx = %d\n", id, score, idx);
	// 	}
	// }

	score_idx = team_score[mTeam][0];
	team_score[mTeam][++score_idx] = mChangeScore;
	++team_score[mTeam][0];
		
	// if (mTeam <= 5) {
	// 	int	id;
	// 	int	score;
	// 	int	idx;
	// 	printf("after update team\n");
	// 	for (int i = 1; i <= team[mTeam][0]; ++i) {
	// 		id = team[mTeam][i];
	// 		score = soldier[id].mScore;
	// 		idx = soldier[id].idx;
	// 		printf("mID = %d, mScore = %d, idx = %d\n", id, score, idx);
	// 	}
	// }

	double	end;
	gettimeofday(&tv, NULL);
	end = tv.tv_sec * 1000 + tv.tv_usec / 1000;

	update_team_time += (end - start) / 1000;
	++update_team_count;
}


int bestSoldier(int mTeam)
{
	int	soldier_idx_1;
	int	soldier_idx_2;
	int	max_idx;
	double	start;
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	start = tv.tv_sec * 1000 + tv.tv_usec / 1000;


	// if (mTeam <= 5) {
	// 	int	id;
	// 	int	score;
	// 	int	idx;
	// 	printf("\npre best\n");
	// 	for (int i = 1; i <= team[mTeam][0]; ++i) {
	// 		id = team[mTeam][i];
	// 		score = soldier[id].mScore;
	// 		idx = soldier[id].idx;
	// 		printf("mID = %d, mScore = %d, idx = %d\n", id, score, idx);
	// 	}
	// }

	for (int i = 1; i <= team[mTeam][0]; ++i)
		lazy_update(team[mTeam][i], team[mTeam]);

	max_idx = 1;
	lazy_update(team[mTeam][max_idx], team[mTeam]);
	find_highest(1, &max_idx, team[mTeam]);
	if (max_idx != 1) {
		soldier_idx_1 = team[mTeam][1];
		soldier_idx_2 = team[mTeam][max_idx];
		swap(&team[mTeam][1], &team[mTeam][max_idx]);
		soldier[soldier_idx_1].idx = max_idx;
		soldier[soldier_idx_2].idx = 1;
	}

	// if (mTeam <= 5) {
	// 	int	id;
	// 	int	score;
	// 	int	idx;
	// 	printf("after best\n");
	// 	for (int i = 1; i <= team[mTeam][0]; ++i) {
	// 		id = team[mTeam][i];
	// 		score = soldier[id].mScore;
	// 		idx = soldier[id].idx;
	// 		printf("mID = %d, mScore = %d, idx = %d\n", id, score, idx);
	// 	}
	// }
	double	end;
	gettimeofday(&tv, NULL);
	end = tv.tv_sec * 1000 + tv.tv_usec / 1000;

	best_time += (end - start) / 1000;
	++best_count;

    return (team[mTeam][1]);
}