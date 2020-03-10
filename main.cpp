// freft -- A cross platform EFT file editor by Frib

#include "mainframe.h"

mainframe *frame;
char buffer[2048]; //buffer for entire program

class fribeftApp: public wxApp {
	public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(fribeftApp);

bool fribeftApp::OnInit()
{
    frame = new mainframe( "Frib EFT Editor", wxPoint(300, 300), wxSize(DEFAULTW, DEFAULTH) );
    frame->Show(true);
		if(wxApp::argc == 2)
			frame->open(static_cast<const char *>(wxApp::argv[1]));

    return true;
}
