/*
* ____________________
* Сумма чисел от 1 до N
* _____________________
*
* Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N:
*
 * ____________________
* Input format
* _____________________
*
 * Одно натуральное число
 *
 * _____________________
* Output format
* ______________________
*
 * Сумма чисел от 1 до введенного числа
 * */

#include <stdio.h>
int sumRecursion(int n);

int main(void){
  int n = 0;
  scanf("%d", &n);
  printf("%d",sumRecursion(n));
  return 0;
}

int sumRecursion(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumRecursion(n - 1);
}
