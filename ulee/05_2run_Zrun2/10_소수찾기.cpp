#include <stdio.h>

int	is_prime(int nb)
{
	int i;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (!(nb % 2 && nb % 3))
		return (0);
	i = 5;
	while (i * i <= nb)
	{
		if (!(nb % i && nb % (i + 2)))
			return (0);
		i += 6;
	}
	return (1);
}
int 	main()
{
	int count;
	int i;
	scanf("%d", &count);
	int numbers[count];
	int prime_count = 0;

	i = 0;
	while (i < count)
	{
		scanf("%d", &numbers[i]);
		i++;
	}

	i = 0;
	while (i < count)
	{
		if (is_prime(numbers[i]))
			prime_count++;
		i++;
	}
	printf("%d", prime_count);

	return (0);
}
