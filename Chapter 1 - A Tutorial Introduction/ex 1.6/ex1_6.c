#include <stdio.h>

int main()
{
	printf("Press any key...\n");                           // Ask the user to press a key (in order to achieve EOF is GNU/Linux, they have to press Ctrl+D)
	printf("(getchar() != EOF) = %d\n", getchar() != EOF);  // Prints the value of whether the input character is not equal to the value of the macro "EOF"
}
