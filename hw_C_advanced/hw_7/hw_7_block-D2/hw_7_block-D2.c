/*
* Найти брата
В программе описано двоичное дерево:
typedef struct tree {
datatype key;
struct tree *left, *right;
struct tree *parent; //ссылка на родителя
} tree;
Требуется реализовать функцию, которая по ключу возвращает адрес соседнего элемента - брата. Если такого ключа нет или у узла нет брата, то необходимо вернуть 0.
Прототип функции:
//translate Найти брата
It is required to implement a function that returns the address of a neighboring element - the brother - by key. If there is no such key or the node has no brother, then return 0.
Function prototype:
В программе описано двоичное дерево:
tree * findBrother(tree *root, int key)

Examples
Input

10 5 15 3 7 13 18 1 6 14 0 3

Output

7
 */
#include <stdio.h>
#include <stdlib.h>

// структура
typedef struct tree {
    int key;
    struct tree *left, *right, *parent;
} tree;

// прототипы
tree * findBrother(tree *root, int key);
tree * searchNode(tree *node, int key);
tree * getSibling(tree *node);
tree* newNode(int key, tree* parent);

// создание нового узла
tree* newNode(int key, tree* parent) {
    tree* node = (tree*)malloc(sizeof(tree));
    node->key = key;
    node->left = node->right = NULL;
    node->parent = parent;
    return node;
}

// функция поиска брата
tree * findBrother(tree *root, int key) {
    if (root == NULL) return NULL;
    tree *target = searchNode(root, key);
    if (target == NULL) return NULL;
    return getSibling(target);
}

// рекурсивный поиск узла
tree * searchNode(tree *node, int key) {
    if (node == NULL) return NULL;
    if (key == node->key) return node;

    tree *left = searchNode(node->left, key);
    if (left != NULL) return left;

    return searchNode(node->right, key);
}

// получение брата
tree * getSibling(tree *node) {
    if (node == NULL || node->parent == NULL) return NULL;

    tree *parent = node->parent;
    if (parent->left == node) {
        return parent->right;
    } else {
        return parent->left;
    }
}


int main() {
    // строим дерево вручную
    tree* root = newNode(10, NULL);
    root->left = newNode(5, root);
    root->right = newNode(15, root);

    root->left->left = newNode(3, root->left);
    root->left->right = newNode(7, root->left);
    root->right->left = newNode(13, root->right);
    root->right->right = newNode(18, root->right);

    root->left->left->left = newNode(1, root->left->left);
    root->left->right->left = newNode(6, root->left->right);
    root->right->left->right = newNode(14, root->right->left);

    int key = 3;
    tree* brother = findBrother(root, key);

    if (brother != NULL) {
        printf("Брат узла %d -> %d\n", key, brother->key);
    } else {
        printf("У узла %d нет брата или он не найден.\n", key);
    }

    return 0;
}
