#include <stdio.h>

int main(void){
  int month=0;
  scanf("%d", &month);
  switch (month) {
    case 1:
    case 2:
    case 12:
      printf("winter");
         break;
    case 3:
    case 4:
    case 5:

      printf("spring");
        break;
    case 6:
    case 7:
    case 8:
      printf("summer");
         break;
    case 9:
    case 10:
    case 11:

       printf("autumn");
         break;
    default:
      printf("There’s no such month");
}
  return 0;
};