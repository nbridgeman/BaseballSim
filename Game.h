/**
 * Contains the method and member variable declarations of the Game class
 * @file Game.h
 * @author Noah Bridgeman/Milo Thatch/TastyChips16
 * @date 5/12/2021
 */
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ncurses.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Team.h"

class Game {
public:
    Game();
    ~Game();
    void play();
    void input_teams();
private:
    // member variables
    Team * _away;
    Team * _home;
    int _away_score;
    int _home_score;
    int _inning;
    bool _bottom_of_inning;
    int _outs;
    size_t _away_batter;
    size_t _home_batter;
    short bases[3];
    bool _game_over;
    // private methods
    void at_bat();
    void output_score() const;
    void hit();
    void out();
    void beginning_of_game() const;
    void end_of_inning();
    void end_of_half_inning();
    void end_of_game();
    void print_suffix() const;
    void get_winner() const;
    bool is_out();
    void final_score() const;
    void get_hit_type(short num);
    void single();
    void double_hit();
    void homerun();
    void triple();
    void clear_bases(short start);
    short sum_bases(short start);
    void shift_runners(short amount);
    void walk();
    void add_runs(short num_runs);
};

#endif // GAME_H
