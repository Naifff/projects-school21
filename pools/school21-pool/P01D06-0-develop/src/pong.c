#include <stdio.h>
// ++ Добавить проверку define
// Макросы
// bool
#define BREAK 0  // прекращение работы программы
#define GAME 1  // продолжение работы программы
// Поле Игры
#define MAX_X_POLE 81
#define MIN_X_POLE 0
#define MAX_Y_POLE 26
#define MIN_Y_POLE 0
// Поле с Цифрами
#define MAX_X_POLENUMBERS MAX_X_POLE
#define MIN_X_POLENUMBERS MIN_X_POLE
#define MAX_Y_POLENUMBERS 3
#define MIN_Y_POLENUMBERS 0
#define INDENT_FROM_NUMBERS (((MAX_X_POLE + 1) - 18)/2 - 1)
// Рокетки
#define START_POSITION_RACKET 11  // сделать функцию подсчета
// Мяч
#define START_POSITION_Y_BALL 13  // сделать функцию подсчета
#define START_POSITION_X_BALL_LEFT (MIN_X_POLE + 2)
#define START_POSITION_X_BALL_RIGHT (MAX_X_POLE - 2)
// Игроки
#define MAX_POINTS 21
// Глобальные переменные
// Поле c  цифрами
int number1 = 0;
int number2 = 0;
int number3 = 0;
int number4 = 0;
// Рокетки
int racket1 = START_POSITION_RACKET;  // Позиция ракетки 1
int racket2 = START_POSITION_RACKET;  // Позиция ракетки 2
// Мяч
int xBall = START_POSITION_X_BALL_LEFT;
int yBall = START_POSITION_Y_BALL;
int ball_k = 0;
// Игроки
int pointsPlayer1 = 0;
int pointsPlayer2 = 0;
int novicePlayer = 1;
void clear() {
    printf("\033[2J");  // Чистит весь экран
    printf("\033[0;0f");  // Переносит курсор в верхний левый угол
}
void saveNumbers(int n, int player) {
    if (n / 10 != 0) {
        if (player == 1) {
            number1 = n / 10;
            number2 = n % 10;
        } else if (player == 2) {
            number3 = n / 10;
            number4 = n % 10;
        }
    } else {
        if (player == 1) {
            number1 = -1;
            number2 = n;
        } else if (player == 2) {
            number3 = -1;
            number4 = n;
        }
    }
}
void printNumber(int n, int numberString) {
    switch (n) {
        case -1: {
            if (numberString == 1) {
                printf("   ");
            } else if (numberString == 2) {
                   printf("   ");
            } else {
                printf("   ");
            }
        } break;
        case 1: {
            if (numberString == 1) {
                printf("   ");
            } else if (numberString == 2) {
                    printf(" | ");
            } else {
                printf(" | ");
            }
        } break;
        case 2: {
            if (numberString == 1) {
                printf(" _ ");
            } else if (numberString == 2) {
                printf(" _|");
            } else {
                printf("|_ ");
            }
        } break;
        case 3: {
            if (numberString == 1) {
            printf(" _ ");
            } else if (numberString == 2) {
                printf(" _|");
            } else {
                printf(" _|");
            }
        } break;
        case 4: {
            if (numberString == 1) {
                printf("   ");
            } else if (numberString == 2) {
                printf("|_|");
            } else {
                printf("  |");
            }
        } break;
        case 5: {
            if (numberString == 1) {
                printf(" _ ");
            } else if (numberString == 2) {
                printf("|_ ");
            } else {
                printf(" _|");
            }
        } break;
        case 6: {
            if (numberString == 1) {
                printf(" _ ");
            } else if (numberString == 2) {
                printf("|_ ");
            } else {
                printf("|_|");
            }
        } break;
        case 7: {
            if (numberString == 1) {
                printf("__ ");
            } else if (numberString == 2) {
                printf("  |");
            } else {
                printf("  |");
            }
        } break;
        case 8: {
            if (numberString == 1) {
                printf(" _ ");
            } else if (numberString == 2) {
                printf("|_|");
            } else {
                printf("|_|");
            }
        } break;
        case 9: {
            if (numberString == 1) {
                printf(" _ ");
            } else if (numberString == 2) {
                printf("|_|");
            } else {
                printf("  |");
            }
        } break;
        case 0: {
            if (numberString == 1) {
                printf(" _ ");
            } else if (numberString == 2) {
                printf("| |");
            } else {
                printf("|_|");
            }
        } break;
    }
}
void printPoleNumbers() {
    saveNumbers(pointsPlayer1, 1);
    saveNumbers(pointsPlayer2, 2);
    printf("PLAYER1      PLAYER2\n");
    printNumber(number1, 1); printf(" "); printNumber(number2, 1); printf("     ");
    printNumber(number3, 1); printf(" "); printNumber(number4, 1); printf("\n");
    printNumber(number1, 2); printf(" "); printNumber(number2, 2); printf("  *  ");
    printNumber(number3, 2); printf(" "); printNumber(number4, 2); printf("\n");
    printNumber(number1, 3); printf(" "); printNumber(number2, 3); printf("  *  ");
    printNumber(number3, 3); printf(" "); printNumber(number4, 3); printf("\n");
}
void ptintPole() {  // Изображение поля
    int count = 1;
    int count2 = 1;
    for (int y = MIN_Y_POLE; y <= MAX_Y_POLE; y++) {
        for (int x = MIN_X_POLE; x <= MAX_X_POLE; x++) {
            if ((x == MAX_X_POLE && y == MAX_Y_POLE) || (x == MIN_X_POLE && y == MIN_Y_POLE) ||
                (x == MIN_X_POLE && y == MAX_Y_POLE) || (x == MAX_X_POLE && y == MIN_Y_POLE) ||
                (x == MAX_X_POLE && y <= MAX_Y_POLE) || (x == MIN_X_POLE && y <= MAX_Y_POLE) ||
                (x <= MAX_X_POLE && y == MAX_Y_POLE) || (x <= MAX_X_POLE && y == MIN_Y_POLE)) {
                printf("%c", '#');
            } else {
                if (x == MIN_X_POLE + 1) {
                    if (y == racket1 + count) {
                        if (count < 4) {
                            printf("%c", '|');
                            count++;
                        } else {
                            printf("%c", ' ');
                        }
                    } else {
                        printf("%c", ' ');
                    }
                } else if (x == MAX_X_POLE - 1) {
                    if (y == racket2 + count2) {
                        if (count2 < 4) {
                            printf("%c", '|');
                            count2++;
                        } else {
                            printf("%c", ' ');
                        }
                    } else {
                            printf("%c", ' ');
                    }
                } else {
                    if (x == xBall && y == yBall) {
                        printf("%c", 'o');
                    } else {
                        printf("%c", ' ');
                    }
                }
            }
        }
        printf("\n");
    }
}
void ptintGame() {  // Вывод всей игры
    clear();
    printPoleNumbers();
    ptintPole();
}
int angle(int racket_place, int y) {
  int ret;
  if (y == racket_place + 1 || y == racket_place + 2 || y == racket_place + 3) {
    if (y == racket_place + 1)
      ret = 1;
    if (y == racket_place + 2)
      ret = 0;
    if (y == racket_place + 3)
      ret = -1;
  }
  return ret;
}
int moveBall() {
    int mode = GAME;
    if (novicePlayer == 1) {  // проверка у какой ракетки отбить
        if (xBall != 2) {
            yBall += ball_k;
            xBall -= 1;
        }
        if ((yBall == racket1 + 1 || yBall == racket1 + 2 || yBall == racket1 + 3) && xBall == 2) {
            ball_k = angle(racket1, yBall);
            yBall += ball_k;
            xBall += 1;
            novicePlayer = 2;
            mode = GAME;  // отбить перешло другому игроку и цикл смены координат прервался
        }
        // третья ситуация - мяч н
        if ((yBall != racket2 + 1 || yBall != racket2 + 2 || yBall != racket2 + 3) && xBall == 2) {
            novicePlayer = 1;  // заново начать переходит проигравшему игроку
            ball_k = 0;
            pointsPlayer2++;
            saveNumbers(pointsPlayer2, 2);
            mode = BREAK;
        }
    }
    if (novicePlayer == 2) {  // проверка у какой ракетки отбить
        if (xBall != 79) {
            yBall += ball_k;
            xBall += 1;
        }
        if ((yBall == racket2 + 1 || yBall == racket2 + 2 || yBall == racket2 + 3) && xBall == 79) {
            ball_k = angle(racket2, yBall);
            yBall += ball_k;
            xBall -= 1;
            novicePlayer = 1;
            mode = GAME;  // отбить перешло другому игроку и цикл смены координат прервался
        }
        // третья ситуация - мяч н
        if ((yBall != racket1 + 1 || yBall != racket1 + 2 || yBall != racket1 + 3) && xBall == 79) {
            novicePlayer = 2;  // заново начать переходит проигравшему игроку
            ball_k = 0;
            pointsPlayer1++;
            saveNumbers(pointsPlayer1, 1);
            mode = BREAK;
        }
    }
    if (yBall == MIN_Y_POLE + 1 || yBall == MAX_Y_POLE - 1) {
        ball_k = ball_k * (-1);
    }
    return mode;
}
void moveRacket() {
    // key1 - нажатие клавиши 1 пользователем
    // key2 - нажатие клавиши 2 пользователем
    printf("Ход PLAYERS: ");
    char key1;
    scanf("%c", &key1);
    // ход 1 player 1 вводит свои клавиши
    if ((key1 == 'a' || key1 == 'A') || (key1 == 'z' || key1 == 'Z')) {
        // player1
        if ((key1 == 'a' || key1 == 'A') && racket1 >= (MIN_Y_POLE + 1))  // ракетка вверх у player1
            racket1--;
        else if ((key1 == 'z' || key1 == 'Z') && racket1 <= (MAX_Y_POLE - 5))  // ракетка вверх у player1
            racket1++;
        // Читаем ход 2-го кто будет ходить
        printf("Ход PLAYERS: ");
        char key2 = getchar();
        scanf("%c", &key2);
        // player2
        if ((key2 == 'k' || key2 == 'K') && racket2 >= (MIN_Y_POLE + 1))  // ракетка вверх у player2
            racket2--;
        else if ((key2 == 'm' || key2 == 'M') && racket2 <= (MAX_Y_POLE - 5))  // ракетка вниз у player2
                racket2++;
        else if (key2 == ' ' || key2 == '\n')  // player2 пропуск хода
            racket2 = racket2;
    // ход 1 player2 вводит свои клавиши
    } else if ((key1 == 'k' || key1 == 'K') || (key1 == 'm' || key1 == 'M')) {
        // player2
        if ((key1 == 'k' || key1 == 'K') && racket2 >= (MIN_Y_POLE + 1))
            racket2--;
        else if ((key1 == 'm' || key1 == 'M') && racket2 <= (MAX_Y_POLE - 5))
                racket2++;
        // Читаем ход 2-го кто будет ходить
        printf("Ход PLAYERS: ");
        char key2 = getchar();
        scanf("%c", &key2);
        // player1
        if ((key2 == 'a' || key2 == 'A') && racket1 >= (MIN_Y_POLE + 1))  // ракетка вверх у player1
            racket1--;
        else if ((key2 == 'z' || key2 == 'Z') && racket1 <= (MAX_Y_POLE - 5))  // ракетка вверх у player1
            racket1++;
        else if (key2 == ' ' || key2 == '\n')  // player1 пропуск хода
            racket1 = racket1;
    } else if (key1 == ' ' || key1 == '\n') {  // Два игрока пропускают ход
        racket1 = racket1;
        racket2 = racket2;
    }
}
int display() {  // Отображение игры
  moveRacket();
  if (moveBall() == BREAK) {
    return BREAK;
  } else {
    return GAME;
  }
}
void start() {
    saveNumbers(pointsPlayer1, 1);
    saveNumbers(pointsPlayer2, 2);
    racket1 = START_POSITION_RACKET;  // Позиция ракетки 1
    racket2 = START_POSITION_RACKET;  // Позиция ракетки 2
    // Мяч
    if (novicePlayer == 1) {
        xBall = START_POSITION_X_BALL_LEFT;
    } else {
        xBall = START_POSITION_X_BALL_RIGHT;
    }
    yBall = START_POSITION_Y_BALL;
     // Рисуем игру при старте мяча
    int end = GAME;
    while ((end = display()) != BREAK) {
        ptintGame();  // Вывод всей игры
    }
    if (end == BREAK && (pointsPlayer1 != MAX_POINTS || pointsPlayer2 != MAX_POINTS)) {
        clear();
        printPoleNumbers();
        if (pointsPlayer1 == MAX_POINTS) {
            printf("PLAYER1 WIN!\n");
        }
        if (pointsPlayer2 == MAX_POINTS) {
            printf("PLAYER2 WIN!\n");
        }
    } else if (end == BREAK) {
        ptintGame(); // Вывод всей игры
    }
}
int main() {
    clear();
    ptintGame();
    start();
    return 0;
}
