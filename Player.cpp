/**
 * Contains the method definitions of the Player class
 * @file Player.cpp
 * @author Noah Bridgeman/Milo Thatch/TastyChips16
 * @date 5/12/2021
 */
#include "Player.h"

/**
 * Default constructor for the Player object
 */
Player::Player() {
    _name = "F.Surname";
}

/**
 * Virtual destructor for the Player class
 */
Player::~Player() {

}

/**
 * Sets the Player's name to a given sting
 * @param name is the string that _name is being set to
 */
void Player::set_name(std::string name) {
    _name = name;
}

/**
 * Returns the player's name
 * @return the player's name
 */
std::string Player::get_name() const {
    return _name;
}
