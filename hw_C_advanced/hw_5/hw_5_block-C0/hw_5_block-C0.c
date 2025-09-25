/*
* Вычеркивание
Сколько различных трехзначных чисел можно получить из заданного натурального N, вычеркивая цифры из его десятичной записи?

Примеры
Входные данные
1111111111111111111111111

Результат работы
1
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH         100
#define NUMBER_OF_DIGITS         10
#define REQUIRED_LENGTH          3
#define HUNDREDS_MULTIPLIER      100
#define TENS_MULTIPLIER          10
#define MIN_THREE_DIGIT_NUMBER   100
#define MAX_THREE_DIGIT_NUMBER   999
#define FIRST_DIGIT_MIN          1
#define FIRST_DIGIT_MAX          9
#define ZERO_ASCII               '0'

int main(void) {
 char input_string[MAX_INPUT_LENGTH + 1];
 scanf("%100s", input_string);
 int string_length = strlen(input_string);

 int unique_numbers[MAX_THREE_DIGIT_NUMBER + 1] = {0};
 int unique_count = 0;

 for (int first_pos = 0; first_pos < string_length; first_pos++) {
  // Пропускаем нули на первой позиции
  if (input_string[first_pos] == ZERO_ASCII) continue;

  for (int second_pos = first_pos + 1; second_pos < string_length; second_pos++) {
   for (int third_pos = second_pos + 1; third_pos < string_length; third_pos++) {
    int number = (input_string[first_pos] - ZERO_ASCII) * HUNDREDS_MULTIPLIER +
                (input_string[second_pos] - ZERO_ASCII) * TENS_MULTIPLIER +
                (input_string[third_pos] - ZERO_ASCII);

    if (number >= MIN_THREE_DIGIT_NUMBER && number <= MAX_THREE_DIGIT_NUMBER) {
     if (!unique_numbers[number]) {
      unique_numbers[number] = 1;
      unique_count++;
     }
    }
   }
  }
 }

 printf("%d\n", unique_count);
 return 0;
}