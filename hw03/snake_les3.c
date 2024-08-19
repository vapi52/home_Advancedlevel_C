#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>

#define MIN_Y  2
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10};
enum PhaseGame {CURRENT, VICTORY, LOSE_OUT};

// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

struct control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t = {0, 0};
    for (size_t i = 0; i < size; i++)
    {
        t[i] = init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
    tail_t *tail = (tail_t *)malloc(MAX_TAIL_SIZE * sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size + 1;
    head->controls = default_controls;
}

/*
 Движение головы с учетом текущего направления движения
 */
int go(struct snake_t *head)
{
    char ch = '@';
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x);  // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    int previous_x = head->x, previous_y = head->y;
    switch (head->direction)
    {
    case LEFT:
        if (head->x <= 0) // Циклическое движение, чтобы не
                          // уходить за пределы экрана
            head->x = max_x - 1;
        else
            --(head->x);
        break;
    case RIGHT:
        if (head->x >= max_x - 1)
            head->x = 0;
        else
            ++(head->x);
        break;
    case UP:
        if (head->y < MIN_Y)
            head->y = max_y - 1;
        else
            --(head->y);
        break;
    case DOWN:
        if (head->y >= max_y - 1)
            head->y = 0;
        else
            ++(head->y);
        break;
    default:
        break;
    }
    if (mvinch(head->y, head->x) == '*')
    {
        mvprintw(previous_y, previous_x, "%c", ch);
        return -1;
    }
    mvprintw(head->y, head->x, "%c", ch);
    refresh();
    return 0;
}

void changeDirection(struct snake_t *snake, const int32_t key)
{
    if (key == snake->controls.down)
        snake->direction = DOWN;
    else if (key == snake->controls.up)
        snake->direction = UP;
    else if (key == snake->controls.right)
        snake->direction = RIGHT;
    else if (key == snake->controls.left)
        snake->direction = LEFT;
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize - 1].y, head->tail[head->tsize - 1].x, " ");
    for (size_t i = head->tsize - 1; i > 0; i--)
    {
        head->tail[i] = head->tail[i - 1];
        if (head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}


int main()
{
    snake_t *snake = (snake_t *)malloc(sizeof(snake_t));
    initSnake(snake, START_TAIL_SIZE, 10, 10);
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Отключаем line buffering
    noecho();             // Отключаем echo() режим при вызове getch
    curs_set(FALSE);      // Отключаем курсор
    mvprintw(0, 5, "Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    enum PhaseGame state = CURRENT;
    int key_pressed = 0;
    while (key_pressed != STOP_GAME)
    {
        key_pressed = getch(); // Считываем клавишу
        if (state == CURRENT)
        {
            if (go(snake) == -1)
            {
                state = LOSE_OUT;
                continue;
            }
            goTail(snake);
            timeout(100); // Задержка при отрисовке
            changeDirection(snake, key_pressed);
        }
        else
        {
            int max_x = 0, max_y = 0;
            getmaxyx(stdscr, max_y, max_x);
            if (state == VICTORY)
                mvprintw(max_y / 2, max_x / 2 - 4, "You have won!");
            else
                mvprintw(max_y / 2, max_x / 2 - 4, "You are defeated!");
        }
    }
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
}
