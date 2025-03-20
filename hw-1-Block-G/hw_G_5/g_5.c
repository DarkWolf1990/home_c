/*
* ________________
* Заменить a на b
* ________________
* В файле input.txt дана символьная строка не более 1000 символов.
 * Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные,
 * так и строчные. Результат записать в output.txt.
 * _______________
*  Input format
*  ________________
*  Строка из маленьких и больших английских букв, знаков препинания и пробелов.
*  ________________
 *  Output format
*  ________________
*  Строка из маленьких и больших английских букв, знаков препинания и пробелов.
 *
 * */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001

int main() {
 char line[MAX_LEN];

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

 for (int i = 0; line[i] != '\0'; i++) {
  if (line[i] == 'a') line[i] = 'b';
  else if (line[i] == 'b') line[i] = 'a';
  else if (line[i] == 'A') line[i] = 'B';
  else if (line[i] == 'B') line[i] = 'A';
 }

 FILE *output_file = fopen("output.txt", "w");
 if (output_file == NULL) {
  printf("Error: unable to open output.txt for writing.\n");
  return 1;
 }
 fprintf(output_file, "%s", line);
 fclose(output_file);

 return 0;
}