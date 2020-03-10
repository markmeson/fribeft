#ifndef MAINFRAME_H
#define MAINFRAME_H

#define DEFAULTW 940
#define DEFAULTH 613

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "efttypes.h"
#include "eftpanel.h"
#include "eft.h"

enum
{
	ID_Open = 1,
	ID_Close = 2,
	ID_Save = 3,
	ID_SaveAs = 4,
};

class mainframe : public wxFrame {
	public:
    mainframe(const wxString& title, const wxPoint& pos, const wxSize& size);
		void setstatus(const char *st);
		void open(const char *path, const char *f = "");
		pnlEFT *pnl;
		void enablesave(bool edited);
	private:
		void close();
		wxMenu *menuFile;
		int m_icursystem;
		int m_icurani;
		struct _EFTFILE *m_cureft;
		struct _SYSTEM **m_systems;
		struct _ANIMATION **m_anis;
		void updatestr(char **dest, wxString s);
		void updatedw(unsigned *d, wxString s);
		void updatefloat(float *f, wxString s);

    void OnClose(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event);

		//Buttons
		void OnPrevSystem(wxCommandEvent& event);
		void OnNextSystem(wxCommandEvent& event);
		void OnAddSystem(wxCommandEvent& event);
		void OnPrevAni(wxCommandEvent& event);
		void OnNextAni(wxCommandEvent& event);
		void OnAddAni(wxCommandEvent& event);

		//ChkBoxes
		void OnAniTwoSided(wxCommandEvent& event);
		void OnAniAlpha(wxCommandEvent& event);
		void OnAniAlphaTest(wxCommandEvent& event);
		void OnAniZTest(wxCommandEvent& event);
		void OnZWrite(wxCommandEvent& event);

		//CmbBoxes
		void OnSrcBlendSelect(wxCommandEvent& event);
		void OnDestBlendSelect(wxCommandEvent& event);
		void OnBlendOpSelect(wxCommandEvent& event);

		//Text Ctrls
		void OnJumpSystem(wxCommandEvent& event);
		void OnJumpAni(wxCommandEvent& event);
		void OnEFTName(wxCommandEvent& event);
		void OnUseSound(wxCommandEvent& event);
		void OnSoundLoopCt(wxCommandEvent& event);
		void OnSoundFile(wxCommandEvent& event);
		void OnSystemName(wxCommandEvent& event);
		void OnSystemUName(wxCommandEvent& event);
		void OnSystemPTLFile(wxCommandEvent& event);
		void OnSystemZMOFile(wxCommandEvent& event);
		void OnSystemPosX(wxCommandEvent& event);
		void OnSystemPosY(wxCommandEvent& event);
		void OnSystemPosZ(wxCommandEvent& event);
		void OnSystemRotX(wxCommandEvent& event);
		void OnSystemRotY(wxCommandEvent& event);
		void OnSystemRotZ(wxCommandEvent& event);
		void OnSystemRotW(wxCommandEvent& event);
		void OnSystemSTBIndex(wxCommandEvent& event);
		void OnSystemUseAni(wxCommandEvent& event);
		void OnSystemAniLoopCt(wxCommandEvent& event);
		void OnSystemAniSTBIndex(wxCommandEvent& event);
		void OnSystemDelay(wxCommandEvent& event);
		void OnSystemIsLinked(wxCommandEvent& event);
		void OnAniName(wxCommandEvent& event);
		void OnAniUName(wxCommandEvent& event);
		void OnAniZMSFile(wxCommandEvent& event);
		void OnAniZMOFile(wxCommandEvent& event);
		void OnAniDDSFile(wxCommandEvent& event);
		void OnAniPosX(wxCommandEvent& event);
		void OnAniPosY(wxCommandEvent& event);
		void OnAniPosZ(wxCommandEvent& event);
		void OnAniRotX(wxCommandEvent& event);
		void OnAniRotY(wxCommandEvent& event);
		void OnAniRotZ(wxCommandEvent& event);
		void OnAniRotW(wxCommandEvent& event);
		void OnAniSTBIndex(wxCommandEvent& event);
		void OnAniUseAni(wxCommandEvent& event);
		void OnAniAniLoopCt(wxCommandEvent& event);
		void OnAniAniSTBIndex(wxCommandEvent& event);
		void OnAniDelay(wxCommandEvent& event);
		void OnAniIsLinked(wxCommandEvent& event);
		void OnAniRepeatCt(wxCommandEvent& event);

		void anienableall();
		void anidisableall();
		void hdrenableall();
		void hdrdisableall();
		void systemenableall();
		void systemdisableall();

		void hdrclearall();
		void aniclearall();
		void systemclearall();

    wxDECLARE_EVENT_TABLE();
};

#endif
