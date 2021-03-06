
#include "cards.h"
#include <cstdlib>
#include <iostream>

using namespace std;
/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

   /*
      Default constructor for the Card class.
      It could give repeated cards. This is OK.
      Most variations of Blackjack are played with
      several decks of cards at the same time.
   */
Card::Card() {
    int r = 1 + rand() % 4;
    switch (r) {
    case 1: suit = OROS; break;
    case 2: suit = COPAS; break;
    case 3: suit = ESPADAS; break;
    case 4: suit = BASTOS; break;
    default: break;
    }

    r = 1 + rand() % 10;
    switch (r) {
    case  1: rank = AS; break;
    case  2: rank = DOS; break;
    case  3: rank = TRES; break;
    case  4: rank = CUATRO; break;
    case  5: rank = CINCO; break;
    case  6: rank = SEIS; break;
    case  7: rank = SIETE; break;
    case  8: rank = SOTA; break;
    case  9: rank = CABALLO; break;
    case 10: rank = REY; break;
    default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
    case OROS:
        suitName = "oros";
        break;
    case COPAS:
        suitName = "copas";
        break;
    case ESPADAS:
        suitName = "espadas";
        break;
    case BASTOS:
        suitName = "bastos";
        break;
    default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
    case AS:
        rankName = "As";
        break;
    case DOS:
        rankName = "Dos";
        break;
    case TRES:
        rankName = "Tres";
        break;
    case CUATRO:
        rankName = "Cuatro";
        break;
    case CINCO:
        rankName = "Cinco";
        break;
    case SEIS:
        rankName = "Seis";
        break;
    case SIETE:
        rankName = "Siete";
        break;
    case SOTA:
        rankName = "Sota";
        break;
    case CABALLO:
        rankName = "Caballo";
        break;
    case REY:
        rankName = "Rey";
        break;
    default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
    string English;
    switch (suit) {
    case OROS:
        English = "cups";
        break;
    case COPAS:
        English = "copas";
        break;
    case ESPADAS:
        English = "spades";
        break;
    case BASTOS:
        English = "clubs";
        break;
    default: break;
    }
    return English;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
    string English;
    switch (rank) {
    case AS:
        English = "Ace";
        break;
    case DOS:
        English = "Two";
        break;
    case TRES:
        English = "Three";
        break;
    case CUATRO:
        English = "Four";
        break;
    case CINCO:
        English = "Five";
        break;
    case SEIS:
        English = "Six";
        break;
    case SIETE:
        English = "Seven";
        break;
    case SOTA:
        English = "Jack";
        break;
    case CABALLO:
        English = "Knight";
        break;
    case REY:
        English = "King";
        break;
    default: break;
    }
    return English;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}

double Card::get_val() const {
    if (this->get_rank() < 8)
        return double(this->get_rank());
    else return 0.5;
}



/* *************************************************
   Hand class
   ************************************************* */
   // Implemente the member functions of the Hand class here.

Hand::Hand()
{
	total = 0;
}

void Hand::print() {}
void Hand::draw() { 
    Card draw;
    cards.push_back(draw);
    total += draw.get_val();
   
}

void Hand::empty() {
    cards.clear();
}

bool Hand::operator>(Hand& d) {
    if (total > d.total && total<=7.5) return true;
    else return false;
}

bool Hand::operator==(Hand& d) {
    if (total == d.total && total <= 7.5) return true;
    else return false;
}


   /* *************************************************
      Player class
      ************************************************* */
      // Implemente the member functions of the Player class here.

Player::Player(int m)
{
	money = m;
	bet = 0;
}

void Player::won() { money += bet; }
void Player::lost() { money -= bet; }

int Player::get_money() {
    return money;
}
bool Player::set_bet(int& b) {
    if (0 < b && b <= money) {
        bet = b;
        return true;
    }
    else {
        return false;
    }

}












