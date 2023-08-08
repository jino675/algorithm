/*
No. 41 3차원 농부
참여자 51 제출 211 배점 100
Problem제출이력정답
시간 : 29개 테스트케이스를 합쳐서 C/C++의 경우 8초 / Java의 경우 20초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.
 

일반적으로 가축들은 평지에서 기르기 마련이지만, 농부 지민이의 가축들은 3차원 좌표공간에서 길러진다.

 

지민이는 N마리의 소와 M마리의 말들을 키우고 있다.

 

각 가축들은 3차원 좌표 평면 상의 점으로 표현되는데, 특이하게도 지민이의 모든 소는 x=c1, y=0 직선 상에 존재하고, 지민이의 모든 말들은 x=c2, y=0 직선 상에 존재한다.

 

최근 삼성대학교의 연구 결과에 의하면, 두 소와 말이 가까이 있을 경우 엄청난 이산화탄소가 발생한다고 한다.

 

두 동물간의 거리는 맨하탄 거리로, P=(x1, y1, z1)와 Q=(x2, y2, z2) 간의 거리는 dist (P, Q) = |x2-x1 |+|y2-y1 |+|z2-z1 | 로 정의된다.

 

농부 지민이는 이 소식을 듣고, 농장을 분석하려고 한다.

 

지민이는 모든 소와 말 쌍에 대해서, 가장 가까운 쌍의 거리와, 이러한 최소 거리를 가지는 쌍의 개수를 알고 싶어한다.

 

지민이를 도와주자.

 


[입력]

 

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

 

각 테스트 케이스의 첫 번째 줄에는 소의 수 N, 말의 수 M이 주어진다. (1 ≤ N, M ≤ 500000)

 

그리고 각 테스트 케이스의 두 번째 줄에는 c1, c2가 주어진다. ( -108 ≤ c1, c2 ≤ 108)

 

세 번째 줄에는 N개의 정수로 소들의 위치가 주어진다.

 

입력은 z1, z2, z3, …, zN  의 형태이며, i번째 소는 (c1,0,zi) 에 위치함을 뜻한다. ( -108 ≤ zi ≤ 108)

 

네 번째 줄에는 M개의 정수로 말들의 위치가 주어진다.

 

입력은 z1, z2, z3, …, zM 의 형태이며, j번째 말은 (c2,0,zj) 에 위치함을 뜻한다. ( -108 ≤ zj ≤ 108)

 

각 테스트 케이스에 대해서, 소들의 위치와 말들의 위치는 서로 다르지만, 소와 말이 같은 위치에 있을 수는 있다.

 

 

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

가장 가까운 소 쌍의 거리와, 그러한 거리를 가지는 소 쌍들의 개수를 공백으로 구분하여 출력하라.

 
입력
2
3 4
1 -3
3 0 6
-2 5 4 2
5 5
1 2
-4 -10 -2 0 -1
3 18 0 1 5	
// 테스트 케이스의 개수

// 첫 번째 테스트 케이스의 N, M

// 첫 번째 테스트 케이스의 c1, c2

// N개의 정수, 소들의 위치

// M개의 정수, 말들의 위치

// 두 번째 테스트 케이스의 N, M


 

sample_input.txt
출력
#1 5 3
#2 1 1	
// 첫 번째 테스트 케이스의 결과

// 두 번째 테스트 케이스의 결과
*/
#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int>	cow;
vector<int>	horse;

int	N;
int	M;
int	c1, c2;

int	min_distance;
int	min_count;

void	find_min(vector<int> &v1, int idx, vector<int> &v2)
{
	int	left, mid, right;
	int	cur_distance;

	left = 0;
	right = v2.size() - 1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		cur_distance = abs(v2[mid] - v1[idx]);
		if (cur_distance < min_distance) {
			min_distance = cur_distance;
			min_count = 1;
		}
		else if (cur_distance == min_distance) {
			++min_count;
		}
		if (v2[mid] > v1[idx]) {
			right = mid - 1;
		}
		else if (v2[mid] <= v1[idx]) {
			left = mid + 1;
		}
	}
}

void	run(vector<int> &v1, vector<int> &v2)
{
	min_distance = INT_MAX;
	min_count = 0;
	for (int i = 0; i < v1.size(); ++i) {
		find_min(v1, i, v2);
	}
	min_distance += abs(c1 - c2);
	v1.clear();
	v2.clear();
}


int	main(void)
{
	int	tc;
	int	input;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N >> M >> c1 >> c2;
		for (int j = 0; j < N; ++j) {
			cin >> input;
			cow.push_back(input);
		}
		for (int j = 0; j < M; ++j) {
			cin >> input;
			horse.push_back(input);
		}
		if (cow.size() < horse.size()) {
			sort(horse.begin(), horse.end());
			run(cow, horse);
		}
		else if (cow.size() >= horse.size()) {
			sort(cow.begin(), cow.end());
			run(horse, cow);
		}
		cout << "#" << i << " " << min_distance << " " << min_count << "\n";
	}
}