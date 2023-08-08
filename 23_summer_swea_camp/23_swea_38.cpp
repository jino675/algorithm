/*
No. 38 촛불 이벤트
참여자 63 제출 172 배점 100
Problem제출이력정답
시간 : 100000개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.
 

당신은 프로포즈를 위해 촛불을 삼각형으로 배치하고 있다. 촛불을 K단 크기로 배치하면, 1단에는 K개의 양초, 2단에는 K-1개의 양초, …, K단에는 1개의 양초를 배치해서 총 (K(K+1))/2개의 양초가 필요하다.

당신이 사용할 양초의 개수 N이 주어질 때, 이 양초를 모두 사용하면 몇 단 크기의 촛불 삼각형을 만들 수 있는지 구하여라.

 

[입력]
첫 번째 줄에 테스트 케이스의 수 TC가 주어진다. 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다. 각 테스트 케이스는 다음과 같이 구성되었다.

첫 번째 줄에 양초 개수가 주어진다. (1≤N≤1018)

 


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

각 테스트 케이스 마다 주어진 양초 N개를 모두 사용하여 만들 수 있는 촛불 삼각형의 단수를 출력한다. 만약 삼각형을 만드는 것이 불가능하면 -1을 출력한다.

입력
5
1
3
6
14
762078456028	// 테스트 케이스 개수
// 첫 번째 케이스 양초의 개수 N = 1



 
sample_input.txt
출력
#1 1
#2 2
#3 3
#4 -1
#5 1234567	// 첫 번째 테스트 케이스 결과
*/
#include <iostream>
#include <cmath>
using namespace std;

long long	N;

int	main(void)
{
	int	tc;
	long long	k;
	long long	temp;	

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N;
		temp = (long long)sqrt(2 * N);
		if (temp * (temp + 1) == 2 * N)
			k = temp;
		else
			k = -1;
		// temp = (long long)sqrt(1 + 8 * N);
		// // printf("N = %lld, sqrt(1 + 8 * N) = %lld, pow(temp, 2) = %lld\n", N, temp, (long long)pow(temp, 2));
		// if ((long long)pow(temp, 2) == 1 + 8 * N) {
		// 	k = (temp - 1) / 2;
		// 	if (2 * k != temp - 1)
		// 		k = -1;
		// }
		// else
		// 	k = -1;
		cout << "#" << i << " " << k << "\n";
	}
	return (0);
}
