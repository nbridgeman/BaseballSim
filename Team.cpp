/**
 * Contains the method definitions of the Team class
 * @file Game.cpp
 * @author Noah Bridgeman
 * @date 5/12/2021
 */
#include "Team.h"

using namespace std;

const short LINEUP_SIZE = 9;

/**
 * Default constructor for Team object
 */
Team::Team() {
    _starter = new Pitcher();
    for (size_t num = 0; num < LINEUP_SIZE; num++) {
        _lineup[num] = new Batter();
    }
}

/**
 * Destructor for Team object
 */
Team::~Team() {
    delete _starter;
    for (size_t num = 0; num < LINEUP_SIZE; num++) {
        delete _lineup[num];
    }
}

/**
 * Takes in input for a team and updates all member variables
 */
void Team::input_team(std::string filename) {
    ifstream infile;
    infile.open(filename);
    infile >> _team_name;
    string name = "F.Surname";
    short first_stat = 50;
    short second_stat = 50;
    infile >> name >> first_stat >> second_stat;
    delete _starter;
    _starter = new Pitcher(name, first_stat, second_stat);
    for (size_t num = 0; num < LINEUP_SIZE; num++) {
        infile >> name >> first_stat >> second_stat;
        delete _lineup[num];
        _lineup[num] = new Batter(name, first_stat, second_stat);
    }
}

/**
 * Returns the team name
 * @return the team name
 */
string Team::get_team_name() {
    return _team_name;
}

/**
 * Returns a batter's name based on a corresponding position in the lineup
 * @param num is the batter's number in the lineup
 * @return a batter's name
 */
string Team::get_batter_name(short num) {
    return _lineup[num]->get_name();
}

/**
 * Executes a given batter's roll method
 * @param num is the batter's positon in the lineup
 * @return the rolled number
 */
short Team::roll_batter(short num) {
    return _lineup[num]->roll();
}

/**
 * Executes a the starter's roll method
 * @return the rolled number
 */
short Team::roll_pitcher() {
    return _starter->roll();
}

/**
 * Subtracts 10 stamina from the starter's stamina stat
 */
void Team::subtract_stamina() {
    _starter->reduce_stamina(10);
}

/**
 * Executes a given batter's roll power method
 * @param num is the batter's positon in the lineup
 * @return the rolled number
 */
short Team::roll_batter_power(short num) {
    return _lineup[num]->roll_power();
}
