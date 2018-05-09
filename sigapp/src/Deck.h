/*
	This header file defines the structure of the class Deck.
	It is a data structure that contains a literal deck of Cards.

	Written by Jeff Foreman, 6 April 2018
*/

# pragma once

# include "Card.h"

# include <deque>

class Deck
{
public: // Special declarations.
	enum DeckType {Main, Hand, Discard};

	// Test card file.
	char* testCard = "../CardFiles/TestCard.obj";

protected: // Class variables and helper functions.
	
	// The vector of cards in the deck.
	std::deque<Card> cards; 

	// Places the cards onto the stack.
	void generateDeck(); 

public: // Class functions.

	// Constructor. Takes in deck type. Builds deck based upon the type.
	Deck(DeckType type); 
	
	// Draws a card from the "top" of this deck and returns the card.
	Card drawCard();

	// Draws a card from the "top" of a deck and places it into this deck.
	Card drawCard(Deck& deck); 

	// Shuffles this deck of cards.
	void shuffle(); 

	// Getter function for the deque of cards.
	Card getCard(int i);

	// Counts the values of the cards in the hand and returns the total.
	int getTotal();

	void print();
};