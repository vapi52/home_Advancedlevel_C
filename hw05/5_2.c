/*Задача 5-2-Префикс и суфикс
На стандартном потоке ввода задаются две символьные строки,
разделённые символом перевода строки. Каждая из строк не превышает по длине 104.
В строках не встречаются пробельные символы.
На стандартный поток вывода напечатайте два числа, разделённых пробелом:
первое число — длина наибольшего префикса первой строки, являющегося суффиксом второй;
второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксом второй.
Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).

Пример №1
Данные на входе:
don't_panic
nick_is_a_mastodon
Данные на выходе:   3 3

Пример №2
Данные на входе:
monty_python
python_has_list_comprehensions
Данные на выходе:   0 6
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

const uint16_t MAX_STRING_LENGTH = 104;

uint8_t prefix_suffix(char first[], char second[])
{
  uint8_t prefix_length = 0;

  uint8_t first_length = strlen(first);
  uint8_t sec_length = strlen(second);
  uint8_t max_length = first_length > sec_length ? first_length : sec_length;
  for (uint16_t length = 1; length < max_length; length++)
  {
    bool accordance = true;
    for (uint16_t i = 0; i < length; i++)
    {
      if (first[i] != second[sec_length - length + i])
      {
        accordance = false;
        break;
      }
    }
    if (accordance)
      prefix_length = length;
  }
  return prefix_length;
}

int main(void)
{
  char first[MAX_STRING_LENGTH], second[MAX_STRING_LENGTH];
  scanf("%s", first);
  scanf("%s", second);

  printf("%u %u\n", prefix_suffix(first, second), prefix_suffix(second, first));
  return 0;
}
