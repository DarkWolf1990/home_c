/*
* Отсортировать слова
Дана строка, состоящая из английских букв и пробелов. В конце строки символ точка. Все слова разделены одним пробелом. Необходимо составить из слов односвязный список и упорядочить по алфавиту. Список необходимо удалить в конце программы. Для сравнение строк можно использовать strcmp. Необходимо использовать данную структуры организации списка.
// A string is given, consisting of English letters and spaces. There is a period at the end of the string. All words are separated by a single space. It is necessary to create a singly linked list from the words and sort them alphabetically. The list must be deleted at the end of the program. For string comparison, you can use strcmp. You must use the given list structure:
struct list {
char word[20];
struct list *next;
}
Необходимо реализовать односвязный список и обслуживающие его функции.
add_to_list
 swap_elements
 print_list
 delete_list

Примеры
Входные данные

efg abcd zzz.

Результат работы
abcd efg zzz

Входные данные
fffff kkkkkk a.

Результат работы
a fffff kkkkkk
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
 char word[20];
 struct list *next;
};

// func to add a word to the list
struct list* add_to_list(struct list *head, const char *word) {
 struct list *new_node = (struct list*)malloc(sizeof(struct list));
 strcpy(new_node->word, word);
 new_node->next = NULL;

 if (head == NULL) {
  return new_node;
 }
 struct list *current = head;
 while (current->next != NULL){
  current = current -> next;
 }
 current->next = new_node;
 return head;
}

// func to swap to data between two nodes

void swap_elements(struct list *a, struct list *b) {
 char temp[20];
 strcpy(temp, a->word);
 strcpy(a->word, b->word);
 strcpy(b->word, temp);
}

// func to print the list

void print_list(struct list *head) {
 struct list *current = head;
 while (current != NULL) {
  printf("%s", current->word);
  if (current->next != NULL) {
   printf(" ");
  }
  current = current->next;
 }
 printf("\n");
}

// func to delete the entire list
void delete_list(struct list *head) {
 struct list *current = head;
 while (current != NULL) {
  struct list *temp = current;
  current = current->next;
  free(temp);
 }
}

// func to sort the list using bubble sort
struct list* sort_list(struct list *head) {
 if (head == NULL || head->next == NULL) {
  return head;
 }

 int swapped;
 struct list *ptr1;
 struct list *lptr = NULL;

 do {
  swapped = 0;
  ptr1 = head;

  while (ptr1->next != lptr) {
   if (strcmp(ptr1->word, ptr1->next->word) > 0) {
    swap_elements(ptr1, ptr1->next);
    swapped = 1;
   }
   ptr1 = ptr1->next;
  }
  lptr = ptr1;
 } while (swapped);

 return head;
}

int main(int argc, char* argv[]) {
 struct list *head = NULL;
 char word[20];
 char ch;
 int word_index = 0;

 // Read input until we reach '.'
 while ((ch = getchar()) != '.') {
  if (ch == ' ' || ch == '\n') {
   if (word_index > 0) {
    word[word_index] = '\0';
    head = add_to_list(head, word);
    word_index = 0;
   }
  } else {
   if (word_index < 19) { // Leave space for null terminator
    word[word_index++] = ch;
   }
  }
 }

 // Add the last word before '.'
 if (word_index > 0) {
  word[word_index] = '\0';
  head = add_to_list(head, word);
 }

 // Sort the list
 head = sort_list(head);

 // Print the sorted list
 print_list(head);

 // Clean up memory
 delete_list(head);

 return 0;
}
