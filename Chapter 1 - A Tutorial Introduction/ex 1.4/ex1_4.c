#include <stdio.h>

int main()
{
	// Variable declaration
	float fahr, celsius;
	int lower, upper, step;

	// Set initial values
	lower = -20;
	upper = 140;
	step = 20;

	celsius = lower;
	printf(" C |  F\n");							// Print small labels for the two columns
	while (celsius <= upper) {						// While the current to-be-converted temp is lower than the upper limit
		fahr = (9.0/5.0) * celsius + 32; 			// Compute temp in fahreneit
		printf("%3.0f %6.1f\n", celsius, fahr);		// Print the formatted temps
		celsius = celsius + step;					// Update the celsius temp
	}
}
