/*
* Польская запись
Необходимо вычислить выражение написанное в обратной польской записи. На вход подается строка состоящая из целых, неотрицательных чисел и арифметических символов. В ответ единственное целое число - результат. Более подробно об Обратной польскаязапись числа можно также почитать тут

Примеры
Входные данные
3 4 +.

Результат работы
7

Входные данные
1 2 + 4 × 3 +.

Результат работы
15

Входные данные
100 25 + 25 /.

Результат работы
5

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 1000

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = value;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return 0;
}

int is_operator(const char* token) {
    return (strlen(token) == 1 &&
           (token[0] == '+' || token[0] == '-' ||
            token[0] == '*' || token[0] == '/'))
           || (strcmp(token, "×") == 0);
}

int main(void) {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    // Используем точку как разделитель конца выражения
    char* token = strtok(input, " .\n");

    while (token != NULL) {
        if (isdigit(token[0])) {
            push(atoi(token));
        } else if (is_operator(token)) {
            int b = pop();
            int a = pop();
            int result;

            if (strcmp(token, "×") == 0) {
                result = a * b;
            } else {
                switch (token[0]) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/': result = a / b; break;
                    default: result = 0;
                }
            }

            push(result);
        }
        token = strtok(NULL, " .\n");
    }

    printf("%d\n", pop());
    return 0;
}

