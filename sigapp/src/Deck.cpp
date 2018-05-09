/*
	Function definitions of the deck class. Please reference Deck.h for more abstract details and API.

	This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

	Written by Jeff Foreman, 6 April 2018
*/

# include "Deck.h"
# include <algorithm>

Deck::Deck(Deck::DeckType type)
{
	// Build the deck based on the type.
	switch (type)
	{
		// The main playing deck.
		case Deck::Main:
			// Build the full deck.
			generateDeck();

			// Shuffle up the deck.
			shuffle();
			break;

		// A player's hand. Composed of cards drawn from the deck. Empty at first.
		case Deck::Hand:
			break;

		// Discard pile. Composed of discarded cards. Empty at first.
		case Deck::Discard:
			break;

		default:
			break;
	}
}

void Deck::generateDeck()
{
	// Temporary card pointer.
	Card *temp;

	// Add the Aces.
	temp = new Card(Card::Ace, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/Ace_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Ace, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/Ace_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Ace, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/Ace_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Ace, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/Ace_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);

	// Add the numeric cards.
	temp = new Card(2, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/2_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(3, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/3_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(4, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/4_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(5, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/5_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(6, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/6_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(7, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/7_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(8, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/8_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(9, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/9_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(10, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/10_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);

	
	temp = new Card(2, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/2_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(3, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/3_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(4, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/4_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(5, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/5_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(6, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/6_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(7, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/7_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(8, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/8_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(9, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/9_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(10, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/10_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);

	
	temp = new Card(2, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/2_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(3, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/3_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(4, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/4_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(5, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/5_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(6, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/6_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(7, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/7_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(8, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/8_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(9, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/9_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(10, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/10_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	

	temp = new Card(2, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/2_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(3, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/3_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(4, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/4_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(5, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/5_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(6, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/6_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(7, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/7_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(8, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/8_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(9, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/9_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(10, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/10_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);
	

	// Add the face cards.
	temp = new Card(Card::Jack, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/Jack_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Jack, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/Jack_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Jack, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/Jack_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Jack, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/Jack_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);

	temp = new Card(Card::Queen, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/Queen_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Queen, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/Queen_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Queen, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/Queen_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::Queen, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/Queen_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);

	temp = new Card(Card::King, Card::CardSuits::Clubs, "../Cards/Card_OBJs/Clubs/King_Clubs/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::King, Card::CardSuits::Diamonds, "../Cards/Card_OBJs/Diamonds/King_Diamonds/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::King, Card::CardSuits::Hearts, "../Cards/Card_OBJs/Hearts/King_Hearts/Card_Template.obj");
	Deck::cards.push_front(*temp);
	temp = new Card(Card::King, Card::CardSuits::Spades, "../Cards/Card_OBJs/Spades/King_Spades/Card_Template.obj");
	Deck::cards.push_front(*temp);
}

Card Deck::drawCard()
{
	// Temporary storage for drawn card.
	Card drawnCard;

	// First check if there are even cards to draw. If not, "return" a blank card.
	if (cards.empty()) return drawnCard;

	// Draw the card from the top of the deck.
	drawnCard = cards.front();

	// Remove the card from the top of the deck.
	cards.pop_front();

	// Return the drawn card.
	return drawnCard;
}

Card Deck::drawCard(Deck& deck) 
{ 
	// Draw a card from the other deck.
	Card drawnCard = deck.drawCard();

	// Check if there actually was a card drawn.
	if (drawnCard.getValue() == 0) return drawnCard;

	// Add the drawn card to this deck.
	cards.push_front(drawnCard);

	return drawnCard;
}

void Deck::shuffle() 
{
	// Seed the random number generator.
	srand(unsigned int(gs_time()));

	// Randomized index.
	int r;

	for (size_t i = 0; i < cards.size(); i++)
	{
		// Get the random index.
		r = i + (rand() % (cards.size() - i));

		// Swap the current index with the random one.
		std::swap(cards[i], cards[r]);
	}
}

Card Deck::getCard(int i) { return cards[i]; }

int Deck::getTotal()
{
	// If the deque is empty, there are no cards in the hand. Return 0.
	if (cards.empty()) return 0;

	// A counter for aces in the hand.
	int aces = 0;

	// Total value in the hand variable.
	int total = 0;

	for (size_t i = 0; i < cards.size(); i++)
	{
		// Check for the occurence of the special card "ace". Keep count of aces.
		if (cards[i].getValue() == 11) aces++;

		// Add the card value to the total.
		total += cards[i].getValue();

		// Special rules for an Ace, which can be either be value 11 or 1. 
		// Default value is 11, if this sets the hand over 21, switch value to 1.
		// Show that the ace has been handled by decrementing the counter.
		if (total > 21 && aces > 0) { total -= 10; aces--; }
	}

	return total;
}

void Deck::print()
{
	for (size_t i = 0; i < cards.size(); i++)
		gsout << "Card [" << i << "] has value: " << cards[i].getValue() << gsnl;
}