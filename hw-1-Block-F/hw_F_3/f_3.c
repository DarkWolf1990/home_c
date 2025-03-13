/**/



#include <stdio.h>
#include <string.h>

void count_digits(const char *number) {
    int freq[10] = {0};


    for (int i = 0; number[i] != '\0'; i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            freq[number[i] - '0']++;
        }
    }


    for (int i = 0; i < 10; i++) {
        if (freq[i] > 0) {
            printf("%d %d\n", i, freq[i]);
        }
    }
}

int main() {
    char number[1001];


    if (scanf("%1000s", number) != 1) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    count_digits(number);

    return 0;
}
