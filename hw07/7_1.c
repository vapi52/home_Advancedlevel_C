/*
 * Задача 7-1-Отсортировать слова
 * Дана строка, состоящая из английских букв и пробелов. В конце строки символ точка.
 * Все слова разделены одним пробелом. Необходимо составить из слов односвязный список
 * и упорядочить по алфавиту.
 * Список необходимо удалить в конце программы. Для сравнение строк можно использовать strcmp.
 * Необходимо использовать данную структуры организации списка.
 * struct list {
 *   char word[20];
 *   struct list *next;
 * }

 * Необходимо реализовать односвязный список и обслуживающие его функции.
 * add_to_list swap_elements print_list delete_list
 * Формат ввода:
 * Строка из английских символов 'a'-'z' и пробелов. В конце строки символ '.'.
 * Длина строки не более 1000 символов.
 * Формат вывода:
 * Упорядоченные по алфавиту слова.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char word[20];
    struct list *next;
} list;

void add_to_list(list **head, const char *word);
void swap_elements(list *a, list *b);
void sort_list(list *head);
void print_list(list *head);
void delete_list(list *head);

int main() {
    list *head = NULL;
    char input[1001];
    char *word;
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }
    if (input[len - 1] == '.') {
        input[len - 1] = '\0';
    }
    word = strtok(input, " ");
    while (word != NULL) {
        add_to_list(&head, word);
        word = strtok(NULL, " ");
    }
    sort_list(head);
    print_list(head);
    delete_list(head);

    return 0;
}

void add_to_list(list **head, const char *word) {
    list *new = (list *)malloc(sizeof(list));
    strcpy(new->word, word);
    new->next = *head;
    *head = new;
}

void swap_elements(list *a, list *b) {
    char temp[20];
    strcpy(temp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, temp);
}

void sort_list(list *head) {
    list *actual, *next;
    int exchanged;

    if (head == NULL) {
        return;
    }

    do {
        exchanged = 0;
        actual = head;

        while (actual->next != NULL) {
            next = actual->next;
            if (strcmp(actual->word, next->word) > 0) {
                swap_elements(actual, next);
                exchanged = 1;
            }
            actual = next;
        }
    } while (exchanged);
}

void print_list(list *head) {
    list *actual = head;
    int initial = 1;
    while (actual != NULL) {
        if (!initial) {
            printf(" ");
        }
        printf("%s", actual->word);
        initial = 0;
        actual = actual->next;
    }
    printf("\n");
}

void delete_list(list *head) {
    list *actual = head;
    list *next;

    while (actual != NULL) {
        next = actual->next;
        free(actual);
        actual = next;
    }
}
