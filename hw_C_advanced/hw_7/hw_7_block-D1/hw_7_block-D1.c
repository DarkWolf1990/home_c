/*
* Вид сверху
В программе описана структура для хранения двоичного дерева:
// The program describes a structure for storing a binary tree:
typedef struct tree {
datatype key;
struct tree *left, *right;
} tree;

//It is necessary to implement a function that prints the top view of the tree. The function must strictly conform to the prototype:
Необходимо реализовать функцию, которая печатает вид дерева сверху. Функция должна строго соответствовать прототипу:
void btUpView(tree *root)

Examples

input

10 5 15 3 7 13 18 1 6 14 0

Output

1 3 5 10 15 18

 */



typedef struct queue_node {
    tree *node;
    int hd; // горизонтальное расстояние
} queue_node;

void btUpView(tree *root) {
    if (root == NULL) return;

    int left_min = 0, right_max = 0;

    // Первый проход – определяем диапазон hd
    queue_node *queue = (queue_node*)malloc(1000 * sizeof(queue_node));
    int front = 0, rear = 0;

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    while (front < rear) {
        queue_node current = queue[front++];

        if (current.hd < left_min) left_min = current.hd;
        if (current.hd > right_max) right_max = current.hd;

        if (current.node->left != NULL) {
            queue[rear].node = current.node->left;
            queue[rear].hd = current.hd - 1;
            rear++;
        }

        if (current.node->right != NULL) {
            queue[rear].node = current.node->right;
            queue[rear].hd = current.hd + 1;
            rear++;
        }
    }
    free(queue);

    int size = right_max - left_min + 1;
    int *topView = (int*)malloc(size * sizeof(int));
    int *visited = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        visited[i] = 0;
        topView[i] = 0;
    }

    // Второй проход – сохраняем первое посещённое значение по hd
    queue_node *queue2 = (queue_node*)malloc(1000 * sizeof(queue_node));
    front = 0, rear = 0;

    queue2[rear].node = root;
    queue2[rear].hd = 0;
    rear++;

    while (front < rear) {
        queue_node current = queue2[front++];
        int index = current.hd - left_min;

        if (!visited[index]) {
            topView[index] = current.node->key;
            visited[index] = 1;
        }

        if (current.node->left != NULL) {
            queue2[rear].node = current.node->left;
            queue2[rear].hd = current.hd - 1;
            rear++;
        }
        if (current.node->right != NULL) {
            queue2[rear].node = current.node->right;
            queue2[rear].hd = current.hd + 1;
            rear++;
        }
    }

    free(queue2);

    // Печатаем результат без лишнего пробела
    int first = 1;
    for (int i = 0; i < size; i++) {
        if (visited[i]) {
            if (!first) printf(" ");
            printf("%d", topView[i]);
            first = 0;
        }
    }
    printf("\n");

    free(topView);
    free(visited);
}