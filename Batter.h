/**
 * Contains the method and member variable declarations of the Batter class
 * @file Batter.h
 * @author Noah Bridgeman
 * @date 5/12/2021
 */
#ifndef BATTER_H
#define BATTER_H

#include "Player.h"
#include <string>

class Batter : public Player {
public:
    Batter();
    Batter(std::string name, short batting, short power);
    short roll();
    short roll_power();
private:
    // based on xwOBA Percentile
    short _batting;
    // based on Hard Hit % Percentile
    short _power;
};

#endif // BATTER_H
