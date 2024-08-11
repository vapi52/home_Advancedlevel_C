/*В программе реализована структура данных:
struct pack_array
{
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
}
Необходимо написать программу, которая упаковывает переданный ей массив
из 32-ух элементов 0 и 1 в указанную структуру данных.
Функция должна строго соответствовать прототипу: void array2struct(int [], struct pack_array *)

Пример №1
Данные на входе:        1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Данные на выходе:
Поля структуры
array = ffff0000
count0 = 16
count1 = 16

Пример №2
Данные на входе:        1 1 1 1 1 1 1 1 1 0 1 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1
Данные на выходе:
Поля структуры
array = ffa70009
count0 = 17
count1 = 15
*/

#include <stdio.h>
#include <stdint.h>

struct pack_array {
    uint32_t array;      // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(int trmd[], struct pack_array *out);

int main ()
{
    int arr_in[32];
    struct pack_array out;
    for (int i=0; i<32; i++)
    {
        scanf("%d", arr_in+i);
    }
    array2struct(arr_in, &out);
    printf("array: 0x%x\ncount0: %d\ncount1 %d\n", out.array, out.count0, out.count1);
    return 0;
}

void array2struct(int trmd[], struct pack_array *out)
{
    for (int i =0; i<32; i++)
    {
        out->count1 += trmd[i];
        out->array  |= trmd[i];
        i<31 ? out->array<<=1 : 1;
    }
    out -> count0=32-out->count1;
}
