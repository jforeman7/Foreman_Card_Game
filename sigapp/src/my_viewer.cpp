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

	// Create scene and UI.
	build_ui();
	build_Character();
	build_table();
	build_scene();
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

	// Add exit button.
	p->add(new UiButton("Exit", EvExit));
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

// Create the Viewer scene.
void MyViewer::build_scene()
{
	Deck main(Deck::DeckType::Main);
	Deck hand(Deck::DeckType::Hand);

	SnModel *a;
	double offset = 0.0;
	for (int i = 0; i < 52; i++)
	{
		a = new SnModel;
		GsVec vec = GsVec(0.0, 160.0, offset);
		GsVec axis;
		GsVec& vecp = vec;
		float radians = 1.5708f;
		GsMat mat;
		mat.rotx(0.0f);
		//GsVec set(vecp, radians);
		//GsVec apply(vec);
		//GsQuat q = GsQuat(0.0f, 45.0f, 45.0f, 45.0f);
		//a->model()->rotate(q);
		
		a->model()->load_obj("../CardFiles/TestCard.obj");
		add_model(a,vec);
		offset += 0.2;

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
float x = 0.0f;
float y = -60.0f;
float z = -160.0f;
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

		double lt, t0 = gs_time();
		do
		{

			lt = gs_time() - t0;
			if (lt < 3.0f)
			{
				//move Z 
				camera().eye.z -= 0.005f;
				camera().center.z -= 0.005f;
				camera().up.z -= 0.005f;

				//move Y
				camera().eye.y += 0.01f;
				camera().center.y += 0.01f;
				camera().up.y += 0.01f;

			}
			else if (lt >3.0f && lt < 3.8f)
			{
				//move x
				camera().eye.x -= 0.07f;
				camera().center.x -= 0.03f;
				camera().eye.z -= 0.07f;
				//camera().eye.y -= 0.03f;


			}
			else if (lt >3.8f && lt < 6.3f)
			{
				camera().eye.z -= 0.02f;

			}
			else if (lt >6.3f && lt < 9)
			{
				camera().eye.x += 0.02f;
				camera().center.x += 0.003f;

			}
			else if (lt > 9 && lt < 9.1f)
			{
				camera().center.x = 0.0f;
			}
			else if (lt > 9.1f && lt < 10.5f)
			{
				camera().eye.z += 0.009f;
				camera().eye.y -= 0.008f;
			}


			render();
			ws_check();
			message().setf("local time = %f", lt);
		} while (lt < 13);


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
	case EvExit: gs_exit();
	}

	return WsViewer::uievent(event);
}
