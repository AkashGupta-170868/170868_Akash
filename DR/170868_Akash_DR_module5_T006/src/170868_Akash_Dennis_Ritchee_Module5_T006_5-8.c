#include <stdio.h>
#include <stdint.h>

static int32_t days_in_month[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int32_t isLeapYear(int32_t year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

int32_t getDayOfYear(int32_t year, int32_t month, int32_t day) {
    int32_t i;
    int32_t leap = isLeapYear(year);

    if (year <= 0) {
        printf("Error: Year must be positive\n");
        return -1;
    }

    if (month < 1 || month > 12) {
        printf("Error: Month must be between 1 and 12\n");
        return -1;
    }

    if (day < 1 || day > days_in_month[leap][month]) {
        printf("Error: Invalid day for given month\n");
        return -1;
    }

    for (i = 1; i < month; i++) {
        day += days_in_month[leap][i];
    }

    return day;
}

int32_t getMonthAndDay(int32_t year, int32_t dayOfYear, int32_t *month, int32_t *day) {
    int32_t i;
    int32_t leap = isLeapYear(year);

    if (year <= 0) {
        printf("Error: Year must be positive\n");
        return -1;
    }

    if (dayOfYear < 1 || dayOfYear > (leap ? 366 : 365)) {
        printf("Error: Day of year must be between 1 and %d\n",
               leap ? 366 : 365);
        return -1;
    }

    for (i = 1; dayOfYear > days_in_month[leap][i]; i++) {
        dayOfYear -= days_in_month[leap][i];
    }

    *month = i;
    *day = dayOfYear;

    return 0;
}

int test_cal() {
    int32_t choice;

    printf("\n===== Date Converter =====\n");
    printf("1. (Year, Month, Day) → Day of Year\n");
    printf("2. (Year, Day of Year) → Month, Day\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int32_t year, month, day, result;

        printf("Enter Year Month Day: ");
        scanf("%d %d %d", &year, &month, &day);

        result = getDayOfYear(year, month, day);

        if (result != -1) {
            printf("Result: %d-%d-%d is Day %d of the year\n",
                   day, month, year, result);
        }

    } else if (choice == 2) {
        int32_t year, dayOfYear, month, day;

        printf("Enter Year and Day of Year: ");
        scanf("%d %d", &year, &dayOfYear);

        if (getMonthAndDay(year, dayOfYear, &month, &day) != -1) {
            printf("Result: Month = %d, Day = %d\n", month, day);
        }

    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
