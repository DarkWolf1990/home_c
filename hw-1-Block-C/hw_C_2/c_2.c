/*
____________________
* Возвести в степень
_____________________

Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.

______________________
Input format
______________________

Два целых числа: N по модулю не превосходящих 1000 и P ≥ 0

______________________
Output format
______________________

Одно целое число
*/

#include <stdio.h>
#include <math.h>
#define MAX 1000
int power(int n, int p);

int main(void){
   int n, p;
    if (scanf("%d %d", &n, &p) != 2) {
        fprintf(stderr, "error input:\n");
        return 1;
    }
    if (abs(n) > MAX || p < 0) {
        fprintf(stderr, "Values entered do not meet the condition!\n");
        return 1;
    }
  printf("%d", power(n, p));
  return 0;
}


int power(int n, int p){
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }

    return result;
}
