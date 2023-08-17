/*
No. 7 [Pro] 블록쌓기게임
참여자 0 제출 0 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 3초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
[제한 사항]

시간

 25개 테스트케이스를 합쳐서 C++ 의 경우 3초 / Java 의 경우 3초
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

위에서 아래로 블록들을 떨어뜨려서 격자판 밑부분에 블록들을 쌓는 게임을 시뮬레이션 하려고 한다.

 

게임이 시작되면 블록들을 떨어뜨릴 격자판이 주어지는데
이 격자판의 행의 개수는 10,000개이고, 열의 개수가 C개이다.

블록들을 떨어뜨릴 때마다 떨어뜨리는 가로 위치 정보인 mCol와
떨어뜨리는 블록의 개수를 알려주는 mHeight와 mLength 정보가 주어진다.

떨어뜨리는 블록의 개수는 mHeight * mLength 이며, 블록들이 직사각형 모양이 형성되도록 위치시킨 후 떨어뜨린다.
블록들로 이루어진 직사각형은 높이가 mHeight이고, 길이가 mLength가 된다.

[Fig. 1]은 mHeight와 mLength의 값에 따라 형성된 블록들의 모양을 보여준다.


                                                 [Fig. 1]

 

블록들이 형성한 직사각형의 가장 왼쪽 블록들이 mCol 위치에 오도록 위치 시킨 후 떨어뜨린다.
떨어지는 블록들은 격자판의 바닥에 닿거나 바로 아래 멈춘 상태의 블록이 존재하면 멈추게 된다.
직사각형을 이루는 블록들은 서로 분리되어 있기 때문에 멈추는 위치가 달라질 수 있다.

 

[Fig. 2]는 가로 위치가 0인 곳에서 높이 1, 길이인 5인 사각형을 이루는 블록들을 떨어뜨렸을 때 격자판의 아래 부분의 10개의 행 만을 보여준다.
5개의 블록들은 모두 동일한 속도로 떨어지다가 격자 판의 바닥에 닿아서 멈춘다.
멈춘 후 쌓여있는 블록들의 최대 높이는 1이고 격자판에 남아있는 블록들의 개수는 5이다.


    
                                                                    [Fig. 2]
 

 

[Fig. 3]는 가로 위치가 3인 곳에서 높이 2, 길이인 4인 사각형을 이루는 블록들을 떨어뜨린 경우를 보여준다.

위치 3, 그리고 4에 있는 블록들은 파란 블록들에 의해 바닥에 닿기 전에 멈추게 된다.
쌓여있는 블록들의 최대 높이는 3이고 블록의 개수는 13이다.



                                                              [Fig. 3]

 

[Fig. 4]는 1*6개의 블록들이 가로 위치 2에서 떨어지는 경우를 보여준다.

빨간 블록과 파란 블록으로 인하여 녹색 블록들은 서로 분리되어 멈추게 된다.
쌓여있는 블록들의 최대 높이는 4이고, 블록의 개수는 19이다.

 


                                                            [Fig. 4]

 

 

블록들이 멈춘 후 각 행에 쌓인 블록들의 개수가 C와 동일하다면 해당 행의 블록들은 모두 삭제되고 남아있는 블록들이 밑으로 내려온다.

 

[Fig. 5]는 2*8 블록들이 떨어졌을 때의 상황을 보여준다.

마지막 행이 모두 블록으로 채워져서 제거되고 나머지 블록들이 밑으로 내려온다.
삭제 후 쌓여있는 블록들의 최대 높이는 3이고, 블록의 개수는 20이다.


                                                         [Fig. 5]

 

[Fig. 6]는 3*15 블록들이 떨어졌을 때의 상황을 보여준다.

마지막 3개의 행이 모두 블록으로 채워져서 제거되고 나머지 블록들이 밑으로 내려온다.
삭제 후 쌓여있는 블록들의 최대 높이는 3이고, 블록의 개수는 20이다.


                                        [Fig. 6]

 

블록들이 떨어져서 쌓이고 삭제되는 블록 쌓기 게임을 시뮬레이션 할 수 있는 프로그램을 작성하라.

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init(int C)

각 테스트 케이스의 처음에 호출된다.

격자판의 열의 개수 C가 주어진다.

처음 격자판은 비어있다.

 

Parameters

    C: 격자판의 열의 개수 (10 ≤ C ≤ 1,000,000)

Result dropBlocks(int mCol, int mHeight, int mLength)

격자판의 가로방향의 위치 mCol에 높이가 mHeight이고 길이가 mLength인 직사각형 모양으로 배치된 블록들을 위치시킨다.
격자판을 벗어나서 블록들이 위치하게 하는 mCol와 mLength 값이 주어지는 경우는 없다.
배치된 블록들이 아래로 내려가다 멈추게 되면 각 행마다 블록들로 가득 찼는지 여부를 확인하여 해당 행의 블록들을 삭제하고 위쪽의 블록들을 밑으로 내린다.
이후 남아있던 블록들의 개수를 1,000,000으로 나눈 나머지와 가장 높은 블록의 높이를 반환한다.

 

Parameters

   mCol: 떨어뜨릴 블록들의 위치 (0 ≤ mCol ≤ C - mLength)
   mHeight: 떨어뜨릴 블록들로 형성되는 사각형의 높이 (1≤ mHeight ≤ 3)
   mLength: 떨어뜨릴 블록들로 형성되는 사각형의 길이 (2 ≤ mLength ≤ C)
 

Return

  Result 내에서 top: 가장 높은 블록의 높이
  Result 내에서 count: 남아 있는 블록들의 개수를 1,000,000으로 나눈 나머지

 

[예제]

아래에는 테스트케이스 1번을 처음부터 순서대로 보여준다.
그림은 격자판의 아래 부분의 10개 행 만을 나타낸 것이다.

순서

Function

Return

Fig.

1

init(15)

 

 

2

dropBlocks(0, 1, 5)

top=1, count=5

Fig. 7 (a)

3

dropBlocks(3, 2, 4)

top=3, count=13

Fig. 7 (b)

4

dropBlocks(2, 1, 6)

top=4, count=19

Fig. 7 (c)

5

dropBlocks(7, 2, 8)

top=3, count=20

Fig. 7 (d)

6

dropBlocks(0, 3, 15)

top=3, count=20

Fig. 7 (e)

7

dropBlocks(5, 1, 10)

top=3, count=30

Fig. 7 (f)

8

dropBlocks(8, 1, 7)

top=3, count=37

Fig. 8 (a)

9

dropBlocks(0, 2, 3)

top=1, count=13

Fig. 8 (b)

10

dropBlocks(0, 1, 2)

top=0, count=0

Fig. 8 (c)

11

dropBlocks(0, 2, 15)

top=0, count=0

Fig. 8 (d)

12

dropBlocks(1, 3, 13)

top=3, count=39

Fig. 8 (e)

13

dropBlocks(2, 3, 4)

top=6, count=51

Fig. 8 (f)

 


                                                           [Fig. 7]

 


                                                             [Fig. 8]

 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.
2. 각 테스트 케이스에서 dropBlocks() 함수의 호출 횟수는 3,000 이하이다.
3. 각 테스트 케이스에서 격자판의 행의 개수는 10,000이다.
4. 각 테스트 케이스에서 격자판의 열의 개수는 1,000,000 이하이다.
5. 격자판에 남아있는 블록들의 개수는 Integer type의 최대값보다 클 수 있다는 점에 유의하라.

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

Sample input 에 대한 정답 출력 결과는 “#TC번호 결과” 의 포맷으로 보여지며 결과가 100 일 경우 정답, 0 일 경우 오답을 의미한다.
*/
#include <cstring>

typedef struct s_node
{
	int				start;
	int				end;
	int				height;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	node_pool[1000000];
int		node_pool_cnt;

typedef struct s_list
{
	t_node	head;

	void	clear(int C) {
		t_node	*new_node = &node_pool[node_pool_cnt++];

		new_node->start = 0;
		new_node->end = C - 1;
		new_node->height = 0;
		new_node->prev = &head;
		new_node->next = &head;
		head.next = new_node;
		head.prev = new_node;
	}
	void	insert(t_node *cur_node, t_node *new_node) {
		new_node->prev = cur_node->prev;
		new_node->next = cur_node;
		cur_node->prev->next = new_node;
		cur_node->prev = new_node;
	}
	void	erase(t_node *cur_node) {
		cur_node->prev->next = cur_node->next;
		cur_node->next->prev = cur_node->prev;
	}
	t_node	*begin(void) {
		return (head.next);
	}
	t_node	*end(void) {
		return (&head);
	}
	bool	isEmpty(void) {
		if (head.next == &head)
			return (true);
		else
			return (false);
	}
}	t_list;

t_list	col_list;
int		row_cnt[10000];

int	height_max;
int	clear_cnt;
int	col_len;

long long	total_cnt;

struct Result{
    int top;
    int count;
};

void init(int C)
{
	node_pool_cnt = 0;
	col_list.clear(C);
	memset(row_cnt, 0, sizeof(int) * height_max);
	height_max = 0;
	clear_cnt = 0;
	total_cnt = 0;
	col_len = C;
}

void	update_row_cnt(int cur_height, int new_height, int new_cnt)
{
	for (int i = cur_height; i < cur_height + new_height; ++i)
		row_cnt[i] += new_cnt;
	if (cur_height + new_height > height_max)
		height_max = cur_height + new_height;
}

void	update_col_list(int a, int b, int height) {
	t_node	*cur_node = col_list.begin();
	t_node	*new_node;

	while (cur_node != col_list.end()) {
		if (a <= cur_node->start && cur_node->start <= b && b < cur_node->end) {
			update_row_cnt(cur_node->height, height, b - cur_node->start + 1);
			if (cur_node->prev != col_list.end() && cur_node->prev->height == cur_node->height + height)
				cur_node->prev->end = b;
			else {
				new_node = &node_pool[node_pool_cnt++];
				new_node->start = cur_node->start;
				new_node->end = b;
				new_node->height = cur_node->height + height;
				col_list.insert(cur_node, new_node);
			}
			cur_node->start = b + 1;
			return ;
		}
		else if (cur_node->start < a && b < cur_node->end) {
			update_row_cnt(cur_node->height, height, b - a + 1);
			new_node = &node_pool[node_pool_cnt++];
			new_node->start = cur_node->start;
			new_node->end = a - 1;
			new_node->height = cur_node->height;
			col_list.insert(cur_node, new_node);
			new_node = &node_pool[node_pool_cnt++];
			new_node->start = a;
			new_node->end = b;
			new_node->height = cur_node->height + height;
			col_list.insert(cur_node, new_node);
			cur_node->start = b + 1;
			return ;
		}
		else if (cur_node->start < a && a <= cur_node->end && cur_node->end <= b) {
			update_row_cnt(cur_node->height, height, cur_node->end - a + 1);
			new_node = &node_pool[node_pool_cnt++];
			new_node->start = cur_node->start;
			new_node->end = a - 1;
			new_node->height = cur_node->height;
			col_list.insert(cur_node, new_node);
			cur_node->start = a;
			cur_node->height = cur_node->height + height;
		}
		else if (a <= cur_node->start && cur_node->end <= b) {
			update_row_cnt(cur_node->height, height, cur_node->end - cur_node->start + 1);
			if (cur_node->prev != col_list.end() && cur_node->prev->height == cur_node->height + height) {
				cur_node->prev->end = cur_node->end;
				col_list.erase(cur_node);
			}
			else
				cur_node->height = cur_node->height + height;
		}
		cur_node = cur_node->next;
	}
	return ;
}

Result dropBlocks(int mCol, int mHeight, int mLength)
{
	Result	ret;

	total_cnt += mHeight * mLength;
	update_col_list(mCol, mCol + mLength - 1, mHeight);
	while (row_cnt[clear_cnt] == col_len)
		++clear_cnt;
    ret.top = height_max - clear_cnt;
    ret.count = (total_cnt - (col_len * clear_cnt)) % 1000000;
    return ret;
}
