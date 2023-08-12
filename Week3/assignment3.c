#include <stdio.h>
#include <stdlib.h>


struct CDate{
    int mYear;
    int mMonth;
    int mDay;
};

const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Returns 1 if it is a leap year, 0 otherwise
int IsLeapYear(int Year){
    return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

//Returns 1 if the given date is valid, 0 otherwise
int IsValidDate(struct CDate *date){
    if (date->mMonth < 1 || date->mMonth > 12)
        return 0;

    int daysInCurrMonth = daysInMonth[date->mMonth - 1];

    if (IsLeapYear(date->mYear) && date->mMonth == 2)
        daysInCurrMonth = 29;

    return (date->mDay >= 1 && date->mDay <= daysInCurrMonth);
}

//Returns the next date of the given date
struct CDate ComputeNextDate(struct CDate *date){
    struct CDate nextDate = *date;

    int daysInCurrMonth = daysInMonth[nextDate.mMonth - 1];

    if (IsLeapYear(nextDate.mYear) && nextDate.mMonth == 2){
        daysInCurrMonth = 29;
    }

    if (nextDate.mDay < daysInCurrMonth) {
        nextDate.mDay++;
    } else {
        nextDate.mDay = 1;
        if (nextDate.mMonth < 12) {
            nextDate.mMonth++;
        } else {
            nextDate.mMonth = 1;
            nextDate.mYear++;
        }
    }

    return nextDate;
}

//Returns the previous date of the given date
struct CDate ComputePreviousDate(struct CDate *date){
    struct CDate prevDate = *date;

    int daysInPrevMonth = daysInMonth[prevDate.mMonth - 2];

    if (IsLeapYear(prevDate.mYear) && prevDate.mMonth == 3){
        daysInPrevMonth = 29;
    }

    if (prevDate.mDay > 1) {
        prevDate.mDay--;
    } else {
        if (prevDate.mMonth > 1) {
            prevDate.mMonth--;
            prevDate.mDay = daysInPrevMonth;
        } else {
            prevDate.mMonth = 12;
            prevDate.mDay = daysInMonth[11];
            prevDate.mYear--;
        }
    }

    return prevDate;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <year> <month> <day>\n", argv[0]);
        exit(-1);
    }

    struct CDate date;
    date.mYear = atoi(argv[1]);
    date.mMonth = atoi(argv[2]);
    date.mDay = atoi(argv[3]);

    if (IsValidDate(&date)) {
        struct CDate nextDate = ComputeNextDate(&date);
        struct CDate prevDate = ComputePreviousDate(&date);

        printf("Next date: %02d-%02d-%04d\n", nextDate.mDay, nextDate.mMonth, nextDate.mYear);
        printf("Previous date: %02d-%02d-%04d\n", prevDate.mDay, prevDate.mMonth, prevDate.mYear);
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}
