#include <stdio.h>


void display(int * arr){

    for(int i = 0; i < 4; i++){
        if(arr[i] == 0){
            printf("11101110\n");
        }
        else if(arr[i] == 1){
            printf("00100100\n");
        }
        else if(arr[i] == 2){
            printf("10111010\n");
        }
        else if(arr[i] == 3){
            printf("10110110\n");
        }
        else if(arr[i] == 4){
            printf("01110100\n");
        }
        else if(arr[i] == 5){
            printf("11010110\n");
        }
        else if(arr[i] == 6){
            printf("11011110\n");
        }
        else if(arr[i] == 7){
            printf("10100100\n");
        }
        else if(arr[i] == 8){
            printf("11111110\n");
        }
        else if(arr[i] == 9){
            printf("11110110\n");
        }
    }
}


int main()
{
    int sec, hh, mm, ss;
    printf("Enter time in seconds: ");
    scanf("%d", &sec);
    hh = sec/3600;
    mm = (sec - hh*3600)/60;
    ss = sec - hh*3600 - mm*60;
    printf("%d seconds = %d hours : %d minutes : %d seconds", sec, hh % 24, ss, mm);

    hh = hh % 24;

    int time[4] = {hh < 10 ? 0 : hh / 10, hh % 10, mm < 10 ? 0 : ss / 10, ss % 10};

    printf("\n");
    display(time);

    return(0);
}
