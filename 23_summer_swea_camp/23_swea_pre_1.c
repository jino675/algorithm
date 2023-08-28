/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   musk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 23:16:57 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/12 23:59:15 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_high
{
	int	r;
	int	c;
	int	val;
}	t_high;

t_high	high_r[200001];
t_high	high_c[200001];

int	main(void)
{
	int		i;
	int		j;
	int		k;
	int		tc;
	int		q;
	int		n;
	int		m;
	int		in_r;
	int		in_c;
	int		in_v;
	int		cur;
	int		res;
	int		f1;
	int		f2;

	setbuf(stdout, NULL);
	scanf("%d", &tc);
	i = -1;
	while (++i < tc) {
		cur = 0;
		res = 0;
		scanf("%d %d %d", &n, &m, &q);
		j = 0;
		while (++j <= n) {
			k = 0;
			while (++k <= m) {
				scanf("%d", &in_v);
				if (k == 1 || in_v > high_r[j].val) {
					high_r[j].r = j;
					high_r[j].c = k;
					high_r[j].val = in_v;
				}
				if (j == 1 || in_v > high_c[k].val) {
					high_c[k].r = j;
					high_c[k].c = k;
					high_c[k].val = in_v;
				}
			}
		}
		k = 0;
		while (++k <= n)
			if (high_r[k].val == high_c[high_r[k].c].val)
				++cur;
		j = -1;
		while (++j < q) {
			f1 = 0;
			f2 = 0;
			scanf("%d %d %d", &in_r, &in_c, &in_v);
			if (in_v > high_r[in_r].val)
				f1 = 1;
			if (in_v > high_c[in_c].val)
				f2 = 1;
			if (f1 == 1 && f2 == 0) {
				if (high_r[in_r].c != in_c && \
					high_r[in_r].val == high_c[high_r[in_r].c].val)
					--cur;
				high_r[in_r].c = in_c;
				high_r[in_r].val = in_v;
			}
			else if (f1 == 0 && f2 == 1) {
				if (high_c[in_c].r != in_r && \
					high_r[high_c[in_c].r].val == high_c[in_c].val)
					--cur;
				high_c[in_c].r = in_r;
				high_c[in_c].val = in_v;
			}
			else if (f1 == 1 && f2 == 1) {
				if (high_c[in_c].r != in_r && \
					high_r[high_c[in_c].r].val == high_c[in_c].val)
					--cur;
				if (high_r[in_r].val != high_c[in_c].val)
					++cur;
				high_r[in_r].c = in_c;
				high_r[in_r].val = in_v;
				high_c[in_c].r = in_r;
				high_c[in_c].val = in_v;
			}
			res += cur;
		}
		printf("#%d %d\n", i + 1, res);
	}
    return (0);
}