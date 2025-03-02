/*
*__________________
* Найти минимум
* ________________
*
 * Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.
 *
 * ________________
* Input format
* _________________
*
 * 5 целых чисел через пробел
 *
 * ________________
* Output format
* ________________
*
 * Одно единственное целое число
*  */

#include <stdio.h>

int main(void){
 int  n=5;
int numbers[n], min=0;

for(int i = 0; i < n; i++) {
 scanf("%d",&numbers[i]);
}
 min = numbers[0];
for (int i = 1; i < n; i++) {
 if (numbers[i] < min){
  min = numbers[i];
}
 }
 printf("%d",min);

 return 0;
}