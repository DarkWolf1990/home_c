/*
__________
Три раза
__________
В файле input.txt дана строка. Вывести ее в файл output.txt
три раза через запятую и показать количество символов в ней.
________________
Input format
________________
Строка из английских букв и пробелов. Не более 100 символов.
В конце могут быть незначащие переносы строк.
_________________
Output format
_________________
Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.
    */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim_trailing_whitespace(char* str) {
    int length = strlen(str);
    while (length > 0 && (isspace(str[length - 1]) || str[length - 1] == '\n' || str[length - 1] == '\r')) {
        str[length - 1] = '\0';
        length--;
    }
}

int main() {
    char line[101];

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


    trim_trailing_whitespace(line);

    fclose(input_file);


    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: unable to open output.txt file for writing.\n");
        return 1;
    }


    int symbol_count = strlen(line);


    fprintf(output_file, "%s, %s, %s %d\n", line, line, line, symbol_count);


    fclose(output_file);

    return 0;
}