#include <stdio.h>
#define DIVIDER 3
int main(){
    int number_1=0, number_2=0, number_3=0;
    double result_median_value, sum=0;
    scanf("%d %d %d",&number_1, &number_2, &number_3 );
    sum = (number_1 + number_2 + number_3);
    result_median_value = sum / DIVIDER;
    printf("%.2f", result_median_value);
    return 0;
}