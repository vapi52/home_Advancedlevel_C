/*Задача 5-1-Вычеркивание
Сколько различных трехзначных чисел можно получить из заданного натурального N,
вычеркивая цифры из его десятичной записи?

Формат данных на входе: Единственное натуральное число N.
Формат данных на выходе: Единственное целое число – найденное количество.

Пример №1
Данные на входе:        1111111111111111111111111
Данные на выходе:   1


Пример №1
Данные на входе:        1111122222
Данные на выходе:   4


Пример №1
Данные на входе:        9876543210
Данные на выходе:   120
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

const uint16_t MAX_NUM_LENGTH = 1000;

uint32_t only_integer_number_found(uint8_t arr[], uint64_t a_len)
{
  bool detect[1000];
  for (uint16_t i = 0; i < 1000; i++)
  {
    detect[i] = false;
  }
  for (uint64_t i = 0; i < a_len - 2; i++)
  {
    for (uint64_t j = i + 1; j < a_len - 1; j++)
    {
      for (uint64_t k = j + 1; k < a_len; k++)
      {
        detect[arr[i] * 100 + arr[j] * 10 + arr[k]] = true;
      }
    }
  }
  uint32_t cnt = 0;
  for (uint16_t i = 0; i < 1000; i++)
  {
    if (detect[i])
    {
      cnt++;
    }
  }
  return cnt;
}

int main(void)
{
  uint8_t arr[MAX_NUM_LENGTH];
  uint64_t a_len = 0;

  char c = 0;
  while ((c = getchar()) != '\n')
  {
    arr[a_len++] = c - '0';
  }

  printf("%u\n", only_integer_number_found(arr, a_len));
  return 0;
}
