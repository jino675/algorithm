/*
No. 37 영어 공부
참여자 40 제출 104 배점 100
Problem제출이력정답
시간 : 31개 테스트케이스를 합쳐서 C/C++의 경우 2초 / Java의 경우 4초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
※ SW expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.
 

수림이는 영어 공부를 도와주는 스마트폰 앱을 사용하고 있다.

이 앱에는 영어 공부를 한 날에는 점수가 전날보다 1씩 쌓이고, 접속하지 않으면 점수가 0이 되는 “연속 공부 기간” 점수가 존재한다.
 

앱에는 랭킹 시스템이 있는데, 수림이가 그동안 적립했던 점수 중 최댓값을 가지고 다른 사람들과 경쟁한다.

즉, 영어 공부를 매일매일 했던 연속 기간이 길면 길수록 랭킹에서 유리하다.
 

수림이는 영어 공부보다는 해킹을 더 좋아해서, p개의 날짜에 대해서 영어 공부를 실제로 하지 않았더라도 한 날이라고 체크할 수 있는 방법을 알아냈다.

수림이가 p개의 날짜를 적절히 체크를 하였을 때, 영어 공부를 매일매일 했던 연속 기간의 최대 가능한 길이를 구하여라.
 

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 영어 공부를 한 날의 수, 추가로 체크할 수 있는 날의 수를 의미하는 자연수 n, p가 주어진다. (1 ≤ n, p ≤ 200,000).

두 번째 줄에는 n개의 서로 다른 정수가 증가하는 순서대로 주어진다. 이들은 수림이가 영어 공부를 실제로 한 날의 번호들이다. 번호의 크기는 0 이상 106 이하이다..
 

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

연속 공부 기간의 가능한 최대 길이를 출력하라.

입력
2
5 2
3 5 6 10 11
2 10
42 420	// 전체 테스트 케이스 수
// 첫 번째 테스트 케이스 n=5, p=2

// 두 번째 테스트 케이스 n=2,p=10
 
input.txt
출력
#1 5
#2 11	// 첫 번째 테스트 케이스의 답
 
*/
#include <iostream>

using namespace std;

int	s_table[200000];
int	p_table[200000];
// int	table_len;

// int	max_idx;
// int	max_val;

int	N;
int	P;

int	res;

void	find_max(void)
{
	int	cur_val;
	int	max_val;
	int	cur_p;
	int	next_p;
	int	left, mid, right;

	max_val = -1;
	for (int i = 0; i < N; ++i) {
		left = i;
		right = N - 1;
		while (1) {
			mid = (left + right) / 2;
			cur_p = p_table[mid] - p_table[i];
			if (mid == N - 1) {
				cur_val = s_table[mid] - s_table[i] + 1 + (P - cur_p);
				break ;
			}
			next_p = p_table[mid + 1] - p_table[i];
			if (next_p > P && cur_p <= P) {
				cur_val = s_table[mid] - s_table[i] + 1 + (P - cur_p);
				break ;
			}
			else if (next_p <= P)
				left = mid + 1;
			else if (cur_p > P)
				right = mid;
		}
		if (cur_val > max_val)
			max_val = cur_val;
	}
	res = max_val;
}

int	main(void)
{
	int	tc;
	// int	input;
	// int	cur_count;
	// int	pre_num;
	// int	cur_val;

	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N >> P;
		res = 0;
		// max_val = -1;
		// table_len = 0;
		// cur_count = 0;
		for (int j = 0; j < N; ++j) {
			cin >> s_table[j];
			if (j > 0)
				p_table[j] = p_table[j - 1] + (s_table[j] - s_table[j - 1] - 1);
			else
				p_table[j] = 0;
			// if (j > 0 && input != pre_num + 1) {
			// 	s_table[table_len] = cur_count;
			// 	p_table[table_len] = input - pre_num - 1;
			// 	// if (table_len > 0) {
			// 	// 	if (p_table[table_len - 1] <= P)
			// 	// 		cur_val = s_table[table_len - 1] + p_table[table_len - 1] + s_table[table_len];
			// 	// 	else
			// 	// 		cur_val = max(s_table[table_len - 1] + P, s_table[table_len] + P);
			// 	// 	if (cur_val > max_val) {
			// 	// 		max_val = cur_val;
			// 	// 		max_idx = table_len - 1;
			// 	// 	}
			// 	// }
			// 	++table_len;
			// 	cur_count = 0;
			// }
			// ++cur_count;
		}
		// s_table[table_len] = cur_count;
		// if (table_len > 0) {
		// 	if (p_table[table_len - 1] <= P)
		// 		cur_val = s_table[table_len - 1] + p_table[table_len - 1] + s_table[table_len];
		// 	else
		// 		cur_val = max(s_table[table_len - 1] + P, s_table[table_len] + P);
		// 	if (cur_val > max_val) {
		// 		max_val = cur_val;
		// 		max_idx = table_len - 1;
		// 	}
		// }

		// for (int j = 0; j < table_len; ++j)
		// 	cout << "s_" << j << " : " << s_table[j] << ", p_" << j <<  " : " << p_table[j] << ", ";
		// cout << "s_" << table_len << " : " << s_table[table_len] << "\n";

		// if (table_len > 0)
		// 	find_max();
		// else
		// 	res = s_table[0] + P;
		find_max();
		cout << "#" << i << " " << res << "\n";
	}
}



// void	find_max(void)
// {
// 	int	cur_left;
// 	int	cur_right;
// 	int	next_left;
// 	int	next_right;
// 	int	left_val;
// 	int	right_val;

// 	cur_left = max_idx;
// 	cur_right = max_idx;
// 	if (p_table[max_idx] <= P) {
// 		res = s_table[max_idx] + p_table[max_idx] + s_table[max_idx + 1];
// 		P -= p_table[max_idx];
// 	}
// 	else {
// 		res = max_val;
// 		return ;
// 	}
// 	while (P > 0) {
// 		// cout << "cur_left : " << cur_left << ", cur_right : " << cur_right << "\n";
// 		// cout << "cur_res : " << res << ", cur_P : " << P << "\n";
// 		if (cur_left > 0)
// 			next_left = cur_left - 1;
// 		else
// 			next_left = -1;
// 		if (cur_right < table_len - 1)
// 			next_right = cur_right + 1;
// 		else
// 			next_right = -1;

// 		if (next_left != -1) {
// 			if (p_table[next_left] <= P)
// 				left_val = s_table[next_left] + p_table[next_left];
// 			else
// 				left_val = P;
// 		}
// 		if (next_right != -1) {
// 			if (p_table[next_right] <= P)
// 				right_val = p_table[next_right] + s_table[next_right + 1];
// 			else
// 				right_val = P;
// 		}

// 		if (next_left != -1 && next_right != -1) {
// 			if (p_table[next_left] > P && p_table[next_right] <= P) {
// 				res += right_val;
// 				P -= p_table[next_right];
// 				cur_right = next_right;
// 			}
// 			else if (p_table[next_left] <= P && p_table[next_right] > P) {
// 				res += left_val;
// 				P -= p_table[next_left];
// 				cur_left = next_left;
// 			}
// 			else if (p_table[next_left] > P && p_table[next_right] > P) {
// 				res += P;
// 				P = 0;
// 			}
// 			else {
// 				if (left_val > right_val) {
// 					res += left_val;
// 					P -= p_table[next_left];
// 					cur_left = next_left;
// 				}
// 				else if (left_val <= right_val) {
// 					res += right_val;
// 					P -= p_table[next_right];
// 					cur_right = next_right;
// 				}
// 			}
// 		}
// 		else if (next_left != -1) {
// 			res += left_val;
// 			P -=p_table[next_left];
// 			cur_left = next_left;
// 		}
// 		else if (next_right != -1) {
// 			res += right_val;
// 			P -= p_table[next_right];
// 			cur_right = next_right;
// 		}
// 		else if (next_left == -1 && next_right == -1) {
// 			res += P;
// 			P = 0;
// 		}
// 	}
// }

// void	find_max(void)
// {
// 	int	cur_p;
// 	int	cur_val;
// 	int	max_val;

// 	max_val = -1;
// 	for (int i = 0; i <= table_len; ++i) {
// 		cur_p = P;
// 		cur_val = 0;
// 		for (int j = 0; cur_p > 0; ++j) {
// 			if (i + j < table_len) {
// 				cur_val += s_table[i + j];
// 				if (p_table[i + j] <= cur_p) {
// 					cur_val += p_table[i + j];
// 					cur_p -= p_table[i + j];
// 				}
// 				else {
// 					cur_val += cur_p;
// 					cur_p = 0;
// 					break ;
// 				}
// 			}
// 			else {
// 				cur_val += cur_p;
// 				cur_p = 0;
// 				break ;
// 			}
// 		}
// 		if (cur_val > max_val) {
// 			max_val = cur_val;
// 		}
// 	}
// 	res = max_val;
// }