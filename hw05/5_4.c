/*Задача 5-4-Двоичные нули
Для заданных натуральных чисел N и K требуется вычислить количество
чисел от 1 до N, имеющих в двоичной записи ровно K нулей.
Например, если N=8 и K=1, то мы можем записать все числа от 1 до 8 в двоичной системе счисления:
1, 10, 11, 100, 101, 110, 111 и 1000. Откуда видно, что только числа 10, 101 и 110 имеют
ровно один ноль в записи, т.е. правильный ответ – 3.
Формат ввода:
На вход поступают два натуральных числа через пробел N и K, не превышающих 20001.
Формат вывода:
Нужно вывести одно целое число — количество чисел от 1 до N с K нулями в двоичном представлении.

Пример №1
Данные на входе:        8 1
Данные на выходе:   3

Пример №2
Данные на входе:        13 2
Данные на выходе:   4

Пример №3
Данные на входе:        1000 5
Данные на выходе:   210
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

const uint16_t MAX_ARRAY_LENGTH = 1000;

uint8_t number_of_zeros_binary_representation(uint32_t num)
{
  uint8_t cnt = 0;
  while (num > 0)
  {
    cnt += 1 - (num & 1);
    num >>= 1;
  }
  return cnt;
}

int main(void)
{
  uint32_t n, k;
  scanf("%d %d", &n, &k);

  uint32_t cnt = 0;
  for (uint32_t i = 0; i < n; i++)
  {
    if (number_of_zeros_binary_representation(i) == k)
    {
      cnt++;
    }
  }
  printf("%u\n", cnt);

  return 0;
}
