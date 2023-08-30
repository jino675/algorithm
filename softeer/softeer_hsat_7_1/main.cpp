/*
자동차 테스트
난이도
    
참가자 수
98
제출 수
155
정답률
49.68%
지원 언어
    
언어별 시간/메모리
언어	시간	메모리
C	2초	1024MB
C++	2초	1024MB
Java	3초	1024MB
Python	2초	1024MB
Javascript	2초	1024MB
문제
자동차 제조 과정에서는 다양한 테스트를 통해 해당 자동차가 잘 만들어졌는지를 평가합니다.

이러한 평가 지표 중 하나는 자동차의 연비입니다.

자동차의 연비가 높을수록 연료 소비가 적고, 더 많은 거리를 주행할 수 있으므로 이는 자동차가 잘 만들어졌는지의 지표로 사용될 수 있습니다.

만약 3대의 자동차를 테스트하고, 각각의 연비를 측정한다고 가정해봅시다.

첫 번째 자동차의 연비는 9km/L,

두 번째 자동차의 연비는 15km/L,

세 번째 자동차의 연비는 20km/L이라고 합시다.

이 경우, 중앙값은 15km/L이 됩니다.



따라서 이 데이터에서는 중앙값을 이용하여 자동차의 평균적인 연비를 파악할 수 있으며,

이는 자동차 제조 과정에서 테스트의 결과를 평가하는 데 활용될 수 있습니다.

n대의 자동차를 새로 만들었지만 여건상 3대의 자동차에 대해서만 테스트가 가능한 상황입니다.

n대의 자동차의 실제 연비 값이 주어졌을 때, q개의 질의에 대해 임의로 3대의 자동차를 골라 테스트하여 중앙값이 mi값이 나오는 서로 다른 경우의 수를 구하는 프로그램을 작성해보세요.

제약조건
* 1 ≤ n ≤ 50,000
* 1 ≤ q ≤ 200,000
* 1 ≤ 자동차의 연비 ≤ 1,000,000,000
* 1 ≤ mi ≤ 1,000,000,000 (i는 1 이상 q 이하입니다. 즉, mi 는 각 질의에 대응하는 중앙값을 의미합니다.)

입력형식
첫 번째 줄에 n, q가 공백을 사이에 두고 주어집니다.


두 번째 줄에는 n개의 자동차의 연비에 해당하는 값이 공백을 사이에 두고 주어집니다.

주어지는 자동차의 연비는 서로 다름을 가정해도 좋습니다.

세 번째 줄부터는 q개의 줄에 걸쳐 테스트 결과로 기대하는 값인 mi가 한 줄에 하나씩 주어집니다.

출력형식
q개의 줄에 걸쳐 3대의 자동차를 골랐을 때 연비의 중앙값이 mi가 나오는 서로 다른 가짓수를 한 줄에 하나씩 출력합니다.

입력예제1
5 3
5 2 3 1 6
1
3
6
출력예제1
0
4
0
입력예제2
6 8
7 4 3 2 6 1
1
2
3
4
5
6
7
1000000000
출력예제2
0
4
6
6
0
4
0
0
*/
#include<iostream>
#include <functional>

using namespace std;

int	n;
int	q;
int	mid_val;
int	res;

int	arr[50000];

int	find(int mid_val)
{
	int	front_cnt, back_cnt, left, right, mid;

	left = 0;
	right = n - 1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (arr[mid] <= mid_val) {
			if (arr[mid] == mid_val)
				break ;
			else
				left = mid + 1;
		}
		else
			right = mid - 1;
	}
	if (arr[mid] != mid_val)
		return (0);
	front_cnt = mid;
	back_cnt = n - mid - 1;
	return (front_cnt * back_cnt);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);	

	for (int i = 0; i < q; ++i) {
		cin >> mid_val;
		res = find(mid_val);
		cout << res << "\n";
	}
	return (0);
}