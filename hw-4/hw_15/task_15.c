#include <stdio.h>

int main(void){
  int
  x1, y1, x2, y2;
 double k, b;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  if (x1 == x2) {
    printf("Error: straight vertical, equation has x shape = %d\n", x1);
    return 1;
  }
  k = (double)(y2-y1)/(x2-x1);
  b = y1-(k*x1);
  if (b >= 0)
    printf("%.2f %.2f\n", k, b);
  else
    printf(" %.2f -%.2f\n", k, -b);

  return 0;
};