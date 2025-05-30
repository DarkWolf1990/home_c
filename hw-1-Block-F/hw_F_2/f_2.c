/*
* _____________________
 * Четные в начало
 * _____________________
 *
 * Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные.
 * Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:
 * void sort_even_odd(int n, int a[])
 *
 * ____________________
 * Input format
 * ____________________
 *
 * Функцийя принмате на вход целые числа
 *
 *
 * ____________________
 * Output format
 * ____________________
 *
 * Отсортированный исходный массив
 *
 *
 * */
void sort_even_odd(int n, int a[]) {
    int temp[n];
    int even_count = 0, odd_count = 0;


    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[even_count++] = a[i];
        }
    }


    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            temp[even_count + odd_count++] = a[i];
        }
    }


    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}
