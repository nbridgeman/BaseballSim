/**
 * Contains the method and member variable declarations of the Pitcher class
 * @file Pitcher.h
 * @author Noah Bridgeman
 * @date 5/12/2021
 */
#ifndef PITCHER_H
#define PITCHER_H

#include "Player.h"
#include <string>

class Pitcher : public Player {
public:
    Pitcher();
    Pitcher(std::string name, short pitching, short stamina);
    void reduce_stamina(short amount);
    short roll();
private:
    // based on xwOBA Percentile
    short _pitching;
    short _stamina;
};

#endif // PITCHER_H
