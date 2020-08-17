/*
			TO BE REVISED -- IT IS ONLY CAPABLE  TO DETECT THE LETTERS OF THE ENGLISH ALPHABET
			I WANT IT TO WORK WITH MOST OF THE ASCII CHARACTERS
*/

#include <stdio.h>

#define CHAR_NUMBER	26 // 26 letters in english alphabet 

main()
{
	int c, i, j, charDec;
	int charFrequency[CHAR_NUMBER];

	for (i = 0; i < CHAR_NUMBER; ++i)
		charFrequency[i] = 0;

	while ((c = getchar()) != EOF) {
		charDec = c - '0';
		if (charDec >= 17 && charDec <= 42)
			++charFrequency[charDec - 17];
		if (charDec >= 49 && charDec <= 74)
			++charFrequency[charDec - 49];
	}

	printf("\n\nCharacter | Frequency\n----------|----------\n");
	for (i = 0; i < CHAR_NUMBER; ++i) {
		printf("     ");
		putchar(i + 65);
		printf(", ");
		putchar(i + 97);
		printf(" | (%3d) ", charFrequency[i]);
		for (j = 0; j < charFrequency[i]; ++j)
			putchar('#');
		putchar('\n');
	}	
}

