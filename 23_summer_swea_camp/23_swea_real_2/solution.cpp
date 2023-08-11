/*
No. 2 [Pro] 삼국지게임
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

 

[문제 설명]

당신은 어린 시절 삼국지 게임 매니아였다. 어린 시절 추억을 살려 삼국지 게임을 만들어보기로 한다.

구현하려는 기능은 구체적으로 아래와 같다.

-     어떤 군주와 다른 군주와의 동맹 (ally)

-     어떤 군주와 그 동맹 군주들이 다른 군주의 영토를 공격 (attack)

-     병사 모집 (recruit)

 

전체 영토는 N x N 영토로 구성되어 있다.

각 영토에는 영토를 다스리는 군주가 있으며, 군주의 이름에 중복은 없으며, 모든 군주는 단 하나의 영토를 통치한다.

초기에는 군주들은 동맹이나 적대관계가 없다. 각 영토에는 병사들이 있다.

 [Fig. 1] 은 N이 4인 경우, 군주의 이름과 각 영토의 병사 수의 예이다.

 

 



_________________ _______ [Fig. 1]

 

군주들은 서로 동맹을 한다.

동맹을 하면 전투 시 함께 공격하고, 함께 방어를 할 수 있다.

두 군주들이 동맹을 하면 서로의 모든 동맹까지 함께 동맹을 맺는다.

동맹을 맺을 때, 동맹을 맺는 두 군주를 포함한 서로의 모든 동맹 군주 간 적대관계가 있는 경우 동맹을 맺지 않는다.

동맹을 맺을 때 두 군주와 그 동맹들의 적대관계는 새로운 동맹에 그대로 유지가 된다.  

[Fig. 2] 와 같이 A, C, D가 동맹이고 F가 적대 관계이고 B, E가 동맹이고 G와 적대 관계일 때,

A와 B가 동맹을 맺으면 A, B, C, D, E 가 동맹이 되고, F, G 와는 적대 관계가 된다.

 



______________________                     _ [Fig. 2]

 

삼국지 게임의 핵심은 전투이다. 전투는 동맹과 동맹 간의 전투다.

공격을 받는 군주가 공격하는 군주의 동맹에 속해 있는 경우에 전투는 발생하지 않는다.

전투는 공격하는 군주의 또는 그의 동맹 (이하 군주의 동맹) 영토가 피 공격 영토에 인접해 있을 경우에 만 발생한다.

 

[Fig. 3] 에서 A ~ H 를 X 에 인접한 군주라 한다.

군주 X 의 영토를 공격할 때 전투가 발생하기 위해서는 공격하는 군주의 동맹이 A ~ H 에 하나라도 있어야 한다.

 

 



_               _ [Fig. 3]

전투가 발생하는 경우 공격하는 동맹의 각 군주들은 방어하는 각 군주들과 서로 적대관계가 된다.  

실제 전투가 일어나지 않는 경우는 적대관계가 되지 않는다.

전투는 공격하는 군주의 동맹들이 함께 공격을 하고, 공격을 받는 군주의 동맹도 함께 방어를 한다.

공격하는 인접 동맹들은 자신이 가진 병사의 절반을 공격 대상 영토에 보내 함께 공격을 하고,

방어를 하는 군주의 인접 동맹에서도 병사의 절반씩을 보내어 함께 방어를 한다.

 

[Fig. 4] 는 군주 A, C, D 가 동맹이고, 군주 B, E가 동맹일 때, 군주 A가 군주 E를 공격하는 경우에 대한 예시다. 군주 E 의 영토가 A의 동맹 C, D 와 인접하므로 전투가 발생한다.  

이 때 공격하는 병사의 수는 군주 E 에 인접한 군주 C의 병사 절반 10명과 군주 D의 병사 절반 7명을 합한 17명이 된다.   

방어하는 병사의 수는 군주 E의 영토에 있는 병사 15명과 군주 B로부터 병사 절반인 5명을 지원받아 총 20명이 된다.

 

 



_______________________                      _ [Fig. 4]

병사들은 상대 병사와 1:1로 싸워 함께 전사한다.

전투의 승리 여부는 남은 병사의 수로 판별한다.

 

만약 공격한 병사의 수가 방어한 병사의 수보다 많다면 공격은 성공한다.

영토가 함락 되었으므로 패배한 군주는 처형되고, 공격을 지휘한 장수가 해당 영토의 새로운 군주가 된다.

새로운 군주의 동맹과 적대관계는 공격한 군주의 동맹 및 적대 관계를 그대로 승계한다.

새로운 군주의 병사의 수는 공격하고 남은 병사의 수가 된다.

 

방어하는 쪽의 병사의 수가 공격하는 쪽의 병사의 수보다 많거나 같으면 공격은 실패한다.

방어하는 군주의 병사의 수는 방어하고 남은 병사의 수가 된다.

 

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

void init(int N, int mSoldier[][], char mMonarch[][][])

각 테스트 케이스의 처음에 호출된다.

전체 영토는 N x N의 격자 모양으로 이루어져 있다.

mSoldier 은 각 영토의 병사의 수이다.  

mMonarch 는 각 영토의 군주 이름이다.

군주 이름은 알파벳 소문자로 이루어져 있으며, 길이는 4 이상 10 이하의 문자열이다.

입력 순서는 아래와 같다.

 	
0

1

……

N-1

 
0

mSoldier[0][0]

mSoldier[0][1]

……

mSoldier[0][N-1]

 
1

mSoldier[1][0]

mSoldier[1][1]

……

mSoldier[1][N-1]

 
……

……

……

……

……

 
N-1

mSoldier[N-1][0]

mSoldier[N-1][1]

……

mSoldier[N-1][N-1]

 
 	 	 	 	 	 
 	 	 	 	 	 
 	
0

1

……

N-1

 
0

mMonarch[0][0]

mMonarch[0][1]

……

mMonarch[0][N-1]

 
1

mMonarch[1][0]

mMonarch[1][1]

……

mMonarch[1][N-1]

 
……

……

……

……

……

 
N-1

mMonarch[N-1][0]

mMonarch[N-1][1]

……

mMonarch[N-1][N-1]

 
 	 	 	 	 	 
초기에는 모든 군주들은 동맹관계도 적대관계도 없다.

 

__Parameters

_____N : 전체 영토의 크기 (4 ≤ N ≤ 25, 16 ≤ N x N ≤ 625)

_____mSoldier : 각 영토의 병사의 수 (4 ≤ mSoldier[][] ≤ 200)

_____mMonarch : 각 영토의 군주의 이름 (4 ≤ mMonarch[][]의 길이 ≤ 10)

void destroy()

각 테스트 케이스의 마지막에 호출된다.

빈 함수로 두어도 채점에는 영향을 주지 않는다.

int ally(char mMonarchA[], char mMonarchB[])

군주 mMonarchA 의 동맹들이 군주 mMonarchB 의 동맹들과 동맹을 맺는다.

군주 mMonarchA 와 군주 mMonarchB 가 동일 하거나 이미 동맹관계이면 -1을 반환한다.

군주 mMonarchA 의 동맹과 군주 mMonarchB 의 동맹 간에 적대관계가 있으면 -2를 반환한다.

위의 두 경우가 아닌 경우 동맹관계가 맺어지고, 1을 반환한다.

 

각 군주 이름은 알파벳 소문자로 이루어져 있으며, 길이는 4 이상 10 이하의 문자열이다.

mMonarchA 와 mMonarchB 는 현재 군주임이 보장된다.

 

__Parameters

_____mMonarchA : 군주의 이름 (4 ≤ 길이 ≤ 10)

_____mMonarchB : 군주의 이름 (4 ≤ 길이 ≤ 10)

 

__Returns

_____동맹의 결과 (이미 동맹관계이면 -1, 적대관계가 있으면 -2, 성공하면 1)

int attack(char mMonarchA[], char mMonarchB[], char mGeneral[])

군주 mMonarchA 와 동맹들이 군주 mMonarchB 의 영토를 공격한다.

공격을 지휘하는 장수는 mGeneral 이다.

 

군주 mMonarchA 와 군주 mMonarchB 가 동맹관계 이면 -1을 반환하고, 전투는 일어나지 않는다.

군주 mMonarchA 의 영토 또는 동맹 영토가 군주 mMonarchB 의 영토와 인접하지 않다면 -2을 반환하고, 전투는 일어나지 않는다.

 

전투가 발생하면 군주 mMonarchA 의 동맹과 군주 mMonarchB 의 동맹은 서로 적대관계가 된다.

 

전투가 발생하면 군주 mMonarchB 의 영토에 인접한 군주 mMonarchA 를 포함한 모든 동맹들은 보유한 병사의 절반을 보내 함께 공격한다.

군주 mMonarchB 의 영토에 인접한 군주 mMonarchB 의 모든 동맹들도 보유한 병사의 절반을 mMonarchB 의 영토로 보내 방어를 돕는다.

보내는 병사 계산시 소수점은 버린다.

공격하는 병사의 수가 0명이라도 전투가 발생한 것이다.

 

전투 시 병사들은 상대 병사와 1:1로 싸워 함께 전사한다.

 

전투의 결과는 남은 병사로 결정한다.

공격하는 쪽의 병사가 남았다면, 공격 성공으로 1을 반환하고,

방어하는 쪽의 병사가 남았거나, 모든 병사가 사망한 경우 0을 반환한다.

공격을 지휘한 장수는 병사 수에 포함하지 않는다.

 

공격이 성공하면 군주 mMonarchB 는 처형되고,

mMonarchB 가 다스렸던 영토는 멸망하여 동맹관계도 적대관계도 없는 새로운 영토가 된다.

새로운 영토의 군주는 mGeneral 이 되고, mMonarchA의 동맹에 편입되며, 적대 관계는 mMonarchA 의 적대 관계와 동일하다.

 

각 군주 이름은 알파벳 소문자로 이루어져 있으며, 길이는 4 이상 10 이하의 문자열이다.

mMonarchA 와 mMonarchB 는 현재 군주임이 보장된다. mGeneral 는 군주가 아님이 보장된다.

 

__Parameters

_____mMonarchA : 공격하는 군주의 이름 (4 ≤ 길이 ≤ 10)

_____mMonarchB : 공격을 받는 영토의 군주의 이름 (4 ≤ 길이 ≤ 10)

_____mGeneral : 공격을 지휘하는 장수의 이름 (4 ≤ 길이 ≤ 10)

 

__Returns

_____공격의 결과 (공격이 승리하면 1, 방어에 성공하면 0, 이미 동맹관계이면 -1,

_____공격 영토 주변에 공격 하는 동맹이 없는 경우 -2)

int recruit(char mMonarch[], int mNum, int mOption)

병사를 모집한다.

mOption 이 0 일 때,

-………. 군주 mMonarch 의 영토에 mNum 명의 병사를 모집한다.

-………. 병사 모집 이후에 군주 mMonarch 영토의 병사의 수를 반환한다.

mOption 이 1 일 때,

-………. 군주 mMonarch 를 포함한 모든 동맹의 영토에 각각 mNum 명의 병사를 모집한다.

-………. 병사 모집 이후에 군주 mMonarch 동맹의 모든 병사의 수 합산하여 반환한다.

 

군주 이름은 알파벳 소문자로 이루어져 있으며, 길이는 4 이상 10 이하의 문자열이다.

mMonarch 는 현재 군주임이 보장된다

 

__Parameters

_____ mMonarch : 군주의 이름 (4 ≤ 길이 ≤ 10)   

_____ mNum : 병사의 수 (1 ≤ mNum ≤ 200)

_____ mOption : 병사를 모집하는 조건

 

__Returns

_____병사의 수

 

[예제]

아래와 같이 함수 호출이 되는 경우를 살펴 보자.

#

Function

Description

return

1

init(4,
{{12, 5, 12, 9}, ….},
{{chengpu,sunce,……….})

전체 영토는 4 x 4이다.
각 영토의 병사의 수와 군주의 이름이 입력으로 주어진다.
각 군주의 동맹관계나 적대관계는 없다.

 

2

ally(chengpu, lingtong)

군주 chengpu 와 군주 lingtong 이 동맹을 맺는다.

1

3

ally(machao, lingtong)

 

1

4

recruit(machao, 3, 0)

군주 machao 의 영토에 병사 3명을 모집한다.

9

5

recruit(chengpu, 6, 1)

군주 chengpu 의 모든 동맹(chengpu, lingtong, machao)의
영토에 병사 6명씩 모집한다.
chengpu 18명, lingtong 20명, machao 15명, 총 53명이다.

53

6

ally(guanyu, xuhuang)

 

1

7

attack(chengpu, machao, ganada)

군주 chengpu 가 군주 machao 를 공격한다.
두 군주는 동맹관계이므로 실제 전투를 일어나지 않는다.

-1

8

attack(chengpu, xuhuang, gaboja)

군주 chengpu 가 군주 xuhuang 를 공격한다.
군주 xuhuang의 주변에 군주 chengpu 의 동맹이 없으므로, 실제 전투는 일어나지 않는다.

-2

9

attack(chengpu, guanyu, chacha)

군주 chengpu 가 군주 guanyu 를 공격한다.
군주 guanyu 의 주변에 군주 chengpu 의 동맹 machao 와 lingtong 이 있으므로, 전투가 일어난다.
전투가 발생하므로, chengpu 의 동맹과 guanyu 동맹은 서로 적대관계가 된다.
공격의 병사수는 machao, lingtong 에서 각각 7명, 10명을 보내어 총 17명이다.
방어의 병사수는 guanyu 의 15명에 xuhuang 이 5명을 보내어 총 20명이다. 
방어의 병사수가 많으므로 공격은 실패이다.

0

10

recruit(xuhuang, 10, 1)

 

28

11

attack(guanyu, lukang, igija)

군주 guanyu 가 군주 lukang 을 공격한다.
공격의 병사수가 많으므로, 공격 선봉 장수인 igija 가 새로운 군주가 된다.

1

12

ally(igija, chengpu)

군주 igija 와 군주 chengpu 는 적대 관계이다.

-2

13

ally(weiyan, huangzhong)

 

1

14

ally(liuzhang, xiahouyuan)

 

1

15

recruit(igija, 10, 0)

 

12

16

attack(huangzhong, igija, jjukkumi)

 

0

17

ally(caozhi, caopi)

 

1

18

ally(caoren, caozhi)

 

1

19

ally(sunce, xuhuang)

 

1

20

attack(caozhi, huanggai, holro)

 

0

21

ally(yuanshu, huanggai)

 

1

22

ally(caopi, yuanshu)

 

-2

23

ally(xiahouyuan, yuanshu)

 

1

24

recruit(guanyu, 10, 1)

 

69

25

recruit(weiyan, 20, 0)

 

25

26

recruit(xiahouyuan, 7, 1)

 

61

27

ally(liuzhang, huanggai)

군주 liuzhang과 huanggai는 이미 동맹 관계이다.

-1

28

attack(huanggai, machao, biribiri)

 

1

29

ally(biribiri, chengpu)

 

-2

30

ally(caozhi, chengpu)

 

1

31

recruit(lingtong, 20, 1)

 

144

32

recruit(biribiri, 22, 0)

 

34

33

recruit(xiahouyuan, 24, 0)

 

34

34

attack(yuanshu, guanyu, nononono)

군주 yuanshu가 군주 guanyu 를 공격한다.
공격의 병사수와 방어의 병사수가 같아 남은 병사가 0이므로, 공격에 실패한다.

0

35

attack(sunce, caopi, noway)

군주 sunce 가 군주 caopi 를 공격한다.
공격하는 병사가 0명이지만, 전투는 발생하고, 공격에 실패한다.

0

 

아래 설명에서 ‘->’는 적대 관계를 나타낸다.

[#1]

chengpu

sunce

huanggai

caozhi

12

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

14

11

yuanshu

machao

guanyu

caoren

9

6

15

10

weiyan

huangzhong

lukang

xuhuang

5

7

11

10

 

[#3]

ally(machao, lingtong) : return 1

 

chengpu

sunce

huanggai

caozhi

12

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

14

11

yuanshu

machao

guanyu

caoren

9

6

15

10

weiyan

huangzhong

lukang

xuhuang

5

7

11

10

 

[#4]

recruit(machao, 3, 0) : return 9

 

chengpu

sunce

huanggai

caozhi

12

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

14

11

yuanshu

machao

guanyu

caoren

9

9

15

10

weiyan

huangzhong

lukang

xuhuang

5

7

11

10

 

[#5]

recruit(chengpu, 6, 1) : return 53

 

chengpu

sunce

huanggai

caozhi

18

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

20

11

yuanshu

machao

guanyu

caoren

9

15

15

10

weiyan

huangzhong

lukang

xuhuang

5

7

11

10

 

[#6]

ally(guanyu, xuhuang) : return 1

 

chengpu

sunce

huanggai

caozhi

18

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

20

11

yuanshu

machao

guanyu

caoren

9

15

15

10

weiyan

huangzhong

lukang

xuhuang

5

7

11

10

 

[#9]

attack(chengpu, guanyu, chacha) : return 0

 

chengpu

sunce

huanggai

caozhi

18

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

10

11

yuanshu

machao

guanyu

caoren

9

8

3

10

weiyan

huangzhong

lukang

xuhuang

5

7

11

5

{machao chengpu lingtong} -> {guanyu xuhuang}

{guanyu xuhuang} -> {machao chengpu lingtong}

 

[#10]

recruit(xuhuang, 10, 1) : return 28

chengpu

sunce

huanggai

caozhi

18

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

10

11

yuanshu

machao

guanyu

caoren

9

8

13

10

weiyan

huangzhong

lukang

xuhuang

5

7

11

15

 

[#11]

attack(guanyu, lukang, igija) : return 1

chengpu

sunce

huanggai

caozhi

18

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

10

11

yuanshu

machao

guanyu

caoren

9

8

7

10

weiyan

huangzhong

igija

xuhuang

5

7

2

8

 

[#14]                            

ally(liuzhang, xiahouyuan) : return 1

chengpu

sunce

huanggai

caozhi

18

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

10

11

yuanshu

machao

guanyu

caoren

9

8

7

10

weiyan

huangzhong

igija

xuhuang

5

7

2

8

 

[#16]

attack(huangzhong, igija, jjukkumi) : return 0

chengpu

sunce

huanggai

caozhi

18

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

10

11

yuanshu

machao

guanyu

caoren

9

8

4

10

weiyan

huangzhong

igija

xuhuang

5

4

16

4

{machao chengpu lingtong} -> {guanyu xuhuang igija}

{guanyu xuhuang igija} -> {machao chengpu lingtong} {weiyan huangzhong}

{weiyan huangzhong} -> {guanyu xuhuang igija}

 

[#19]

ally(sunce, xuhuang) ) : return 1

 

chengpu

sunce

huanggai

caozhi

18

5

12

9

liuzhang

xiahouyuan

lingtong

caopi

9

12

10

11

yuanshu

machao

guanyu

caoren

9

8

4

10

weiyan

huangzhong

igija

xuhuang

5

4

16

4

{sunce guanyu xuhuang igija} -> {machao chengpu lingtong} {weiyan huangzhong}

{machao chengpu lingtong} -> {sunce guanyu xuhuang igija}

{weiyan huangzhong} -> {sunce guanyu xuhuang igija}

 

[#20]

attack(caozhi, huanggai, holro) : return 0

chengpu

sunce

huanggai

caozhi

18

5

3

5

liuzhang

xiahouyuan

lingtong

caopi

9

12

10

6

yuanshu

machao

guanyu

caoren

9

8

4

10

weiyan

huangzhong

igija

xuhuang

5

4

16

4

{sunce guanyu xuhuang igija} -> {machao chengpu lingtong weiyan huangzhong}

{huanggai} -> {caoren caozhi caopi}

{machao chengpu lingtong} -> {sunce guanyu xuhuang igija}

{caoren caozhi caopi} -> {huanggai}

{weiyan huangzhong} -> {sunce guanyu xuhuang igija}

 

[#22]

ally(caopi, yuanshu) : return -2

 

chengpu

sunce

huanggai

caozhi

18

5

3

5

liuzhang

xiahouyuan

lingtong

caopi

9

12

10

6

yuanshu

machao

guanyu

caoren

9

8

4

10

weiyan

huangzhong

igija

xuhuang

5

4

16

4

 

[#23]

ally(xiahouyuan, yuanshu) : return 1

chengpu

sunce

huanggai

caozhi

18

5

3

5

liuzhang

xiahouyuan

lingtong

caopi

9

12

10

6

yuanshu

machao

guanyu

caoren

9

8

4

10

weiyan

huangzhong

igija

xuhuang

5

4

16

4

{sunce guanyu xuhuang igija} -> {machao chengpu lingtong} {weiyan huangzhong}

{liuzhang xiahouyuan yuanshu huanggai} -> {caoren caozhi caopi}

{machao chengpu lingtong} -> {sunce guanyu xuhuang igija}

{caoren caozhi caopi} -> {liuzhang xiahouyuan yuanshu huanggai}

{weiyan huangzhong} -> {sunce guanyu xuhuang igija}

 

[#26]

recruit(xiahouyuan, 7, 1) : return 61

chengpu

sunce

huanggai

caozhi

18

15

10

5

liuzhang

xiahouyuan

lingtong

caopi

16

19

10

6

yuanshu

machao

guanyu

caoren

16

8

14

10

weiyan

huangzhong

igija

xuhuang

25

4

26

14

 

[#28]

attack(huanggai, machao, biribiri) : return 1

chengpu

sunce

huanggai

caozhi

18

15

10

5

liuzhang

xiahouyuan

lingtong

caopi

8

10

5

6

yuanshu

biribiri

guanyu

caoren

8

12

14

10

weiyan

huangzhong

igija

xuhuang

25

4

26

14

{sunce guanyu xuhuang igija} -> {chengpu lingtong} {weiyan huangzhong}

{liuzhang xiahouyuan yuanshu huanggai biribiri} -> {caoren caozhi caopi} {chengpu lingtong}

{caoren caozhi caopi} -> {liuzhang xiahouyuan yuanshu huanggai biribiri}

{weiyan huangzhong} -> {sunce guanyu xuhuang igija}

{chengpu lingtong} -> {liuzhang xiahouyuan yuanshu huanggai biribiri} {sunce guanyu xuhuang igija}

 

[#30]

ally(caozhi, chengpu) : return 1

chengpu

sunce

huanggai

caozhi

18

15

10

5

liuzhang

xiahouyuan

lingtong

caopi

8

10

5

6

yuanshu

biribiri

guanyu

caoren

8

12

14

10

weiyan

huangzhong

igija

xuhuang

25

4

26

14

{sunce guanyu xuhuang igija} -> {caoren caozhi caopi chengpu lingtong} {weiyan huangzhong}

{liuzhang xiahouyuan yuanshu huanggai biribiri} -> {caoren caozhi caopi chengpu lingtong}

{caoren caozhi caopi chengpu lingtong} -> {liuzhang xiahouyuan yuanshu huanggai biribiri} {sunce guanyu xuhuang igija}

{weiyan huangzhong} -> {sunce guanyu xuhuang igija}

 

[#33]

recruit(xiahouyuan, 24, 0) : return 34

chengpu

sunce

huanggai

caozhi

38

15

10

25

liuzhang

xiahouyuan

lingtong

caopi

8

34

25

26

yuanshu

biribiri

guanyu

caoren

8

34

14

30

weiyan

huangzhong

igija

xuhuang

25

4

26

14

 

[#34]

attack(yuanshu, guanyu, nononono) : return 0

chengpu

sunce

huanggai

caozhi

38

15

10

25

liuzhang

xiahouyuan

lingtong

caopi

8

17

25

26

yuanshu

biribiri

guanyu

caoren

8

17

0

30

weiyan

huangzhong

igija

xuhuang

25

4

13

7

{sunce guanyu xuhuang igija} -> {caoren caozhi caopi chengpu lingtong} {weiyan huangzhong} {liuzhang xiahouyuan yuanshu huanggai biribiri}

{liuzhang xiahouyuan yuanshu huanggai biribiri} -> {caoren caozhi caopi chengpu lingtong} {sunce guanyu xuhuang igija}

{caoren caozhi caopi chengpu lingtong} -> {liuzhang xiahouyuan yuanshu huanggai biribiri} {sunce guanyu xuhuang igija}

{weiyan huangzhong} -> {sunce guanyu xuhuang igija}

 

[#35]

attack(sunce, caopi, noway) : return 0

chengpu

sunce

huanggai

caozhi

38

15

10

13

liuzhang

xiahouyuan

lingtong

caopi

8

17

13

65

yuanshu

biribiri

guanyu

caoren

8

17

0

15

weiyan

huangzhong

igija

xuhuang

25

4

13

7

 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가, 종료 시 destroy() 함수가 호출된다.

2. 각 테스트 케이스에서 ally() 함수는 최대 8,000회 호출된다.

3. 각 테스트 케이스에서 attack() 함수는 최대 8,000회 호출된다.

4. 각 테스트 케이스에서 recruit() 함수는 최대 13,000회 호출된다.

5. 각 API에 전달되는 모든 문자열은 소문자이며, ‘\0’ (NULL 문자) 로 끝난다.

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

Sample input 에 대한 정답 출력 결과는 “#TC번호 결과” 의 포맷으로 보여지며 결과가 100 일 경우 정답, 0 일 경우 오답을 의미한다.
*/
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;


typedef struct s_location
{
	int	x;
	int	y;

	bool	operator==(const struct s_location &other) {
		return (other.x == x && other.y == y);
	}
	bool	operator!=(const struct s_location &other) {
	return (other.x != x || other.y != y);
	}
}	t_location;

typedef struct s_team
{
	struct s_team					*higher;
	list<t_location>				ally_list;
	unordered_set<struct s_team *>	enemy_list;
}	t_team;

int			(*sol_table)[25];
char		(*mon_table)[25][11];
t_team		*team_table[25][25];

t_team		team_pool[625];
int			team_pool_cnt;

int			map_size;

unordered_map<string, t_location>	name_table;

void init(int N, int mSoldier[25][25], char mMonarch[25][25][11])
{
	for (int i = 0; i < team_pool_cnt; ++i) {
		team_pool[i].higher = NULL;	
		team_pool[i].ally_list.clear();
		team_pool[i].enemy_list.clear();
	}
	team_pool_cnt = 0;
	sol_table = mSoldier;
	mon_table = mMonarch;

	map_size = N;
	for (int i = 0; i < map_size; ++i) {
		for (int j = 0; j < map_size; ++j) {
			team_table[i][j] = &team_pool[team_pool_cnt++];
			team_table[i][j]->ally_list.push_back((t_location){j, i});
		}
	}
	name_table.clear();
	for (int i = 0; i < map_size; ++i) {
		for (int j = 0; j < map_size; ++j) {
			name_table[(string)mon_table[i][j]] = (t_location){j, i};
		}
	}
}

t_team	*find_team(t_location cur_loc)
{
	t_team	*cur_team;

	cur_team = team_table[cur_loc.y][cur_loc.x];
	if (cur_team->higher != NULL) {
		while (cur_team->higher != NULL)
			cur_team = cur_team->higher;
		team_table[cur_loc.y][cur_loc.x] = cur_team;
	}
	return (team_table[cur_loc.y][cur_loc.x]);
}

int ally(char mMonarchA[11], char mMonarchB[11])
{
	t_location	loc_a, loc_b, loc_low;
	t_team		*team_a, *team_b, *team_high, *team_low;

	loc_a = name_table[(string)mMonarchA];
	loc_b = name_table[(string)mMonarchB];
	team_a = find_team(loc_a);
	team_b = find_team(loc_b);

	if (team_a == team_b)
		return (-1);
	if (team_a->enemy_list.find(team_b) != team_b->enemy_list.end())
		return (-2);
	if (team_a->enemy_list.size() > team_b->enemy_list.size()) {
		team_high = team_a;
		team_low = team_b;
		loc_low = loc_b;
	}
	else {
		team_high = team_b;
		team_low = team_a;
		loc_low = loc_a;
	}
	auto iter = team_low->enemy_list.begin(); 
	while (iter != team_low->enemy_list.end()) {
		team_high->enemy_list.insert(*iter);
		(*iter)->enemy_list.insert(team_high);
		(*iter)->enemy_list.erase(team_low);
		iter = team_low->enemy_list.erase(iter);
	}
	team_high->ally_list.splice(team_high->ally_list.end(), team_low->ally_list);
	team_low->higher = team_high;
	team_table[loc_low.y][loc_low.x] = team_high;
	return (1);
}

int	check_ally(int x, int y, t_team *cur_team)
{
	t_team *temp_team;

	if (x < 0 || y < 0 || x >= map_size || y >= map_size)
		return (0);
	temp_team = find_team((t_location){x, y});
	if (temp_team == cur_team)
		return (1);
	else
		return (0);
}

int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11])
{
	t_location	loc_a, loc_b;
	t_team		*team_a, *team_b;
	int			a_sol, b_sol, ally_cnt;

	loc_a = name_table[(string)mMonarchA];
	loc_b = name_table[(string)mMonarchB];
	team_a = find_team(loc_a);
	team_b = find_team(loc_b);

	if (team_a == team_b)
		return (-1);
	ally_cnt = 0;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == 0 && j == 0)
				continue ;
			ally_cnt += check_ally(loc_b.x + j, loc_b.y + i, team_a);
		}
	}
	if (ally_cnt == 0)
		return (-2);

	team_a->enemy_list.insert(team_b);
	team_b->enemy_list.insert(team_a);

	a_sol = 0;
	b_sol = sol_table[loc_b.y][loc_b.x];
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == 0 && j == 0)
				continue ;
			if (check_ally(loc_b.x + j, loc_b.y + i, team_a) == 1) {
				a_sol += sol_table[loc_b.y + i][loc_b.x + j] / 2;
				sol_table[loc_b.y + i][loc_b.x + j] -= sol_table[loc_b.y + i][loc_b.x + j] / 2;
			}
			else if (check_ally(loc_b.x + j, loc_b.y + i, team_b) == 1) {
				b_sol += sol_table[loc_b.y + i][loc_b.x + j] / 2;
				sol_table[loc_b.y + i][loc_b.x + j] -= sol_table[loc_b.y + i][loc_b.x + j] / 2;
			}
		}
	}

	sol_table[loc_b.y][loc_b.x] = abs(a_sol - b_sol);
	if (a_sol > b_sol) {
		name_table.erase((string)mon_table[loc_b.y][loc_b.x]);
		strcpy(mon_table[loc_b.y][loc_b.x], mGeneral);
		name_table[(string)mon_table[loc_b.y][loc_b.x]] = loc_b;
		team_table[loc_b.y][loc_b.x] = team_a;
		// auto iter = team_a->ally_list.begin();
		// while (iter != team_a->ally_list.end()) {
		// 	if (*iter == loc_b) {
		// 		printf("\n\n********************\n\n");
		// 		sleep(100);
		// 	}
		// 	++iter;
		// }
		team_a->ally_list.push_back(loc_b);
		auto iter = team_b->ally_list.begin();
		while (iter != team_b->ally_list.end()) {
			if (*iter == loc_b) {
		// 		printf("attack_success %s %s %s,  x : %d, y : %d, cur_name : %s\n\n", \
		// mMonarchA, mMonarchB, mGeneral, (*iter).x, (*iter).y, mon_table[(*iter).y][(*iter).x]);	
		// 	sleep(1);
				iter = team_b->ally_list.erase(iter);
				break ;
			}
			else
				++iter;
		}
		return (1);
	}
	else
		return (0);
}

int recruit(char mMonarch[11], int mNum, int mOption)
{
	int			res;
	t_location	loc;
	t_team		*cur_team, *temp_team;

	loc = name_table[(string)mMonarch];
	if (mOption == 0) {
		sol_table[loc.y][loc.x] += mNum;
		return (sol_table[loc.y][loc.x]);
	}
	else if (mOption == 1) {
		res = 0;
		cur_team = find_team(loc);
		auto	iter = cur_team->ally_list.begin();
		while (iter != cur_team->ally_list.end()) {
			// printf("recruit %s %d %d,  x : %d, y : %d, name : %s\n", \
							mMonarch, mNum, mOption, (*iter).x, (*iter).y, mon_table[(*iter).y][(*iter).x]);
			temp_team = find_team(*iter);
			if (temp_team != cur_team) {
				iter = cur_team->ally_list.erase(iter);
			}
			else {
				// printf("x : %d, y : %d,  before_sol : %d", (*iter).x, (*iter).y, sol_table[(*iter).y][(*iter).x]);
			
				sol_table[(*iter).y][(*iter).x] += mNum;
				res += sol_table[(*iter).y][(*iter).x];
				
				// printf(" after_sol : %d, res : %d\n", sol_table[(*iter).y][(*iter).x], res);
			
				++iter;
			}
		}
		return (res);
	}
	else
		return (-1);
}

void destroy()
{

}

// void	change_cap(t_location &cap)
// {
// 	int	cap_one, new_cap_one;
// 	t_location	cur_cap, new_cap, enemy;

// 	auto iter = cap_table[cap.y][cap.x].sub_list.begin();
// 	while (iter != cap_table[cap.y][cap.x].sub_list.end()) {
// 		cur_cap = find_cap(*iter);
// 		if (cur_cap == cap) {
// 			new_cap = cur_cap;
// 			break ;
// 		}
// 		else
// 			iter = cap_table[cap.y][cap.x].sub_list.erase(iter);
// 	}	//부하들로 등록되었던 놈들 중에 여전히 자기를 섬기는 애를 한 명이라도 찾는다. 자기 섬기는 게 아니면 삭제. 중간에 끊길수도
// 	if (iter != cap_table[cap.y][cap.x].sub_list.end()) {	//여기서 검사 후에
// 		cap_table[cap.y][cap.x].sub_list.erase(iter);	//새로운 대장은 리스트에서 삭제.
// 		cap_table[cap.y][cap.x].loc = new_cap;
// 		iter = cap_table[cap.y][cap.x].sub_list.begin();
// 		while (iter != cap_table[cap.y][cap.x].sub_list.end()) {
// 			cur_cap = find_cap(*iter);
// 			if (cur_cap != new_cap)
// 				iter = cap_table[cap.y][cap.x].sub_list.erase(iter);
// 			else
// 				++iter;
// 		}	//서브 리스트 모두 업데이트 후 정리
// 		cap_table[new_cap.y][new_cap.x].loc = new_cap;
// 		cap_table[new_cap.y][new_cap.x].sub_list.splice(cap_table[new_cap.y][new_cap.x].sub_list.end(),\
// 														 cap_table[cap.y][cap.x].sub_list);

// 		cap_one = convert_one(cap);
// 		new_cap_one = convert_one(new_cap);
// 		auto	enemy_iter = cap_table[cap.y][cap.x].enemy_table.begin();
// 		while (enemy_iter != cap_table[cap.y][cap.x].enemy_table.end()) {
// 			enemy = convert_two(*enemy_iter);
// 			cap_table[enemy.y][enemy.x].enemy_table.erase(cap_one);
// 			cap_table[enemy.y][enemy.x].enemy_table.insert(new_cap_one);
// 			++enemy_iter;
// 		}
// 		cap_table[new_cap.y][new_cap.x].enemy_table = cap_table[cap.y][cap.x].enemy_table;
// 	}
// 	else {
// 		cap_table[cap.y][cap.x].sub_list.clear();
// 		cap_one = convert_one(cap);
// 		auto	enemy_iter = cap_table[cap.y][cap.x].enemy_table.begin();
// 		while (enemy_iter != cap_table[cap.y][cap.x].enemy_table.end()) {
// 			enemy = convert_two(*enemy_iter);
// 			cap_table[enemy.y][enemy.x].enemy_table.erase(cap_one);
// 			++enemy_iter;
// 		}
// 		cap_table[cap.y][cap.x].enemy_table.clear();
// 	}
	
// }