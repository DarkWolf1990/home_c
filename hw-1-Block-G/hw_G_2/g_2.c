/*
* ____________________
* Строка и цифры
* ___________________
* Считать число N из файла input.txt. Сформировать строку из N символов.
 * N четное число, не превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания,
 * кроме 0, на нечетных позициях - заглавные буквы в порядке следования в английском алфавите.
 * Результат записать в файл output.txt
* __________________
* Input format
* __________________
* Четное N ≤ 26
 *
 * __________________
*  Output format
* ___________________
* Строка из английских букв и цифр
 * */
#include <stdio.h>

int main() {
 int N;
 char result[27] = {0};


 FILE *input_file = fopen("input.txt", "r");
 if (input_file == NULL) {
  printf("Error: file input.txt not found or cannot be opened.\n");
  return 1;
 }


 if (fscanf(input_file, "%d", &N) != 1) {
  printf("Error: unable to read integer from file.\n");
  fclose(input_file);
  return 1;
 }


 fclose(input_file);


 if (N % 2 != 0 || N > 26) {
  printf("Error: N must be an even number not exceeding 26.\n");
  return 1;
 }

 char current_char = 'A';
 int current_digit = 2;

 for (int i = 0; i < N; i++) {
  if (i % 2 == 0) {

   result[i] = current_char++;
  } else {

   result[i] = '0' + current_digit;
   current_digit += 2;
   if (current_digit > 8) {
    current_digit = 2;
   }
  }
 }


 FILE *output_file = fopen("output.txt", "w");
 if (output_file == NULL) {
  printf("Error: unable to open output.txt file for writing.\n");
  return 1;
 }


 fprintf(output_file, "%s\n", result);


 fclose(output_file);

 return 0;
}