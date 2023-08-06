#include <stdio.h>
#include <stdlib.h>


// Number of days for each month. 
int daysInEachMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int CalculateDayOfYear(int month, int day, int year){

    //Error checks
    if(month <= 0 || month > 12){
        fprintf(stderr, "The given month is out of range.\n");
        return -1;
    }
    else if(day <= 0 || day > daysInEachMonth[month - 1]){
        fprintf(stderr, "The given day is out of range.\n");
        return -1;
    }
    else if(year < 0){
        fprintf(stderr, "The given year is out of range.\n");
        return -1;
    }

    /*
        If the given month is later than February and it is a leap year,
        then February should be 29 instead of 28 days. We are adding this only for 
        the date after February because before it, the 29th day is not passed.
        Leap year is the year that is divisible by 4 except for years
        that are both divisible by 100 and not divisible by 400.
    */
    if(month > 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
        daysInEachMonth[1]++;
    }

    //Traverse through each month, get its day and add it into day variable
    //to count number of days. 
    month--; //Ignore the current month's day number. It is stored in day
    while(month > 0){
        day += daysInEachMonth[month - 1];
        month--;
    }

    return day;

}



int main(int argc, char* argv[]){

    if(argc < 4){
        fprintf(stderr, "Run the program using following format: ./dayNumber [month] [day] [year]\n");
        exit(-1);
    }

    printf("Day number is %d\n", CalculateDayOfYear(atoi(argv[1]),atoi(argv[2]),atoi(argv[3])));

    return 0;
}


