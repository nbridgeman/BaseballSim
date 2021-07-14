/**
 * Contains the method definitions of the Game class
 * @file Game.cpp
 * @author Noah Bridgeman
 * @date 5/12/2021
 */
#include "Game.h"

const std::string OUT_OPTIONS[5] = {" grounded out. ", " flew out. ", " popped out. ",
                                    " struck out. ", " lined out. "};
const std::string HIT_OPTIONS[4] = {" hit a single.\n", " hit a double.\n",
                                    " hit a triple.\n", " hit a home run.\n"};
const short NUM_BASES = 3;

/**
 * Default constructor for Game object
 */
Game::Game() {
    _away_score = 0;
    _home_score = 0;
    _inning = 1;
    _outs = 0;
    _bottom_of_inning = false;
    _away = new Team();
    _home = new Team();
    _away_batter = 0;
    _home_batter = 0;
    for (size_t base = 0; base < NUM_BASES; base++) {
        bases[base] = 0;
    }
    _game_over = false;
    std::srand(time(0));
}

/**
 * Destructor for Game object
 */
Game::~Game() {
    delete _home;
    delete _away;
}

/**
 * Takes input that is assigned to the member variables of team objects
 */
void Game::input_teams() {
    _away->input_team();
    _home->input_team();
}

/**
 * Outputs the score to a ncurses window
 */
void Game::output_score() const {
    printw("%d", _away_score);
    printw(" - ");
    printw("%d", _home_score);
    printw("\n");
}

/**
 * Outputs the appropriate suffix for an inning number
 */
void Game::print_suffix() const {
    switch (_inning) {
        case 1:
            printw("st.\n");
            break;
        case 2:
            printw("nd.\n");
            break;
        case 3:
            printw("rd.\n");
            break;
        default:
            printw("th.\n");
            break;
    }
}

/**
 * Outputs messages at the beginning of the game
 */
void Game::beginning_of_game() const {
    attron(COLOR_PAIR(2));
    printw("Welcome to ");
    // CITE: https://bit.ly/2SCpHeZ
    // HELP: Information on how to print a string object using printw()
    printw(_away->get_team_name().data());
    printw(" vs ");
    printw(_home->get_team_name().data());
    printw("!\nLet's play ball!\n");
    printw("Start of the top of the 1st.\n");
    attroff(COLOR_PAIR(2));
}

/**
 * Determines the winner of the game and outputs the result
 */
void Game::get_winner() const {
    if (_away_score > _home_score) {
        printw("The ");
        printw(_away->get_team_name().data());
        printw(" win!\n");
    } else {
        printw("The ");
        printw(_home->get_team_name().data());
        printw(" win!\n");
    }
}

/**
 * Outputs game information and resets variables for the next inning
 */
void Game::end_of_inning() {
    attron(COLOR_PAIR(2));
    printw("End of the bottom of the ");
    // CITE: https://bit.ly/2RMsa6o
    // HELP: Information on how to print an int using printw()
    printw("%d", _inning);
    print_suffix();
    _inning++;
    _home->subtract_stamina();
    _bottom_of_inning = false;
    _outs = 0;
    clear_bases(0);
    if (_inning >= 10 && _away_score != _home_score) {
        final_score();
        _game_over = true;
    } else {
        printw("Current Score: ");
        output_score();
        printw("Start of the top of the ");
        printw("%d", _inning);
        print_suffix();
    }
    attroff(COLOR_PAIR(2));
}

/**
 * Outputs the final score and winner
 */
void Game::final_score() const {
    printw("Final Score: ");
    output_score();
    get_winner();
}

/**
 * Outputs game information and resets member variables for the bottom of the inning
 */
void Game::end_of_half_inning() {
    attron(COLOR_PAIR(2));
    printw("End of the top of the ");
    printw("%d", _inning);
    print_suffix();
    _away->subtract_stamina();
    _bottom_of_inning = true;
    _outs = 0;
    clear_bases(0);
    if (_inning >= 9 && _home_score > _away_score) {
        final_score();
        _game_over = true;
    } else {
        printw("Current Score: ");
        output_score();
        printw("Start of the bottom of the ");
        printw("%d", _inning);
        print_suffix();
        attroff(COLOR_PAIR(2));
    }
}

/**
 * Finds the number of runners on the bases at and following the inputted starting base
 * @param start is the first base you check from
 * @return the number of runners on bases from the start parameter
 */
short Game::sum_bases(short start) {
    short sum = 0;
    for (size_t base = start; base < NUM_BASES; base++) {
        sum += bases[base];
    }
    return sum;
}

/**
 * Sets the number of runners on the starting base and all subsequent to zero
 * @param start isthe first base you clear
 */
void Game::clear_bases(short start) {
    for (size_t base = start; base < NUM_BASES; base++) {
        bases[base] = 0;
    }
}

/**
 * Shifts all runners a given number of bases
 * @param amount is the number of bases the runners are being advanced
 */
void Game::shift_runners(short amount) {
    for (short base = NUM_BASES - 1; base >= 0; base--) {
        if (bases[base] == 1) {
            bases[base + amount] = 1;
            bases[base] = 0;
        }
    }
    bases[amount - 1] = 1;
}

/**
 * Adds a given number of runs to the appropriate team's total and
 * outputs the updated score
 * @param num_runs is the number of runs being added
 */
void Game::add_runs(short num_runs) {
    if (_bottom_of_inning) {
        _home_score += num_runs;
    } else {
        _away_score += num_runs;
    }
    printw("Current score: ");
    output_score();
}

/**
 * Outputs that a single was hit, shifts runners one base, and adds any scored runs
 */
void Game::single() {
    printw(HIT_OPTIONS[0].data());
    short num_runs = sum_bases(2);
    clear_bases(2);
    shift_runners(1);
    if (num_runs > 0) {
        add_runs(num_runs);
    }
}

/**
 * Outputs that a double was hit, shifts runners two bases, and adds any scored runs
 */
void Game::double_hit() {
    printw(HIT_OPTIONS[1].data());
    short num_runs = sum_bases(1);
    clear_bases(1);
    shift_runners(2);
    if (num_runs > 0) {
        add_runs(num_runs);
    }
}

/**
 * Outputs that a triple was hit, shifts runners three bases, and adds any scored runs
 */
void Game::triple() {
    printw(HIT_OPTIONS[2].data());
    short num_runs = sum_bases(0);
    clear_bases(0);
    shift_runners(3);
    if (num_runs > 0) {
        add_runs(num_runs);
    }
}

/**
 * Outputs that a home run was hit, clears the bases, and adds any scored runs
 */
void Game::homerun() {
    printw(HIT_OPTIONS[3].data());
    short num_runs = sum_bases(0) + 1;
    add_runs(num_runs);
    clear_bases(0);
}

/**
 * Determines the type of hit and runs the corresponding method
 * @param num is the amount of power a batter hit the ball with
 */
void Game::get_hit_type(short num) {
    if (num <= 85) {
        single();
    } else if (num > 85 && num <= 110) {
        double_hit();
    } else if (num > 110 && num <= 123) {
        homerun();
    } else if (num > 123) {
        triple();
    }
}

/**
 * Outputs that a player hit the ball, runs methods to determine the type of hit,
 * and updates the batter number
 */
void Game::hit() {
    if (_bottom_of_inning) {
        printw(_home->get_batter_name(_home_batter % 9).data());
        get_hit_type(_home->roll_batter_power(_home_batter % 9));
        _home_batter++;
    } else {
        printw(_away->get_batter_name(_away_batter % 9).data());
        get_hit_type(_away->roll_batter_power(_home_batter % 9));
        _away_batter++;
    }
}

/**
 * Outputs that a player walked, shifts the appropriate runners, and updates the
 * batter number
 */
void Game::walk() {
    if (_bottom_of_inning) {
        printw(_home->get_batter_name(_home_batter % 9).data());
        _home_batter++;
    } else {
        printw(_away->get_batter_name(_away_batter % 9).data());
        _away_batter++;
    }
    printw(" walked.\n");
    if (bases[0] == 1 && bases[1] == 1 && bases[2] == 1) {
        add_runs(1);
    } else if (bases[0] == 1 && bases[1] == 1) {
        bases[2] = 1;
    } else if (bases[0] == 1 && bases[2] == 1) {
        bases[1] = 1;
    } else if (bases[0] == 1) {
        bases[1] = 1;
    } else {
        bases[0] = 1;
    }
}

/**
 * Outputs that a player got out in a random way and the updated number of outs,
 * updates the batter number
 */
void Game::out() {
    if (_bottom_of_inning) {
        printw(_home->get_batter_name(_home_batter % 9).data());
        _home_batter++;
    } else  {
        printw(_away->get_batter_name(_away_batter % 9).data());
        _away_batter++;
    }
    printw(OUT_OPTIONS[rand() % 5].data());
    _outs++;
    printw("%d", _outs);
    if (_outs > 1) {
        printw(" outs.\n");
    } else {
        printw(" out.\n");
    }
}

/**
 * Determines if a batter is out or not based on corresponding roll methods
 * @return if the batter is out or not
 */
bool Game::is_out() {
    if (_bottom_of_inning) {
        if (_home->roll_batter(_home_batter % 9) > _away->roll_pitcher())
            return false;
    } else {
        if (_away->roll_batter(_away_batter % 9) > _home->roll_pitcher())
            return false;
    }
    return true;
}

/**
 * Determines is a batter is out, got a hit, or walked and runs the corresponding method
 */
void Game::at_bat() {
    if (is_out()) {
        out();
    } else {
        if ((rand() % 4) == 0) {
            walk();
        } else {
            hit();
        }
    }
}

/**
 * Runs through the necessary methods to play through an entire game,
 * progresses as the user presses any key
 */
void Game::play() {
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    beginning_of_game();
    int ch;
    nodelay(stdscr, TRUE);
    while (!_game_over) {
        if ((ch = getch()) == ERR) {
        } else {
            if (_game_over) {
                break;
            } else if (_outs < 3) {
                at_bat();
                refresh();
            } else if (_bottom_of_inning) {
                end_of_inning();
                refresh();
            } else {
                end_of_half_inning();
                refresh();
            }
        }
    }
}
