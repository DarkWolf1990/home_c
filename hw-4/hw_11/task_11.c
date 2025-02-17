#include <stdio.h>
#include <limits.h>
#define N 5

int main() {
    int num, max = INT_MIN, min = INT_MAX;


    for (int i = 0; i < N; i++) {
        scanf("%d", &num);

        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }

    printf("%d", max+min);
    return 0;
}