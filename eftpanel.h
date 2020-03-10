///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

#define ID_EFTName 1000
#define ID_UseSound 1001
#define ID_SoundLoopCt 1002
#define ID_SoundFile 1003
#define ID_Systems 1004
#define ID_PrevSystem 1005
#define ID_CurSystem 1006
#define ID_NextSystem 1007
#define ID_AddSystem 1008
#define ID_SystemName 1009
#define ID_SystemUName 1010
#define ID_SystemPTLFile 1011
#define ID_SystemZMOFile 1012
#define ID_SystemPosX 1013
#define ID_SystemPosY 1014
#define ID_SystemPosZ 1015
#define ID_SystemRotX 1016
#define ID_SystemRotY 1017
#define ID_SystemRotZ 1018
#define ID_SystemRotW 1019
#define ID_SystemSTBIndex 1020
#define ID_SystemUseAni 1021
#define ID_SystemAniLoopCt 1022
#define ID_SystemAniSTBIndex 1023
#define ID_SystemDelay 1024
#define ID_SystemIsLinked 1025
#define ID_Anis 1026
#define ID_PrevAni 1027
#define ID_CurAni 1028
#define ID_NextAni 1029
#define ID_AddAni 1030
#define ID_AniName 1031
#define ID_AniUName 1032
#define ID_AniZMSFile 1033
#define ID_AniZMOFile 1034
#define ID_AniDDSFile 1035
#define ID_AniTwoSided 1036
#define ID_AniAlpha 1037
#define ID_AniAlphaTest 1038
#define ID_AniZTest 1039
#define ID_AniZWrite 1040
#define ID_AniSrcBlend 1041
#define ID_AniDestBlend 1042
#define ID_AniBlendOp 1043
#define ID_AniPosX 1044
#define ID_AniPosY 1045
#define ID_AniPosZ 1046
#define ID_AniRotX 1047
#define ID_AniRotY 1048
#define ID_AniRotZ 1049
#define ID_AniRotW 1050
#define ID_AniSTBIndex 1051
#define ID_AniUseAni 1052
#define ID_AniAniLoopCt 1053
#define ID_AniAniSTBIndex 1054
#define ID_AniDelay 1055
#define ID_AniIsLinked 1056
#define ID_AniRepeatCt 1057

///////////////////////////////////////////////////////////////////////////////
/// Class pnlEFT
///////////////////////////////////////////////////////////////////////////////
class pnlEFT : public wxPanel
{
	private:

	public:
		wxStaticText* lblEFTName;
		wxTextCtrl* txtEFTName;
		wxStaticText* lblUseSound;
		wxTextCtrl* txtUseSound;
		wxStaticText* lblSoundLoopCt;
		wxTextCtrl* txtSoundLoopCt;
		wxStaticText* lblSoundFile;
		wxTextCtrl* txtSoundFile;
		wxStaticLine* linLeft;
		wxStaticText* lblSystemsCt;
		wxButton* btnPrevSystem;
		wxTextCtrl* txtCurSystem;
		wxButton* btnNextSystem;
		wxButton* btnAddSystem;
		wxStaticText* lblSystemName;
		wxTextCtrl* txtSystemName;
		wxStaticText* lblSoundLoopCt4;
		wxTextCtrl* txtSoundLoopCt4;
		wxStaticText* lblSystemUName;
		wxTextCtrl* txtSystemUName;
		wxStaticText* lblSystemPTLFile;
		wxTextCtrl* txtSystemPTLFile;
		wxStaticText* lblSystemZMOFile;
		wxTextCtrl* txtSystemZMOFile;
		wxStaticText* lblSystemPosX;
		wxTextCtrl* txtSystemPosX;
		wxStaticText* lblSystemPosY;
		wxTextCtrl* txtSystemPosY;
		wxStaticText* lblSystemPosZ;
		wxTextCtrl* txtSystemPosZ;
		wxStaticText* lblSystemRotX;
		wxTextCtrl* txtSystemRotX;
		wxStaticText* lblSystemRotY;
		wxTextCtrl* txtSystemRotY;
		wxStaticText* lblSystemRotZ;
		wxTextCtrl* txtSystemRotZ;
		wxStaticText* lblSystemRotW;
		wxTextCtrl* txtSystemRotW;
		wxStaticText* lblSystemSTBIndex;
		wxTextCtrl* txtSystemSTBIndex;
		wxStaticText* lblSystemUseAni;
		wxTextCtrl* txtSystemUseAni;
		wxStaticText* lblSystemAniLoopCt;
		wxTextCtrl* txtSystemAniLoopCt;
		wxStaticText* lblSystemAniSTBIndex;
		wxTextCtrl* txtSystemAniSTBIndex;
		wxStaticText* lblSystemDelay;
		wxTextCtrl* txtSystemDelay;
		wxStaticText* lblSystemIsLinked;
		wxTextCtrl* txtSystemIsLinked;
		wxStaticText* lblAnisCt;
		wxButton* btnPrevAni;
		wxTextCtrl* txtCurAni;
		wxButton* btnNextAni;
		wxButton* btnAddAni;
		wxStaticText* lblAniName;
		wxTextCtrl* txtAniName;
		wxStaticText* lblAniUName;
		wxTextCtrl* txtAniUName;
		wxStaticText* lblAniZMSFile;
		wxTextCtrl* txtAniZMSFile;
		wxStaticText* lblAniZMOFile;
		wxTextCtrl* txtAniZMOFile;
		wxStaticText* lblAniDDSFile;
		wxTextCtrl* txtAniDDSFile;
		wxCheckBox* chkAniTwoSided;
		wxCheckBox* chkAniAlpha;
		wxCheckBox* chkAniAlphaTest;
		wxCheckBox* chkAniZTest;
		wxCheckBox* chkAniZWrite;
		wxStaticText* lblAniSourceBlend;
		wxComboBox* cmbAniSourceBlend;
		wxStaticText* lblAniDestBlend;
		wxComboBox* cmbAniDestBlend;
		wxStaticText* lblAniBlendOp;
		wxComboBox* cmbAniBlendOp;
		wxStaticText* lblSystemPosX1;
		wxTextCtrl* txtAniPosX;
		wxStaticText* lblAniPosY;
		wxTextCtrl* txtAniPosY;
		wxStaticText* lblAniPosZ;
		wxTextCtrl* txtAniPosZ;
		wxStaticText* lblSystemRotX1;
		wxTextCtrl* txtAniRotX;
		wxStaticText* lblAniRotY;
		wxTextCtrl* txtAniRotY;
		wxStaticText* lblAniRotZ;
		wxTextCtrl* txtAniRotZ;
		wxStaticText* lblAniRotW;
		wxTextCtrl* txtAniRotW;
		wxStaticText* lblAniSTBIndex;
		wxTextCtrl* txtAniSTBIndex;
		wxStaticText* lblAniUseAni;
		wxTextCtrl* txtAniUseAni;
		wxStaticText* lblAniAniLoopCt;
		wxTextCtrl* txtAniAniLoopCt;
		wxStaticText* lblAniAniSTBIndex;
		wxTextCtrl* txtAniAniSTBIndex;
		wxStaticText* lblAniDelay;
		wxTextCtrl* txtAniDelay;
		wxStaticText* lblAniIsLinked;
		wxTextCtrl* txtAniIsLinked;
		wxStaticText* lblAniRepeatCt;
		wxTextCtrl* txtAniRepeatCt;

	//public:

		pnlEFT( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 940,613 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
		~pnlEFT();

};

