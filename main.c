#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * factorise - find the list number to find a multiple
 * @num: number to check
 */
void factorise(long long num, long long div)
{
	long long flag = 1;

	while (flag)
	{
		if ((num % div) == 0)
		{
			printf("%llu=%llu*%llu\n", num, (num/div), div);
			flag = 0;
		}
		++div;
	}
}
/**
 * main - open a file and take the contents
 * @ac: arguement count
 * @av: arguements
 * Return: 0
 */
int main(int ac, char **av)
{
	FILE *ptr;
	char buff[255];
	long long num, div;

	if (ac != 2)
	{
		fprintf(stderr, "Error: need to provide one file\n");
		return (EXIT_FAILURE);
	}

	ptr = fopen(av[1], "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(buff, sizeof(buff), ptr))
	{
		div = 2;
		num = atoll(buff);
		factorise(num, div);
	}
	fclose(ptr);

	return (0);
}
