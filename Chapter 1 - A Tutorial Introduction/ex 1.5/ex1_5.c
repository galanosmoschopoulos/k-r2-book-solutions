#include <stdio.h>

int main()
{
	int fahr;

	for (fahr = 300; fahr >= 0; fahr = fahr - 20)           // Start at fahr=300, each time subtract 20, until fahr reaches 0
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));   // Calculate and print the temps
}
