/*
* ________________________
* В двоичную систему
* ________________________
*
 * Перевести натуральное число в двоичную систему счисления.
 * Необходимо реализовать рекурсивную функцию.
 *
 * _______________________
* Input format
* ________________________
*
 * Целое не отрицательное число в десятичной системе счисления
 *
 * ______________
* Output format
* _______________
*
 * Целое число в двоичной системе счисления
 * */

#include <stdio.h>

void convertingBinarySystem(int num);

int main(void){
  int num =0;
  scanf("%d",&num);
  if (num == 0) {
  printf("0");
 } else {
  convertingBinarySystem(num);
 }
 return 0;
}

void convertingBinarySystem(int num){
const int DIVISOR = 2;
 if (num == 0) {
  return;
 }
 convertingBinarySystem(num / DIVISOR);
 printf("%d", num % DIVISOR);
}