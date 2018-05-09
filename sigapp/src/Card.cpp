/*
	Function definitions of the card class. Please reference Card.h for more abstract details and API.

	This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

	Written by Jeff Foreman, 5 April 2018
*/

# include "Card.h"

Card::Card() { this->value = 0; this->suit = Blank; this->cardFile = ""; }

Card::Card(int value, Card::CardSuits suit, char* cardFile){ this->value = value; this->suit = suit; this->cardFile = cardFile; }

int Card::getValue() { return this->value; }

Card::CardSuits Card::getSuit() { return this->suit; }

char* Card::getCardFile() { return this->cardFile; }