/*
No. 5 [Pro] 개발협업도구
참여자 0 제출 0 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 3초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
[제한 사항]

 

 

 

시간

 25개 테스트케이스를 합쳐서 C++ 의 경우 3초 / Java 의 경우 3초
메모리

 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
 

 

※ 본 문제는 임직원의 S/W 문제해결 역량 향상을 위한 Professional 실전형 연습문제이며

함께 제공되는 Testcase 또한 학습을 위한 연습용입니다.

 

 

 

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

 

[문제 설명]

프로젝트 형상 관리를 위해 개발 협업 도구를 사용한다.

개발 협업 도구의 프로젝트 관리 단위는 가지인데, 가지들은 Tree 형태로 분기된다.

각각의 가지는 개발 협업 도구 상에서, 파일들이 저장되는 공간이다.

가지 내 모든 파일들은 이름, 내용, 생성 시각, 최근 수정 시각 정보를 갖는다.

 



                                                             [Fig. 1]

 

사용자는 개발 협업 도구 내 특정 가지에서 파일을 생성 또는 수정 하거나

해당 가지에서 자식 가지로 분기 또는 부모 가지로 병합하는 동작을 수행 할 수 있다.

개발 협업 도구의 초기 상태는, “root” 가지만 있고, 이 “root” 가지는 파일들이 없는 상태로 주어진다.

초기 상태에서, 시간 순서대로 아래 4 가지 동작을 수행하는 프로그램을 작성하라.

1. 새로운 파일 생성

2. 기존 파일 수정

3. 가지 분기

4. 부모 가지로 병합

 

각 동작에 대한 설명은 아래와 같다.

 

1. 새로운 파일 생성

가지 내 새로운 파일을 생성한다. 각각의 가지는 최대 50 개의 파일만 저장할 수 있다.

만약, 50 개의 파일이 저장된 가지에 새로운 파일을 생성해야 할 경우,

가장 생성 시각이 오래된 파일을 하나 삭제한 후, 새로운 파일을 생성한다.

 

2. 기존 파일 수정

가지 내 특정 파일을 수정한다. 이때 수정된 파일의 최근 수정 시각이 update 된다.

 

3. 가지 분기

특정 가지에 자식 가지 생성 후, 자식 가지로 모든 파일을 복사한다.

복사된 파일의 이름, 내용, 생성 시각, 최근 수정 시각은 원본 파일과 같다.

새로운 가지는 분기를 통해서만 만들 수 있다.

따라서 “root” 가지를 제외한 모든 가지는 단 하나의 부모 가지를 갖지만, 자식 가지는 여럿일 수 있다.

그리고 분기된 각 가지에 있는 파일 수정 사항은, 다른 가지에 있는 파일에 영향을 끼치지 않아야 함에 유의하라.

 

4. 부모 가지로 병합

“root” 가지가 아닌 모든 가지는, 부모 가지와 병합이 가능하다. 부모 가지로 병합 후, 해당 가지는 사라진다.

 

만약, 병합 하고자 하는 가지를 “x” 라 했을 때, “x” 의 자식 가지가 없을 경우, 가지에 있는 파일 병합 동작은 아래 규칙을 따른다.

1) “x” 에 있는 파일이 “x” 의 부모 가지에 없을 경우, 해당 파일은 부모 가지로 복사된다.

2) “x” 에 있는 파일이 “x” 의 부모 가지에 있을 경우,

2-1) 부모 가지의 파일과 생성 시각이 다른 경우, “x” 의 파일은 무시된다.

2-2) 부모 가지의 파일과 생성 시각이 같고, 최근 수정 시각이 “x” 의 파일이 더 최신인 경우, 부모 가지의 파일이 “x” 의 파일로 대체된다.

 (반대로 부모 가지에 속한 파일이 더 최근에 수정된 경우, “x” 의 파일은 무시된다.)

2-3) 생성 시각, 수정 시각이 모두 같은 경우, “x” 의 파일은 무시된다.

위 과정을 마치고 부모 가지에 남은 파일의 개수가 50 개를 초과하면, 생성 시각이 오래된 파일들을 삭제하여 50 개를 맞춘 후 “x” 가지를 삭제한다.

 

“x” 에게 자식 가지가 있을 경우, “x” 를 부모 가지로 병합하는 과정은 다음과 같다.

1) “x” 의 자식 가지들을 “x” 로 병합한다.

만약, “x” 의 자식 가지가 여러 개 일 경우, “x” 에서 분기된 순으로 자식 가지를 병합한다.

2) 자식 가지가 각각 분기된 가지를 가질 경우, 이 과정이 재귀적으로 반복된다.

3) “x” 가지의 자식 가지들의 병합이 모두 끝나면, “x” 를  “x” 의 부모 가지로 병합한다.

 

예를 들어 [Fig. 2] 와 같이, 가지들이 구성되어 있고 “x” 로부터 ①~⑥ 순서대로 분기되었을 때, “x” 를 부모 가지인 “root” 로 병합하는 경우를 생각해보자.

 



                                                             [Fig. 2]

 

“x” 의 자손들을 “x” 가지로 병합하는 과정은 [Fig. 3] 의 ①~⑥ 순으로 진행한다.

“x” 의 자손들이 모두 병합되면, 그때 ⑦ 과 같이 “x” 의 부모인 “root” 로의 병합을 수행한다.

 



                                                             [Fig. 3]

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main 과 User Code를 참고하라.

 

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init()

각 테스트 케이스의 처음에 한 번 호출된다.

호출 직후 “root” 이름의 가지만 존재하며, “root” 가지에는 아무 파일도 존재하지 않는다.

void create(int mTime, char mBranch[], char mFile[], char mData[])

mTime 시각, mBranch 가지에 이름이 mFile 인 파일을 생성한다.

생성된 파일의 내용은 mData 이다.

 

함수 호출 시점에 이름이 mBranch 인 가지가 존재한다.

함수 호출 시점에 mBranch 가지에는 이름이 mFile 인 파일이 없다.

mBranch, mFile, mData 는 모두 길이가 1 이상 10 이하인 문자열로, 영문 소문자로만 이루어져 있으며 ‘＼0’ 으로 끝난다.

 

Parameters

mTime : 함수가 호출되는 시각 (1 ≤ mTime ≤ 10,000)

mBranch : 파일을 생성될 가지의 이름

mFile : 생성된 파일의 이름

mData : 생성된 파일의 내용

void edit(int mTime, char mBranch[], char mFile[], char mData[])

mTime 시각, mBranch 가지 내 파일 중, 이름이 mFile 인 파일을 수정한다.

수정된 파일의 내용은 mData 이다.

 

함수 호출 시점에 이름이 mBranch 인 가지가 존재한다.

함수 호출 시점에 mBranch 가지에는 이름이 mFile 인 파일이 존재한다.

mBranch, mFile, mData 는 모두 길이가 1 이상 10 이하인 문자열로, 영문 소문자로만 이루어져 있으며 ‘＼0’ 으로 끝난다.

 

Parameters

mTime : 함수가 호출되는 시각 (1 ≤ mTime ≤ 10,000)

mBranch : 수정할 파일이 위치한 가지의 이름

mFile : 수정하는 파일의 이름

mData : 수정된 파일의 내용

void branch(int mTime, char mBranch[], char mChild[])

mTime 시각에 이름이 mBranch 인 가지를 분기한다.

mBranch 로 부터 분기된 가지의 이름은 mChild 이다.

분기 후, mBranch 가지의 파일들을 모두 mChild 가지로 복사한다.

 

함수 호출 시점에 이름이 mBranch 인 가지가 존재한다.

mChild 는 init() 함수 호출 이후 생성된 모든 가지와 이름이 다르다. (생성 후, 삭제된 가지의 이름과도 다르다.)

mBranch, mChild 는 모두 길이가 1 이상 10 이하인 문자열로, 영문 소문자로만 이루어져 있으며 ‘＼0’ 으로 끝난다.

 

Parameters

mTime : 함수가 호출되는 시각 (1 ≤ mTime ≤ 10,000)

mBranch : 분기할 가지의 이름

mChild : mBranch 로부터 분기 후 새로이 생성된 가지의 이름

void merge(int mTime, char mBranch[])

mTime 시각, 이름이 mBranch 인 가지를 해당 가지의 부모 가지로 병합한다.

mBranch 는 “root” 가 아니며, 함수 호출 시점에 이름이 mBranch 인 가지가 존재한다.

mBranch 는 길이가 1 이상 10 이하인 문자열로, 영문 소문자로만 이루어져 있으며 ‘＼0’ 으로 끝난다.

 

Parameters

mTime : 함수가 호출되는 시각 (1 ≤ mTime ≤ 10,000)

mBranch : 부모 가지로 병합할 가지의 이름

int readfile(int mTime, char mBranch[], char mFile[], char retString[])

mTime 시각, mBranch 가지에 있는 파일 중, 이름이 mFile 인 파일의 내용을 읽는다.

파일의 내용은 retString 문자 배열에 담고, 파일 내용의 길이를 반환한다.

 

함수 호출 시점에 이름이 mBranch 인 가지가 존재한다.

함수 호출 시점에 mBranch 가지에는 mFile 이름의 파일이 존재한다.

mBranch, mFile 은 모두 길이 1 이상 10 이하의 문자열로, 영문 소문자로만 이루어져 있으며 ‘＼0’ 으로 끝난다.

 

Parameters

mTime : 함수가 호출되는 시각 (1 ≤ mTime ≤ 10,000)

mBranch : 파일이 위치한 가지의 이름

mFile : 파일의 이름

retString : 반환할 파일 내용을 저장하는 문자열 변수

 

Returns

읽은 파일 내용을 retString 배열에 담고, 그 길이를 반환한다.

 

[예제]

[Table-1] ~ [Table-6] 는 첫 번째 테스트 케이스에서 호출 되는 함수들을 순서대로 보여준다.

각각의 표에서 retString 항목은, readfile 함수 호출 시, 반환되는 파일의 내용이다.

[Fig. 4] ~ [Fig. 9] 는 예제 함수 호출 순번 중, 특정 시점의 상황을 보여주는 그림으로

현재 가지의 구성을 나타내는 그림과, 각 가지에 존재하는 파일 목록으로 구성된다.

 

1. 순번 1~3 – [Table-1], [Fig. 4] 참고

순번 3 은, init() 함수 호출 후, “root” 가지가 있고

“root” 가지에 main과 user 파일이 생성된 상황을 보여준다.

Order

Function

retString

return

1

init()

 

 

2

create(1, “root", "main", "hello”)

 

 

3

create(2, “root", "user", "world”)

 

 

                                                              [Table-1]

main 과 user 파일은 생성 후, 수정되지 않았으므로 각 파일의 생성 시각과 최근 수정 시각은 동일하다.


                                                             [Fig. 4]

 

2. 순번 4 – [Table-2], [Fig. 5] 참고

순번 4 의 branch 함수는 “root” 가지에서 “dev” 가지로 분기하는 동작을 수행한다.

“root” 가지에 있는 모든 파일들의 정보(이름, 내용, 생성 시각, 최근 수정 시각)가 모두 동일하게 복사되어 “dev” 가지에 저장되어 있음을 알 수 있다.

Order

Function

retString

return

4

branch(3, “root”, ”dev”)

 

 

                                                              [Table-2]


                                                             [Fig. 5]

 

3. 순번 5~8 – [Table-3], [Fig. 6] 참고

순번 5, 6의 create 함수 호출 후 “root” 와 “dev” 가지에 생성 시각과 내용이 다른 “module” 파일이 생성된다.

이후 7, 8번 edit 함수 호출 후, “root” 가지의 “main” 파일과 “dev” 가지의 “user” 파일이 각각 수정된다.

이때 수정된 파일의 최근 수정 시각 정보가 변경되어 있음을 알 수 있다.

Order

Function

retString

return

5

create(4, “root”, ”module”, ”mode”)

 

 

6

create(5, “dev”, ”module”, ”mod”)

 

 

7

edit(6, “root”, ”main”, ”hi”)

 

 

8

edit(7, “dev”, ”user”, ”word”)

 

 

                                                              [Table-3]


                                                             [Fig. 6]

 

4. 순번 9~17 – [Table-4], [Fig. 7] 참고

순번 9~11의 readfile 함수 호출 시, root 가지에 있는 각 파일의 내용인 “hi”, “world”, “mode” 를 읽어온다.

이때, 함수 호출에 대한 반환 값으로 파일 내용 문자열의 길이인 2, 5, 4 를 각각 반환한다.

 

순번 12 의 branch 함수는 “dev” 가지에서 “bugfix” 가지로 분기하는 동작을 수행한다.

이후, “bugfix” 가지에 ”sononly”, “dev” 가지에 “paronly” 라는 파일이 생성된다.

 

Order

Function

retString

return

9

readfile(8, “root”, ”main”)

“hi”

2

10

readfile(9, “root”, ”user”)

“world”

5

11

readfile(10, “root”, ”module”)

“mode”

4

12

branch(11, “dev”, ”bugfix”)

 

 

13

create(12, “bugfix”, ”sononly”, ”son”)

 

 

14

create(13, “dev”, ”paronly”, ”par”)

 

 

15

branch(14, “dev”, ”patch”)

 

 

16

readfile(15, “bugfix”, ”user”)

“word”

4

17

edit(16, “patch”, ”user”, ”lord”)

 

 

18

edit(17, “bugfix”, ”user”, ”sword”)

 

 

                                                              [Table-4]

 

아래 [Fig. 7] 은 순번 17, 18 의 edit 함수 호출이 끝난 직후 상황을 보여준다.


                                                             [Fig. 7]

 

5. 순번 19 – [Table-5], [Fig. 8], [Fig. 9] 참고

순번 19 의 merge 함수는 “dev” 가지를 부모 가지인 “root” 가지로 병합하는 동작을 수행 한다.

Order

Function

retString

Return

19

merge(18, “dev”)

 

 

                                                              [Table-5]

 

“dev” 가지는 자식 가지가 두개가 있다. 이중, 먼저 분기된 가지인 “bugfix” 를 “dev” 가지로 병합한다.

“bugfix” 에 있는 파일 중, “sononly” 파일은 자식가지에만 존재하는 파일로 “dev” 가지로 복사된다.

이외, “bugfix” 에 있는 나머지 세개의 파일은, 이름이 같은 파일이 부모 가지에 있다.

이중, “main”, “module” 파일은 부모/자식 가지에서 동일하므로 하나만 남는다.

반면 “user” 파일은 이름과 생성 시각만 같고, 내용과 최근 수정 시각이 다르다. ([Fig. 7] 참고)

“dev” 가지의 “user” 파일 최근 수정 시각 = 7

“bugfix” 가지의 “user” 파일 최근 수정 시각 = 17

이중, 더 최근에 수정된 “bugfix” 가지의 “user” 파일의 정보를 “dev” 가지의 “user” 파일에 반영한다.

 

아래 [Fig. 8] 는 “dev” 의 자식 가지 중, “bugfix” 가 병합된 상태를 보여준다.

 


                                                             [Fig. 8]

 

“bugfix” 가지의 병합이 끝난 후, “patch” 가지를 “dev” 가지로 병합한다.

“patch” 에 있는 파일은, 모두 같은 이름의 파일이 부모 가지에 있다.

이중, “user” 파일만 이름과 생성 시각만 같고, 내용과 최근 수정 시각이 다르다. ([Fig. 8] 참고)

“dev” 가지의 “user” 파일 최근 수정 시각 = 17

“patch” 가지의 “user” 파일 최근 수정 시각 = 16

“dev” 가지의 “user” 파일이 더 최근에 수정되었으므로, 그대로 둔다.

 

아래 [Fig. 9] 의 상황은 “dev” 의 자식 가지가 모두 병합된 상태를 보여준다.

  
                                                             [Fig. 9]

 

“dev” 의 자식 가지 병합이 끝난 후, “dev” 가지가 “root” 가지로 병합된다.

“paronly”, “sononly” 는 자식(“dev”)가지에만 존재하는 파일로 “root” 가지에 그대로 반영된다.

“main”, “user” 파일은 부모(“root”), 자식(“dev”) 가지에서 이름과 생성 시각이 동일하므로

“dev” 가지에 있는 “main”, “user” 파일의 최근 수정 시각이 더 최근인 경우에만 “root” 가지로 반영한다.

한편, 부모 자식 가지에 존재하는 “module” 파일은 이름은 같으나 생성 시각이 다르다.

이 경우, 자식 가지의 파일은 무시된다.

 

“dev” 가지가 “root” 가지로 병합이 완료된 상황은 아래 [Fig. 10] 과 같다.

 
                                                              [Fig. 10]

 

6. 순번 20~24 – [Table-6] 참고

순번 20~24 의 readfile 함수 호출 동작은 위 [Fig. 10] 의, “root” 가지 내 파일의 내용을 하나씩 읽어온다.

Order

Function

retString

return

20

readfile(19, “root”, ”main”)

“hi”

2

21

readfile(20, “root”, ”user”)

“sword”

5

22

readfile(21, “root”, ”module”)

“mode”

4

23

readfile(22, “root”, ”sononly”)

“son”

3

24

readfile(23, “root”, ”paronly”)

“par”

3

                                                              [Table-6]

 

[제약사항]

1. 각 테스트 케이스 시작 시, init() 함수가 한 번 호출된다.

2. 각 테스트 케이스에서 mTime 은 1 부터 시작하며 init() 함수를 제외한, 매 함수 호출 시 마다 1 씩 증가한다.

3. 문자열은 항상 ‘＼0’ (널 문자)로 끝난다.

4. 각 테스트 케이스에서 init() 을 제외한 모든 함수 호출 횟수의 총합은 최대 10,000 이다.

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

Sample input 에 대한 정답 출력 결과는 “#TC번호 결과” 의 포맷으로 보여지며 결과가 100 일 경우 정답, 0 일 경우 오답을 의미한다
*/
#include <iostream>
#include <unistd.h>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

struct 	t_file;
struct 	t_branch;

template	<typename T>
struct	t_list
{
	T	*head;
	int	node_cnt;

	void	clear(void) {
		if (head != NULL)
			delete head;
		head = new T;
		head->next = head;
		head->prev = head;
		node_cnt = 0;
	}
	void	push_back(T *new_node) {
		new_node->prev = head->prev;
		new_node->next = head;
		head->prev->next = new_node;
		head->prev = new_node;
		++node_cnt;
	}
	void	pop_front(void) {
		head->next->next->prev = head;
		head->next = head->next->next;
		--node_cnt;
	}
	void	insert(T *new_node, T *cur_node) {
		new_node->prev = cur_node->prev;
		new_node->next = cur_node;
		cur_node->prev->next = new_node;
		cur_node->prev = new_node;
		++node_cnt;
	}
	T	*erase(T *node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
		--node_cnt;
		return (node->next);
	}
	T	*begin(void) {
		return (head->next);
	}
	T	*end(void) {
		return (head);
	}
	int	cnt(void) {
		return (node_cnt);
	}
};

struct t_file
{
	string			file_name;
	string			data;
	int				created;
	int				modified;
	struct t_file	*next;
	struct t_file	*prev;
};

struct t_branch
{
	string				branch_name;
	t_branch			*parent;
	t_list<t_file>		file_list;
	t_list<t_branch>	child_list;
	t_branch			*next;
	t_branch			*prev;
	unordered_map<string, t_file *>	file_table;

	void	clear(void) {
		file_list.clear();
		child_list.clear();
		file_table.clear();
	}
};

t_file		file_pool[500000];
int			file_pool_cnt;
t_branch	branch_pool[10000];
int			branch_pool_cnt;

t_branch	root;

unordered_map<string, t_branch *>	branch_table;

void init() {
	file_pool_cnt = 0;
	branch_pool_cnt = 0;
	branch_table.clear();
	root.clear();
	root.branch_name = "root";
	branch_table.insert({root.branch_name, &root});
}

void create(int mTime, char mBranch[], char mFile[], char mData[])
{
	t_file		*new_file;
	t_branch	*cur_branch;

	cur_branch = branch_table[(string)mBranch];
	new_file = &file_pool[file_pool_cnt++];
	new_file->file_name = mFile;
	new_file->data = mData;
	new_file->created = mTime;
	new_file->modified = mTime;
	cur_branch->file_list.push_back(new_file);
	cur_branch->file_table.insert({new_file->file_name, new_file});
	if (cur_branch->file_list.cnt() > 50) {
		cur_branch->file_table.erase(cur_branch->file_list.begin()->file_name);
		cur_branch->file_list.pop_front();
	}
}

void edit(int mTime, char mBranch[], char mFile[], char mData[])
{
	t_file		*cur_file;
	t_branch	*cur_branch;

	cur_branch = branch_table[(string)mBranch];
	cur_file = cur_branch->file_table[(string)mFile];
	cur_file->data = mData;
	cur_file->modified = mTime;
}

void branch(int mTime, char mBranch[], char mChild[])
{
	t_file		*cur_file, *new_file;
	t_branch	*cur_branch, *new_branch;

	cur_branch = branch_table[(string)mBranch];
	new_branch = &branch_pool[branch_pool_cnt++];
	new_branch->clear();
	new_branch->branch_name = mChild;
	cur_file = cur_branch->file_list.begin();
	while (cur_file != cur_branch->file_list.end()) {
		new_file = &file_pool[file_pool_cnt++];
		new_file->file_name = cur_file->file_name;
		new_file->data = cur_file->data;
		new_file->created = cur_file->created;
		new_file->modified = cur_file->modified;
		new_branch->file_list.push_back(new_file);
		new_branch->file_table.insert({new_file->file_name, new_file});
		cur_file = cur_file->next;
	}
	new_branch->parent = cur_branch;
	cur_branch->child_list.push_back(new_branch);
	branch_table.insert({new_branch->branch_name, new_branch});
}

void	run_merge(t_branch *cur_branch) {
	t_file		*cur_file, *parent_file, *next_file, *ptr;
	t_branch	*child_branch, *parent_branch;

	child_branch = cur_branch->child_list.begin();
	while (child_branch != cur_branch->child_list.end()) {
		run_merge(child_branch);
		child_branch = cur_branch->child_list.begin();
	}
	parent_branch = cur_branch->parent;
	cur_file = cur_branch->file_list.begin();
	while (cur_file != cur_branch->file_list.end()) {
		next_file = cur_file->next;
		auto	iter = parent_branch->file_table.find(cur_file->file_name);
		if (iter != parent_branch->file_table.end()) {
			parent_file = (*iter).second;
			if (cur_file->created == parent_file->created && \
						cur_file->modified > parent_file->modified) {
				parent_file->data = cur_file->data;
				parent_file->modified = cur_file->modified;
			}
		}
		else {
			ptr = parent_branch->file_list.begin();
			while (ptr != parent_branch->file_list.end()) {
				if (cur_file->created < ptr->created)
					break ;
				ptr = ptr->next;
			}
			parent_branch->file_list.insert(cur_file, ptr);
			parent_branch->file_table.insert({cur_file->file_name, cur_file});
		}
		cur_file = next_file;
	}
	while (parent_branch->file_list.cnt() > 50) {
		parent_branch->file_table.erase(parent_branch->file_list.begin()->file_name);
		parent_branch->file_list.pop_front();
	}
	parent_branch->child_list.erase(cur_branch);
	branch_table.erase(cur_branch->branch_name);
}

void merge(int mTime, char mBranch[])
{
	t_branch	*cur_branch;

	cur_branch = branch_table[(string)mBranch];
	run_merge(cur_branch);
}

int readfile(int mTime, char mBranch[], char mFile[], char retString[])
{
	t_file		*cur_file;
	t_branch	*cur_branch;

	cur_branch = branch_table[(string)mBranch];
	cur_file = cur_branch->file_table[(string)mFile];
	strcpy(retString, cur_file->data.c_str());
	return (cur_file->data.size());
}