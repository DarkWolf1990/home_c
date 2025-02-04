#include <stdio.h>

int main(){
    int number_1=0, number_2=0;
    scanf("%d %d",&number_1, &number_2);
    if (number_1>number_2) {
        printf("%d %d", number_2, number_1);
    }
    else {
        printf("%d %d", number_1, number_2);
    }

    return 0;
}