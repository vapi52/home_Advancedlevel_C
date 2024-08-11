/* Задача 1-1-Сколько раз встречается максимум

На стандартном потоке ввода задается натуральное число N (N > 0),
после которого следует последовательность из N целых чисел.
На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум.
Указание: использовать массивы запрещается.

Пример №1
Данные на входе:    6 1 2 3 2 0 3
Данные на выходе:   2
Пример №2
Данные на входе:    3 5 2 -1
Данные на выходе:   1
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t number;
    scanf("%u", &number);

    uint32_t num_max;
    scanf("%u", &num_max);
    uint32_t count_max = 1;
    for (uint32_t i = 0; i < number - 1; i++)
    {
        uint32_t num_next;
        scanf("%u", &num_next);
        if (num_next > num_max)
        {
            num_max = num_next;
            count_max = 1;
        }
        else if (num_next == num_max)
        {
            count_max++;
        }
    }
    printf("%u\n", count_max);
    return 0;
}

