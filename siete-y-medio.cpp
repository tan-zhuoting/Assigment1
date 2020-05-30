
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

    int game_num = 1;
    int bet;
    Player you(100), dealer(900);
    std::cout << "You have $"<<you.get_money()<<". Enter bet: ";
    std::cin >> bet;
    std::cout <<endl<< game_num;

    std::cout << "your bets: " <<bet;

    you.set_bet(bet);
    


    return 0;
}