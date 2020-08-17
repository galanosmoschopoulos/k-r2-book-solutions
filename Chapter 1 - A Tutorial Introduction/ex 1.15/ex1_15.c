#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

float tempConvertion(int fahr);									// Function prototype

int main()
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)		// Start at fahr = (the lower limit), increase fahr by STEP, stop when fahr touches the upper limit
		printf("%3d %6.1f\n", fahr, tempConvertion(fahr));		// Call the function 'tempConvertion()' and print the calculated values

	return 0;
}
float tempConvertion(int fahr)
{
	int celsius;
	celsius = (5.0/9.0)*(fahr-32);								// Calculate the temperature in celsius
	return celsius;												// Return calculated value
}


/* Alternative:
 * float tempConvertion(int fahr)
 * {
 * 	return (5.0/9.0)*(fahr-32);
 * }
 */
