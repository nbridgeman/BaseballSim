/**
 * Contains the method definitions of the Pitcher class
 * @file Pitcher.cpp
 * @author Noah Bridgeman
 * @date 5/12/2021
 */
#include "Pitcher.h"

/**
 * Default constructor for the Pitcher object
 */
Pitcher::Pitcher() {
    _name = "F.Surname";
    _pitching = 50;
    _stamina = 50;
}

/**
 * Constructor for the Batter object that takes in stats
 * @param name is the string that _name is being set to
 * @param pitching is the value that _pitching is being set to
 * @param stamina is the value that _stamina is being set to
 */
Pitcher::Pitcher(std::string name, short pitching, short stamina) {
    _name = name;
    _pitching = pitching;
    _stamina = stamina;
}

/**
 * Reduces a pitcher's _stamina by a given amount
 * @param amount is the amount that a pitcher's stamina is being reduced by
 */
void Pitcher::reduce_stamina(short amount) {
    if (_stamina > 0) {
        _stamina -= amount;
    }
}

/**
 * Returns a random number times a multipler based on the pitcher's _pitching,
 * with a tenth of _stamina added to it
 * @return a random number times a calculated multipler plus a tenth of their _stamina
 */
short Pitcher::roll() {
    return (((rand() % 50) * (1.2 + (_pitching / 100.0))) + (_stamina / 10.0));
}
