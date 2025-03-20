/*
* ___________________
* По одному разу
* __________________
* В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
 * Найдите только те символы слов, которые встречаются в обоих словах только один раз.
 * Напечатайте их через пробел в файл output.txt в лексикографическом порядке.
 *
 * ________________
*  Input format
*  ________________
* Два слова из маленьких английских букв через пробел.
* Длинна каждого слова не больше 100 символов.
 *
 * ______________
*  Output format
*  ______________
* Маленькие английские буквы через пробел.
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 101

int compare_chars(const void *a, const void *b) {
 return (*(char *)a - *(char *)b);
}

int main() {
 char word1[MAX_LEN], word2[MAX_LEN];
 char line[2 * MAX_LEN];
 int freq1[26] = {0}, freq2[26] = {0};
 char result[27];
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

 if (sscanf(line, "%100s %100s", word1, word2) != 2) {
  printf("Error: invalid input format.\n");
  return 1;
 }

 for (int i = 0; word1[i] != '\0'; i++) {
  freq1[word1[i] - 'a']++;
 }
 for (int i = 0; word2[i] != '\0'; i++) {
  freq2[word2[i] - 'a']++;
 }

 for (int i = 0; i < 26; i++) {
  if (freq1[i] == 1 && freq2[i] == 1) {
   result[count++] = 'a' + i;
  }
 }
 result[count] = '\0';

 qsort(result, count, sizeof(char), compare_chars);

 FILE *output_file = fopen("output.txt", "w");
 if (output_file == NULL) {
  printf("Error: unable to open output.txt for writing.\n");
  return 1;
 }

 for (int i = 0; i < count; i++) {
  fprintf(output_file, "%c%c", result[i], (i == count - 1) ? '\n' : ' ');
 }
 fclose(output_file);

 return 0;
}