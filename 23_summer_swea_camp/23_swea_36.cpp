/*
No. 36 사탕 분배
참여자 53 제출 143 배점 100
Problem제출이력정답
시간 : 150개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

나연이는 A개의 사탕을, 다현이는 B개의 사탕을 갖고 있다. 두 사람은 아래와 같은 작업을 정확히 K번 반복하려고 한다.
- 둘 중 사탕의 개수가 더 적은 사람을 X, 더 많은 사람을 Y라고 하자. 단, 두 사람이 같은 개수의 사탕을 갖고 있다면 나연이가 X, 다현이가 Y이다.
- X가 P개의 사탕을, Y가 Q개의 사탕을 갖고 있을 때, Y는 X에게 자신의 사탕 P개를 준다. 결과적으로 X가 가진 사탕은 2P개, Y가 가진 사탕은 Q-P개가 된다.
  작업이 끝나고 난 후, 두 사람이 각각 가지고 있는 사탕의 개수를 A',B'라고 하자. min(A',B')의 값은 얼마일까?

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스는 하나의 줄로 이루어지며, 각 줄에는 세 개의 정수 A,B,K (1≤A,B≤109, 1≤K≤2⋅109)가 공백 하나를 사이로 두고 주어진다.

[출력]
각 테스트 케이스마다, K번의 반복 작업이 끝나고 난 후, 두 사람이 각각 가지고 있는 사탕의 개수를 A',B'라고 할 때, min(A',B' )의 값을 한 줄에 하나씩 출력한다.

입력
4
4 9 1
4 9 2
4 9 3
500 2000 2000000000	 
sample_input.txt
출력
#1 5
#2 3
#3 6
#4 500
*/
#include <iostream>
#include <functional>

using namespace std;

int	A;
int	B;
int	C;
int	K;

// int	find_min(void)
// {
// 	int	P, Q;
// 	int	temp_P, temp_Q;
// 	int	temp;
// 	int	cur_count;

// 	P = min(A, B);
// 	Q = max(A, B);
// 	while (K > 0) {
// 		// printf("cur_P : %d, cur_Q : %d, ", P, Q);
// 		cur_count = -1;
// 		temp = Q / P + 1;
// 		// printf("temp : %d, ", temp);
// 		while (temp > 0) {
// 			temp >>= 1;
// 			++cur_count;
// 		}
// 		if (K - cur_count < 0)
// 			cur_count = K;
// 		K -= cur_count;
// 		temp_Q = Q - ((1 << cur_count) - 1) * P;
// 		temp_P = (1 << cur_count) * P;
// 		Q = temp_P;
// 		P = temp_Q;
// 		// printf("cur_count : %d, now_P : %d, now_Q : %d\n", cur_count, Q, P);
// 	}
// 	return (min(P, Q));
// }


int	two_pow_mod(int k, int C)
{
	int	res;

	if (k == 0) {
		return (1);
	}
	res = two_pow_mod(k / 2, C);
	res = ((long long)res * (long long)res) % C;
	if ((k & 1) == 1)
		res = ((long long)res * 2) % C;
	return (res);
}

int	find_min(void)
{
	int	res;

	res = (two_pow_mod(K, C) * A) % C;
	return (min(res, C - res));
}


int	main(void)
{
	int	tc;
	int	res;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> A >> B >> K;
		C = A + B;
		res = find_min();
		cout << "#" << i << " " << res << "\n";
	}
	return (0);
}