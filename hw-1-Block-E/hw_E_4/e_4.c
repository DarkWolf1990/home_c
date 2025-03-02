/*
* ____________________
* Два максимума
* ___________________
*
 * Считать массив из 10 элементов
 * и найти в нем два максимальных элемента и напечатать их сумму.
 *
* _____________________
* Input format
* _____________________
*
* 10 целых чисел через пробел.
 *
 * ________________
* Output format
* _________________
*
 * Сумма двух максимальных элементов.
 *  */

#include <stdio.h>
#include <limits.h>

int main(void){
    const int  n=10;
    int numbers[n], max_1 = INT_MIN, max_2 = INT_MIN;

    for(int i = 0; i < n; i++) {
        scanf("%d",&numbers[i]);
    }

    for (int i = 0; i < n; i++) {
        if (numbers[i] > max_1){
            max_2 = max_1;
            max_1 = numbers[i];
        } else if (numbers[i] >= max_2){
            max_2 = numbers[i];
        }

    }

    printf("%d\n",max_1 + max_2);

    return 0;
}
