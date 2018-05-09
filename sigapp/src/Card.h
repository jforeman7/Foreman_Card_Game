/*
	This header file defines the structure of the class Card.
	A Card belongs to one of four suits, and holds a value of either two through ten, a face value, or is an ace.
	These define the individual units of a Deck.

	This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

	Written by Jeff Foreman, 5 April 2018
*/

# pragma once

# include <sig/sn_primitive.h>

class Card
{
public: // Special declarations.

	// Enumerate the card suits.
	enum CardSuits { Clubs, Diamonds, Hearts, Spades, Blank };

	// Declare the special values of the face cards and the ace for Blackjack.
	const static int Ace = 11, Jack = 10, Queen = 10, King = 10; 

protected: // Class variables.

	int value; // Value of the card.
	CardSuits suit; // Suit of the card.
	char* cardFile; // Name of the 3ds file for the card.

public: // Class functions.

	// Default constructor.
	Card();

	// Constructor. Takes in the card value, suit, and color.
	Card(int value, CardSuits suit, char* cardFile);

	// Getters.
	int getValue(); // Returns card value.
	CardSuits getSuit(); // Returns card suit.
	char* getCardFile(); // Returns 3ds file name for the card.

};