/*
 Задача 7-2-Вид сверху
 В программе описана структура для хранения двоичного дерева:
 typedef struct tree {
     datatype key;
         struct tree *left, *right;

 } tree;
Необходимо реализовать функцию, которая печатает вид дерева сверху. Функция должна строго соответствовать прототипу: void btUpView(tree *root)
В качестве ответа загрузите только одну функцию void btUpView(tree *root)
Пример №1
Данные на входе:

       10
     /   \
   5     15
  / \   /  \
 3   7 13   18
/   /
1   6

*/
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int32_t datatype;
typedef struct tree {
    datatype key;
    struct tree *left, *right;

} tree;

void insert(tree **root, datatype key);
void get_left(tree *root);
void get_right(tree *root);
void btUpView(tree *root);

int main() {
    tree *own_tree = NULL;
    insert(&own_tree, 10);
    insert(&own_tree, 5);
    insert(&own_tree, 15);
    insert(&own_tree, 3);
    insert(&own_tree, 7);
    insert(&own_tree, 13);
    insert(&own_tree, 18);
    insert(&own_tree, 1);
    insert(&own_tree, 6);
    btUpView(own_tree);
}

void btUpView(tree *root) {
    get_left(root);
    if(root->right) {
        get_right(root->right);
    }
    printf("\n");
}

void get_left(tree *root) {
    if(root->left) {
        get_left(root->left);
    }
    printf("%d ", root->key);
}

void get_right(tree *root) {
    printf("%d ", root->key);
    if(root->right) {
        get_left(root->right);
    }
}

void insert(tree **root, datatype key) {
    if(!*root) {
        *root = (tree *) calloc(1, sizeof(tree));
        (*root)->key = key;
    }
    else if((*root)->key < key) {
        insert(&(*root)->right, key);
    }
    else {
        insert(&(*root)->left, key);
    }
}
