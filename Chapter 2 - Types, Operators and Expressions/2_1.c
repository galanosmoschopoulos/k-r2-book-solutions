#include <stdio.h>
#include <limits.h>
#include <math.h>

int main()
{
	printf("Using limits.h and float.h:\n---------------------------\n");
	printf("[CHAR] min=%d, max=%d\n", SCHAR_MIN, SCHAR_MAX);
	printf("[INT] min=%d, max=%d\n", INT_MIN, INT_MAX);
	printf("[SHORT] min=%d, max=%d\n", SHRT_MIN, SHRT_MAX);
	printf("[LONG] min=%ld, max=%ld\n", LONG_MIN, LONG_MAX);
	printf("[UNSIGNED CHAR] min=0, max=%u\n", UCHAR_MAX);
	printf("[UNSIGNED INT] min=0, max=%u\n", UINT_MAX);
	printf("[UNSIGNED SHORT] min=0, max=%u\n", USHRT_MAX);
	printf("[UNSIGNED LONG] min=0, max=%lu\n", ULONG_MAX);

	printf("\n\nUsing calculation:\n------------------\n");
	signed long max, min; 
	
	signed char testchar = 0;
	signed int testint = 0;
	signed short testshort = 0;
	signed long testlong = 0;

	while((max=testchar)<++testchar) {}
	testchar = 0;
	while((min=testchar)>--testchar) {}
	printf("[CHAR] min=%d, max=%d\n", min, max);

	while((max=testint)<++testint) {}
	testint = 0;
	while((min=testint)>--testint) {}
	printf("[INT] min=%d, max=%d\n", min, max);
	
	while((max=testshort)<++testshort) {}
	testshort = 0;
	while((min=testshort)>--testshort) {}
	printf("[SHORT] min=%d, max=%d\n", min, max);

	//while((max=testlong)<++testlong) {}
	//testlong = 0;
	//while((min=testlong)>--testlong) {}
	//printf("[LONG] min=%d, max=%d\n", min, max);
	printf("LONG calculation disabled due to calculation time needed.\n");
	
	unsigned char testunchar = 0;
	unsigned int testunint = 0;
	unsigned short testunshort = 0;
	unsigned long testunlong = 0;
	printf("[UNSIGNED CHAR] min=0, max=%u\n", --testunchar);
	printf("[UNSIGNED INT] min=0, max=%u\n", --testunint);
	printf("[UNSIGNED SHORT] min=0, max=%u\n", --testunshort);
	printf("[UNSIGNED LONG] min=0, max=%lu\n", --testunlong);
}
