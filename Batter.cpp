/**
 * Contains the method definitions of the Batter class
 * @file Batter.cpp
 * @author Noah Bridgeman
 * @date 5/12/2021
 */
#include "Batter.h"

/**
 * Default constructor for the Batter object
 */
Batter::Batter() {
    _name = "F.Surname";
    _batting = 50;
    _power = 50;
}

/**
 * Constructor for the Batter object that takes in stats
 * @param name is the string that _name is being set to
 * @param batting is the value that _batting is being set to
 * @param power is the value that _power is being set to
 */
Batter::Batter(std::string name, short batting, short power) {
    _name = name;
    _batting = batting;
    _power = power;
}

/**
 * Returns a random number times a multiplier based on the batter's _batting stat
 * @return a random number times a calculated multiplier
 */
short Batter::roll() {
    return (rand() % 50) * (1.0 + (_batting / 100.0));
}

/**
 * Returns a random number plus a fourth of a player's _power stat
 * @return a random number plus one fourth of a player's _power
 */
short Batter::roll_power() {
    return (rand() % 100) + (_power / 4.0);
}
