/*
 * Descriptions:its determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers (limits , float )
 * Author : Akash Gupta
 * Created at : 19-02-2026
 * Modified at : 19-02-2026
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_ranges() {
    printf("===== RANGES =====\n");

    printf("Signed char:   %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: 0 to %u\n", UCHAR_MAX);

    printf("Signed short:   %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short: 0 to %u\n", USHRT_MAX);

    printf("Signed int:   %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int: 0 to %u\n", UINT_MAX);

    printf("Signed long:   %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long: 0 to %lu\n", ULONG_MAX);

    printf("\n===== FLOATING POINT (HEADER) =====\n");

    printf("Float:  %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);
}
