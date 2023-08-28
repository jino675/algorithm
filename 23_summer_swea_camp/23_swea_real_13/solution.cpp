/*
No. 13 [Pro] 단어미로
참여자 17 제출 32 배점 100
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

  ㅇ   A.  2개의 파일을 생성하셔야 합니다. ( main.cpp / solution.cpp 또는 Solution.java / UserSolution.java )

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

여러 개의 방으로 구성된 미로가 있다.

각 방에는 길이가 11 인 단어가 있다. 이에 더해 다른 방으로 이동하기 위해 앞 방향, 중간 방향, 뒤 방향으로 이동에 필요한 숫자가 있다.

앞 방향 숫자, 뒤 방향 숫자는 2 또는 4 이고, 중간 방향 숫자는 3 이다.

 

앞 방향 숫자가 N 이고, 중간 방향 숫자가 3, 뒤 방향 숫자가 K 일 때,

앞으로 이동시, 현재 위치 방의 단어 앞 N 개 문자와 같은, 뒤 N 개의 문자가 있는 단어의 방으로 이동한다.

중간으로 이동시, 현재 위치 방의 단어 5, 6, 7 번째 문자와 같은, 5, 6, 7 번째 문자가 있는 단어의 방으로 이동한다.

뒤로 이동시, 현재 위치 방의 단어 뒤 K 개 문자와 같은, 앞 K 개의 문자가 있는 단어의 방으로 이동한다.

 

예를 들어, 현재 위치의 방에 “appletmango” 단어가 있고, 앞 방향 숫자는 4, 중간 방향 숫자는 3, 뒤 방향 숫자가 2일 경우,

앞으로 이동시, 단어의 앞 4개의 문자인 “appl”이 있는 “???????appl” 단어가 있는 방으로 이동한다.

중간으로 이동시, 단어의 중간 3개의 문자인 “etm”이 있는 “????etm????” 단어가 있는 방으로 이동한다.

뒤로 이동시, 단어의 뒤 2개의 문자인 “go”가 있는 “go?????????” 단어가 있는 방으로 이동한다.

 

단, 이동시 자기 방은 제외되어, 자기 방에서 자기 방으로 이동하지는 않는다.

이동 가능한 방이 여러 개 일 경우, 사전 순으로 가장 빠른 단어가 있는 방으로 이동한다.

 

방의 단어와 이동에 필요한 숫자가 변경될 수 있다. 이럴 경우, 단어 미로의 이동은 변경될 수 있다.

 

단어와 이동에 필요한 숫자가 주어질 때, 단어 미로를 이동하면서 각 방의 단어를 확인하는 프로그램을 작성하여 보자.

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

아래는 User Code 부분에 작성해야 하는 API 의 설명이다. 

 

void init()

각 테스트 케이스의 처음에 호출된다.

 

단어 미로에 방의 개수는 0 이다.

현재 위치로 설정된 방이 없다.

void addRoom(int mID, char mWord[], int mDirLen[])

단어 미로에 방 번호가 mID 이고, mWord[] 단어가 있는 방이 추가된다.

mDirLen[0]은 앞 방향 숫자를, mDirLen[1]은 중간 방향 숫자를, mDirLen[2]는 뒤 방향 숫자를 나타낸다.

 

앞 방향 숫자, 뒤 방향 숫자는 2 또는 4 이고, 중간 방향 숫자는 3 이다.

mID는 맨 처음 호출할 때 1이고 그 다음 호출할 때마다 1씩 증가한다.

mWord[]는 ‘\0’으로 끝나는 영어 소문자로 구성된 문자열이고, ‘\0’ 제외한 길이가 11이다.

mWord[]는 단어 미로에 있는 단어와 중복되지 않는다.

 

Parameters

  mID          : 추가되는 방 번호 ( 1 ≤ mID ≤ 30,000 )

  mWord[]  : 추가되는 방의 단어 ( |mWord| = 11, |A|는 A 문자열의 길이를 의미한다. )

  mDirLen[] : 추가되는 방의 앞 방향, 중간 방향, 뒤 방향 숫자 ( mDirLen[0] = 2 or 4, mDirLen[1] = 3,                                      mDirLen[2] = 2 or 4 )

void setCurrent(char mWord[])

단어 미로에 mWord[] 가 있는 방이 현재 위치가 된다.

 

mWord[]는 ‘\0’으로 끝나는 영어 소문자로 구성된 문자열이고, ‘\0’ 제외한 길이가 11이다.

mWord[] 단어가 미로에 있음이 보장된다.

 

Parameters

  mWord[]  : 현재 위치가 되는 방의 단어 ( |mWord| = 11 )

int moveDir(int mDir)

단어 미로의 현재 위치 방에서 mDir 방향으로 이동하고, 이동한 경우 이동한 방의 번호를 반환한다.

mDir 방향으로 이동 가능한 방이 없어 이동이 실패할 경우 0 을 반환한다.

 

이동할 때 현재 위치 방은 제외되어, 다시 현재 위치 방으로 이동하지 않는다.

mDir = 0, 앞 방향으로 이동한다.

mDir = 1, 중간 방향으로 이동한다.

mDir = 2, 뒤 방향으로 이동한다.

이동 방법은 본문을 참고한다.

 

이동 가능한 방이 여러 개 일 경우, 방의 단어가 사전 순으로 가장 빠른 방으로 이동한다.

현재 위치로 설정된 방이 있음이 보장된다.

 

Parameters

  mDir  : 이동 방향 ( 0 ≤ mDir ≤ 2 )

Returns

  이동이 가능할 경우 이동한 방의 번호를 반환

  이동이 불가능 할 경우 0을 반환

void changeWord(char mWord[], char mChgWord[], int mChgLen[])

단어 미로에서 단어가 mWord[] 인 방을 찾고, 그 방의 단어를 mChgWord[] 로 변경한다.

또 한, mChgLen[0]은 앞 방향 숫자로, mChgLen[1]은 중간 방향 숫자로, mChgLen[2]는 뒤 방향 숫자로 변경한다.

 

단어 변경으로 단어 미로의 이동은 변경 될 수 있다.

앞 방향 숫자, 뒤 방향 숫자는 2 또는 4 이고, 중간 방향 숫자는 3 이다.

mChgWord[]는 ‘\0’으로 끝나는 영어 소문자로 구성된 문자열이고, ‘\0’ 제외한 길이가 11이다.

 

단어 미로에 mWord[] 의 방이 있음이 보장된다.

mChgWord[]는 mWord[]와 다르고, 단어 미로에 있는 단어와 중복되지 않는다.

방 번호는 변경되지 않는다.

 

Parameters

  mWord[]       : 변경이 되는 방의 단어 ( |mWord| = 11 )

  mChgWord[]  : 변경되는 단어 ( |mChgWord| = 11 )

  mChgLen[]    : 변경되는 앞 방향, 중간 방향, 뒤 방향 숫자 (mChgWord[0] = 2 or 4, mChgWord[1] = 3,                                  mChgWord[2] = 2 or 4 )

 

[예제]

아래에는 테스트케이스 1번을 처음부터 순서대로 보여준다.

Order

Function

Return Value

1

init()

 

2

addRoom(1, “appletmango”, { 4, 3, 2 })

 

3

addRoom(2, “bcyaerrkang”, { 2, 3, 4 })

 

4

addRoom(3, “efkabcdappl”, { 2, 3, 4 })

 

5

addRoom(4, “applerryabc”, { 2, 3, 2 })

 

6

addRoom(5, “applefgappl”, { 2, 3, 4 })

 

7

addRoom(6, “nggoerrerer”, { 2, 3, 2 })

 

8

setCurrent(“appletmango”)

 

9

moveDir(0)

5

10

moveDir(0)

0

11

moveDir(2)

4

12

moveDir(1)

2

13

moveDir(0)

4

                                                                              [Table 1]

Order 13. moveDir(0) 실행 후, 단어 미로의 상태는 [Fig. 1] 과 같다.

현재 위치 방의 단어는 “applerryabc” 이다. (이동 경로 화살표 표시)



 

[Table 2]는 [Table 1]이후의 함수 호출이다.

Order

Function

Return Value

14

changeWord(“applerryabc”, “gogoaurappl”, { 2, 3, 4 })

 

15

moveDir(0)

1

16

moveDir(2)

4

17

changeWord(“applefgappl”, “efgaaurappl”, { 4, 3, 2 })

 

18

moveDir(2)

1

19

moveDir(0)

5

20

addRoom(7, “plaaqwrtble”, {2, 3, 4})

 

21

addRoom(8, “baswerrefka”, {4, 3, 4})

 

22

addRoom(9, “kangqwrbcya”, {4, 3, 4})

 

23

moveDir(2)

7

24

moveDir(1)

9

25

moveDir(0)

2

26

moveDir(1)

8

                                                                              [Table 2]

Order 26. moveDir(1) 실행 후, 단어 미로의 상태는 [Fig. 2] 와 같다.

현재 위치 방의 단어는 “baswerrefka” 이다. (이동 경로 화살표 표시)



 

[Table 3]는 [Table 2] 이후의 함수 호출이다.

Order

Function

Return Value

27

setCurrent(“nggoerrerer”)

 

28

moveDir(0)

2

29

moveDir(2)

9

30

moveDir(2)

2

31

moveDir(2)

9

32

moveDir(1)

7

33

moveDir(0)

5

34

moveDir(1)

4

35

changeWord(“gogoaurappl”, “plaaerruhbz”, { 2, 3, 2 })

 

36

moveDir(1)

8

37

moveDir(2)

3

38

moveDir(2)

1

39

moveDir(0)

5

40

moveDir(1)

0

41

moveDir(2)

4

42

moveDir(0)

5

                                                                              [Table 3]

Order 42. moveDir(0) 실행 후, 단어 미로의 상태는 [Fig. 3] 과 같다.

현재 위치 방의 단어는 “efgaaurappl” 이다. (이동 경로 화살표 표시)



 

 

 [제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. 방에 있는 단어의 길이는 11 이다.

3. 방에 있는 앞 방향, 뒤 방향 숫자는 2 또는 4 이고, 중간 방향 숫자는 3 이다.

4. 방 이동시, 이동 가능한 방이 여러 개 일 경우 사전 순으로 가장 빠른 방으로 이동한다.

5. 각 테스트 케이스에서 addRoom() 함수의 호출 횟수는 최대 30,000 이다.

6. 각 테스트 케이스에서 setCurrent() 함수의 호출 횟수는 최대 500 이다.

7. 각 테스트 케이스에서 moveDir() 함수의 호출 횟수는 최대 50,000 이다.

8. 각 테스트 케이스에서 changeWord() 함수의 호출 횟수는 최대 3,000 이다.
*/
void init()
{
}

void addRoom(int mID, char mWord[], int mDirLen[])
{
}

void setCurrent(char mWord[])
{
}

int moveDir(int mDir)
{
	return 0;
}

void changeWord(char mWord[], char mChgWord[], int mChgLen[])
{
}