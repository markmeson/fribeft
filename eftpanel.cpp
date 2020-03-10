///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "eftpanel.h"

///////////////////////////////////////////////////////////////////////////

pnlEFT::pnlEFT( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxGridSizer* gloMain;
	gloMain = new wxGridSizer( 1, 2, 0, 0 );

	wxBoxSizer* vloLeft;
	vloLeft = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* vloGeneral;
	vloGeneral = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* hloEFTName;
	hloEFTName = new wxBoxSizer( wxHORIZONTAL );

	lblEFTName = new wxStaticText( this, wxID_ANY, wxT("EFT Name:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	lblEFTName->Wrap( -1 );
	lblEFTName->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	hloEFTName->Add( lblEFTName, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtEFTName = new wxTextCtrl( this, ID_EFTName, wxEmptyString, wxPoint( -1,-1 ), wxSize( 330,25 ), 0 );
	hloEFTName->Add( txtEFTName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloGeneral->Add( hloEFTName, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSound;
	hloSound = new wxBoxSizer( wxHORIZONTAL );

	lblUseSound = new wxStaticText( this, wxID_ANY, wxT("Use Sound:"), wxDefaultPosition, wxSize( 88,-1 ), 0 );
	lblUseSound->Wrap( -1 );
	hloSound->Add( lblUseSound, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtUseSound = new wxTextCtrl( this, ID_UseSound, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	txtUseSound->SetMinSize( wxSize( -1,25 ) );

	hloSound->Add( txtUseSound, 0, wxALL, 5 );


	hloSound->Add( 0, 0, 1, wxEXPAND, 5 );

	lblSoundLoopCt = new wxStaticText( this, wxID_ANY, wxT("Sound Loop Count:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	lblSoundLoopCt->Wrap( -1 );
	hloSound->Add( lblSoundLoopCt, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSoundLoopCt = new wxTextCtrl( this, ID_SoundLoopCt, wxEmptyString, wxDefaultPosition, wxSize( -1,25 ), 0 );
	hloSound->Add( txtSoundLoopCt, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloGeneral->Add( hloSound, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSoundFile;
	hloSoundFile = new wxBoxSizer( wxHORIZONTAL );

	lblSoundFile = new wxStaticText( this, wxID_ANY, wxT("Sound File:"), wxDefaultPosition, wxSize( 88,-1 ), 0 );
	lblSoundFile->Wrap( -1 );
	hloSoundFile->Add( lblSoundFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSoundFile = new wxTextCtrl( this, ID_SoundFile, wxEmptyString, wxDefaultPosition, wxSize( 346,25 ), 0 );
	hloSoundFile->Add( txtSoundFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloGeneral->Add( hloSoundFile, 1, wxEXPAND, 5 );


	vloLeft->Add( vloGeneral, 1, wxALL|wxEXPAND, 5 );

	linLeft = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	vloLeft->Add( linLeft, 0, wxEXPAND | wxALL, 0 );

	wxBoxSizer* vloSystems;
	vloSystems = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* hloSystemsControls;
	hloSystemsControls = new wxBoxSizer( wxHORIZONTAL );

	hloSystemsControls->SetMinSize( wxSize( -1,30 ) );
	lblSystemsCt = new wxStaticText( this, ID_Systems, wxT("Systems"), wxDefaultPosition, wxSize( 105,-1 ), 0 );
	lblSystemsCt->Wrap( -1 );
	lblSystemsCt->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	hloSystemsControls->Add( lblSystemsCt, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	hloSystemsControls->Add( 0, 0, 2, wxEXPAND, 5 );

	btnPrevSystem = new wxButton( this, ID_PrevSystem, wxT("<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	btnPrevSystem->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	btnPrevSystem->SetMinSize( wxSize( -1,25 ) );
	btnPrevSystem->SetMaxSize( wxSize( 35,-1 ) );

	hloSystemsControls->Add( btnPrevSystem, 0, wxALIGN_CENTER_VERTICAL, 0 );

	txtCurSystem = new wxTextCtrl( this, ID_CurSystem, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTER );
	txtCurSystem->SetMinSize( wxSize( -1,25 ) );

	hloSystemsControls->Add( txtCurSystem, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 10 );

	btnNextSystem = new wxButton( this, ID_NextSystem, wxT(">"), wxDefaultPosition, wxDefaultSize, 0 );
	btnNextSystem->SetMinSize( wxSize( -1,25 ) );
	btnNextSystem->SetMaxSize( wxSize( 35,-1 ) );

	hloSystemsControls->Add( btnNextSystem, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	btnAddSystem = new wxButton( this, ID_AddSystem, wxT("Append"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	btnAddSystem->SetMinSize( wxSize( -1,25 ) );
	btnAddSystem->SetMaxSize( wxSize( 80,-1 ) );

	hloSystemsControls->Add( btnAddSystem, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystems->Add( hloSystemsControls, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemName;
	hloSystemName = new wxBoxSizer( wxHORIZONTAL );

	lblSystemName = new wxStaticText( this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblSystemName->Wrap( -1 );
	hloSystemName->Add( lblSystemName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemName = new wxTextCtrl( this, ID_SystemName, wxEmptyString, wxDefaultPosition, wxSize( 350,25 ), 0 );
	hloSystemName->Add( txtSystemName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxBoxSizer* hloSoundLoopCt4;
	hloSoundLoopCt4 = new wxBoxSizer( wxHORIZONTAL );

	lblSoundLoopCt4 = new wxStaticText( this, wxID_ANY, wxT("Sound Loop Count:"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	lblSoundLoopCt4->Wrap( -1 );
	hloSoundLoopCt4->Add( lblSoundLoopCt4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSoundLoopCt4 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,25 ), 0 );
	hloSoundLoopCt4->Add( txtSoundLoopCt4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	hloSystemName->Add( hloSoundLoopCt4, 1, wxEXPAND, 5 );


	vloSystems->Add( hloSystemName, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemUName;
	hloSystemUName = new wxBoxSizer( wxHORIZONTAL );

	lblSystemUName = new wxStaticText( this, wxID_ANY, wxT("Unique Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblSystemUName->Wrap( -1 );
	hloSystemUName->Add( lblSystemUName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemUName = new wxTextCtrl( this, ID_SystemUName, wxEmptyString, wxDefaultPosition, wxSize( 350,25 ), 0 );
	hloSystemUName->Add( txtSystemUName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystems->Add( hloSystemUName, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemPTLFile;
	hloSystemPTLFile = new wxBoxSizer( wxHORIZONTAL );

	lblSystemPTLFile = new wxStaticText( this, wxID_ANY, wxT("PTL File:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblSystemPTLFile->Wrap( -1 );
	hloSystemPTLFile->Add( lblSystemPTLFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemPTLFile = new wxTextCtrl( this, ID_SystemPTLFile, wxEmptyString, wxDefaultPosition, wxSize( 350,25 ), 0 );
	hloSystemPTLFile->Add( txtSystemPTLFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystems->Add( hloSystemPTLFile, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemZMOFile;
	hloSystemZMOFile = new wxBoxSizer( wxHORIZONTAL );

	lblSystemZMOFile = new wxStaticText( this, wxID_ANY, wxT("ZMO File:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblSystemZMOFile->Wrap( -1 );
	hloSystemZMOFile->Add( lblSystemZMOFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemZMOFile = new wxTextCtrl( this, ID_SystemZMOFile, wxEmptyString, wxDefaultPosition, wxSize( 350,25 ), 0 );
	hloSystemZMOFile->Add( txtSystemZMOFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystems->Add( hloSystemZMOFile, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemsBottom;
	hloSystemsBottom = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* vloSystemFloats;
	vloSystemFloats = new wxBoxSizer( wxVERTICAL );

	vloSystemFloats->SetMinSize( wxSize( 135,-1 ) );
	wxBoxSizer* hloSystemPosX;
	hloSystemPosX = new wxBoxSizer( wxHORIZONTAL );

	lblSystemPosX = new wxStaticText( this, wxID_ANY, wxT("Position X:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemPosX->Wrap( -1 );
	hloSystemPosX->Add( lblSystemPosX, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemPosX = new wxTextCtrl( this, ID_SystemPosX, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloSystemPosX->Add( txtSystemPosX, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemFloats->Add( hloSystemPosX, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemPosY;
	hloSystemPosY = new wxBoxSizer( wxHORIZONTAL );

	lblSystemPosY = new wxStaticText( this, wxID_ANY, wxT("Position Y:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemPosY->Wrap( -1 );
	hloSystemPosY->Add( lblSystemPosY, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemPosY = new wxTextCtrl( this, ID_SystemPosY, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloSystemPosY->Add( txtSystemPosY, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemFloats->Add( hloSystemPosY, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemPosZ;
	hloSystemPosZ = new wxBoxSizer( wxHORIZONTAL );

	lblSystemPosZ = new wxStaticText( this, wxID_ANY, wxT("Position Z:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemPosZ->Wrap( -1 );
	hloSystemPosZ->Add( lblSystemPosZ, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemPosZ = new wxTextCtrl( this, ID_SystemPosZ, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloSystemPosZ->Add( txtSystemPosZ, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemFloats->Add( hloSystemPosZ, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemRotX;
	hloSystemRotX = new wxBoxSizer( wxHORIZONTAL );

	lblSystemRotX = new wxStaticText( this, wxID_ANY, wxT("Rotation X:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemRotX->Wrap( -1 );
	hloSystemRotX->Add( lblSystemRotX, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemRotX = new wxTextCtrl( this, ID_SystemRotX, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloSystemRotX->Add( txtSystemRotX, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemFloats->Add( hloSystemRotX, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemRotY;
	hloSystemRotY = new wxBoxSizer( wxHORIZONTAL );

	lblSystemRotY = new wxStaticText( this, wxID_ANY, wxT("Rotation Y:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemRotY->Wrap( -1 );
	hloSystemRotY->Add( lblSystemRotY, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemRotY = new wxTextCtrl( this, ID_SystemRotY, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloSystemRotY->Add( txtSystemRotY, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemFloats->Add( hloSystemRotY, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemRotZ;
	hloSystemRotZ = new wxBoxSizer( wxHORIZONTAL );

	lblSystemRotZ = new wxStaticText( this, wxID_ANY, wxT("Rotation Z:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemRotZ->Wrap( -1 );
	hloSystemRotZ->Add( lblSystemRotZ, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemRotZ = new wxTextCtrl( this, ID_SystemRotZ, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloSystemRotZ->Add( txtSystemRotZ, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemFloats->Add( hloSystemRotZ, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemRotW;
	hloSystemRotW = new wxBoxSizer( wxHORIZONTAL );

	lblSystemRotW = new wxStaticText( this, wxID_ANY, wxT("Rotation W:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemRotW->Wrap( -1 );
	hloSystemRotW->Add( lblSystemRotW, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemRotW = new wxTextCtrl( this, ID_SystemRotW, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloSystemRotW->Add( txtSystemRotW, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemFloats->Add( hloSystemRotW, 1, wxEXPAND, 5 );


	hloSystemsBottom->Add( vloSystemFloats, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* vloSystemDWs;
	vloSystemDWs = new wxBoxSizer( wxVERTICAL );

	vloSystemDWs->SetMinSize( wxSize( -135,-1 ) );
	wxBoxSizer* hloSystemSTBIndex;
	hloSystemSTBIndex = new wxBoxSizer( wxHORIZONTAL );

	lblSystemSTBIndex = new wxStaticText( this, wxID_ANY, wxT("STB Index:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemSTBIndex->Wrap( -1 );
	hloSystemSTBIndex->Add( lblSystemSTBIndex, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemSTBIndex = new wxTextCtrl( this, ID_SystemSTBIndex, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloSystemSTBIndex->Add( txtSystemSTBIndex, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemDWs->Add( hloSystemSTBIndex, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemUseAni;
	hloSystemUseAni = new wxBoxSizer( wxHORIZONTAL );

	lblSystemUseAni = new wxStaticText( this, wxID_ANY, wxT("Use Animation:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblSystemUseAni->Wrap( -1 );
	hloSystemUseAni->Add( lblSystemUseAni, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemUseAni = new wxTextCtrl( this, ID_SystemUseAni, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloSystemUseAni->Add( txtSystemUseAni, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemDWs->Add( hloSystemUseAni, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemAniLoopCt;
	hloSystemAniLoopCt = new wxBoxSizer( wxHORIZONTAL );

	lblSystemAniLoopCt = new wxStaticText( this, wxID_ANY, wxT("Loop Count:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblSystemAniLoopCt->Wrap( -1 );
	hloSystemAniLoopCt->Add( lblSystemAniLoopCt, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemAniLoopCt = new wxTextCtrl( this, ID_SystemAniLoopCt, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloSystemAniLoopCt->Add( txtSystemAniLoopCt, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemDWs->Add( hloSystemAniLoopCt, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemAniSTBIndex;
	hloSystemAniSTBIndex = new wxBoxSizer( wxHORIZONTAL );

	lblSystemAniSTBIndex = new wxStaticText( this, wxID_ANY, wxT("Anim STB Idx:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblSystemAniSTBIndex->Wrap( -1 );
	hloSystemAniSTBIndex->Add( lblSystemAniSTBIndex, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemAniSTBIndex = new wxTextCtrl( this, ID_SystemAniSTBIndex, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloSystemAniSTBIndex->Add( txtSystemAniSTBIndex, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemDWs->Add( hloSystemAniSTBIndex, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemDelay;
	hloSystemDelay = new wxBoxSizer( wxHORIZONTAL );

	lblSystemDelay = new wxStaticText( this, wxID_ANY, wxT("Delay:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemDelay->Wrap( -1 );
	hloSystemDelay->Add( lblSystemDelay, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemDelay = new wxTextCtrl( this, ID_SystemDelay, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloSystemDelay->Add( txtSystemDelay, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemDWs->Add( hloSystemDelay, 1, wxEXPAND, 5 );

	wxBoxSizer* hloSystemIsLinked;
	hloSystemIsLinked = new wxBoxSizer( wxHORIZONTAL );

	lblSystemIsLinked = new wxStaticText( this, wxID_ANY, wxT("Is Linked:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemIsLinked->Wrap( -1 );
	hloSystemIsLinked->Add( lblSystemIsLinked, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtSystemIsLinked = new wxTextCtrl( this, ID_SystemIsLinked, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloSystemIsLinked->Add( txtSystemIsLinked, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloSystemDWs->Add( hloSystemIsLinked, 1, wxEXPAND, 5 );


	hloSystemsBottom->Add( vloSystemDWs, 1, wxALL|wxEXPAND, 5 );


	vloSystems->Add( hloSystemsBottom, 1, wxEXPAND, 5 );


	vloLeft->Add( vloSystems, 3, wxALL|wxEXPAND, 5 );


	gloMain->Add( vloLeft, 1, wxALL|wxEXPAND, 10 );

	wxBoxSizer* vloAnis;
	vloAnis = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* hloAnisControls;
	hloAnisControls = new wxBoxSizer( wxHORIZONTAL );

	hloAnisControls->SetMinSize( wxSize( -1,30 ) );
	lblAnisCt = new wxStaticText( this, ID_Anis, wxT("Animations"), wxDefaultPosition, wxSize( 130,-1 ), wxALIGN_LEFT );
	lblAnisCt->Wrap( -1 );
	lblAnisCt->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	hloAnisControls->Add( lblAnisCt, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	hloAnisControls->Add( 0, 0, 1, wxEXPAND, 5 );

	btnPrevAni = new wxButton( this, ID_PrevAni, wxT("<"), wxDefaultPosition, wxDefaultSize, 0 );
	btnPrevAni->SetMinSize( wxSize( 35,25 ) );

	hloAnisControls->Add( btnPrevAni, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtCurAni = new wxTextCtrl( this, ID_CurAni, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTER );
	txtCurAni->SetMinSize( wxSize( -1,25 ) );

	hloAnisControls->Add( txtCurAni, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	btnNextAni = new wxButton( this, ID_NextAni, wxT(">"), wxDefaultPosition, wxDefaultSize, 0 );
	btnNextAni->SetMinSize( wxSize( 35,25 ) );

	hloAnisControls->Add( btnNextAni, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	btnAddAni = new wxButton( this, ID_AddAni, wxT("Append"), wxDefaultPosition, wxDefaultSize, 0 );
	btnAddAni->SetMinSize( wxSize( -1,25 ) );
	btnAddAni->SetMaxSize( wxSize( 80,-1 ) );

	hloAnisControls->Add( btnAddAni, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAnis->Add( hloAnisControls, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	wxBoxSizer* hloAniName;
	hloAniName = new wxBoxSizer( wxHORIZONTAL );

	lblAniName = new wxStaticText( this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblAniName->Wrap( -1 );
	hloAniName->Add( lblAniName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniName = new wxTextCtrl( this, ID_AniName, wxEmptyString, wxDefaultPosition, wxSize( 350,25 ), 0 );
	hloAniName->Add( txtAniName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAnis->Add( hloAniName, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniUName;
	hloAniUName = new wxBoxSizer( wxHORIZONTAL );

	lblAniUName = new wxStaticText( this, wxID_ANY, wxT("Unique Name:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblAniUName->Wrap( -1 );
	hloAniUName->Add( lblAniUName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniUName = new wxTextCtrl( this, ID_AniUName, wxEmptyString, wxDefaultPosition, wxSize( 350,25 ), 0 );
	hloAniUName->Add( txtAniUName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAnis->Add( hloAniUName, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniZMSFile;
	hloAniZMSFile = new wxBoxSizer( wxHORIZONTAL );

	lblAniZMSFile = new wxStaticText( this, wxID_ANY, wxT("ZMS File:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblAniZMSFile->Wrap( -1 );
	hloAniZMSFile->Add( lblAniZMSFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniZMSFile = new wxTextCtrl( this, ID_AniZMSFile, wxEmptyString, wxDefaultPosition, wxSize( 350,25 ), 0 );
	hloAniZMSFile->Add( txtAniZMSFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAnis->Add( hloAniZMSFile, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniZMOFile;
	hloAniZMOFile = new wxBoxSizer( wxHORIZONTAL );

	lblAniZMOFile = new wxStaticText( this, wxID_ANY, wxT("ZMO File:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblAniZMOFile->Wrap( -1 );
	hloAniZMOFile->Add( lblAniZMOFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniZMOFile = new wxTextCtrl( this, ID_AniZMOFile, wxEmptyString, wxDefaultPosition, wxSize( 350,25 ), 0 );
	hloAniZMOFile->Add( txtAniZMOFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAnis->Add( hloAniZMOFile, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniDDSFile;
	hloAniDDSFile = new wxBoxSizer( wxHORIZONTAL );

	lblAniDDSFile = new wxStaticText( this, wxID_ANY, wxT("DDS File:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblAniDDSFile->Wrap( -1 );
	hloAniDDSFile->Add( lblAniDDSFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniDDSFile = new wxTextCtrl( this, ID_AniDDSFile, wxEmptyString, wxDefaultPosition, wxSize( 350,25 ), 0 );
	hloAniDDSFile->Add( txtAniDDSFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAnis->Add( hloAniDDSFile, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAnisMiddle;
	hloAnisMiddle = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* vloAnisMidLeft;
	vloAnisMidLeft = new wxBoxSizer( wxVERTICAL );

	vloAnisMidLeft->SetMinSize( wxSize( -1,90 ) );
	wxBoxSizer* hloAnisEnables;
	hloAnisEnables = new wxBoxSizer( wxHORIZONTAL );

	chkAniTwoSided = new wxCheckBox( this, ID_AniTwoSided, wxT("Two-Sided"), wxDefaultPosition, wxSize( 110,20 ), wxALIGN_RIGHT );
	hloAnisEnables->Add( chkAniTwoSided, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	chkAniAlpha = new wxCheckBox( this, ID_AniAlpha, wxT("α"), wxDefaultPosition, wxSize( 50,20 ), wxALIGN_RIGHT );
	hloAnisEnables->Add( chkAniAlpha, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	chkAniAlphaTest = new wxCheckBox( this, ID_AniAlphaTest, wxT("α-test"), wxDefaultPosition, wxSize( 80,20 ), wxALIGN_RIGHT );
	hloAnisEnables->Add( chkAniAlphaTest, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	chkAniZTest = new wxCheckBox( this, ID_AniZTest, wxT("z-test"), wxDefaultPosition, wxSize( 75,20 ), wxALIGN_RIGHT );
	hloAnisEnables->Add( chkAniZTest, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	chkAniZWrite = new wxCheckBox( this, ID_AniZWrite, wxT("z-write"), wxDefaultPosition, wxSize( 70,20 ), wxALIGN_RIGHT );
	hloAnisEnables->Add( chkAniZWrite, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAnisMidLeft->Add( hloAnisEnables, 0, wxEXPAND, 5 );

	wxBoxSizer* vloAnisBlends;
	vloAnisBlends = new wxBoxSizer( wxHORIZONTAL );

	vloAnisBlends->SetMinSize( wxSize( -1,30 ) );
	wxBoxSizer* vloAniBlendTypes;
	vloAniBlendTypes = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* hloAniSourceBlend;
	hloAniSourceBlend = new wxBoxSizer( wxHORIZONTAL );

	hloAniSourceBlend->SetMinSize( wxSize( 280,-1 ) );
	lblAniSourceBlend = new wxStaticText( this, wxID_ANY, wxT("Src Blend:"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	lblAniSourceBlend->Wrap( -1 );
	hloAniSourceBlend->Add( lblAniSourceBlend, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	cmbAniSourceBlend = new wxComboBox( this, ID_AniSrcBlend, wxEmptyString, wxDefaultPosition, wxSize( 190,25 ), 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	hloAniSourceBlend->Add( cmbAniSourceBlend, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniBlendTypes->Add( hloAniSourceBlend, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniDestBlend;
	hloAniDestBlend = new wxBoxSizer( wxHORIZONTAL );

	lblAniDestBlend = new wxStaticText( this, wxID_ANY, wxT("Dst Blend:"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	lblAniDestBlend->Wrap( -1 );
	hloAniDestBlend->Add( lblAniDestBlend, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	cmbAniDestBlend = new wxComboBox( this, ID_AniDestBlend, wxEmptyString, wxDefaultPosition, wxSize( 190,25 ), 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	hloAniDestBlend->Add( cmbAniDestBlend, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniBlendTypes->Add( hloAniDestBlend, 1, wxEXPAND, 5 );


	vloAnisBlends->Add( vloAniBlendTypes, 1, wxEXPAND, 5 );

	wxBoxSizer* vloAniBlendOp;
	vloAniBlendOp = new wxBoxSizer( wxVERTICAL );

	lblAniBlendOp = new wxStaticText( this, wxID_ANY, wxT("Blend Op:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblAniBlendOp->Wrap( -1 );
	vloAniBlendOp->Add( lblAniBlendOp, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	cmbAniBlendOp = new wxComboBox( this, ID_AniBlendOp, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	vloAniBlendOp->Add( cmbAniBlendOp, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAnisBlends->Add( vloAniBlendOp, 1, wxALIGN_BOTTOM, 0 );


	vloAnisMidLeft->Add( vloAnisBlends, 0, wxEXPAND, 5 );


	hloAnisMiddle->Add( vloAnisMidLeft, 0, wxALL|wxEXPAND, 5 );


	vloAnis->Add( hloAnisMiddle, 0, wxEXPAND, 5 );

	wxBoxSizer* hloAnisBottom;
	hloAnisBottom = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* vloAniFloats;
	vloAniFloats = new wxBoxSizer( wxVERTICAL );

	vloAniFloats->SetMinSize( wxSize( 135,-1 ) );
	wxBoxSizer* hloAniPosX;
	hloAniPosX = new wxBoxSizer( wxHORIZONTAL );

	lblSystemPosX1 = new wxStaticText( this, wxID_ANY, wxT("Position X:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemPosX1->Wrap( -1 );
	hloAniPosX->Add( lblSystemPosX1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniPosX = new wxTextCtrl( this, ID_AniPosX, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloAniPosX->Add( txtAniPosX, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniFloats->Add( hloAniPosX, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniPosY;
	hloAniPosY = new wxBoxSizer( wxHORIZONTAL );

	lblAniPosY = new wxStaticText( this, wxID_ANY, wxT("Position Y:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblAniPosY->Wrap( -1 );
	hloAniPosY->Add( lblAniPosY, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniPosY = new wxTextCtrl( this, ID_AniPosY, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloAniPosY->Add( txtAniPosY, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniFloats->Add( hloAniPosY, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniPosZ;
	hloAniPosZ = new wxBoxSizer( wxHORIZONTAL );

	lblAniPosZ = new wxStaticText( this, wxID_ANY, wxT("Position Z:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblAniPosZ->Wrap( -1 );
	hloAniPosZ->Add( lblAniPosZ, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniPosZ = new wxTextCtrl( this, ID_AniPosZ, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloAniPosZ->Add( txtAniPosZ, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniFloats->Add( hloAniPosZ, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniRotX;
	hloAniRotX = new wxBoxSizer( wxHORIZONTAL );

	lblSystemRotX1 = new wxStaticText( this, wxID_ANY, wxT("Rotation X:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblSystemRotX1->Wrap( -1 );
	hloAniRotX->Add( lblSystemRotX1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniRotX = new wxTextCtrl( this, ID_AniRotX, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloAniRotX->Add( txtAniRotX, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniFloats->Add( hloAniRotX, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniRotY;
	hloAniRotY = new wxBoxSizer( wxHORIZONTAL );

	lblAniRotY = new wxStaticText( this, wxID_ANY, wxT("Rotation Y:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblAniRotY->Wrap( -1 );
	hloAniRotY->Add( lblAniRotY, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniRotY = new wxTextCtrl( this, ID_AniRotY, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloAniRotY->Add( txtAniRotY, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniFloats->Add( hloAniRotY, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniRotZ;
	hloAniRotZ = new wxBoxSizer( wxHORIZONTAL );

	lblAniRotZ = new wxStaticText( this, wxID_ANY, wxT("Rotation Z:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblAniRotZ->Wrap( -1 );
	hloAniRotZ->Add( lblAniRotZ, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniRotZ = new wxTextCtrl( this, ID_AniRotZ, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloAniRotZ->Add( txtAniRotZ, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniFloats->Add( hloAniRotZ, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniRotW;
	hloAniRotW = new wxBoxSizer( wxHORIZONTAL );

	lblAniRotW = new wxStaticText( this, wxID_ANY, wxT("Rotation W:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblAniRotW->Wrap( -1 );
	hloAniRotW->Add( lblAniRotW, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniRotW = new wxTextCtrl( this, ID_AniRotW, wxEmptyString, wxDefaultPosition, wxSize( 100,25 ), 0 );
	hloAniRotW->Add( txtAniRotW, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniFloats->Add( hloAniRotW, 1, wxEXPAND, 5 );


	hloAnisBottom->Add( vloAniFloats, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* vloAniDWs;
	vloAniDWs = new wxBoxSizer( wxVERTICAL );

	vloAniDWs->SetMinSize( wxSize( -135,-1 ) );
	wxBoxSizer* hloAniSTBIndex;
	hloAniSTBIndex = new wxBoxSizer( wxHORIZONTAL );

	lblAniSTBIndex = new wxStaticText( this, wxID_ANY, wxT("STB Index:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblAniSTBIndex->Wrap( -1 );
	hloAniSTBIndex->Add( lblAniSTBIndex, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniSTBIndex = new wxTextCtrl( this, ID_AniSTBIndex, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloAniSTBIndex->Add( txtAniSTBIndex, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniDWs->Add( hloAniSTBIndex, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniUseAni;
	hloAniUseAni = new wxBoxSizer( wxHORIZONTAL );

	lblAniUseAni = new wxStaticText( this, wxID_ANY, wxT("Use Animation:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblAniUseAni->Wrap( -1 );
	hloAniUseAni->Add( lblAniUseAni, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniUseAni = new wxTextCtrl( this, ID_AniUseAni, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloAniUseAni->Add( txtAniUseAni, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniDWs->Add( hloAniUseAni, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniAniLoopCt;
	hloAniAniLoopCt = new wxBoxSizer( wxHORIZONTAL );

	lblAniAniLoopCt = new wxStaticText( this, wxID_ANY, wxT("Loop Count:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblAniAniLoopCt->Wrap( -1 );
	hloAniAniLoopCt->Add( lblAniAniLoopCt, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniAniLoopCt = new wxTextCtrl( this, ID_AniAniLoopCt, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloAniAniLoopCt->Add( txtAniAniLoopCt, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniDWs->Add( hloAniAniLoopCt, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniAniSTBIndex;
	hloAniAniSTBIndex = new wxBoxSizer( wxHORIZONTAL );

	lblAniAniSTBIndex = new wxStaticText( this, wxID_ANY, wxT("Anim STB Idx:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblAniAniSTBIndex->Wrap( -1 );
	hloAniAniSTBIndex->Add( lblAniAniSTBIndex, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniAniSTBIndex = new wxTextCtrl( this, ID_AniAniSTBIndex, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloAniAniSTBIndex->Add( txtAniAniSTBIndex, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniDWs->Add( hloAniAniSTBIndex, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniDelay;
	hloAniDelay = new wxBoxSizer( wxHORIZONTAL );

	lblAniDelay = new wxStaticText( this, wxID_ANY, wxT("Delay:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblAniDelay->Wrap( -1 );
	hloAniDelay->Add( lblAniDelay, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniDelay = new wxTextCtrl( this, ID_AniDelay, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloAniDelay->Add( txtAniDelay, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniDWs->Add( hloAniDelay, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniIsLinked;
	hloAniIsLinked = new wxBoxSizer( wxHORIZONTAL );

	lblAniIsLinked = new wxStaticText( this, wxID_ANY, wxT("Is Linked:"), wxDefaultPosition, wxSize( 75,-1 ), 0 );
	lblAniIsLinked->Wrap( -1 );
	hloAniIsLinked->Add( lblAniIsLinked, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniIsLinked = new wxTextCtrl( this, ID_AniIsLinked, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloAniIsLinked->Add( txtAniIsLinked, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniDWs->Add( hloAniIsLinked, 1, wxEXPAND, 5 );

	wxBoxSizer* hloAniRepeatCt;
	hloAniRepeatCt = new wxBoxSizer( wxHORIZONTAL );

	lblAniRepeatCt = new wxStaticText( this, wxID_ANY, wxT("Repeat Count:"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblAniRepeatCt->Wrap( -1 );
	hloAniRepeatCt->Add( lblAniRepeatCt, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	txtAniRepeatCt = new wxTextCtrl( this, ID_AniRepeatCt, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	hloAniRepeatCt->Add( txtAniRepeatCt, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	vloAniDWs->Add( hloAniRepeatCt, 1, wxEXPAND, 5 );


	hloAnisBottom->Add( vloAniDWs, 1, wxALL|wxEXPAND, 5 );


	vloAnis->Add( hloAnisBottom, 0, wxEXPAND, 5 );


	gloMain->Add( vloAnis, 1, wxALL|wxEXPAND, 10 );


	this->SetSizer( gloMain );
	this->Layout();
}

pnlEFT::~pnlEFT()
{
}
