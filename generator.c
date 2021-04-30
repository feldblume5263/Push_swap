#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int						is_dup(int *rand, int num, int end)
{
	int					idx;

	idx = 0;
	while (idx < end)
	{
		if (rand[idx] == num)
			return (1);
		idx++;
	}
	return (0);
}

int						main(int argc, char **argv)
{
	int					max;

	if (argc != 2)
		return (1);
	max = atoi(argv[1]);
	if (max <= 0)
		return (1);

	int					random[max];
	int					idx;
	int					num;

	idx = 0;
	while (idx < max)
	{
		num = rand() % max;
		if (is_dup(random, num, idx) == 1)
			continue ;
		random[idx] = num;
		idx++;
	}
	idx = 0;
	while (idx < max)
	{
		printf("%d ", random[idx]);
		idx++;
	}
	printf("\n");
}
