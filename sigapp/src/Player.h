/*
	This header file defines the structure of the class Player.
	It contains a deck of cards belonging to the player, and the choice the player made during the turn.

	This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

	Written by Jeff Foreman, 8 May 2018
*/

#pragma once

# include "Deck.h"

class Player
{
public:

	// Enumerate the player choices.
	enum Choice { Draw, Hold };

	// The choice the player made during their turn.
	Choice choice;

	// The deck of cards belonging to the player.
	Deck deck;

public:

	// Default constructor.
	Player();

	// Constructor that defines the deck of the player.
	Player(Deck deck);
};