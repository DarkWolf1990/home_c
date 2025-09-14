/*
* Всего памяти
Описана структура данных для хранения информации об использованной памяти:
typedef struct list {
void *address;
size_t size;
char comment[64];
struct list *next;
} list;
Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется. Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0.

Прототип функции:
size_t totalMemoryUsage(list *head)

Примеры
Входные данные:
3
      140525067852320 10
      140525067852350 30
      140525067852900 100

Результат работы:
140

 */

#include <stdio.h>

size_t totalMemoryUsage(list *head) {
    size_t total_size = 0;
    list *current = head;

    while (current != NULL) {
        total_size += current->size;
        current = current->next;
    }

    return total_size;
}