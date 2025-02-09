#include <stdio.h>

int main(){
    int number_1, number_2, number_3, result_sum, result_multy;
    scanf("%d %d %d",&number_1, &number_2, &number_3 );
    result_sum = number_1+number_2+number_3;
    result_multy = number_1*number_2*number_3;
    printf("%d+%d+%d=%d\n",number_1,number_2,number_3,result_sum);
    printf("%d*%d*%d=%d",number_1,number_2,number_3,result_multy);
    return 0;
}