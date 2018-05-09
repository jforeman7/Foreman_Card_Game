/*
Function definitions of the viewer. Please reference my_viewer.h for more abstract details.

This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

Written by Jeff Foreman, 5 April 2018
*/

# include "my_viewer.h"
# include "Card.h"
# include "Deck.h"

# include <sigogl/ui_button.h>
# include <sigogl/ui_radio_button.h>
# include <sig/sn_primitive.h>
# include <sig/sn_transform.h>
# include <sig/sn_manipulator.h>

# include <sigogl/ws_run.h>

// Viewer constructor.
MyViewer::MyViewer(int x, int y, int w, int h, const char* l) : WsViewer(x, y, w, h, l)
{
	// Initialize global variables.
	_nbut = 0;
	this->x = 0.0f, this->y = -60.0f, this->z = -160.0f;

	main = new Deck(Deck::DeckType::Main);
	player = new Deck(Deck::DeckType::Hand);
	dealer = new Deck(Deck::DeckType::Hand);

	turn = Turn::Player;

	// Create scene and UI.
	build_ui();
	build_deck();
	//build_Character();
	//build_table();
	//build_scene();
}

// Build the viewer UI.
void MyViewer::build_ui()
{
	// Panel pointers.
	UiPanel *p;

	// Create a UI manager.
	UiManager* uim = WsWindow::uim();

	// Add the panel to the left side of the screen.
	p = uim->add_panel("", UiPanel::HorizLeft);

	// Add Player Draw Card Button.
	p->add(new UiButton("Draw Card", EvDraw));

	// Add Player Hold Button.
	p->add(new UiButton("Hold", EvHold)); p->top()->separate();

	// Add exit button.
	p->add(new UiButton("Exit", EvExit)); p->top()->separate();
}

// Adds model part to the scene.
void MyViewer::add_model(SnShape* s, GsVec p)
{
	// Create a manipulator.
	SnManipulator* manip = new SnManipulator;

	// Create the model matrix.
	GsMat m;

	// Place the model matrix at the specified point.
	m.translation(p);

	// Set as the model matrix.
	manip->initial_mat(m);

	// Create a new group.
	SnGroup* g = new SnGroup;

	// Add model to the group.
	g->add(s);

	// Add model to the scene.
	manip->child(g);
	rootg()->add(manip);
}

// Add the deck of cards to the scene.
void MyViewer::build_deck()
{
	SnModel* s;
	double offset = 0.0;
	GsVec p;

	for (int i = 0; i < 52; i++)
	{
		p = GsVec(0.0, 160.0, offset);
		s = new SnModel;
		s->model()->load_obj(main->getCard(i).getCardFile());
		add_model(s, p);
		offset += 0.2;
	}
}

// Create the Viewer scene.
void MyViewer::build_scene()
{
	double offset = 0.0;
	for (int i = 0; i < 52; i++)
	{
		GsVec axis;
		float radians = 1.5708f;
		GsMat mat;
		mat.rotx(0.0f);
		//GsVec set(vecp, radians);
		//GsVec apply(vec);
		//GsQuat q = GsQuat(0.0f, 45.0f, 45.0f, 45.0f);
		//a->model()->rotate(q);

		//Floor model added below
		//initialize the points
		SnModel *p = new SnModel();
		GsModel &m = *p->model();
		//The four corners of our square
		GsVec A00 = GsVec(-1000.0f, -7.0f, -1000.0f);
		GsVec A10 = GsVec(-1000.0f, -7.0f, 1000.0f);
		GsVec A01 = GsVec(1000.0f, -7.0f, -1000.0f);
		GsVec A11 = GsVec(1000.0f, -7.0f, 1000.0f);
		//Push the points that make one triangle
		m.V.push() = A00;
		m.V.push() = A10;
		m.V.push() = A01;
		//Push the points that make the other triangle
		m.V.push() = A10;
		m.V.push() = A11;
		m.V.push() = A01;
		m.F.push() = GsModel::Face(0, 1, 2);
		m.F.push() = GsModel::Face(3, 4, 5);
		//first face triangle
		m.N.push() = GsVec(0, 0, 1);
		m.N.push() = GsVec(0, 0, 1);
		m.N.push() = GsVec(0, 0, 1);
		//second face triangle
		m.N.push() = GsVec(0, 0, 1);
		m.N.push() = GsVec(0, 0, 1);
		m.N.push() = GsVec(0, 0, 1);
		//first texture coordinate triangle
		m.T.push() = GsVec2(0.0f, 1.0f);
		m.T.push() = GsVec2(0.0f, 0.0f);
		m.T.push() = GsVec2(1.0f, 1.0f);
		//second texture coordinate triangle
		m.T.push() = GsVec2(0.0f, 0.0f);
		m.T.push() = GsVec2(1.0f, 0.0f);
		m.T.push() = GsVec2(1.0f, 1.0f);
		//given code that avoids texture issues
		GsModel::Group &g = *m.G.push();
		g.fi = 0;
		g.fn = m.F.size();
		g.dmap = new GsModel::Texture;
		m.M.push().init();
		//maps the texture
		g.dmap->fname.set("../CasinoFloor.png");
		// sets smooth model and model as textured
		m.set_mode(GsModel::Smooth, GsModel::PerGroupMtl);
		m.textured = true;
		// draw the object
		rootg()->add(p);
	}
}

// Create the table
void MyViewer::build_table()
{
	SnModel *b;

	b = new SnModel;
	b->model()->load_obj("../Table/table.obj");
	b->model()->scale(5.0f);
	add_model(b, GsVec(0.0f, 0.0f, 0.5f));
}

// Create the the player
void MyViewer::build_Character()
{
	SnModel *s;

	s = new SnModel;
	s->model()->load_obj("../Character/body.obj");
	s->model()->scale(140.0f);
	add_model(s, GsVec(x, y, z));

	s = new SnModel;
	s->model()->load_obj("../Character/leftarms.obj");
	s->model()->scale(140.0f);
	add_model(s, GsVec(x, y,z));
	s = new SnModel;
	s->model()->load_obj("../Character/lefthand.obj");
	s->model()->scale(140.0f);
	add_model(s, GsVec(x, y, z));
	s = new SnModel;
	s->model()->load_obj("../Character/leftshoulder.obj");
	s->model()->scale(140.0f);
	add_model(s, GsVec(x, y, z));
	s = new SnModel;
	s->model()->load_obj("../Character/leftupperarm.obj");
	s->model()->scale(140.0f);
	add_model(s, GsVec(x, y, z));

	s = new SnModel;
	s->model()->load_obj("../Character/rightarm.obj");
	s->model()->scale(140.0f);
	add_model(s, GsVec(x, y, z));
	s = new SnModel;
	s->model()->load_obj("../Character/righthand.obj");
	s->model()->scale(140.0f);
	add_model(s, GsVec(x, y, z));
	s = new SnModel;
	s->model()->load_obj("../Character/rightshoulder.obj");
	s->model()->scale(140.0f);
	add_model(s, GsVec(x, y, z));
	s = new SnModel;
	s->model()->load_obj("../Character/rightupperarm.obj");
	s->model()->scale(140.0f);
	add_model(s, GsVec(x, y,z));
}

void MyViewer::handle_dealer_turn()
{
	// If the player gets 21, they win.
	if (player->getTotal() == 21) { gsout << "PLAYER WINS" << gsnl; return; }

	// If the player goes over 21, they lose.
	if (player->getTotal() > 21) { gsout << "DEALER WINS" << gsnl; return; }

	// If the dealer gets 21, they win.
	if (dealer->getTotal() == 21) { gsout << "DEALER WINS" << gsnl; return; }

	// If the dealer goes over 21, they lose.
	if (dealer->getTotal() > 21) { gsout << "PLAYER WINS" << gsnl; return; }

	// If the dealer has more than 17 points, they will play it safe and not draw.
	if (dealer->getTotal() > 17)
	{
		// If the player also chose to Hold, compare totals.
		if (choice == Choice::Hold)
		{
			// If the player scored more than the dealer, they win.
			if (player->getTotal() > dealer->getTotal()) { gsout << "PLAYER WINS" << gsnl; return; }

			// Otherwise the dealer wins.
			gsout << "DEALER WINS" << gsnl; return;
		}
		return;
	}

	// Dealer decides to draw a card.
	dealer->drawCard(*main);
	turn = Turn::Player;
}

void MyViewer::player_animation()
{

}

void MyViewer::dealer_animation()
{

}

void MyViewer::print_game_status()
{

}

// Handle keyboard events.
int MyViewer::handle_keyboard(const GsEvent &event)
{
	// First let system check events.
	int ret = WsViewer::handle_keyboard(event);
	if (ret) return ret;

	// Handle the appropriate key event.
	switch (event.key)
	{
	case GsEvent::KeyEsc: gs_exit(); return 1;

		//move camera
	case GsEvent::KeySpace:
	{
		return 1;
	}

	default: gsout << "Key pressed: " << event.key << gsnl;
	}

	return 0;
}

// Handle UI events.
int MyViewer::uievent(int event)
{
	// Handle the appropriate UI event.
	switch (event)
	{
		case EvDraw: 
		{
			if (turn != Turn::Player) return 1;
			choice = Choice::Draw;
			player->drawCard(*main);
			turn = Turn::Dealer;
			handle_dealer_turn();

			return 1;
		}
		case EvHold:
		{
			if (turn != Turn::Player) return 1;
			choice = Choice::Hold;
			turn = Turn::Dealer;
			handle_dealer_turn();

			return 1;
		}

		case EvExit: gs_exit();
	}

	return WsViewer::uievent(event);
}
