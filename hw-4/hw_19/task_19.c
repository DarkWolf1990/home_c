#include <stdio.h>

int main(void){
  int side_a=0, side_b=0, side_c=0;
  scanf("%d %d %d",&side_a, &side_b, &side_c);
  if (side_a + side_b > side_c &&
       side_a + side_c > side_b &&
       side_b + side_c > side_a) {
    printf("YES\n");
       } else {
           printf("NO\n");
       }
};