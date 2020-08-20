#include <stdio.h>

int main()
{
	// Variable declaration
	float fahr, celsius;
	int lower, upper, step;

	// Set initial values
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf(" F |  C\n");                            // Print small labels for the two columns
	while (fahr <= upper) {                         // While the current to-be-converted temp is lower than the upper limit
		celsius = (5.0/9.0) * (fahr-32.0);          // Compute temp in celsius
		printf("%3.0f %6.1f\n", fahr, celsius);     // Print the formatted temps
		fahr = fahr + step;                         // Update the fahreneit temp
	}
}
