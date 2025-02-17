#include <stdio.h>

int main(void){
  int number_1=0, number_2=0;
  scanf("%d %d",&number_1, &number_2);
  if(number_1>number_2){
    printf("Above");
  };
  if(number_1<number_2){
    printf("Less");
  };
 if (number_1==number_2){
   printf("Equal");
 }
  return 0;
};
