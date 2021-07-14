/**
 * Contains the method and member variable declarations of the Player class
 * @file Player.h
 * @author Noah Bridgeman/Milo Thatch/TastyChips16
 * @date 5/12/2021
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <ctime>
#include <cstdlib>

class Player {
public:
    Player();
    virtual ~Player();
    void set_name(std::string name);
    std::string get_name() const;
    virtual short roll() = 0;
protected:
    std::string _name;
};

#endif // PLAYER_H
