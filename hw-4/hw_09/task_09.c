#include <stdio.h>
#include <limits.h>
#define N 5

int main() {
    int num, max = INT_MIN;


    for (int i = 0; i < N; i++) {
        scanf("%d", &num);

        if (num > max) {
            max = num;
        }
    }

    printf("%d", max);
    return 0;
}