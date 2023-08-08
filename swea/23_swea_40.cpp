/*
No. 40 광고 시간 정하기
참여자 47 제출 204 배점 100
Problem제출이력정답
시간 : 20개 테스트케이스를 합쳐서 C/C++의 경우 3초 / Java의 경우 5초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.
 

한나는 스페이스 스퀘어에 L분짜리 광고를 하나 올리려고 한다. 한나가 조사한 바에 따르면, 광고에 효과가 아주 좋은 N개의 피크 시간대가 있으며, i번째 피크 시간대는 si분부터 ei분 까지다.
한나는 최대한 피크 시간대와 길게 겹치도록 광고를 올리고 싶다.
한나는 적절히 t를 정해, t분부터 t+L분까지 지속되는 광고를 올릴 것이다.
이 때, 광고가 올라가 있는 시간과 피크 시간대가 가장 많이 겹치도록 했을 때, 그 겹치는 시간이 얼마나 되는지 구하는 프로그램을 작성하라.
 

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 하나의 정수 L (1 ≤ L ≤ 108 )이 주어진다.
두 번째 줄에는 하나의 정수 N(1≤N≤105)이 주어진다.
다음부터 N개의 줄의 i번째 줄에는 두 정수 si, ei (0 ≤ si < ei < 108)가 공백 하나로 구분되어 주어진다.
ei < si+1 (1 ≤ i < N)을 만족한다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
광고가 올라가 있는 시간과 피크 시간대가 가장 많이 겹치도록 했을 때, 그 겹치는 시간을 (분 단위로) 출력한다.
아래 테스트 케이스의 경우, 3분에 광고를 시작하게 하면, 8분까지 광고가 지속된다. 이 때, 3분에서 5분, 6분에서 8분까지 광고가 피크 시간대와 겹치고 최대 4분 겹치게 된다.)

입력
1
5
2
2 5
6 10     	
// 테스트 케이스 개수
// L = 5
// N = 2
// s1 = 2, e1 = 5
// s2 = 6, e2 = 10
 

2_input.txt
출력
#1 4            	// 첫 번째 테스트 케이스 결과
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct s_list
{
	int	s;
	int	e;
	int	time; //누적 시간
}	t_list;

t_list	list[100001];

int	L;
int	N;

int	res;

int	find_val(int start)
{
	int	left, right, mid;
	int	cur_time;
	int	pre_time;
	int	cur_val;

	left = start;
	right = N;
	while (left <= right) {
		mid = left + (right - left) / 2;
		cur_time = list[mid].e - list[mid].s;
		pre_time = list[mid].s - list[start].s;
		if (pre_time > L) {
			right = mid - 1;
		}
		else if (pre_time <= L) {
			if ((mid < N && L < list[mid + 1].s - list[start].s) || mid == N) {
				cur_val = list[mid].time - list[start].time;
				cur_val += min(cur_time, L - pre_time);
				return (cur_val);
			}
			else
				left = mid + 1;
		}
	}
	return (0);
}

void	run(void)
{
	int	max_val;
	int	cur_val;

	max_val = 0;
	for (int i = 1; i <= N; ++i) {
		cur_val = find_val(i);
		if (cur_val > max_val)
			max_val = cur_val;
	}
	res = max_val;
}

int	main(void)
{
	int	tc;
	int	total_time;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> L >> N;
		total_time = 0;
		for (int j = 1; j <= N; ++j) {
			cin >> list[j].s >> list[j].e;
			list[j].time = total_time;
			total_time += list[j].e - list[j].s;
		}
		run();
		cout << "#" << i << " " << res << "\n";
	}
}
