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

class MyViewer : public WsViewer
{
protected:
	enum MenuEv { EvExit }; // Enumerations of UI events.
	UiCheckButton* _nbut; // UI drop down buttons.

public:
	// Constructor.
	MyViewer(int x, int y, int w, int h, const char* l);

	// Build the UI.
	void build_ui();

	// Add models to the scene. Takes in the primitive to be added, and the point to be added at.
	void add_model(SnShape* s, GsVec p);

	// Build the models to be added to the scene.
	void build_scene();
	void build_Character();
	void build_table();

	// Handle keyboard events.
	virtual int handle_keyboard(const GsEvent &e) override;

	// Handle UI events.
	virtual int uievent(int e) override;
};

