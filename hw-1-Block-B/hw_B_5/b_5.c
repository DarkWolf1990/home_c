/*
* _______________
* Сумма цифр
* _______________
*Ввести целое число и найти сумму его цифр.
*
 * _____________________
* Input format
* ______________________
* Одно целое число большее или равное нулю.
 *
 * ______________________
* Output format
* ______________________
*
 * Одно число - сумма цифр
 *
 * */

#include <stdio.h>

int main(void){
 unsigned int number = 0, sum = 0;
 if(scanf("%u", &number)!=1){
  printf("error reading input");
 }
 while(number >0){
  sum += number % 10;
  number /= 10;
 }
 printf("%u", sum);

 return 0;
}
