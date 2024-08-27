/*
Задача 7-3-Найти брата
В программе описано двоичное дерево:
typedef struct tree {
    datatype key;
        struct tree *left, *right;
        struct tree *parent; //ссылка на родителя
                 //
} tree;
Требуется реализовать функцию, которая по ключу возвращает адрес соседнего элемента - брата.
Если такого ключа нет или у узла нет брата, то необходимо вернуть 0.
Прототип функции: tree * findBrother(tree *root, int key)

Загрузите в качестве ответа только текст функции, строго согласно прототипу: tree * findBrother(tree *root, int key)
Пример №1
Данные на входе:

        10
       /   \
      5     15
     / \   /  \
    3   7 13   18
   /   /
  1   6

Например, для дерева узел с ключом 5
Данные на выходе: имеет брата 15
*/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int32_t datatype;
typedef struct tree {
    datatype key;
    struct tree *left, *right;
    struct tree *parent;
} tree;

void insert(tree **root, datatype key, tree *pt);
void get_left(tree *root);
void get_right(tree *root);
void btUpView(tree *root);
void findBrother(tree *root, int key);

int main() {
    tree *own_tree = NULL;
    insert(&own_tree, 10, NULL);
    insert(&own_tree, 5, NULL);
    insert(&own_tree, 15, NULL);
    insert(&own_tree, 3, NULL);
    insert(&own_tree, 7, NULL);
    insert(&own_tree, 13, NULL);
    insert(&own_tree, 18, NULL);
    insert(&own_tree, 1, NULL);
    insert(&own_tree, 6, NULL);

    findBrother(own_tree, 5);
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

tree *find_key(tree *root, datatype key) {
    tree *tmp = NULL;
    if(root) {
        if(root->key < key) {
            tmp = find_key(root->right, key);
        }
        else if(root->key > key) {
            tmp = find_key(root->left, key);
        }
        else {
            tmp = root;
        }
    }
    return tmp;
}

void findBrother(tree *root, datatype key) {
    tree *fnd;
    fnd = find_key(root, key);
    if(fnd) {
        if(fnd->parent->right && fnd->parent->right != fnd) {
            printf("%d\n", fnd->parent->right->key);
        }
        else if(fnd->parent->left && fnd->parent->left != fnd) {
            printf("%d\n", fnd->parent->left->key);
        }
        else {
            printf("0\n");
        }
    }
}


void insert(tree **root, datatype key, tree *pt) {
    if(!*root) {
        *root = (tree *) calloc(1, sizeof(tree));
        (*root)->key = key;
        (*root)->parent = pt;
    }
    else if((*root)->key < key) {
        insert(&(*root)->right, key, *root);
    }
    else {
        insert(&(*root)->left, key, *root);
    }
}
