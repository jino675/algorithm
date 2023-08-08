#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PRINT 200

int main(void)
{
	char	c[6];
	int		dice_res;
	int		status;

	printf("%d\n", NUM_PRINT);
	c[5] = '\0';
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 200; ++i) {
		for (int j = 0; j < 5; ++j) {
			c[j] = rand() % 52;
			if (c[j] < 26)
				c[j] += 'A';
			else
				c[j] += 'a' - 26;
			if (j > 0) {
				dice_res = rand() % 10;
				if (dice_res == 0) {
					c[j] = '\0';
					break ;
				}
			}
		}
		printf("%s ", c);
		status = rand() % 2;
		if (status == 1)
			printf("%s\n", "enter");
		else
			printf("%s\n", "leave");
	}
	return (0);
}