#include <stdio.h>
# define N 3
int main(){
    int number_1=0, number_2=0, number_3=0, max=0;
    scanf("%d %d %d",&number_1, &number_2, &number_3 );
    if (number_1>=number_2 && number_1 >= number_3) {
        max = number_1;
        printf("%d", max);
    }
    if (number_1<=number_2 && number_2 <= number_3){
        max = number_3;
        printf("%d", max);
    }
    if (number_1<=number_2 && number_2 >= number_3){
        max = number_2;
        printf("%d", max);
    }


    return 0;
}