#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(int ac, char **av)
{
	int	parent;
	int	N;

	if (ac != 2)
		return (1);
	N = atoi(av[1]);
	srand((unsigned int)time(NULL));
	printf("1 %d ", N);
	for (int i = 1; i < N; ++i) {
		parent = rand() % i + 1;
		printf("%d ", parent);
	}
	return (0);
}