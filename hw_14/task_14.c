#include <stdio.h>
#include <limits.h>

#define SEPARATOR_10 10
#define SEPARATOR_100 100
#define N 3

int main(void) {
    int number, first_number, second_number, third_number, max = INT_MIN;


    scanf("%d", &number);


    first_number = number % SEPARATOR_10;
    second_number = (number % SEPARATOR_100) / SEPARATOR_10;
    third_number = number / SEPARATOR_100;

    int arr[N] = {first_number, second_number, third_number};


    for (int i = 0; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }


    printf("%d\n", max);

    return 0;
}
