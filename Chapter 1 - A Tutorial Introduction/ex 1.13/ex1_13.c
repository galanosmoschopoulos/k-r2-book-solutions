#include <stdio.h>

#define IN		1
#define OUT		0
#define MAX_LENGTH 	20 

int main()
{
	int c, i, j, state, currentLength, minLengthDetected, maxLengthDetected, maxWordsPerLength;
	int wordLengths[MAX_LENGTH];											// Holds the amount of words for each length (its index representes a length)

	maxWordsPerLength = 0;
	currentLength = 0;	
	state = OUT;

	for (i = 0; i < MAX_LENGTH; ++i)										// Initialize the array with 0s
		wordLengths[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {							// If we detect a blank, a tab or a newline
			if (state == IN) { 												// If we're in a word
				++wordLengths[currentLength-1];								// Add one more word to the index of the current length
				currentLength = 0;											// Reset current length
			}
			state = OUT; 													// We are out of the world as these ' ', '\n' AND '\t' separate words
		}
		else {
			state = IN;
			++currentLength;												// If we iterate through a word, increase the current length
		}
	}

	for (i = 0; i < MAX_LENGTH; ++i)										// Detect which is the maximum length of a world and the minimum length of a world
		if (wordLengths[i] != 0)
			maxLengthDetected = i+1;
	for (i = MAX_LENGTH; i >= 0; --i)
		if (wordLengths[i] != 0)
			minLengthDetected = i+1;

	int noOfLengths = maxLengthDetected - minLengthDetected + 1;			// Calculate how many lengths we have to graph

	printf("\n\nLength | No of words\n-------|------------\n");
	for (i = minLengthDetected-1; i < maxLengthDetected; ++i) {				// Iterate through the different lengths
		printf("%6d | ", i+1);												// Print the length
		printf("(%2d) ", wordLengths[i]);									// Print the amount of words for the said length
		for (j = 0; j < wordLengths[i]; ++j)								// Print a bar whose size is proportional to the amount of words
			putchar('#');
		putchar('\n');
	}
	printf("\n\n\n");

	for (i = minLengthDetected-1; i < maxLengthDetected; ++i)				// Find the maximum amount of words of the same length
		if (wordLengths[i] > maxWordsPerLength)
			maxWordsPerLength = wordLengths[i];
	
	for (i = maxWordsPerLength; i > 0; --i) {								// i starts from maxWordsPerLength, goes to 0 -- i is an amount of words
		for (j = minLengthDetected-1; j < maxLengthDetected; ++j)			// j starts from minLengthDetected, goes to maxLengthDetected -- j is a length
			if (wordLengths[j] >= i)										// If the amount of words for a length j is greater or equal to the amount of words i, print a #
				printf("#  ");
			else
				printf("   ");
		putchar('\n');
	}
	for (i = minLengthDetected-1; i < maxLengthDetected; ++i)				// Print the amount of words for each length
		if (wordLengths[i] < 10)
			printf("%d  ", wordLengths[i]);
		else
			printf("%d ", wordLengths[i]);
	printf("\t[no of words]\n");

	for (i = 0; i < 3 * noOfLengths - 2; ++i)								// Print a line
		printf("-");	
	putchar('\n');

	for (i = minLengthDetected; i <= maxLengthDetected; ++i)				// Print the range of lengths
		if (i < 10)
			printf("%d  ", i);		
		else
			printf("%d ", i);
	printf("\t[word length]\n");
}
