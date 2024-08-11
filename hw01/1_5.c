/*Задача 1-5-Поиск последовательности бит
На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
Требуется взять K подряд идущих битов числа N так, чтобы полученное число было максимальным.
Программа должна вывести полученное число.

Данные на входе:    Два целых числа: 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
Данные на выходе:   Одно целое число

Пример №1
Данные на входе:    2 1
Данные на выходе:   1

Пример №2
Данные на входе:    12 3
Данные на выходе:   6
*/

#include <stdio.h>
#include <stdint.h>

uint8_t number_bit_length(uint32_t n);


int main(void)
{
    uint32_t n;
    uint8_t k;

    scanf("%u %hhu", &n, &k);

    uint32_t m = (1 << k) - 1;

    uint32_t max = n & m;
    uint8_t d = number_bit_length(n) - number_bit_length(m);
    for (uint8_t i = 1; i < d + 1; i++)
    {
        m <<= 1;
        if (((n & m) >> i) > max)
        {
            max = (n & m) >> i;
        }
    }

    printf("%u\n", max);

    return 0;
}

uint8_t number_bit_length(uint32_t n)
{
    uint8_t len = 0;
    while (n != 0)
    {
        len++;
        n >>= 1;
    }
    return len;
}
