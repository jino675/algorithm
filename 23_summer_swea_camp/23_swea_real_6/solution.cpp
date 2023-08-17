/*
No. 6 [Pro] 뉴스알림
참여자 16 제출 56 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 3초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
[제한 사항]

시간

 25개 테스트케이스를 합쳐서 C++ 의 경우 3초 / Java 의 경우 3초 / Python 의 경우 5초
메모리

 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
 

 

  ①   C 또는 C++로 답안을 작성하시는 응시자께서는 검정시스템에 제출 시, Language 에서 C++ 를 선택하신 후 제출하시기 바랍니다.

  ②   Main 과 User Code 부분으로 구성되어 있습니다.

  ㅇ   A.  Main         : 수정할 수 없는 코드이며, 채점 시 비 정상적인 답안 검출 등 평가를 위한 로직이 추가 될 수 있습니다.

  ㅇ   B.  User Code  : 실제 응시자가 작성해야 하는 코드이며, 제출 시에는 표준 입출력 함수가 포함되어 있으면 안 됩니다.

  ③   Local PC 에서 프로그래밍 시 유의 사항

  ㅇ   A.  2개의 파일을 생성하셔야 합니다. ( main.cpp / solution.cpp 또는 Solution.java / UserSolution.java 또는 main.py / solution.py )

  ㅇ   B.  Main 부분의 코드를 main.cpp 또는 Solution.java 또는 main.py 에 복사해서 사용하시기 바랍니다.

  ㅇ   C.  sample_input.txt 를 사용하시기 위해서는 Main 부분의 코드 내에

  ㅇ   C.  표준 입력을 파일로 전환하는 코드 ( 주석처리 되어 있음 ) 의 주석을 풀어서 사용하시면 됩니다.

  ㅇ   D.  User Code 부분의 코드를 작성하신 후 서버에 제출하실 때,

  ㅇ   D.  디버깅을 위한 표준 입출력 함수를 모두 삭제 또는 주석 처리해 주셔야 합니다.

  ④   문제 내에 제약조건을 모두 명시하지 않으므로 주어지는 코드를 분석하셔야 합니다.

  ⑤   코드는 개발 언어에 따라 상이할 수 있으므로, 작성할 언어를 기준으로 분석하셔야 합니다.

 

※ 본 문제는 임직원의 S/W 문제해결 역량 향상을 위한 Professional 실전형 연습문제이며

함께 제공되는 Testcase 또한 학습을 위한 연습용입니다.

 

[문제 설명]

등록한 유저들에게 뉴스 알림 서비스를 제공하는 여러 개의 뉴스 채널이 있다.

유저가 뉴스 채널에 알림 서비스를 등록 하면, 뉴스가 해당 뉴스 채널에 제공될 때 마다 유저는 뉴스 알림을 받을 수 있다.

 

뉴스를 제공받은 뉴스 채널은 mDelay 지연시간 후에 등록한 유저에게 뉴스 알림을 보낸다.

즉, mTime 시각에 뉴스 채널이 뉴스를 제공 받았다면, 뉴스 채널은 등록한 유저에게 (mTime + mDelay) 시각에 뉴스 알림을 보낸다. mDelay 지연시간은 뉴스마다 다를 수 있다.

 

뉴스가 취소 되면 제공된 뉴스는 삭제된다. 뉴스가 알림을 보내기 전에 삭제되면 뉴스 알림을 보내지 않는다. 또한, 뉴스가 알림을 보낸 후에 삭제되면 유저가 받은 뉴스 알림도 바로 삭제된다.

즉, mTime 시각에 뉴스가 제공되고, (mTime + mDelay) 시각 전에 뉴스가 삭제되면 뉴스 알림은 보내지 않는다. 만약, (mTime + mDelay) 시각 또는 그 이후에 뉴스가 삭제되면 유저가 받은 뉴스 알림도 삭제된다.

 

뉴스 알림은 다음과 같은 기능을 가지고 있다.

  1) 유저 등록 : 유저가 뉴스 알림 서비스를 제공하는 뉴스 채널에 알림 등록을 한다.

  2) 뉴스 제공 : 새로운 뉴스가 뉴스 채널에 제공된다. 뉴스 채널은 뉴스가 제공된 시각에서 mDelay 지연시간만큼 더해진 시각에 알림 등록한 유저에게 뉴스 알림을 보낸다.

  3) 뉴스 취소 : 뉴스가 삭제된다. 뉴스 채널에 제공된 뉴스는 삭제되고, 이미 유저에게 알림을 보낸 뉴스라면 유저에게 보내진 뉴스 알림도 삭제된다.

  4) 유저 확인 : 유저가 받은 뉴스 알림의 개수와 뉴스 내용을 확인한다.

 

뉴스 채널과 유저의 등록 정보가 주어질 때, 유저가 받은 뉴스 알림을 확인할 수 있는 프로그램을 작성하여 보자.

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init(int N, int K)

각 테스트 케이스의 처음에 호출된다.

 

N 명의 유저와 뉴스 알림 서비스를 제공하는 K 개의 뉴스 채널이 있다.

 

현재 시각은 0 이고, 제공된 뉴스는 없다.

 

 

Parameters

  N : 뉴스 알림을 받는 유저의 수 ( 1 ≤ N ≤ 500 )

  K : 뉴스 알림을 보내는 뉴스 채널의 수 ( 1 ≤ K ≤ 500 )

void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[])

mTime 시각에 mUID 유저는 뉴스 알림을 받기 위해 mNum 개의 뉴스 채널 mChannelIDs[] 에 각각 등록한다.

 

mTime 시각에 유저에게 보내지는 뉴스 알림이 있는 경우 먼저 알림을 보낸 후, mUID 유저를 뉴스 채널에 등록한다.

 

mChannelIDs[] 뉴스 채널들은 서로 중복되지 않는다.

 

mUID 는 중복으로 주어질 수 있지만, 동일 유저에게 등록되는 뉴스 채널은 서로 중복되지 않는다.

예를 들어 아래와 같을 경우, 11 유저는 중복 호출되지만 등록되는 뉴스 채널은 중복되지 않는다.

registerUser(1, 11, 2, {111, 222})

registerUser(25, 11, 3, {444, 333, 555})

 

 

Parameters

  mTime       : 현재 시각 ( 1 ≤ mTime ≤ 1,000,000,000 )

  mUID        : 유저의 ID ( 1 ≤ mUID ≤ 1,000,000,000 )

  mNum       : 유저가 등록하는 뉴스 채널의 수 ( 1 ≤ mNum ≤ 30 )

  mChannelIDs[] : 유저가 등록하는 뉴스 채널의 ID ( 1 ≤ mChannelIDs[] 의 값 ≤ 1,000,000,000 )

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID)

mTime 시각에 mDelay 시간이 있는 mNewsID 뉴스가 mChannelID 뉴스 채널에 제공되고, mChannelID 뉴스 채널에 알림을 등록한 유저의 수를 반환한다.

 

mChannelID 뉴스 채널은 (mTime + mDelay) 시각에 뉴스 알림을 등록한 유저들에게 mNewsID 뉴스 알림을 보낸다.

 

mChannelID 뉴스 채널에 알림 등록한 유저가 1 명 이상 있음이 보장된다.

mNewsID 는 중복으로 주어지지 않는다.

 

 

Parameters

  mTime : 현재 시각 ( 1 ≤ mTime ≤ 1,000,000,000 )

  mNewsID : 뉴스의 ID (1 ≤ mNewsID ≤ 1,000,000,000 )

  mDelay : 뉴스의 delay 시간 ( 1 ≤ mDelay ≤ 10,000 )

  mChannelID : 뉴스를 제공받는 뉴스 채널의 ID ( 1 ≤ mChannelID ≤ 1,000,000,000 )

 

Returns

  mChannelID 뉴스 채널에 알림 등록한 유저의 수

void cancelNews(int mTime, int mNewsID)

mTime 시각에 mNewsID 뉴스가 취소되어 삭제된다.

 

mNewsID 뉴스가 유저들에게 뉴스 알림이 보내 졌으면 유저에게 있는 mNewsID 뉴스 알림도 삭제되어야 한다.

 

mNewsID 뉴스는 offerNews() 에서 제공된 뉴스이다.

mNewsID 뉴스는 이미 취소되어 삭제된 뉴스일 수도 있다.

 

 

Parameters

  mTime   : 현재 시각 ( 1 ≤ mTime ≤ 1,000,000,000 )

  mNewsID : 취소되는 뉴스 ID (1 ≤ mNewsID ≤ 1,000,000,000 )

int checkUser(int mTime, int mUID, int mRetIDs[])

mTime 시각에 mUID 유저가 받은 뉴스 알림의 개수를 반환하고, mUID 유저가 받은 뉴스의 ID 를 최신 받은 순서대로 최대 3개 mRetIDs[] 에 저장한다. 삭제된 뉴스 알림은 제외한다.

 

mTime 시각에 유저에게 보내지는 뉴스 알림이 있는 경우 먼저 알림을 보낸 후, 유저가 받은 뉴스 알림의 개수를 반환한다.

 

함수 호출 후, mUID 유저가 받은 뉴스 알림은 모두 삭제되어 알림의 개수는 0 이 된다.

 

mUID 유저가 같은 시간대에 2개 이상의 뉴스 알림을 받은 경우, 뉴스 ID 가 큰 경우 더 최신이다.

받은 뉴스 알림이 2개 이하일 경우 받은 뉴스의 ID만 최신 받은 순서대로 저장한다.

mUID 유저가 받은 뉴스 알림이 없을 경우 0 을 반환한다.

 

registerUser() 에서 알림을 등록한 유저임이 보장된다.

 

 

Parameters

  mTime   : 현재 시각 ( 1 ≤ mTime ≤ 1,000,000,000 )

  mUID    : 뉴스 알림을 확인하는 유저 ID ( 1 ≤ mUID ≤ 1,000,000,000 )

  mRetIDs[] : 받은 뉴스 ID를 최신 순서대로 저장하는 공간

 

Returns

  mUID 유저가 받은 뉴스 알림의 개수 (삭제된 뉴스 알림은 제외 )

 

 

 

[예제]

아래에는 테스트케이스 1번을 처음부터 순서대로 보여준다.

Order

Function

Return Value

1

init(3, 5)

 

2

registerUser(1, 11, 2, {111, 222})

 

3

registerUser(2, 22, 3, {333, 444, 555})

 

4

registerUser(3, 33, 2, {555, 111})

 

                                                                 [Table 1]

Order 4. registerUser(3, 33, 2, {555, 111}) 실행 후, 뉴스 채널과 유저의 상태는 [Fig. 1] 과 같다.

( 뉴스 채널 안의 숫자는 알림 등록을 한 유저이다. )

 

 

[Table 2]는 [Table 1]이후의 함수 호출이다.

Order

Function

Return Value

5

offerNews(5, 12345, 20, 555)

2

6

offerNews(10, 54321, 15, 111)

2

7

offerNews(11, 11111, 14, 222)

1

8

offerNews(14, 22222, 20, 444)

1

9

offerNews(17, 33333, 8, 333)

1

10

checkUser(20, 33, mRetIDs[])

0

mRetIDs[]={}

11

registerUser(25, 11, 3, {444, 333, 555})

 

12

checkUser(26, 11, mRetIDs[])

2

mRetIDs[]={ 54321, 11111 }

13

checkUser(27, 33, mRetIDs[])

2

mRetIDs[]={ 54321, 12345 }

                                                                 [Table 2]

Order 12. checkUser(26, 11, mRetIDs[]) 실행 전, 뉴스 채널과 유저의 상태는 [Fig. 2] 와 같다.

( 444 뉴스 채널은 34 시각에 22222 뉴스 알림을 유저에게 보낸다. )

 

 

[Table 3]는 [Table 2] 이후의 함수 호출이다.

Order

Function

Return Value

14

offerNews(28, 32112, 8, 333)

2

15

offerNews(29, 56789, 9, 444)

2

16

offerNews(30, 12215, 5, 555)

3

17

cancelNews(32, 22222)

 

18

offerNews(34, 34219, 18, 111)

2

19

cancelNews(35, 12215)

 

20

checkUser(36, 22, mRetIDs[])

3

mRetIDs[]={ 32112, 33333, 12345 }

21

checkUser(37, 22, mRetIDs[])

0

mRetIDs[]={}

22

cancelNews(40, 56789)

 

23

checkUser(41, 11, mRetIDs[])

1

mRetIDs[]={ 32112 }

24

offerNews(47, 55555, 10, 222)

1

25

offerNews(48, 77777, 13, 222)

1

26

offerNews(49, 77111, 10, 555)

3

27

offerNews(51, 34577, 10, 111)

2

28

offerNews(57, 88888, 4, 444)

2

29

offerNews(59, 99999, 10, 111)

2

30

checkUser(61, 11, mRetIDs[])

6

mRetIDs[]={ 88888, 77777, 34577 }

31

checkUser(62, 22, mRetIDs[])

2

mRetIDs[]={ 88888, 77111 }

32

checkUser(63, 33, mRetIDs[])

3

mRetIDs[]={ 34577, 77111, 34219 }

                                                                 [Table 3]

Order 30. checkUser(61, 11, mRetIDs[]) 실행 전, 뉴스 채널과 유저의 상태는 [Fig. 3] 과 같다.

 

 

 

 [제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. 각 테스트 케이스에서 함수 호출시 mTime 은 항상 1 이상 증가하는 값이다.

3. 각 테스트 케이스에서 모든 유저가 받은 뉴스 알림의 총합은 최대 4,000,000 이다.

4. 각 테스트 케이스에서 registerUser() 함수의 호출 횟수는 최대 5,000 이다.

5. 각 테스트 케이스에서 offerNews() 함수의 호출 횟수는 최대 30,000 이다.

6. 각 테스트 케이스에서 cancelNews() 함수의 호출 횟수는 최대 3,000 이다.

7. 각 테스트 케이스에서 checkUser() 함수의 호출 횟수는 최대 1,000 이다.

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

Sample input 에 대한 정답 출력 결과는 “#TC번호 결과” 의 포맷으로 보여지며 결과가 100 일 경우 정답, 0 일 경우 오답을 의미한다.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

struct s_news;
typedef struct s_news t_news;

typedef struct s_user
{
	int		chanel_cnt;
	t_news	*news[30000];
	int		news_cnt;
}	t_user;

typedef struct s_channel
{
	t_user	*user_list[500];
	int		user_cnt;
}	t_channel;

typedef struct s_news
{
	int			news_id;
	int			show_time;
	int			is_deleted;
	t_channel	*channel;
}	t_news;

typedef struct s_heap
{
	t_news	*heap[30000];
	int		heap_size;

	void	clear(void) {
		heap_size = 0;
	}
	void	swap(t_news **a, t_news **b) {
		t_news	*temp;

		temp = *a;
		*a = *b;
		*b = temp;
	}
	void	push(t_news *new_news) {
		int	cur_idx, parent_idx;

		++heap_size;
		heap[heap_size] = new_news;
		cur_idx = heap_size;
		parent_idx = cur_idx / 2;
		while (true) {
			if (parent_idx == 0)
				break ;
			if (heap[cur_idx]->show_time < heap[parent_idx]->show_time || \
				(heap[cur_idx]->show_time == heap[parent_idx]->show_time && \
					heap[cur_idx]->news_id < heap[parent_idx]->news_id)) {
				swap(&heap[cur_idx], &heap[parent_idx]);
				cur_idx = parent_idx;
				parent_idx = cur_idx / 2;
			}
			else
				break ;
		}
	}
	void	pop(void) {
		int	cur_idx, l_child, r_child, next_idx;

		heap[1] = heap[heap_size];
		--heap_size;
		cur_idx = 1;
		l_child = cur_idx * 2;
		r_child = cur_idx * 2 + 1;
		while (true) {
			if (r_child <= heap_size) {
				if (heap[l_child]->show_time < heap[r_child]->show_time || \
					(heap[l_child]->show_time == heap[r_child]->show_time && \
						heap[l_child]->news_id < heap[r_child]->news_id))
					next_idx = l_child;
				else
					next_idx = r_child;
			}
			else if (l_child <= heap_size)
				next_idx = l_child;
			else
				break ;
			if (heap[cur_idx]->show_time > heap[next_idx]->show_time || \
				(heap[cur_idx]->show_time == heap[next_idx]->show_time && \
					heap[cur_idx]->news_id > heap[next_idx]->news_id)) {
				swap(&heap[cur_idx], &heap[next_idx]);
				cur_idx = next_idx;
				l_child = cur_idx * 2;
				r_child = cur_idx * 2 + 1;
			}
			else
				break ;
		}
	}
	t_news	*top(void) {
		return (heap[1]);
	}
	bool	isEmpty(void) {
		if (heap_size == 0)
			return (true);
		else
			return (false);
	}
}	t_heap;


t_news		news_pool[30000];
t_user		user_pool[500];
t_channel	channel_pool[500];
int			news_pool_cnt;
int			user_pool_cnt;
int			channel_pool_cnt;

unordered_map<int, t_news *>	news_table;
unordered_map<int, t_user *>	user_table;
unordered_map<int, t_channel *>	channel_table;

t_heap	news_heap;

void	send_news(int cur_time)
{
	t_news		*cur_news;
	t_user		*cur_user;
	t_channel	*cur_channel;

	while (news_heap.isEmpty() != true) {
		cur_news = news_heap.top();
		if (cur_news->show_time > cur_time)
			break ;
		news_heap.pop();
		if (cur_news->is_deleted == 0) {
			cur_channel = cur_news->channel;
			for (int j = 0; j < cur_channel->user_cnt; ++j) {
				cur_user = cur_channel->user_list[j];
				cur_user->news[cur_user->news_cnt++] = cur_news;
			}
		}
	}
}

void init(int N, int K)
{
	news_heap.clear();
	news_table.clear();
	user_table.clear();
	channel_table.clear();
	news_pool_cnt = 0;
	user_pool_cnt = 0;
	channel_pool_cnt = 0;
}

void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[])
{
	t_user		*cur_user;
	t_channel	*cur_channel;

	send_news(mTime);
	auto	iter = user_table.find(mUID);
	if (iter == user_table.end()) {
		cur_user = &user_pool[user_pool_cnt++];
		cur_user->chanel_cnt = 0;
		cur_user->news_cnt = 0;
		user_table[mUID] = cur_user;
	}
	else
		cur_user = (*iter).second;
	for (int i = 0; i < mNum; ++i) {
		auto	iter = channel_table.find(mChannelIDs[i]);
		if (iter == channel_table.end()) {
			cur_channel = &channel_pool[channel_pool_cnt++];
			cur_channel->user_cnt = 0;
			channel_table[mChannelIDs[i]] = cur_channel;
		}
		else
			cur_channel = (*iter).second;
		cur_channel->user_list[cur_channel->user_cnt++] = cur_user;
	}
}

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID)
{
	t_news		*cur_news;
	t_channel	*cur_channel;


	auto	iter = channel_table.find(mChannelID);
	if (iter == channel_table.end()) {
		cur_channel = &channel_pool[channel_pool_cnt++];
		cur_channel->user_cnt = 0;
		channel_table[mChannelID] = cur_channel;
	}
	else
		cur_channel = (*iter).second;

	cur_news = &news_pool[news_pool_cnt++];
	cur_news->news_id = mNewsID;
	cur_news->show_time = mTime + mDelay;
	cur_news->is_deleted = 0;
	cur_news->channel = cur_channel;
	news_table[mNewsID] = cur_news;

	news_heap.push(cur_news);
	return (cur_channel->user_cnt);
}

void cancelNews(int mTime, int mNewsID)
{
	t_news		*cur_news;

	cur_news = news_table[mNewsID];
	cur_news->is_deleted = 1;
}

int checkUser(int mTime, int mUID, int mRetIDs[])
{
	int			news_cnt;
	t_news		*cur_news;
	t_user		*cur_user;

	send_news(mTime);
	cur_user = user_table[mUID];
	news_cnt = 0;
	for (int i = cur_user->news_cnt - 1; i >= 0; --i) {
		cur_news = cur_user->news[i];
		if (cur_news->is_deleted == 0) {
			if (news_cnt < 3)
				mRetIDs[news_cnt] = cur_news->news_id;
			++news_cnt;
		}
	}
	cur_user->news_cnt = 0;
	return (news_cnt);
}