#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2048
#define MAX_NUM_TAX_VALUES 10

int parseLineAndPutIntoIntArray(char * str, int * array){
    const char s[2] = ",";
    char *token;
    int index = 0;
    token = strtok(str, s);
    while( token != NULL ) {
        array[index++] = atoi(token);
        token = strtok(NULL, s);
    }
    return index;
}

void fileRead(char * filename, int * values, int * percentage, int * len){
    FILE * fp = fopen(filename,"r");
    char str[MAX_LINE_LENGTH];
    if(fp == NULL) {
      perror("Error opening file");
      exit(-1);
    }
    int line = 0;
    while(fgets (str, MAX_LINE_LENGTH, fp)){
        if (line == 0){
            *len = parseLineAndPutIntoIntArray(str, values);
        }
        else{
            *len = parseLineAndPutIntoIntArray(str, percentage);
        }
        line++;
    }
    fclose(fp);
}

float calculateTax(int * values, int len,int * percentage, int salary){

    int aralik;
    float tax = 0;
    for(int i = 1; i < len; i++){
        aralik = values[i] - values[i - 1];
        if(aralik <= salary){
            salary -= aralik; 
            printf("aralik: %d\n",aralik);
            printf("salary: %d\n",salary);
            tax += aralik * (float)percentage[i-1] / 100;
            printf("tax: %f\n",tax);
        }
        else{
            tax += salary * (float)percentage[i-1] / 100;
            printf("else tax: %f\n",tax);
            break;
        }
    }
    return tax;

}

int main(int argc, char *argv[]){

    int values[MAX_NUM_TAX_VALUES];
    int percentage[MAX_NUM_TAX_VALUES];
    int len;
    int salary = atoi(argv[1]);
    fileRead("values.txt",values,percentage, &len);
    printf("%.2f\n", calculateTax(values, len, percentage, salary));

}