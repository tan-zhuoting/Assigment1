
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)

// Stub for main
int main() {
    int bet;
    int game_num = 1;
    Player you(100), dealer(900);
    std::cout << "You have $"<<you.get_money()<<". Enter bet: ";
    std::cin >> bet;
    std::cout <<endl<< game_num;

    std::cout << "your bets: " <<bet;

    you.set_bet(bet);

    Hand new_round;
    new_round.draw();

    you.won();
    std::cout << you.get_money();

    you.lost();
    std::cout << you.get_money();

    new_round.draw();

    new_round.empty();

    Hand another;

    if (another == new_round) std::cout << "empty sucessfully";
    if (another > new_round) std::cout << "something wrong ";

    


    return 0;
}