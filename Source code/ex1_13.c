#include <stdio.h>

#define IN		1
#define OUT		0
#define MAX_LENGTH 	20 

main()
{
	int c, i, j, state, currentLength, minLengthDetected, maxLengthDetected;
	int wordLengths[MAX_LENGTH];
	
	currentLength = 0;	
	state = OUT;
	for (i = 0; i < MAX_LENGTH; ++i)
		wordLengths[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) { 
				++wordLengths[currentLength-1];
				currentLength = 0;
			}
			state = OUT; 
		}
		else {
			state = IN;
			++currentLength;
		}
	}

	for (i = 0; i < MAX_LENGTH; ++i)
		if (wordLengths[i] != 0)
			maxLengthDetected = i+1;
	for (i = MAX_LENGTH; i >= 0; --i)
		if (wordLengths[i] != 0)
			minLengthDetected = i+1;
	int noOfLengths = maxLengthDetected - minLengthDetected + 1;

	printf("\n\nLength | No of words\n-------|------------\n");
	for (i = minLengthDetected-1; i < maxLengthDetected; ++i) {
		printf("%6d | ", i+1);
		printf("(%d) ", wordLengths[i]);
		for (j = 0; j < wordLengths[i]; ++j)
			putchar('#');
		putchar('\n');
	}
	printf("\n\n\n");

	int maxWordsPerLength = 0;

	for (i = minLengthDetected-1; i < maxLengthDetected; ++i)
		if (wordLengths[i] > maxWordsPerLength)
			maxWordsPerLength = wordLengths[i];
	
	for (i = maxWordsPerLength; i > 0; --i) {
		for (j = minLengthDetected-1; j < maxLengthDetected; ++j)
			if (wordLengths[j] >= i)
				printf("#  ");
			else
				printf("   ");
		putchar('\n');
	}
	for (i = minLengthDetected-1; i < maxLengthDetected; ++i)
		if (wordLengths[i] < 10)
			printf("%d  ", wordLengths[i]);
		else
			printf("%d ", wordLengths[i]);
	printf("\t[no of words]\n");

	for (i = 0; i < 3 * noOfLengths - 2; ++i)
		printf("-");	
	putchar('\n');

	for (i = minLengthDetected; i <= maxLengthDetected; ++i)
		if (i < 10)
			printf("%d  ", i);		
		else
			printf("%d ", i);
	printf("\t[word length]\n");
}
