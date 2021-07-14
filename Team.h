/**
 * Contains the method and member variable declarations of the Team class
 * @file Game.h
 * @author Noah Bridgeman/Milo Thatch/TastyChips16
 * @date 5/12/2021
 */
#ifndef TEAM_H
#define TEAM_H

#include "Pitcher.h"
#include "Batter.h"
#include <string>
#include <iostream>

class Team {
public:
    Team();
    ~Team();
    void input_team();
    std::string get_team_name();
    std::string get_batter_name(short num);
    short roll_batter(short num);
    short roll_pitcher();
    void subtract_stamina();
    short roll_batter_power(short num);
private:
    std::string _team_name;
    Pitcher * _starter;
    Batter * _lineup[9];
};

#endif // TEAM_H
