/*
	Function definitions of the card class. Please reference Card.h for more abstract details and API.

	This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

	Written by Jeff Foreman, 5 April 2018
*/

# include "Card.h"

Card::Card() { this->value = 0; this->suit = Unset; this->color = GsColor::black; }

Card::Card(int value, Card::CardSuits suit, GsColor color){ this->value = value; this->suit = suit; this->color = color; }

int Card::getValue() { return this->value; }

Card::CardSuits Card::getSuit() { return this->suit; }

GsColor Card::getColor() { return this->color; }