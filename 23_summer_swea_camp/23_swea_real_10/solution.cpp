/*
No. 10 [Pro] 단어게임
참여자 21 제출 45 배점 100

[문제 설명]

단어 카드들이 있다.

각 카드에는 단어와 그 단어와 연관된 주제어가 적혀져 있다.



 

각 플레이어들은 여러 장의 카드를 가지고 있고 같은 카드를 여러 장 가질 수도 있다.

각 플레이어들이 가진 카드의 수는 다를 수 있다.

 

다른 플레이어들이 자신의 카드들을 볼 수 있고 자신 또한 다른 플레이어들의 카드들을 볼 수 있다.

 

매 라운드마다 시작 문자열과 주제어가 제시되고 각 플레이어는 가지고 있는 카드 중 다음 조건에 만족하는 한 장의 카드를 제출한다. 만약 플레이어가 만족하는 카드가 없으면 제출하지 않는다.

① 각 플레이어는 자신이 가지고 있는 카드 중 단어가 시작 문자열로 시작되고 주제어가 제시된 주제어와 일치하는 카드가 있으면 그 카드를 제출한다.

② 만약, 플레이어가 ① 조건을 만족하는 카드를 여러 장 가지고 있는 경우, 그런 카드들 중에서 그 카드와 같은 카드를 가지고 있는 플레이어의 수가 가장 많은 카드를 제출한다. (한 플레이어가 같은 카드를 한 장 가지고 있건 여러 장 가지고 있건 한 명으로 센다.)

③ 만약, 플레이어가 ② 조건을 만족하는 카드를 여러 장 가지고 있는 경우, 그런 카드들 중에서 사전 순으로 가장 앞선 단어가 적힌 카드 하나를 제출한다.

 

모든 플레이어들이 동시에 카드를 제출한다.

 

제출된 카드를 비교하여 각 플레이어들이 얻는 점수가 계산되고 제출된 카드는 버린다. 버린 카드는 다음 라운드부터 사용될 수 없다.

 

예로, 어떤 플레이어가 [Fig. 1]과 같이 카드를 가지고 있는 경우를 생각하자.

시작 문자열은 “ba”이고 주제어는 “food”이면 “banana/[food]”인 카드를 제출한다.

시작 문자열은 “ba”이고 주제어가 “sport”이면 “baseball/[sport]”인 카드와 “basketball/[sport]”인 카드 중에서 그 카드와 같은 카드를 가지고 있는 플레이어의 수가 가장 많은 카드를 제출한다. 만약 그 수가 같은 경우 사전 순으로 “baseball”이 "basketball" 보다 더 앞서므로 “baseball/[sport]”를 제출한다.

시작 문자열은 “z”이고 주제어가 “product”이면 단어가 “z”로 시작하고 주제어가 “product”인 카드가 없으므로 어떤 카드도 제출하지 않는다.

 

해당 라운드에서 각 플레이어들이 얻는 점수는 다음과 같다.

플레이어가 제출한 카드와 같은 카드를 제출한 다른 플레이어들이 있는 경우 그 플레이어 수의 제곱만큼 점수를 얻는다. 플레이어의 수에서 본인은 제외한다.

예로, 플레이어 A가 “baseball/[sport]”인 카드를 제출하였을 때 2명의 다른 플레이어가 같은 카드를 제출했다면 4점을 얻는다.

만약, 같은 카드를 제출한 다른 플레이어가 없거나 카드를 제출하지 못한 경우 점수를 얻지 못한다.

 

플레이어들은 자유롭게 게임 도중에 게임에 참여하거나 나갈 수 있다. 게임에 처음 참여할 때 그 플레이어가 가진 점수는 0이고 게임에 나간 플레이어가 다시 참여할 수는 없다. 플레이어가 게임을 나갈 때 가지고 있는 모든 카드들을 반납한다.

 

이와 같은 단어 게임을 시뮬레이션하는 프로그램을 작성하라.

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 Java에 대해서는 제공되는 Solution.java와 UserSolution.java를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init(int N, char mWordList[][], char mSubjectList[][])

테스트 케이스에 대한 초기화 함수. 각 테스트 케이스의 맨 처음 1회 호출된다.

 

게임에서 사용되는 카드의 종류는 N개가 있고 각 종류의 카드는 1부터 N까지의 카드 번호로 구별된다. 카드 번호가 i인 카드에 적힌 단어와 주제어는 각각 mWordList[i – 1]와 mSubjectList[i – 1]이다. (1 ≤ i ≤ N)

 

mWordList[]와 mSubjectList[]는 영어 소문자로 구성된 문자열이고 길이는 2 이상 10 이하이다. 문자열 끝에는 ‘\0’이 있고 길이에는 포함되지 않는다.

 

mWordList로부터 주어진 단어 중에 서로 같은 단어는 없다. 즉, a ≠ b 이면 mWordList[a] ≠ mWordList[b]이다.

 

mSubjectList로부터 주어진 주제어 중 서로 다른 주제어의 개수는 최대 20이다.

 

초기에 참가한 플레이어는 없다.

 

Parameters
  N : 게임에서 사용되는 카드 종류의 개수 (1 ≤ N ≤ 10,000)
  mWordList : 카드에 적힌 단어 리스트 (2 ≤ |mWordList[]| ≤ 10, |a|는 문자열 a의 길이를 뜻한다.)
  mSubjectList : 카드에 적힌 주제어 리스트 (2 ≤ |mSubjectList[]| ≤ 10)

void join(int mID, int M, int mCardList[])

ID가 mID인 플레이어가 게임에 참가한다.

 

플레이어 mID가 참가할 때 플레이어 mID가 가진 카드의 개수는 M이고 가진 카드들은 mCardList[0] ~ mCardList[M – 1]로 주어진다. mCardList[]의 값은 카드 번호를 의미한다.

 

플레이어 mID의 초기 점수는 0이다.

 

가진 카드 중에 같은 카드가 여러 개 있을 수 있다.

 

mID는 맨 처음 호출할 때 1이고 그 다음 호출할 때마다 1씩 증가한다.

 

Parameters
  mID : 참가할 플레이어 ID (1 ≤ mID ≤ 50)
  M : 참가할 플레이어가 가진 카드의 수 (1 ≤ M ≤ 1,500)
  mCardList : 참가할 플레이어가 가진 카드 리스트 (1 ≤ mCardList[] ≤ N)

int playRound(char mBeginStr[], char mSubject[])

한 라운드가 진행된다. 그 라운드의 시작 문자열은 mBeginStr이고 주제어는 mSubject이다.

 

라운드 진행 과정은 본문 설명을 참고하라.

 

라운드가 끝나고 플레이어들이 제출한 카드의 번호를 모두 합한 값을 반환한다. 만약, 모든 플레이어가 제출한 카드가 없는 경우 0을 반환한다.

 

mBeginStr은 영어 소문자로 구성된 문자열이고 길이는 1 이상 2 이하이다. 문자열 끝에는 ‘\0’이 있고 길이에는 포함되지 않는다.

 

mSubject는 init() 함수 호출 시 전달되는 mSubjectList 배열에 있는 문자열 중 하나이다.

 

Parameters
  mBeginStr : 라운드의 시작 문자열 (1 ≤ |mBeginStr| ≤ 2)
  mSubject : 라운드의 주제어 (2 ≤ |mSubject| ≤ 10)

Returns
  해당 라운드에서 플레이어들이 제출한 카드의 번호의 합

int leave(int mID)

ID가 mID인 플레이어가 게임을 떠나고 플레이어 mID가 얻은 점수를 반환한다.

 

참여하지 않은 플레이어 또는 이미 떠난 플레이어의 mID로 호출되는 경우는 없다.

 

Parameters
  mID : 떠날 플레이어의 ID (1 ≤ mID ≤ 50)

Returns
  플레이어 mID가 얻은 점수

 

 

[예제]

[Table 1]과 같이 함수가 호출되는 경우를 생각해 보자.

Order

Function

Return

Figure

1

init(10, {“banana”, … }, {“food”, … })

 

[Fig. 2]

2

join(1, 5, {8, 5, 7, 2, 9})

 

 

3

join(2, 5, {1, 2, 5, 9, 7})

 

 

4

join(3, 5, {10, 2, 4, 2, 10})

 

 

5

join(4, 5, {10, 4, 4, 10, 7})

 

[Fig. 3]

6

playRound(“b”, “food”)

21

[Fig. 4]

7

playRound(“ba”, “sport”)

8

[Fig. 5]

8

join(5, 5, {3, 8, 7, 9, 5})

 

 

9

join(6, 5, {10, 5, 2, 5, 4})

 

 

10

playRound(“p”, “product”)

30

[Fig. 6]

11

leave(1)

4

 

12

leave(2)

4

 

13

leave(3)

5

 

14

playRound(“z”, “sport”)

0

 

15

leave(4)

9

 

16

join(7, 8, {9, 8, 3, 1, 9, 2, 5, 9})

 

 

17

join(8, 4, {5, 6, 2, 7})

 

 

18

playRound(“b”, “product”)

15

[Fig. 7]

19

playRound(“b”, “sport”)

16

[Fig. 8]

20

playRound(“b”, “product”)

16

[Fig. 9]

21

leave(5)

2

 

22

leave(6)

8

 

23

leave(7)

6

 

24

leave(8)

4

 

 

                                                                        [Table 1]

순서 1에서 init() 함수가 호출될 때 게임에서 사용되는 카드 종류는 [Fig. 2]와 같다. 카드 아래의 수는 카드 번호이다.



 

순서 5일 때 플레이어 1, 2, 3, 4가 받은 카드는 [Fig. 3]과 같다.



순서 6에서 playRound() 함수가 호출될 때 플레이어들이 제출한 카드는 [Fig. 4]와 같다. 파란 색이 칠해진 카드는 제출한 카드이고 제출한 카드 번호의 합은 7 + 7 + 7 = 21이다. 괄호 안의 수는 플레이어가 해당 라운드까지 얻은 점수이다.



순서 7에서 playRound() 함수가 호출될 때 플레이어들이 제출한 카드는 [Fig. 5]와 같다. 제출한 카드 번호의 합은 4 + 4 = 8이다.



순서 10에서 playRound() 함수가 호출될 때 플레이어들이 제출한 카드는 [Fig. 6]과 같다. 제출한 카드 번호의 합은 10 + 10 + 10 = 30이다.



순서 18에서 playRound() 함수가 호출될 때 플레이어들이 제출한 카드는 [Fig. 7]과 같다. 제출한 카드 번호의 합은 9 + 2 + 2 + 2 = 15이다.



순서 19에서 playRound() 함수가 호출될 때 플레이어들이 제출한 카드는 [Fig. 8]과 같다. 제출한 카드 번호의 합은 3 + 4 + 3 + 6 = 16이다.



순서 20에서 playRound() 함수가 호출될 때 플레이어들이 제출한 카드는 [Fig. 9]와 같다. 제출한 카드 번호의 합은 8 + 8 = 16이다.



 [제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 한 번 호출된다.

2. 각 테스트 케이스에서 join(), leave() 함수의 호출 횟수는 각각 50 이하이다.

3. 각 테스트 케이스에서 playRound() 함수의 호출 횟수는 각각 1,500 이하이다.

4. 각 테스트 케이스에서 단어가 제시된 시작 문자열로 시작하고 주제어가 제시된 주제어와 일치하는 카드의 수의 누적 합은 500,000 이하이다.


*/
#include <cstring>

#define MAXL	(10)

long long	my_hash(char *str, int len) {
	long long	res = 0;
	long long	p_i = 1;

	for (int i = len - 1; i >= 0; --i) {
		res += (str[i] - 'a') * p_i;
		p_i *= 26;
	}
	return (res);
}

long long	my_hash(char *str) {
	long long	res = 0;
	long long	p_i = 1;

	for (int i = 0; str[i] != '\0'; ++i) {
		res += (str[i] - 'a') * p_i;
		p_i *= 26;
	}
	return (res);
}

typedef struct s_card
{
	int			num;
	long long	word_hash[10];
	int			word_len;
	long long	sub_hash;
	int			player_table[51];
	int			player_cnt;
	int			cur_cnt;
	int			temp_cnt;
}	t_card;

t_card	card[10001];

typedef struct s_node
{
	t_card			*ptr;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	node_pool[75000];
int		node_pool_cnt;

typedef struct s_player
{
	t_node			head;
	int 			id;
	int				score;
	t_card			*best_card;
	struct s_player	*next;
	struct s_player	*prev;

	void	clear(int mID) {
		head.next = &head;
		head.prev = &head;
		id = mID;
		score = 0;
		best_card = NULL;
	}
	void	push(int card_num) {
		t_node	*new_node = &node_pool[node_pool_cnt++];

		new_node->ptr = &card[card_num - 1];
		++new_node->ptr->player_table[id];
		if (new_node->ptr->player_table[id] == 1)
			++new_node->ptr->player_cnt;
		new_node->next = head.next;
		new_node->prev = &head;
		head.next->prev = new_node;
		head.next = new_node;
	}
	void	erase(t_node *cur_node) {
		cur_node->prev->next = cur_node->next;
		cur_node->next->prev = cur_node->prev;
	}
	int	find_best(long long begin_hash, int begin_len, long long sub_hash) {
		t_node		*cur_node = begin();
		t_node		*best_node = NULL;
		int			lower_len;

		while (cur_node != end()) {
			if (cur_node->ptr->word_hash[begin_len - 1] == begin_hash && \
					cur_node->ptr->sub_hash == sub_hash) {
				if (best_node == NULL)
					best_node = cur_node;
				else {
					if (cur_node->ptr->player_cnt > best_node->ptr->player_cnt)
						best_node = cur_node;
					else if (cur_node->ptr->player_cnt == best_node->ptr->player_cnt) {
						if (cur_node->ptr->word_len < best_node->ptr->word_len)
							lower_len = cur_node->ptr->word_len;
						else
							lower_len = best_node->ptr->word_len;
						if (cur_node->ptr->word_hash[lower_len - 1] < \
								best_node->ptr->word_hash[lower_len - 1])
							best_node = cur_node;
						else if (cur_node->ptr->word_hash[lower_len - 1] == \
								best_node->ptr->word_hash[lower_len - 1]) {
							if (cur_node->ptr->word_len < best_node->ptr->word_len)
								best_node = cur_node;
						}
					}
				}
			}
			cur_node = cur_node->next;
		}
		if (best_node == NULL)
			return (0);
		++best_node->ptr->cur_cnt;
		++best_node->ptr->temp_cnt;
		best_card = best_node->ptr;
		erase(best_node);
		return (best_card->num);
	}
	void	calculate_score(void) {
		if (best_card == NULL)
			return ;
		score += (best_card->cur_cnt - 1) * (best_card->cur_cnt - 1);
		--best_card->temp_cnt;
		if (best_card->temp_cnt == 0)
			best_card->cur_cnt = 0;
		--best_card->player_table[id];
		if (best_card->player_table[id] == 0)
			--best_card->player_cnt;
		best_card = NULL;
	}
	t_node	*begin(void) {
		return (head.next);
	}
	t_node	*end(void) {
		return (&head);
	}
}	t_player;

t_player	player_pool[51];

typedef struct s_player_list
{
	t_player	head;

	void		clear(void) {
		head.next = &head;
		head.prev = &head;
	}
	void		push(t_player *new_player) {
		new_player->prev = &head;
		new_player->next = head.next;
		head.next->prev = new_player;
		head.next = new_player;
	}
	void		erase(t_player *player) {
		player->prev->next = player->next;
		player->next->prev = player->prev;
	}
	t_player	*begin(void) {
		return (head.next);
	}
	t_player	*end(void) {
		return (&head);
	}
}	t_player_list;

t_player_list	player_list;

void init(int N, char mWordList[][MAXL + 1], char mSubjectList[][MAXL + 1])
{
	int i, j;

	for (i = 0; i < N; ++i) {
		card[i].num = i + 1;
		card[i].cur_cnt = 0;
		card[i].temp_cnt = 0;
		card[i].player_cnt = 0;
		for (j = 1; j <= 50; ++j)
			card[i].player_table[j] = 0;
		for (j = 0; mWordList[i][j] != '\0'; ++j)
			card[i].word_hash[j] = my_hash(mWordList[i], j + 1);
		card[i].word_len = j;
		card[i].sub_hash = my_hash(mSubjectList[i]);
	}
	node_pool_cnt = 0;
	player_list.clear();
}

void join(int mID, int M, int mCardList[])
{
	t_player	*new_player = &player_pool[mID];

	new_player->clear(mID);
	for (int i = 0; i < M; ++i)
		new_player->push(mCardList[i]);
	player_list.push(new_player);
}

int playRound(char mBeginStr[], char mSubject[])
{
	int			res = 0;
	t_player	*cur_player;
	int			begin_str_len = strlen(mBeginStr);
	long long	begin_hash = my_hash(mBeginStr, begin_str_len);
	long long	sub_hash = my_hash(mSubject);

	cur_player = player_list.begin();
	while (cur_player != player_list.end()) {
		res += cur_player->find_best(begin_hash, begin_str_len, sub_hash);
		cur_player = cur_player->next;
	}
	cur_player = player_list.begin();
	while (cur_player != player_list.end()) {
		cur_player->calculate_score();
		cur_player = cur_player->next;
	}
	return (res);
}

int leave(int mID)
{
	t_player	*cur_player = &player_pool[mID];
	t_node		*cur_node = cur_player->begin();

	while (cur_node != cur_player->end()) {
		--cur_node->ptr->player_table[mID];
		if (cur_node->ptr->player_table[mID] == 0)
			--cur_node->ptr->player_cnt;
		cur_node = cur_node->next;
	}
	player_list.erase(cur_player);
	return (cur_player->score);
}