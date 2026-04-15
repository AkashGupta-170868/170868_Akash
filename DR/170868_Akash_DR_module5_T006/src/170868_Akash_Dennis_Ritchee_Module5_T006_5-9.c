/*
 * Descriptions:  Rewrite appropriate programs from earlier chapters and exercises with pointers
 instead of array indexing. 1.getline 2.atoi 3.itoa 4.reverse 5.strindex 6.gettop
 * Author : Akash Gupta
 * Created at : 30-03-2026
 * Modified at : 30-03-2026
 */

#include <stdio.h>

static int daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

/* function name : leap_year();
 * Descriptions: get the line input by user till Eof and \n
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
int check_leap_year(int year) {
    return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
}

/* function name : calculate_day_of_year();
 * Descriptions: get the line input by user till Eof and \n
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
int calculate_day_of_year(int year, int month, int day) {
    int i;
    int leap = check_leap_year(year);
    int *p = *(daytab + leap);

    if (year < 0) return -1;
    if (month < 1 || month > 12) return -1;
    if (day < 1 || day > *(p + month)) return -1;

    for (i = 1; i < month; i++)
        day += *(p + i);

    return day;
}
/* function name : calculate_month_day();
 * Descriptions: get the line input by user till Eof and \n
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
int calculate_month_day(int year, int yearday, int *pmonth, int *pday) {
    int i;
    int leap = check_leap_year(year);
    int *p = *(daytab + leap);

    if (year < 0) return -1;
    if (yearday < 1 || yearday > (leap ? 366 : 365)) return -1;

    for (i = 1; yearday > *(p + i); i++)
        yearday -= *(p + i);

    *pmonth = i;
    *pday = yearday;

    return 0;
}

int test_cal2() {
    int choice;

    printf("===== MENU =====\n");
    printf("1. (Year, Month, Day) -> Day of Year\n");
    printf("2. (Year, Day of Year) -> Month, Day\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int year, month, day, result;

        printf("Enter Year Month Day: ");
        scanf("%d %d %d", &year, &month, &day);

        result = calculate_day_of_year(year, month, day);

        if (result == -1) {
            if (year < 0)
                printf("Error: Year must be positive\n");
            else if (month < 1 || month > 12)
                printf("Error: Month must be between 1 and 12\n");
            else
                printf("Error: Invalid day for given month/year\n");
        } else {
            printf("Result: %d is the %dth day of %d\n", day, result, year);
        }
    }

    else if (choice == 2) {
        int year, yearday, month, day;

        printf("Enter Year and Day of Year: ");
        scanf("%d %d", &year, &yearday);

        if (calculate_month_day(year, yearday, &month, &day) == -1) {
            if (year < 0)
                printf("Error: Year must be positive\n");
            else
                printf("Error: Day of year must be between 1 and %d\n",
                       check_leap_year(year) ? 366 : 365);
        } else {
            printf("Result: Month = %d, Day = %d\n", month, day);
        }
    }

    else {
        printf("Invalid choice\n");
    }

    return 0;
}
