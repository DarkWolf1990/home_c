/*
* ________________________________
* Среднее арифметическое чисел
* _______________________________
*
* Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.
 *
 * __________________
* Input format
* ___________________
*
 * 5 целых не нулевых чисел через пробел
 *
 * ____________________
* Output format
* _____________________
*
 * Одно число в формате "%.3f"
 * */

#include <stdio.h>

int main(void){
  int const DIVISOR = 5;
  int number_1 = 0, number_2=0, number_3=0, number_4 = 0, number_5 =0;

 double arithmetic_mean=0;
  scanf("%d %d %d %d %d", &number_1, &number_2, &number_3, &number_4, &number_5);
  arithmetic_mean = (double)(number_1+number_2+number_3+number_4+number_5)/DIVISOR;
  printf("%.3f",arithmetic_mean);
  return 0;
}
