/**
 * Plays through a baseball game with two user-inputted teams
 * @file main.cpp
 * @author Noah Bridgeman/Milo Thatch/TastyChips16
 * @date 5/12/2021
 */
#include <ncurses.h>
#include "Game.h"

// Controls operation of the program.
int main() {
    Game game;
    game.input_teams();
    initscr();
    noecho();
    scrollok(stdscr, TRUE);

    if (!has_colors()) {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    game.play();

    attroff(COLOR_PAIR(1));
    refresh();
    int ch = 0;
    while (ch != 27) {
        ch = getch();
    }

    endwin();
    return 0;
}
