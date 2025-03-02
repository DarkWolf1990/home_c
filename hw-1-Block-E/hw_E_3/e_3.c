/*
* _____________________
 *Максимум и минимум
* ____________________
*
 * Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
 *
 * ___________________
 * Input format
 * ___________________
 *
 * 10 целых чисел через пробел
 *
 *_________________
 * Output format
 * ________________
 *
 * 4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.
 * */
#include <stdio.h>

int main(void){
    int  n=10;
    int numbers[n], min=0, max=0;
    int minIndex = 0, maxIndex = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d",&numbers[i]);
    }
    min = numbers[0];
    max = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] < min){
            min = numbers[i];
            minIndex = i;
        }

    }
    for (int j = 1; j < n; j++) {
        if (numbers[j] > max){
            max = numbers[j];
            maxIndex = j;
        }

    }
    printf("%d %d %d %d",maxIndex+1, max, minIndex+1, min);

    return 0;
}