// calculator
#include <stdio.h>

int	main()
{
	float i = 10;
	float min1 = 5;
	float min2 = 2;
	float m1;
	float m2;

	m1 = ((i/2) - (min1));
	m2 = ((i/2) - (min2));
	printf("i:%f\nmin1/2: %f\nmin2/2: %f\n", i, (min1), (min2));
	printf("m1: %f\nm2: %f\n", m1, m2);
	return (0);

}