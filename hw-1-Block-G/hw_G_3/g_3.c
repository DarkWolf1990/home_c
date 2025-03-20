/*
* _______________________
* Последний номер символа
* _______________________
* В файле input.txt дана строка из не более 1000 символов.
* Показать номера символов, совпадающих с последним символом строки.
Результат записать в файл output.txt
*
* _______________
* Input format
* _______________
* Строка из не более 1000 символов
*
* ________________
* Output format
* _______________
* Целые числа через пробел - номера символа, который совпадает с последним символом строки.
 * */

#include <stdio.h>
#include <string.h>

int main() {
    char line[1001];
    int indices[1000];
    int count = 0;

    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: file input.txt not found or cannot be opened.\n");
        return 1;
    }

    if (fgets(line, sizeof(line), input_file) == NULL) {
        printf("Error: unable to read string from file.\n");
        fclose(input_file);
        return 1;
    }

    fclose(input_file);

    line[strcspn(line, "\n")] = '\0';

    int length = strlen(line);
    if (length == 0) {
        printf("Error: the string is empty.\n");
        return 1;
    }

    char last_char = line[length - 1];

    for (int i = 0; i < length - 1; i++) {
        if (line[i] == last_char) {
            indices[count++] = i; // Нумерация с 0
        }
    }

    // Запись в файл
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: unable to open output.txt for writing.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(output_file, "%d%c", indices[i], (i == count - 1) ? '\n' : ' ');
    }

    fclose(output_file);

    return 0;
}
