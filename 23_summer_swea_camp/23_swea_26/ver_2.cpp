#include <iostream>
#include <climits>
#include <unordered_set>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int					N;
int					K;
int					A[10];
vector<int>			my_vector;
int					min_cnt;

unordered_set<int>	visited;

void	make_my_vector(int cur_lev, long long cur_val)
{
	long long	mul;

	if (cur_lev == N) {
		my_vector.push_back(cur_val);
		return ;
	}
	mul = cur_val;
	while (true) {
		make_my_vector(cur_lev + 1, mul);
		mul *= A[cur_lev];
		if (mul > K)
			return ;
	}
}

int		is_sub(int leftover, int cur_divisor, int pre_divisor)
{
	if (cur_divisor > leftover)
		return (0);
	else if (pre_divisor % cur_divisor != 0)
		return (0);
	else
		return (1);
}

void	find_min(void)
{
	int		leftover, cur_cnt, cur_divisor, pre_divisor, cur_val;

	for (auto iter_1 = my_vector.begin(); iter_1 != my_vector.end(); ++iter_1) {
		cur_val = *iter_1;
		auto	iter_2 = visited.find(cur_val);
		if (iter_2 != visited.end())
			continue ;
		leftover = K;
		cur_cnt = 0;

		pre_divisor = cur_val;
		for (auto iter_3 = iter_1; iter_3 != my_vector.end(); ++iter_3) {
			cur_divisor = *iter_3;
			if (cur_val % cur_divisor == 0)
				visited.insert(cur_val);
			if (is_sub(leftover, cur_divisor, pre_divisor) == 1) {
				pre_divisor = cur_divisor;
				while (cur_divisor <= leftover) {
					cur_cnt += leftover / cur_divisor;
					leftover = leftover % cur_divisor;
				}
				if (cur_cnt >= min_cnt)
					break ;
				if (leftover == 0) {
					if (cur_cnt < min_cnt)
						min_cnt = cur_cnt;
					break ;
				}
			}
		}
	}
}

int	main(void)
{
	int	tc;
	ios::sync_with_stdio(false);
    
	cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cin >> N;
		for (int j = 0; j < N; ++j)
			cin >> A[j];
		cin >> K;
		min_cnt = INT_MAX;
		my_vector.clear();
		visited.clear();
		make_my_vector(0, 1);
		sort(my_vector.begin(), my_vector.end(), greater<int>());
		find_min();
		cout << "#" << i << " " << min_cnt << "\n";
	}
	return (0);
}