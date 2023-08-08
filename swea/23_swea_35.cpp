/*
No. 35 염라대왕의 이름 정렬
참여자 47 제출 120 배점 100
Problem제출이력정답
시간 : 50개 테스트케이스를 합쳐서 C/C++의 경우 5초 / Java의 경우 10초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

염라대왕은 이승의 사람들의 모든 이름을 가지고 있다.

어느날 저승에 일어난 진도 8.0 지진에 항상 정리되어 있던 이승 명부가 흐트러졌다.

이승 명부는 이름의 길이가 짧을수록 이 앞에 있었고, 같은 길이면 사전 순으로 앞에 있었다.

이왕 이렇게 된 김에 모든 이름을 다시 정리하고 같은 이름은 하나만 남겨놓기로 한 염라대왕을 도와주자.


[입력]

첫 번째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 50)가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 이승 명부의 이름 개수 N(1 ≤ N ≤ 20,000)이 주어진다.

각 테스트 케이스의 두 번째 줄부터 N개의 줄에 걸쳐서 알파벳 소문자로 이루어진 이름들이 주어진다.

이름에는 공백이 포함되지 않으며 최소 1개, 최대 50개의 알파벳으로 이루어져 있다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

정리된 이름을 한 줄에 하나씩 출력하라. 같은 이름은 한 번만 출력해야 하는 것을 주의하라.

입력
2
5
my
name
is
ho
seok
12
s
a
m
s
u
n
g
j
j
a
n
g	// 테스트 케이스 개수
// 첫 번째 테스트 케이스, N = 5

 

 

// 두 번째 테스트 케이스, N = 12











 
s_input.txt
출력
#1
ho
is
my
name
seok
#2
a
g
j
m
n
s
u	// 첫 번째 테스트 케이스 결과





// 두 번째 테스트 케이스 결과
 
*/
#include <iostream>
#include <cstring>

using namespace std;

char	input[20000][51];
char	*names[20000];
char	*temp[20000];

int	N;

int	my_compare(char *a, char *b)
{
	int	i, j;
	int	is_greater;

	is_greater = 0;
	i = 0;
	j = 0;
	while (a[i] != '\0' && b[j] != '\0') {
		if (a[i] > b[j]) {
			is_greater = 1;
			break ;
		}
		else if (a[i] < b[j]) {
			is_greater = -1;
			break ;
		}
		++i;
		++j;
	}
	while (a[i] != '\0' && b[j] != '\0') {
		++i;
		++j;
	}
	while (a[i] != '\0')
		++i;
	while (b[j] != '\0')
		++j;
	if (i < j)
		return (-1);
	else if (i > j)
		return (1);
	else
		return (is_greater);
}

void	my_merge(int start, int mid, int end)
{
	int i, j, k;
	
	i = start;
	j = mid + 1;
	k = start;
	// cout << "=====before=====\n";
	// for (int j = start; j <= end; ++j)
	// 	cout << names[j] << "\n";
	while (i <= mid && j <= end) {
		if (my_compare(names[i], names[j]) < 0)
			temp[k++] = names[i++];
		else
			temp[k++] = names[j++];
	}
	while (i <= mid)
		temp[k++] = names[i++];
	while (j <= end)
		temp[k++] = names[j++];
	for (k = start; k <= end; ++k)
		names[k] = temp[k];
	// cout << "=====after=====\n";
	// for (int j = start; j <= end; ++j)
	// 	cout << names[j] << "\n";
}

void	merge_sort(int start, int end)
{
	int	mid;

	if (start == end)
		return ;
	mid = (end + start) / 2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);
	my_merge(start, mid, end);
}

int	main(void)
{
	int		tc;
	char	*cur;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> input[j];
			names[j] = input[j];
		}
		merge_sort(0, N - 1);
		cout << "#" << i << "\n";
		cur = names[0];
		cout << names[0] << "\n";
		for (int j = 1; j < N; ++j) {
			if (strcmp(names[j], cur) != 0) {
				cout << names[j] << "\n";
				cur = names[j];
			}
		}
	}
	return (0);
}