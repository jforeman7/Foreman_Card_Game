/*
This header file defines the structure and global variables of the program viewer.

This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

Written by Jeff Foreman, 5 April 2018
*/

# pragma once

# include <sig/sn_poly_editor.h>
# include <sig/sn_lines2.h>

# include <sigogl/ui_button.h>
# include <sigogl/ws_viewer.h>

#include "Deck.h"

class MyViewer : public WsViewer
{
protected:
	enum MenuEv {EvDraw, EvHold, EvExit }; // Enumerations of UI events.
	enum Turn { Player, Dealer }; // Enumerations of the turns.
	enum Choice { Draw, Hold }; // Enumerations of the choices.
	UiCheckButton* _nbut; // UI drop down buttons.
	float x, y, z; // Global coordinates.
	Choice choice; // Keeps track of the previous choice.
	Turn turn; // Keeps track of whos turn it is.
	Deck *main; // Main Deck pointer.
	Deck *player; // Player Deck pointer.
	Deck *dealer; // Dealer Deck pointer.

public:
	// Constructor.
	MyViewer(int x, int y, int w, int h, const char* l);

	// Build the UI.
	void build_ui();

	// Add models to the scene. Takes in the primitive to be added, and the point to be added at.
	void add_model(SnShape* s, GsVec p);

	// Build the models to be added to the scene.
	void build_deck();
	void build_scene();
	void build_Character();
	void build_table();

	// Dealer turn handler.
	void handle_dealer_turn();

	// Handle keyboard events.
	virtual int handle_keyboard(const GsEvent &e) override;

	// Handle UI events.
	virtual int uievent(int e) override;
};

