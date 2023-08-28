#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_arrow
{
	int				num;
	int				cost;
	int				is_visited;
	struct s_arrow *next;
}	t_arrow;

typedef struct s_student
{
	int		is_pointed;
	t_arrow	*arrow;
}	t_student;

t_student	*student;
int			min;

static void	DFS(int cur_idx, int start, int cur_total)
{
	t_arrow	*next;

	if (cur_total >= min)
		return ;
	if (cur_total > 0 && cur_idx == start) {
		min = cur_total;
		return ;
	}
	next = student[cur_idx].arrow;
	while (next != NULL) {
		if (next->is_visited == 0) {
			next->is_visited = 1;
			DFS(next->num, start, cur_total + next->cost);
			next->is_visited = 0;
		}
		next = next->next;
	}
}

int	main(void)
{
	int		i;
	int		j;
	int		tc;
	int		n;
	int		m;
	int		in_from;
	int		in_to;
	int		in_cost;
	t_arrow		*arrow;

	setbuf(stdout, NULL);
	scanf("%d", &tc);
	i = 0;
	while (++i <= tc) {
		min = 2147483647;
		scanf("%d %d", &n, &m);
		student = (t_student *)calloc(n + 1, sizeof(t_student));
		j = 0;
		while (++j <= m) {
			scanf("%d %d %d", &in_from, &in_to, &in_cost);
			arrow = (t_arrow *)malloc(sizeof(t_arrow));
			arrow->num = in_to;
			arrow->cost = in_cost;
			arrow->is_visited = 0;
			arrow->next = student[in_from].arrow;
			student[in_from].arrow = arrow;
			++student[in_to].is_pointed;
		}
		j = 0;
		while (++j <= n) {
			if (student[j].is_pointed == 0)
				continue ;
			DFS(j, j, 0);
		}
		if (min == 2147483647)
			min = -1;
		printf("#%d %d\n", i, min);
	}
}
