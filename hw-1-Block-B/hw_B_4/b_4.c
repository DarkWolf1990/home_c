/*
* __________________________
* Ровно три цифры
 * ________________________
*
 * Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
 *
 * _______________
* Input format
* ________________
*
 * Целое положительное число
 *
 * _______________
* Output format
* ________________
*
 * Одно слов: YES или NO
* */

#include <stdio.h>
#define LIMITR_1 100
#define LIMITR_2 999
int main(void){
  int number = 0;
  if(scanf("%d", &number)!=1){
    printf("error reading input");
  }
  if(number >=LIMITR_1 && number <=LIMITR_2){
    printf("YES");
  }
  else {
  printf("NO");
  }
  return 0;
}

