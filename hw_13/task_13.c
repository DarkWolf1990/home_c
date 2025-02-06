#include <stdio.h>
#define SEPARATOR_10 10
#define SEPARATOR_100 100
int main(void){
    int number, first_number=0, second_number=0, third_number=0, res=0;
    scanf("%d",&number);
    first_number = number%SEPARATOR_10;
    second_number= number%SEPARATOR_100/SEPARATOR_10;
    third_number= number/SEPARATOR_100;
    res = first_number *  second_number * third_number;
    printf("%d\n", res);
    return 0;
}