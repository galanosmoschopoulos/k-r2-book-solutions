#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -20;
	upper = 140;
	step = 20;

	celsius = lower;
	printf(" C |  F\n");
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32; 
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
