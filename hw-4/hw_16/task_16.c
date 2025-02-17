#include <stdio.h>

int main(void){
  int number_1=0, number_2=0, number_3=0;
  scanf("%d %d %d", &number_1 ,&number_2 , &number_3);
  if(number_1<number_3&& number_3>number_2){
    printf("YES");
  }else{
    printf("NO");
  };
  return 0;
};