/*
No. 23 힙
참여자 73 제출 169 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 1초 / Java의 경우 2초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

힙(Heap)은 최댓값 혹은 최솟값을 찾아내는 연산을 빠르게 하기 위해 고안된 자료구조이다.

완전이진트리(Complete binary tree)를 기본으로 한 자료구조로서 다음과 같은 힙 속성(property)을 만족한다.

- A가 B의 부모노드(parent node) 이면, A의 키(key)값과 B의 키값 사이에는 항상 일정한 대소관계가 성립한다.

키값의 대소관계는 오로지 부모노드와 자식노드 간에만 성립하며, 형제노드 사이에서는 일정한 대소관계가 정해지지 않는다.

부모노드의 키값이 자식노드의 키값보다 항상 크거나 같은 힙을 '최대 힙', 부모노드의 키값이 자식노드의 키값보다 항상 작거나 같은 힙을 '최소 힙'이라고 부른다.

다음 그림은 최대 힙의 예시이다.



힙의 루트노드(root node)는 힙을 구성하는 노드의 키값 중 최댓값 혹은 최솟값을 가지게 된다.

본 문제에서는 최대 힙(max heap)을 올바르게 구현하였는지 확인할 수 있다.

초기에 최대 힙이 비어있을 때에 다음의 2가지 연산을 수행하는 프로그램을 작성하자.

연산 1. 자연수 x를 삽입

연산 2. 최대 힙의 루트 노드의 키값을 출력하고, 해당 노드를 삭제

예를 들어, 쿼리가 순서대로 다음과 같이 5개가 주어졌다고 가정해보자.

1. 연산 1 - 3을 삽입

2. 연산 1 - 5를 삽입

3. 연산 2 - 최댓값 출력 후 해당 키값 삭제

4. 연산 1 - 1을 삽입

5. 연산 2 - 최댓값 출력 후 해당 키값 삭제

3번째 연산을 수행할 때를 기준으로 최대 키값은 5이기 때문에 5가 출력되고, 5는 삭제되기 때문에 최대 힙에는 3만 남게 된다.

5번째 연산을 수행할 때를 기준으로 최대 키값은 3이기 때문에 3이 출력되고, 3은 삭제되기 때문에 최대 힙에는 1만 남게 된다.

만약 가장 큰 키값이 여러 개일 경우에는, 삭제할 때에 그 키값을 가지는 노드들 전부가 삭제되는 것이 아니라, 루트 노드 단 하나만 삭제됨에 주의한다.


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스마다 첫째 줄에 수행해야하는 연산의 수를 나타내는 자연수 N(1≤N≤105)이 주어진다. 

둘째 줄부터 N개의 줄에 걸쳐서 순서대로 수행해야하는 연산에 대한 정보가 주어진다.

연산 1을 수행해야 한다면 2개의 자연수 '1 x'가 주어지며, x(1≤x≤109)를 최대 힙에 추가하는 연산임을 의미한다.

연산 2를 수행해야 한다면 1개의 자연수 '2'가 주어지며, 현재 최대 힙의 루트 노드의 키값을 출력하고 해당 노드를 삭제하는 연산임을 의미한다.


[출력]

각 테스트 케이스마다 첫째 줄에 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 연산 2의 결과들을 공백 하나를 사이에 두고 순서대로 출력한다.

만약, 연산 2를 수행해야 하는데 힙에 원소가 없어서 출력해야 할 최대 키값이 존재하지 않는다면 -1을 출력한다.


[힌트]

힙(Heap) 자료구조의 정의에 대한 설명은 본 사이트의 다음 부분에서 찾아보실 수 있습니다.

 'Learn' → 'Course' → 'Programming - Intermediate' → 'SW 문제해결 기본 - Tree' → '5차시 heap'

아래는 구현과 관련하여 도움이 될 수 있는 힌트입니다.

1. 힙은 완전이진트리이기 때문에 배열로 구현하면 상당히 편리합니다.

다음과 같이 힙의 노드들에 번호를 붙여 보겠습니다. 노드 아래에 '[ ]' 안에 있는 숫자가 각 노드의 번호입니다.

트리에서의 높이가 높을수록, 높이가 같다면 왼쪽에 위치할수록 번호가 작으며 1번부터 시작합니다.



2. 어떤 노드의 번호가 x일 때에 다음과 같은 성질을 만족합니다.

1. x의 부모 노드 번호 = (x를 2로 나눈 몫)

2. x의 왼쪽 자식 노드 번호 = (x 곱하기 2)

3. x의 오른쪽 자식 노드 번호 = (x 곱하기 2) + 1

3. 삭제 연산을 구현할 때에, 자식 노드 2개가 모두 존재한다면 둘 중 큰 키값을 가지는 노드와 현재 노드의 위치를 바꾸어주는 식으로 구현함에 주의합니다.

4. C++의 경우, Standard Template Library로 안에 priority_queue가 있으며 최대 힙과 같은 역할을 수행합니다.

Java의 경우, PriorityQueue를 이용하면 구현되어 있는 method들을 호출하여 사용할 수 있습니다.

5. 힙이 비어있는지 먼저 확인을 하고, 원소를 삭제하는 연산을 수행해야 합니다.

입력
2
3
1 1
2
2
5
1 3
1 5
2
1 1
2
 

sample_input.txt
출력
#1 1 -1
#2 5 3
*/
// #include <stdio.h>
#include <iostream>
// #include <queue>
// #include <functional>

using namespace std;

int	max_heap[100001];
// int	res[100001];

int	heap_size;
int	N;

void	my_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	push(int x)
{
	int	cur_idx;
	int	parent_idx;

	cur_idx = heap_size + 1;
	max_heap[cur_idx] = x;
	parent_idx = cur_idx / 2;
	while (1) {
		if (parent_idx < 1)
			break ;
		else {
			if (max_heap[parent_idx] < max_heap[cur_idx]) {
				my_swap(&max_heap[parent_idx], &max_heap[cur_idx]);
				cur_idx = parent_idx;
				parent_idx = cur_idx / 2;
			}
			else
				break ;
		}
	}
	++heap_size;
}

int	pop(void)
{
	int	temp;
	int	cur_idx;
	int	next_idx;
	int	child_idx_1;
	int	child_idx_2;

	if (heap_size == 0)
		return (-1);
	temp = max_heap[1];
	max_heap[1] = max_heap[heap_size];
	cur_idx = 1;
	child_idx_1 = cur_idx * 2;
	child_idx_2 = cur_idx * 2 + 1;
	while (1) {
		if (child_idx_2 <= heap_size) {
			if (max_heap[child_idx_1] > max_heap[child_idx_2])
				next_idx = child_idx_1;
			else
				next_idx = child_idx_2;
		}
		else if (child_idx_1 <= heap_size) {
			next_idx = child_idx_1;
		}
		else
			break ;
		if (max_heap[next_idx] > max_heap[cur_idx]) {
			my_swap(&max_heap[next_idx], &max_heap[cur_idx]);
			cur_idx = next_idx;
			child_idx_1 = cur_idx * 2;
			child_idx_2 = cur_idx * 2 + 1;
		}
		else
			break ;
	}
	--heap_size;
	return (temp);
}


int	main(void)
{
	int	tc;
	int	cmd;
	int	x;
	// int	res_idx;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// setbuf(stdout, NULL);
	// scanf(" %d", &tc);
	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		// priority_queue<int> pq;
		// printf("#%d ", i + 1);
		cout << "#" << i + 1 << " ";
		heap_size = 0;
		// res_idx = 0;
		// scanf(" %d", &N);
		cin >> N;
		for (int j = 0; j < N; ++j) {
			// scanf(" %d", &cmd);
			cin >> cmd;
			if (cmd == 1) {
				// scanf(" %d", &x);
				cin >> x;
				// pq.emplace(x);
				push(x);
			}
			else if (cmd == 2) {
				// if (pq.empty() == 1)
				// 	// res[res_idx++] = -1;
				// 	// printf("-1 ");
				// 	cout << "-1 ";
				// else {
				// 	// printf("%d ", pq.top());
				// 	cout << pq.top() << " ";
				// 	pq.pop();
				// }
				cout << pop() << " ";
			}
		}
		// for (int j = 0; j < res_idx; ++j) {
					// printf("%d ", res[j]);
		// }
		// printf("\n");
		cout << endl;
	}
}