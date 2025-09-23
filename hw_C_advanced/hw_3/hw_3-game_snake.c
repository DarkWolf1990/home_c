/*
 * 1. Доработать функционал игры "Змейка", реализовать в игре ситуацию, когда змея врезается сама в себя.
 * 2.Выход за границы экрана.
 * 3. * Переписать timeout через clock.
 * */

/*
 * Игра "Змейка"
 * Функционал:
 * 1. Движение змейки
 * 2. Поедание еды
 * 3. Проверка столкновений с хвостом и границами
 * 4. Цветная змейка (зелёная)
 * 5. Окончание игры с выводом сообщения Game Over
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h> // для toupper()

#define CONTROLS 2
#define MIN_Y  2  // Минимальная координата по Y, чтобы не писать над инструкцией
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10};

// Структура для клавиш управления
struct control_buttons {
    int down;
    int up;
    int left;
    int right;
} control_buttons;

// Стандартные клавиши управления
struct control_buttons default_controls[CONTROLS] = {
    {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},     // стрелки
    {'s', 'w', 'a', 'd'}                         // WASD (нижний регистр)
};

// Структура для одной части хвоста
typedef struct tail_t {
    int x;
    int y;
} tail_t;

// Структура змейки
typedef struct snake_t {
    int x;  // координата головы по X
    int y;  // координата головы по Y
    int direction; // направление движения
    size_t tsize;  // текущий размер хвоста
    struct tail_t *tail; // массив хвоста
    struct control_buttons controls; // клавиши управления
} snake_t;

// Структура еды
typedef struct food_t {
    int x;
    int y;
    char symbol;
} food_t;

// Инициализация хвоста (обнуляем координаты)
void initTail(tail_t t[], size_t size) {
    tail_t init_t = {0,0};
    for(size_t i=0; i<size; i++) t[i] = init_t;
}

// Инициализация головы змейки
void initHead(snake_t *head, int x, int y) {
    head->x = x;
    head->y = y;
    head->direction = RIGHT; // начальное направление вправо
}

// Инициализация змейки целиком
void initSnake(snake_t *head, size_t size, int x, int y) {
    tail_t *tail = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail;
    head->tsize = size+1; // начальный хвост
    head->controls = default_controls[0];
}

// Генерация еды в случайной позиции
void spawnFood(food_t *food, int max_x, int max_y) {
    food->x = rand() % max_x;
    food->y = (rand() % (max_y - MIN_Y)) + MIN_Y;
    food->symbol = '#'; // символ еды
}

// Отрисовка еды на экране
void drawFood(food_t *food) {
    mvprintw(food->y, food->x, "%c", food->symbol);
}

// Проверка, съела ли змейка еду
int checkFood(snake_t *snake, food_t *food) {
    if(snake->x == food->x && snake->y == food->y) {
        snake->tsize++; // увеличиваем хвост
        return 1;       // еда съедена
    }
    return 0;
}

// Движение головы змейки и отрисовка
void go(snake_t *head) {
    char ch = '@';
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x); // размеры терминала

    // Стираем предыдущую позицию головы
    mvprintw(head->y, head->x, " ");

    // Сдвигаем голову в зависимости от направления
    switch(head->direction){
        case LEFT: if(head->x <= 0) head->x = max_x; mvprintw(head->y, --(head->x), "%c", ch); break;
        case RIGHT: mvprintw(head->y, ++(head->x), "%c", ch); break;
        case UP: mvprintw(--(head->y), head->x, "%c", ch); break;
        case DOWN: mvprintw(++(head->y), head->x, "%c", ch); break;
    }

    // Отрисовка головы зелёным цветом
    attron(COLOR_PAIR(1));
    mvprintw(head->y, head->x, "%c", ch);
    attroff(COLOR_PAIR(1));

    refresh();
}

// Изменение направления по нажатой клавише
int playGame() {
    // инициализация змейки
    snake_t * snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake,START_TAIL_SIZE, 10, 10);

    //
}

void changeDirection(snake_t* snake, const int32_t key){
    for (int i = 0; i < CONTROLS; i++) {
        // Нормализуем символ (если это буква)
        int norm_key = (isalpha(key) ? tolower(key) : key);

        if (key == default_controls[i].down || norm_key == default_controls[i].down)
            snake->direction = DOWN;
        else if (key == default_controls[i].up || norm_key == default_controls[i].up)
            snake->direction = UP;
        else if (key == default_controls[i].right || norm_key == default_controls[i].right)
            snake->direction = RIGHT;
        else if (key == default_controls[i].left || norm_key == default_controls[i].left)
            snake->direction = LEFT;
    }
}

// Движение хвоста змейки
void goTail(snake_t *head){
    char ch = '*';
    // Стираем последний символ хвоста
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x," ");

    // Сдвигаем все части хвоста
    for(size_t i = head->tsize-1; i>0; i--){
        head->tail[i] = head->tail[i-1];
        if(head->tail[i].y || head->tail[i].x){
            attron(COLOR_PAIR(1));
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
            attroff(COLOR_PAIR(1));
        }
    }

    // Первая часть хвоста занимает предыдущую позицию головы
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

// Проверка столкновения головы со своим хвостом
int checkSelfCollision(snake_t *snake) {
    for (size_t i = 1; i < snake->tsize; i++) {
        if (snake->x == snake->tail[i].x && snake->y == snake->tail[i].y) {
            return 1;  // столкновение с хвостом
        }
    }
    return 0;
}

// Проверка выхода за границы экрана
int checkWallCollision(snake_t *snake, int max_x, int max_y) {
    if (snake->x < 0 || snake->x >= max_x || snake->y < MIN_Y || snake->y >= max_y) {
        return 1; // столкновение с границей
    }
    return 0;
}

// ======================= ОСНОВНАЯ ФУНКЦИЯ ==========================
int main(){
    srand(time(NULL)); // генератор случайных чисел

    // Инициализация змейки
    snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake, START_TAIL_SIZE, 10, 10);

    // Инициализация curses
    initscr();
    keypad(stdscr, TRUE);
    raw();
    noecho();
    curs_set(FALSE);
    mvprintw(0, 0, "Use arrows for control. Press 'F10' for EXIT");
    timeout(0);

    // Проверка поддержки цвета
    if(!has_colors()){
        endwin();
        printf("Ваш терминал не поддерживает цвета\n");
        return 1;
    }

    // Включаем цвет и задаём пару цветов (зелёная змейка)
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    // Получаем размеры экрана
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x);

    // Создаём первую еду
    food_t food;
    spawnFood(&food, max_x, max_y);

    int key_pressed = 0;
    int game_over = 0;
    timeout(100);
    // ==================== ОСНОВНОЙ ЦИКЛ ИГРЫ ======================
    while (key_pressed != STOP_GAME && !game_over) {
        key_pressed = getch();          // считываем нажатую клавишу
        changeDirection(snake, key_pressed); // меняем направление

        go(snake);    // двигаем голову
        goTail(snake); // двигаем хвост
        drawFood(&food); // отрисовываем еду

        // Проверка съеденной еды
        if (checkFood(snake, &food))
            spawnFood(&food, max_x, max_y);

        // Проверяем столкновения
        if (checkSelfCollision(snake) || checkWallCollision(snake, max_x, max_y)) {
            game_over = 1; // столкновение с хвостом или стеной
        }

        // Задержка через timeout (можно переписать через clock)
    }

    // ===================== КОНЕЦ ИГРЫ ==========================
    if (game_over) {
        clear();
        mvprintw(max_y/2, (max_x-9)/2, "Game Over");
        mvprintw(max_y/2 + 1, (max_x-30)/2, "Press F10 to exit...");
        refresh();

        // Ждём нажатия F10, чтобы пользователь увидел сообщение
        int ch = 0;
        while (ch != KEY_F(10)) {
            ch = getch();
        }
    }

    // ==================== ЗАВЕРШЕНИЕ ИГРЫ =======================
    free(snake->tail);  // освобождение памяти
    free(snake);
    endwin();           // завершение режима curses
    return 0;
}
