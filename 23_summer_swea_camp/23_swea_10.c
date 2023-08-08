/*
No. 10 [S/W 문제해결 기본] 9일차 - 사칙연산
참여자 33 제출 35 배점 100
Problem제출이력정답
시간 : 10개 테스트케이스를 합쳐서 C/C++의 경우 10초 / Java의 경우 20초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

사칙연산으로 구성되어 있는 식은 이진 트리로 표현할 수 있다. 아래는 식 “(9/(6-4))*3”을 이진 트리로 표현한 것이다.

임의의 정점에 연산자가 있으면 해당 연산자의 왼쪽 서브 트리의 결과와 오른쪽 서브 트리의 결과에 해당 연산자를 적용한다.
 

 

사칙연산 “+, -, *, /”와 양의 정수로만 구성된 임의의 이진 트리가 주어질 때, 이를 계산한 결과를 출력하는 프로그램을 작성하라.

계산 중간 과정에서의 연산은 모두 실수 연산으로 한다.


[입력]

총 10개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 줄에는 정점의 개수 N(1≤N≤1000)이 주어진다. 그다음 N 줄에 걸쳐 각 정점의 정보가 주어진다.

정점이 정수면 정점 번호와 양의 정수가 주어지고, 정점이 연산자이면 정점 번호, 연산자, 해당 정점의 왼쪽 자식, 오른쪽 자식의 정점 번호가 차례대로 주어진다.

정점 번호는 1부터 N까지의 정수로 구분된고 루트 정점의 번호는 항상 1이다.

위의 예시에서, 숫자 4가 7번 정점에 해당하면 “7 4”으로 주어지고, 연산자 ‘/’가 2번 정점에 해당하면 두 자식이 각각 숫자 9인 4번 정점과 연산자 ‘-’인 5번 정점이므로 “2 / 4 5”로 주어진다.

[출력]

각 테스트케이스마다 '#t'(t는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고 사칙연산을 계산한 결과값을 출력한다.

결과값은 소수점 아래는 버리고 정수로 출력한다.
입력
5
1 - 2 3
2 - 4 5
3 10
4 88
5 65
7
1 / 2 3
2 - 4 5
3 - 6 7
4 261
5 61
6 81
7 71
...

input.txt
출력
#1 13
#2 20
...
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct s_tree
{
	int				num;
	int				key_i;
	char			key_c;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*root;
int		N;
char	buf[100];

t_tree	*find_node(t_tree *cur, int num)
{
	t_tree	*res;

	if (cur == NULL)
		return (NULL);
	if (cur->num == num)
		return (cur);
	res = find_node(cur->left, num);
	if (res != NULL)
		return (res);
	res = find_node(cur->right, num);
	if (res != NULL)
		return (res);
	return (NULL);
}

void	add_tree(int num, int key_i, char key_c, int left, int right)
{
	t_tree	*temp;
	t_tree	*cur;

	cur = find_node(root, num);
	if (key_i != -1)
		cur->key_i = key_i;
	else
		cur->key_c = key_c;
	if (left != -1) {
		temp = (t_tree *)calloc(1, sizeof(t_tree));
		temp->num = left;
		cur->left = temp;
	}
	if (right != -1) {
		temp = (t_tree *)calloc(1, sizeof(t_tree));
		temp->num = right;
		cur->right = temp;
	}
}

void	read_line(void)
{
	char	*input[4];
	int		start;
	int		idx;
	int		num;
	int		key_i;
	char	key_c;
	int		left;
	int		right;

	left = -1;
	right = -1;
	key_i = -1;
	key_c = -1;
	idx = -1;
	start = 0;
	scanf(" %[^\n]s", buf);
	for (int i = 0; ; ++i) {
		if (buf[i] == ' ') {
			input[++idx] = &buf[start];
			buf[i] = '\0';
			start = i + 1; 
		}
		else if (buf[i] == '\0') {
			input[++idx] = &buf[start];
			break ;
		}
	}
	for (int i = 0; i <= idx; ++i) {
		if (i == 0)
			num = atoi(input[0]);
		if (i == 1) {
			if (input[1][0] == '+' || \
				input[1][0] == '-' || \
				input[1][0] == '*' || \
				input[1][0] == '/')
				key_c = input[1][0];
			else
				key_i = atoi(input[1]);
		}
		if (i == 2)
			left = atoi(input[2]);
		if (i == 3)
			right = atoi(input[3]);
	}
	add_tree(num, key_i, key_c, left, right);
}

int	calculate(t_tree *cur)
{
	int		val_1;
	int		val_2;

	if (cur->left == NULL && cur->right == NULL) {
		return (cur->key_i);
	}
	val_1 = calculate(cur->left);
	val_2 = calculate(cur->right);
	if (cur->key_c == '+')
		return (val_1 + val_2);
	if (cur->key_c == '-')
		return (val_1 - val_2);
	if (cur->key_c == '*')
		return (val_1 * val_2);
	if (cur->key_c == '/')
		return (val_1 / val_2);
	return (0);
}

void	remove_tree(t_tree *cur)
{
	if (cur == NULL)
		return ;
	remove_tree(cur->left);
	remove_tree(cur->right);
	free(cur);
}

int main(void)
{
	int	res;

	setbuf(stdout, NULL);
	for (int i = 0; i < 10; ++i) {
		scanf(" %d", &N);
		root = (t_tree *)calloc(1, sizeof(t_tree));
		root->num = 1;
		for (int j = 0; j < N; ++j)
			read_line();
		res = calculate(root);
		printf("#%d %d\n", i + 1, res);
		remove_tree(root);
	}
	return (0);
}