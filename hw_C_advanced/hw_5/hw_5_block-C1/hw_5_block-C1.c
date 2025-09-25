/*
* Префикс и суффикс
На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки. Каждая из строк не превышает подлине 104. В строках не встречаются пробельные символы. На стандартный поток вывода напечатайте два числа, разделённых пробелом: первое число — длина наибольшего префикса первойстроки, являющегося суффиксом второй; второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксомвторой. Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).

Примеры
Входные данные

don't_panic
nick_is_a_mastodon

Результат работы:
3 3

Входные данные:
monty_python
python_has_list_comprehensions

Результат работы
0 6
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10005

int main(void) {
    char A[MAX_LENGTH], B[MAX_LENGTH];

    // Чтение входных данных
    fgets(A, MAX_LENGTH, stdin);
    fgets(B, MAX_LENGTH, stdin);

    // Удаляем символы новой строки
    A[strcspn(A, "\n")] = '\0';
    B[strcspn(B, "\n")] = '\0';

    int lenA = strlen(A);
    int lenB = strlen(B);

    int result1 = 0, result2 = 0;

    // Часть 1: префикс A = суффикс B
    int max_len = (lenA < lenB) ? lenA : lenB;
    for (int L = max_len; L > 0; L--) {
        // Сравниваем префикс A длины L с суффиксом B длины L
        if (strncmp(A, B + lenB - L, L) == 0) {
            result1 = L;
            break;
        }
    }

    // Часть 2: суффикс A = префикс B
    for (int L = max_len; L > 0; L--) {
        // Сравниваем суффикс A длины L с префиксом B длины L
        if (strncmp(A + lenA - L, B, L) == 0) {
            result2 = L;
            break;
        }
    }

    printf("%d %d\n", result1, result2);

    return 0;
}
