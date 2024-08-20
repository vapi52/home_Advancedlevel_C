/*Задача 5-3-Польская запись
Необходимо вычислить выражение написанное в обратной польской записи.
На вход подается строка состоящая из целых, не отрицательных чисел и арифметических символов.
В ответ единственное целое число - результат. Более подробно об Обратной польская запись числа
можно также почитать тут

Формат ввода:
Строка состоящая из целых чисел и символов '+', '-', '*', '/', ' '. В конце строки символ '.'. Строка корректная. Длина строки не превосходит 1000 символов. Все числа и операции разделены ровно одним пробелом.
Формат вывода:
Целое число, результат вычисления выражения.
Пример №1
Данные на входе:        3 4 +.
Данные на выходе:   7

Пример №2
Данные на входе:        1 2 + 4 × 3 +.
Данные на выходе:   15

Пример №3
Данные на входе:        100 25 + 25 /.
Данные на выходе:   5

Пример №4
Данные на входе:        1 2 3 4 + * +.
Данные на выходе:   15
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

const uint16_t MAX_ARRAY_LENGTH = 1000;

int main(void)
{
  int numbers[MAX_ARRAY_LENGTH];
  uint16_t arr_length = 0;

  char ch;
  while ((ch = getchar()) != '.')
  {
    if ('0' <= ch && ch <= '9')
    {
      uint16_t number = ch - '0';
      while ((ch = getchar()) != ' ')
      {
        number = number * 10 + ch - '0';
      }
      numbers[arr_length++] = number;
    }
    else
    {
      int res;
      switch (ch)
      {
      case '+':
        res = numbers[arr_length - 2] + numbers[arr_length - 1];
        break;
      case '-':
        res = numbers[arr_length - 2] - numbers[arr_length - 1];
        break;
      case '*':
        res = numbers[arr_length - 2] * numbers[arr_length - 1];
        break;
      case '/':
        res = numbers[arr_length - 2] / numbers[arr_length - 1];
        break;
      case ' ':
        continue;
      default:
        break;
      }
      numbers[arr_length - 2] = res;
      arr_length--;
    }
  }
  printf("%d\n", numbers[0]);
  return 0;
}
