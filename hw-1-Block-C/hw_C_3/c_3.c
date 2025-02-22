/*
*
 * ____________________________
* Среднее арифметическое чисел
* _____________________________
*
 * Написать функцию, которая возвращает среднее арифметическое
*  двух переданных ей аргументов (параметров).
 * int middle(int a, int b)
*
 * _______________
* Input format
* _______________
*
* Два целых не отрицательных числа
 *
 * ______________
* Output format
* _______________
*
 * Одно целое число
 * */

#include <stdio.h>

int middle(int a, int b);

int main(void){
  int a=0, b=0;
  scanf("%d %d", &a, &b);
  if(a<0 || b<0){
    printf("Input wrong data");
   return 1;
  }
 printf("%d",middle(a, b));
  return 0;
}

int middle(int a, int b){
  const int DEVIZOR = 2;
  int average = (a+b) / DEVIZOR;
  return average;
}
