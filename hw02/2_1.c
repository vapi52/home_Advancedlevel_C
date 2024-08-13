/*Задача 2-1-Максимальный блок
Описана структура данных
typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

Требуется реализовать только одну функцию, которая в данном списке находит
адрес блока памяти занимающий больше всего места. Адрес хранится в поле address,
поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать NULL.
Если есть несколько таких блоков, то вернуть адрес любого из них. Прототип функции:
void * findMaxBlock(list *head)
*/

#include <stdio.h>

typedef struct list
{
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

void *findMaxBlock(list *head);

int main(void)
{
    list blockN = {.address = &blockN, .size = 100, .next = NULL};
    list block2 = {.address = &block2, .size = 30, .next = &blockN};
    list block1 = {.address = &block1, .size = 10, .next = &block2};

    list *max = findMaxBlock(&block1);
    printf("Max_list_size = %lld\n", max->size);
    printf("Max_list_address = %p", max->address);
    return 0;
}

void *findMaxBlock(list *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    list *biggest = head;
    head = head->next;
    while (head)
    {
        if (head->size > biggest->size)
        {
            biggest = head;
        }
        head = head->next;
    }
    return biggest->address;
}

