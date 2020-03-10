#include "mainframe.h"

extern char buffer[2048];

eft maineft;

wxBEGIN_EVENT_TABLE(mainframe, wxFrame)
    EVT_MENU(ID_Close, mainframe::OnClose)
    EVT_MENU(ID_Open,   mainframe::OnOpen)
    EVT_MENU(ID_Save,   mainframe::OnSave)
    EVT_MENU(ID_SaveAs,   mainframe::OnSaveAs)
    EVT_MENU(wxID_EXIT,  mainframe::OnExit)
		EVT_BUTTON(ID_PrevSystem, mainframe::OnPrevSystem)
		EVT_BUTTON(ID_NextSystem, mainframe::OnNextSystem)
		EVT_BUTTON(ID_AddSystem, mainframe::OnAddSystem)
		EVT_BUTTON(ID_PrevAni, mainframe::OnPrevAni)
		EVT_BUTTON(ID_NextAni, mainframe::OnNextAni)
		EVT_BUTTON(ID_AddAni, mainframe::OnAddAni)
		EVT_COMBOBOX(ID_AniSrcBlend, mainframe::OnSrcBlendSelect)
		EVT_COMBOBOX(ID_AniDestBlend, mainframe::OnDestBlendSelect)
		EVT_COMBOBOX(ID_AniBlendOp, mainframe::OnBlendOpSelect)
		EVT_CHECKBOX(ID_AniTwoSided, mainframe::OnAniTwoSided)
		EVT_CHECKBOX(ID_AniAlpha, mainframe::OnAniAlpha)
		EVT_CHECKBOX(ID_AniAlphaTest, mainframe::OnAniAlphaTest)
		EVT_CHECKBOX(ID_AniZTest, mainframe::OnAniZTest)
		EVT_CHECKBOX(ID_AniZWrite, mainframe::OnZWrite)
		EVT_TEXT(ID_EFTName, mainframe::OnEFTName)
		EVT_TEXT(ID_UseSound, mainframe::OnUseSound)
		EVT_TEXT(ID_SoundLoopCt, mainframe::OnSoundLoopCt)
		EVT_TEXT(ID_SoundFile, mainframe::OnSoundFile)
		EVT_TEXT(ID_CurSystem, mainframe::OnJumpSystem)
		EVT_TEXT(ID_SystemName, mainframe::OnSystemName)
		EVT_TEXT(ID_SystemUName, mainframe::OnSystemUName)
		EVT_TEXT(ID_SystemPTLFile, mainframe::OnSystemPTLFile)
		EVT_TEXT(ID_SystemZMOFile, mainframe::OnSystemZMOFile)
		EVT_TEXT(ID_SystemPosX, mainframe::OnSystemPosX)
		EVT_TEXT(ID_SystemPosY, mainframe::OnSystemPosY)
		EVT_TEXT(ID_SystemPosZ, mainframe::OnSystemPosZ)
		EVT_TEXT(ID_SystemRotX, mainframe::OnSystemRotX)
		EVT_TEXT(ID_SystemRotY, mainframe::OnSystemRotY)
		EVT_TEXT(ID_SystemRotZ, mainframe::OnSystemRotZ)
		EVT_TEXT(ID_SystemRotW, mainframe::OnSystemRotW)
		EVT_TEXT(ID_SystemSTBIndex, mainframe::OnSystemSTBIndex)
		EVT_TEXT(ID_SystemUseAni, mainframe::OnSystemUseAni)
		EVT_TEXT(ID_SystemAniLoopCt, mainframe::OnSystemAniLoopCt)
		EVT_TEXT(ID_SystemAniSTBIndex, mainframe::OnSystemAniSTBIndex)
		EVT_TEXT(ID_SystemDelay, mainframe::OnSystemDelay)
		EVT_TEXT(ID_SystemIsLinked, mainframe::OnSystemIsLinked)
		EVT_TEXT(ID_CurAni, mainframe::OnJumpAni)
		EVT_TEXT(ID_AniName, mainframe::OnAniName)
		EVT_TEXT(ID_AniUName, mainframe::OnAniUName)
		EVT_TEXT(ID_AniZMSFile, mainframe::OnAniZMSFile)
		EVT_TEXT(ID_AniZMOFile, mainframe::OnAniZMOFile)
		EVT_TEXT(ID_AniDDSFile, mainframe::OnAniDDSFile)
		EVT_TEXT(ID_AniPosX, mainframe::OnAniPosX)
		EVT_TEXT(ID_AniPosY, mainframe::OnAniPosY)
		EVT_TEXT(ID_AniPosZ, mainframe::OnAniPosZ)
		EVT_TEXT(ID_AniRotX, mainframe::OnAniRotX)
		EVT_TEXT(ID_AniRotY, mainframe::OnAniRotY)
		EVT_TEXT(ID_AniRotZ, mainframe::OnAniRotZ)
		EVT_TEXT(ID_AniRotW, mainframe::OnAniRotW)
		EVT_TEXT(ID_AniSTBIndex, mainframe::OnAniSTBIndex)
		EVT_TEXT(ID_AniUseAni, mainframe::OnAniUseAni)
		EVT_TEXT(ID_AniAniLoopCt, mainframe::OnAniAniLoopCt)
		EVT_TEXT(ID_AniAniSTBIndex, mainframe::OnAniAniSTBIndex)
		EVT_TEXT(ID_AniDelay, mainframe::OnAniDelay)
		EVT_TEXT(ID_AniIsLinked, mainframe::OnAniIsLinked)
		EVT_TEXT(ID_AniRepeatCt, mainframe::OnAniRepeatCt)
wxEND_EVENT_TABLE()

mainframe::mainframe(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    menuFile = new wxMenu;
    menuFile->Append(ID_Open, "&Open...\tCtrl-O", "Open an EFT File");
    menuFile->Append(ID_Close, "&Close...\tCtrl-X", "Close EFT File");
    menuFile->Append(ID_Save, "&Save...\tCtrl-S", "Save EFT File");
    menuFile->Append(ID_SaveAs, "&Save As...\tCtrl-A", "Save EFT File As...");
		menuFile->Enable(ID_Close, 0);
		menuFile->Enable(ID_Save, 0);
		menuFile->Enable(ID_SaveAs, 0);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar(menuBar);

		pnl = new pnlEFT(this, wxID_ANY);

    CreateStatusBar();
    SetStatusText("Welcome to Frib EFT Editor!");
		m_icursystem = 0;
		m_icurani = 0;

		//Set Up Combo Boxes
		pnl->cmbAniSourceBlend->Append("NONE");
		pnl->cmbAniSourceBlend->Append("ZERO");
		pnl->cmbAniSourceBlend->Append("ONE");
		pnl->cmbAniSourceBlend->Append("SRCCOLOR");
		pnl->cmbAniSourceBlend->Append("INVSRCCOLOR");
		pnl->cmbAniSourceBlend->Append("SRCALPHA");
		pnl->cmbAniSourceBlend->Append("INVSRCALPHA");
		pnl->cmbAniSourceBlend->Append("DESTALPHA");
		pnl->cmbAniSourceBlend->Append("INVDESTALPHA");
		pnl->cmbAniSourceBlend->Append("DESTCOLO");
		pnl->cmbAniSourceBlend->Append("INVDESTCOLOR");
		pnl->cmbAniSourceBlend->Append("SRCALPHASAT");
		pnl->cmbAniSourceBlend->Append("BOTHSRCALPHA");
		pnl->cmbAniSourceBlend->Append("BOTHINVSRCALPHA");
		pnl->cmbAniSourceBlend->Append("BLENDFACTOR");
		pnl->cmbAniSourceBlend->Append("INVBLENDFACTOR");
		pnl->cmbAniSourceBlend->Append("SRCCOLOR2");
		pnl->cmbAniSourceBlend->Append("INVSRCCOLOR2");
	
		pnl->cmbAniDestBlend->Append("NONE");
		pnl->cmbAniDestBlend->Append("ZERO");
		pnl->cmbAniDestBlend->Append("ONE");
		pnl->cmbAniDestBlend->Append("SRCCOLOR");
		pnl->cmbAniDestBlend->Append("INVSRCCOLOR");
		pnl->cmbAniDestBlend->Append("SRCALPHA");
		pnl->cmbAniDestBlend->Append("INVSRCALPHA");
		pnl->cmbAniDestBlend->Append("DESTALPHA");
		pnl->cmbAniDestBlend->Append("INVDESTALPHA");
		pnl->cmbAniDestBlend->Append("DESTCOLO");
		pnl->cmbAniDestBlend->Append("INVDESTCOLOR");
		pnl->cmbAniDestBlend->Append("SRCALPHASAT");
		pnl->cmbAniDestBlend->Append("BOTHSRCALPHA");
		pnl->cmbAniDestBlend->Append("BOTHINVSRCALPHA");
		pnl->cmbAniDestBlend->Append("BLENDFACTOR");
		pnl->cmbAniDestBlend->Append("INVBLENDFACTOR");
		pnl->cmbAniDestBlend->Append("SRCCOLOR2");
		pnl->cmbAniDestBlend->Append("INVSRCCOLOR2");

		pnl->cmbAniBlendOp->Append("NONE");
		pnl->cmbAniBlendOp->Append("ADD");
		pnl->cmbAniBlendOp->Append("SUB");
		pnl->cmbAniBlendOp->Append("RVRS SUB");
		pnl->cmbAniBlendOp->Append("MIN");
		pnl->cmbAniBlendOp->Append("MAX");
		
		hdrdisableall();
		systemdisableall();
		anidisableall();
}

void mainframe::setstatus(const char *st) {	SetStatusText(st); }

void mainframe::OnExit(wxCommandEvent& event) { 
	if(maineft.isOpen()) {
		wxCommandEvent ce;
		OnClose(ce);
	}
	Close(true); 
}

void mainframe::OnClose(wxCommandEvent& event) { 
	if(maineft.isEdited()) {
		int response = wxMessageBox("If you proceed without saving, your changes will be lost. Do you want to save the current file now?", "File has been modified", wxICON_QUESTION | wxYES_NO | wxCANCEL, this);
		if(response == wxCANCEL) {
			setstatus("Close File Canceled.");
			return;
		}
		if(response == wxYES) {
			wxFileDialog savedlg(this, _("Save EFT File"), "", "", "EFT files (*.eft;*.EFT)|*.eft;*.EFT", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
			if(savedlg.ShowModal() == wxID_CANCEL) {
				setstatus("Save canceled.");
				return;
			}
			if(!maineft.save(savedlg.GetPath())) {
				wxMessageBox("Error saving EFT File!", "Error", wxOK, this);
				return;
			}
			wxMessageBox("The file was saved successfully!", "Success", wxOK, this);
			setstatus("EFT file saved successfully.");
		}
	}

	close(); 

	hdrclearall();
	hdrdisableall();
	pnl->lblAnisCt->SetLabel("Animations");
	aniclearall();
	anidisableall();
	pnl->lblSystemsCt->SetLabel("Systems");
	systemclearall();
	systemdisableall();
}

void mainframe::close() {
	maineft.close();
	menuFile->Enable(ID_Close, 0);
	menuFile->Enable(ID_Save, 0);
	menuFile->Enable(ID_SaveAs, 0);
	SetClientSize(DEFAULTW, DEFAULTH);
	SetLabel("Frib EFT Editor");
}

void mainframe::enablesave(bool edited) {
	if(edited)
		menuFile->Enable(ID_Save, 1);
	else
		menuFile->Enable(ID_Save, 0);
}

void mainframe::OnOpen(wxCommandEvent& event) {
	wxFileDialog fdlg(this, "Open EFT File", "", "", "EFT files (*.eft;*.EFT)|*.eft;*.EFT", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

	if(maineft.isOpen()) {
		if(maineft.isEdited()) {
			int response = wxMessageBox("If you proceed without saving, your changes will be lost. Do you want to save the current file now?", "File has been modified", wxICON_QUESTION | wxYES_NO | wxCANCEL, this);
			if(response == wxCANCEL) {
				setstatus("Open File Canceled.");
				return;
			}
			if(response == wxYES) {
				wxFileDialog savedlg(this, _("Save EFT File"), "", "", "EFT files (*.eft;*.EFT)|*.eft;*.EFT", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
				if(savedlg.ShowModal() == wxID_CANCEL) {
					setstatus("Save canceled.");
					return;
				}
				if(!maineft.save(savedlg.GetPath())) {
					wxMessageBox("Error saving EFT File!", "Error", wxOK, this);
					return;
				}
				wxMessageBox("The file was saved successfully!", "Success", wxOK, this);
				setstatus("EFT file saved successfully.");
			}
		}

		if (fdlg.ShowModal() == wxID_CANCEL) {
			SetStatusText("Open File Canceled...");
			return;	
		}

		close();

		hdrclearall();
		hdrdisableall();
		systemclearall();
		systemdisableall();
		aniclearall();
		anidisableall();
	} else {
		if (fdlg.ShowModal() == wxID_CANCEL) {
			SetStatusText("Open File Canceled...");
			return;	
		}
	}

	open(fdlg.GetPath(), fdlg.GetFilename());
}

void mainframe::open(const char *path, const char *f) {
	if(!maineft.setfile(path, f)) {
		wxLogMessage("Error setting EFT file name");
		return;
	}
	int openresult;
	if((openresult = maineft.open())) {
		switch(openresult) {
			case FILENOTFOUND:
				wxLogMessage("EFT File Not Found!");
				break;
			case FILEOPENERR:
				wxLogMessage("Error opening EFT File!");
				break;
			case INVALIDFILE:
				wxLogMessage("File is not a valid EFT file!");
				break;
		}
		return;
	}

	//open EFT succeeded
	m_cureft = maineft.getcureft();
	m_systems = m_cureft->systems;
	m_anis = m_cureft->anis;
	
	hdrenableall();
	//Initialize First System
	int systemct = m_cureft->systemct;
	if(systemct) {
		m_icursystem = 1;
		systemenableall();
		pnl->btnPrevSystem->Enable(false);
		if(m_icursystem == systemct)
			pnl->btnNextSystem->Enable(false);
	}
	pnl->btnAddSystem->Enable(true);

	//Initialize First Animation
	int anict = m_cureft->anict;
	if(anict) {
		m_icurani = 1;
		anienableall();
		pnl->btnPrevAni->Enable(false);
		if(m_icurani == anict)
			pnl->btnNextAni->Enable(false);
	}
	pnl->btnAddAni->Enable(true);

	SetClientSize(DEFAULTW, DEFAULTH);
	sprintf(buffer, "Frib EFT Editor - %s", static_cast<const char *>(strlen(f) > 0 ? f : path));
	SetLabel(buffer);
	menuFile->Enable(ID_Close, 1);
	menuFile->Enable(ID_SaveAs, 1);
}

void mainframe::OnSave(wxCommandEvent& event) {
	if(maineft.save()) {
		wxMessageBox("The file was saved successfully!", "Success", wxOK, this);
		setstatus("EFT file saved successfully.");
	}
}

void mainframe::OnSaveAs(wxCommandEvent& event) {
	wxFileDialog savedlg(this, _("Save EFT File"), "", "", "EFT files (*.eft;*.EFT)|*.eft;*.EFT", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if(savedlg.ShowModal() == wxID_CANCEL) {
		setstatus("Save canceled.");
		return;
	}
	if(!maineft.save(savedlg.GetPath())) {
		wxMessageBox("Error saving EFT File!", "Error", wxOK, this);
		return;
	}
	wxMessageBox("The file was saved successfully!", "Success", wxOK, this);
	setstatus("EFT file saved successfully.");
}

void mainframe::hdrclearall() {
	pnl->txtEFTName->ChangeValue("");
	pnl->txtUseSound->ChangeValue("");
	pnl->txtSoundLoopCt->ChangeValue("");
	pnl->txtSoundFile->ChangeValue("");
}

void mainframe::hdrdisableall() {
	pnl->txtEFTName->Enable(false);
	pnl->txtUseSound->Enable(false);
	pnl->txtSoundLoopCt->Enable(false);
	pnl->txtSoundFile->Enable(false);
}

void mainframe::hdrenableall() {
	pnl->txtEFTName->Enable(true);
	pnl->txtUseSound->Enable(true);
	pnl->txtSoundLoopCt->Enable(true);
	pnl->txtSoundFile->Enable(true);
}

void mainframe::aniclearall() {
	pnl->txtCurAni->ChangeValue("");
	pnl->txtAniName->ChangeValue("");
	pnl->txtAniUName->ChangeValue("");
	pnl->txtAniZMSFile->ChangeValue("");
	pnl->txtAniZMOFile->ChangeValue("");
	pnl->txtAniDDSFile->ChangeValue("");
	pnl->chkAniTwoSided->SetValue(false);
	pnl->chkAniAlpha->SetValue(false);
	pnl->chkAniAlphaTest->SetValue(false);
	pnl->chkAniZTest->SetValue(false);
	pnl->chkAniZWrite->SetValue(false);
	pnl->cmbAniSourceBlend->SetSelection(0);
	pnl->cmbAniDestBlend->SetSelection(0);
	pnl->cmbAniBlendOp->SetSelection(0);
	pnl->txtAniPosX->ChangeValue("");
	pnl->txtAniPosY->ChangeValue("");
	pnl->txtAniPosZ->ChangeValue("");
	pnl->txtAniRotX->ChangeValue("");
	pnl->txtAniRotY->ChangeValue("");
	pnl->txtAniRotZ->ChangeValue("");
	pnl->txtAniRotW->ChangeValue("");
	pnl->txtAniSTBIndex->ChangeValue("");
	pnl->txtAniUseAni->ChangeValue("");
	pnl->txtAniAniLoopCt->ChangeValue("");
	pnl->txtAniAniSTBIndex->ChangeValue("");
	pnl->txtAniDelay->ChangeValue("");
	pnl->txtAniIsLinked->ChangeValue("");
	pnl->txtAniRepeatCt->ChangeValue("");

}

void mainframe::anidisableall() {
	pnl->btnPrevAni->Enable(false);
	pnl->btnNextAni->Enable(false);
	pnl->txtCurAni->Enable(false);
	pnl->btnAddAni->Enable(false);
	pnl->txtAniName->Enable(false);
	pnl->txtAniUName->Enable(false);
	pnl->txtAniZMSFile->Enable(false);
	pnl->txtAniZMOFile->Enable(false);
	pnl->txtAniDDSFile->Enable(false);
	pnl->chkAniTwoSided->Enable(false);
	pnl->chkAniAlpha->Enable(false);
	pnl->chkAniAlphaTest->Enable(false);
	pnl->chkAniZTest->Enable(false);
	pnl->chkAniZWrite->Enable(false);
	pnl->cmbAniSourceBlend->Enable(false);
	pnl->cmbAniDestBlend->Enable(false);
	pnl->cmbAniBlendOp->Enable(false);
	pnl->txtAniPosX->Enable(false);
	pnl->txtAniPosY->Enable(false);
	pnl->txtAniPosZ->Enable(false);
	pnl->txtAniRotX->Enable(false);
	pnl->txtAniRotY->Enable(false);
	pnl->txtAniRotZ->Enable(false);
	pnl->txtAniRotW->Enable(false);
	pnl->txtAniSTBIndex->Enable(false);
	pnl->txtAniUseAni->Enable(false);
	pnl->txtAniAniLoopCt->Enable(false);
	pnl->txtAniAniSTBIndex->Enable(false);
	pnl->txtAniDelay->Enable(false);
	pnl->txtAniIsLinked->Enable(false);
	pnl->txtAniRepeatCt->Enable(false);
}

void mainframe::anienableall() {
	pnl->btnPrevAni->Enable(true);
	pnl->btnNextAni->Enable(true);
	pnl->txtCurAni->Enable(true);
	pnl->btnAddAni->Enable(true);
	pnl->txtAniName->Enable(true);
	pnl->txtAniUName->Enable(true);
	pnl->txtAniZMSFile->Enable(true);
	pnl->txtAniZMOFile->Enable(true);
	pnl->txtAniDDSFile->Enable(true);
	pnl->chkAniTwoSided->Enable(true);
	pnl->chkAniAlpha->Enable(true);
	pnl->chkAniAlphaTest->Enable(true);
	pnl->chkAniZTest->Enable(true);
	pnl->chkAniZWrite->Enable(true);
	pnl->cmbAniSourceBlend->Enable(true);
	pnl->cmbAniDestBlend->Enable(true);
	pnl->cmbAniBlendOp->Enable(true);
	pnl->txtAniPosX->Enable(true);
	pnl->txtAniPosY->Enable(true);
	pnl->txtAniPosZ->Enable(true);
	pnl->txtAniRotX->Enable(true);
	pnl->txtAniRotY->Enable(true);
	pnl->txtAniRotZ->Enable(true);
	pnl->txtAniRotW->Enable(true);
	pnl->txtAniSTBIndex->Enable(true);
	pnl->txtAniUseAni->Enable(true);
	pnl->txtAniAniLoopCt->Enable(true);
	pnl->txtAniAniSTBIndex->Enable(true);
	pnl->txtAniDelay->Enable(true);
	pnl->txtAniIsLinked->Enable(true);
	pnl->txtAniRepeatCt->Enable(true);
}

void mainframe::systemclearall() {
	pnl->txtCurSystem->ChangeValue("");
	pnl->txtSystemName->ChangeValue("");
	pnl->txtSystemUName->ChangeValue("");
	pnl->txtSystemPTLFile->ChangeValue("");
	pnl->txtSystemZMOFile->ChangeValue("");
	pnl->txtSystemPosX->ChangeValue("");
	pnl->txtSystemPosY->ChangeValue("");
	pnl->txtSystemPosZ->ChangeValue("");
	pnl->txtSystemRotX->ChangeValue("");
	pnl->txtSystemRotY->ChangeValue("");
	pnl->txtSystemRotZ->ChangeValue("");
	pnl->txtSystemRotW->ChangeValue("");
	pnl->txtSystemSTBIndex->ChangeValue("");
	pnl->txtSystemUseAni->ChangeValue("");
	pnl->txtSystemAniLoopCt->ChangeValue("");
	pnl->txtSystemAniSTBIndex->ChangeValue("");
	pnl->txtSystemDelay->ChangeValue("");
	pnl->txtSystemIsLinked->ChangeValue("");
}

void mainframe::systemdisableall() {
	pnl->btnPrevSystem->Enable(false);
	pnl->btnNextSystem->Enable(false);
	pnl->txtCurSystem->Enable(false);
	pnl->btnAddSystem->Enable(false);
	pnl->txtSystemName->Enable(false);
	pnl->txtSystemUName->Enable(false);
	pnl->txtSystemPTLFile->Enable(false);
	pnl->txtSystemZMOFile->Enable(false);
	pnl->txtSystemPosX->Enable(false);
	pnl->txtSystemPosY->Enable(false);
	pnl->txtSystemPosZ->Enable(false);
	pnl->txtSystemRotX->Enable(false);
	pnl->txtSystemRotY->Enable(false);
	pnl->txtSystemRotZ->Enable(false);
	pnl->txtSystemRotW->Enable(false);
	pnl->txtSystemSTBIndex->Enable(false);
	pnl->txtSystemUseAni->Enable(false);
	pnl->txtSystemAniLoopCt->Enable(false);
	pnl->txtSystemAniSTBIndex->Enable(false);
	pnl->txtSystemDelay->Enable(false);
	pnl->txtSystemIsLinked->Enable(false);
}

void mainframe::systemenableall() {
	pnl->btnPrevSystem->Enable(true);
	pnl->btnNextSystem->Enable(true);
	pnl->txtCurSystem->Enable(true);
	pnl->btnAddSystem->Enable(true);
	pnl->txtSystemName->Enable(true);
	pnl->txtSystemUName->Enable(true);
	pnl->txtSystemPTLFile->Enable(true);
	pnl->txtSystemZMOFile->Enable(true);
	pnl->txtSystemPosX->Enable(true);
	pnl->txtSystemPosY->Enable(true);
	pnl->txtSystemPosZ->Enable(true);
	pnl->txtSystemRotX->Enable(true);
	pnl->txtSystemRotY->Enable(true);
	pnl->txtSystemRotZ->Enable(true);
	pnl->txtSystemRotW->Enable(true);
	pnl->txtSystemSTBIndex->Enable(true);
	pnl->txtSystemUseAni->Enable(true);
	pnl->txtSystemAniLoopCt->Enable(true);
	pnl->txtSystemAniSTBIndex->Enable(true);
	pnl->txtSystemDelay->Enable(true);
	pnl->txtSystemIsLinked->Enable(true);
}

void mainframe::OnPrevSystem(wxCommandEvent& event) {	
	int systemct = m_cureft->systemct;
	if(m_icursystem == 1)
		return;

	systemclearall();

	if(m_icursystem == systemct)
		pnl->btnNextSystem->Enable(true);

	m_icursystem--;

	if(m_icursystem == 1)
		pnl->btnPrevSystem->Enable(false);

	maineft.loadsystem(m_icursystem);
}

void mainframe::OnNextSystem(wxCommandEvent& event) {
	int systemct = m_cureft->systemct;
	if(m_icursystem == systemct)
		return;

	systemclearall();

	if(m_icursystem == 1)
		pnl->btnPrevSystem->Enable(true);

	m_icursystem++;

	if(m_icursystem == systemct)
		pnl->btnNextSystem->Enable(false);

	maineft.loadsystem(m_icursystem);
}

//Add a new System
void mainframe::OnAddSystem(wxCommandEvent& event) {
	m_systems = maineft.addsystem();
	int systemct = m_cureft->systemct;
	m_icursystem = systemct;
	sprintf(buffer, "Systems (%d)", systemct);
	pnl->lblSystemsCt->SetLabel(buffer);
	maineft.loadsystem(m_icursystem);
	systemenableall();
	pnl->btnNextSystem->Enable(false);
	if(systemct == 1)
		pnl->btnPrevSystem->Enable(false);
	maineft.setedited();
}

void mainframe::OnPrevAni(wxCommandEvent& event) {
	int anict = m_cureft->anict;
	if(m_icurani == 1)
		return;

	aniclearall();

	if(m_icurani == anict)
		pnl->btnNextAni->Enable(true);

	m_icurani--;

	if(m_icurani == 1)
		pnl->btnPrevAni->Enable(false);

	maineft.loadani(m_icurani);
}

void mainframe::OnNextAni(wxCommandEvent& event) { 
	int anict = m_cureft->anict;
	if(m_icurani == anict)
		return;

	aniclearall();

	if(m_icurani == 1)
		pnl->btnPrevAni->Enable(true);

	m_icurani++;

	if(m_icurani == anict)
		pnl->btnNextAni->Enable(false);

	maineft.loadani(m_icurani);
}

//Add A new Animation
void mainframe::OnAddAni(wxCommandEvent& event) {
	m_anis = maineft.addani();
	int anict = m_cureft->anict;
	m_icurani = anict;
	sprintf(buffer, "Animations (%d)", anict);
	pnl->lblAnisCt->SetLabel(buffer);
	maineft.loadani(m_icurani);
	anienableall();
	pnl->btnNextAni->Enable(false);
	if(anict == 1)
		pnl->btnPrevAni->Enable(false);
	maineft.setedited();
}

//Jump to a different Animation/System
void mainframe::OnJumpSystem(wxCommandEvent& event) { 
	wxString ws = pnl->txtCurSystem->GetLineText(0);
	long newsysid = strtol(static_cast<const char *>(ws), NULL, 0);
	int systemct = m_cureft->systemct;
	if(newsysid < 1 || newsysid > systemct) {
		setstatus("System out of range.");
		return;
	}
	m_icursystem = newsysid;
	sprintf(buffer, "Jumped to System %d.", m_icursystem);
	setstatus(buffer);
	if(m_icursystem == 1) {
		pnl->btnPrevSystem->Enable(false);
		if(systemct > 1)
			pnl->btnNextSystem->Enable(true);
	}
	if(m_icursystem == systemct) {
		pnl->btnNextSystem->Enable(false);
		if(systemct > 1)
			pnl->btnPrevSystem->Enable(true);
	}
	maineft.loadsystem(m_icursystem);
}
void mainframe::OnJumpAni(wxCommandEvent& event) { 
	wxString ws = pnl->txtCurAni->GetLineText(0);
	long newaniid = strtol(static_cast<const char *>(ws), NULL, 0);
	int anict = m_cureft->anict;
	if(newaniid < 1 || newaniid > anict) {
		setstatus("Animation out of range.");
		return;
	}
	m_icurani = newaniid;;
	sprintf(buffer, "Jumped to Animation %d.", m_icurani);
	setstatus(buffer);
	if(m_icurani == 1) {
		pnl->btnPrevAni->Enable(false);
		if(anict > 1)
			pnl->btnNextAni->Enable(true);
	}
	if(m_icurani == anict) {
		pnl->btnNextAni->Enable(false);
		if(anict > 1)
			pnl->btnPrevAni->Enable(true);
	}
	maineft.loadani(m_icurani);
}

//Header Changes
void mainframe::OnEFTName(wxCommandEvent& event) { 
	updatestr(&m_cureft->name, pnl->txtEFTName->GetLineText(0));
}
void mainframe::OnUseSound(wxCommandEvent& event) { 
	updatedw(&m_cureft->usesound, pnl->txtUseSound->GetLineText(0));
}
void mainframe::OnSoundLoopCt(wxCommandEvent& event) { 
	updatedw(&m_cureft->soundloopct, pnl->txtSoundLoopCt->GetLineText(0));
}
void mainframe::OnSoundFile(wxCommandEvent& event) { 
	updatestr(&m_cureft->soundfile, pnl->txtSoundFile->GetLineText(0));
}

//System String Changes
void mainframe::OnSystemName(wxCommandEvent& event) { 
	updatestr(&m_systems[m_icursystem-1]->name, pnl->txtSystemName->GetLineText(0));
}
void mainframe::OnSystemUName(wxCommandEvent& event) { 
	updatestr(&m_systems[m_icursystem-1]->uniquename, pnl->txtSystemUName->GetLineText(0));
}
void mainframe::OnSystemPTLFile(wxCommandEvent& event) { 
	updatestr(&m_systems[m_icursystem-1]->ptlfile, pnl->txtSystemPTLFile->GetLineText(0));
}
void mainframe::OnSystemZMOFile(wxCommandEvent& event) { 
	updatestr(&m_systems[m_icursystem-1]->zmofile, pnl->txtSystemZMOFile->GetLineText(0));
}

//System Float Changes
void mainframe::OnSystemPosX(wxCommandEvent& event) { 
	updatefloat(&m_systems[m_icursystem-1]->position.x, pnl->txtSystemPosX->GetLineText(0));
}
void mainframe::OnSystemPosY(wxCommandEvent& event) { 
	updatefloat(&m_systems[m_icursystem-1]->position.y, pnl->txtSystemPosY->GetLineText(0));
}
void mainframe::OnSystemPosZ(wxCommandEvent& event) { 
	updatefloat(&m_systems[m_icursystem-1]->position.z, pnl->txtSystemPosZ->GetLineText(0));
}
void mainframe::OnSystemRotX(wxCommandEvent& event) { 
	updatefloat(&m_systems[m_icursystem-1]->rotation.x, pnl->txtSystemRotX->GetLineText(0));
}
void mainframe::OnSystemRotY(wxCommandEvent& event) { 
	updatefloat(&m_systems[m_icursystem-1]->rotation.y, pnl->txtSystemRotY->GetLineText(0));
}
void mainframe::OnSystemRotZ(wxCommandEvent& event) { 
	updatefloat(&m_systems[m_icursystem-1]->rotation.z, pnl->txtSystemRotZ->GetLineText(0));
}
void mainframe::OnSystemRotW(wxCommandEvent& event) { 
	updatefloat(&m_systems[m_icursystem-1]->rotation.w, pnl->txtSystemRotW->GetLineText(0));
}

//System DW Changes
void mainframe::OnSystemSTBIndex(wxCommandEvent& event) { 
	updatedw(&m_systems[m_icursystem-1]->stbindex, pnl->txtSystemSTBIndex->GetLineText(0));
}
void mainframe::OnSystemUseAni(wxCommandEvent& event) { 
	updatedw(&m_systems[m_icursystem-1]->useani, pnl->txtSystemUseAni->GetLineText(0));
}
void mainframe::OnSystemAniLoopCt(wxCommandEvent& event) { 
	updatedw(&m_systems[m_icursystem-1]->aniloopct, pnl->txtSystemAniLoopCt->GetLineText(0));
}
void mainframe::OnSystemAniSTBIndex(wxCommandEvent& event) { 
	updatedw(&m_systems[m_icursystem-1]->anistbindex, pnl->txtSystemAniSTBIndex->GetLineText(0));
}
void mainframe::OnSystemDelay(wxCommandEvent& event) { 
	updatedw(&m_systems[m_icursystem-1]->delay, pnl->txtSystemDelay->GetLineText(0));
}
void mainframe::OnSystemIsLinked(wxCommandEvent& event) { 
	updatedw(&m_systems[m_icursystem-1]->islinked, pnl->txtSystemIsLinked->GetLineText(0));
}

//Animation String Changes
void mainframe::OnAniName(wxCommandEvent& event) { 
	updatestr(&m_anis[m_icurani-1]->name, pnl->txtAniName->GetLineText(0));
}
void mainframe::OnAniUName(wxCommandEvent& event) { 
	updatestr(&m_anis[m_icurani-1]->uniquename, pnl->txtAniUName->GetLineText(0));
}
void mainframe::OnAniZMSFile(wxCommandEvent& event) { 
	updatestr(&m_anis[m_icurani-1]->zmsfile, pnl->txtAniZMSFile->GetLineText(0));
}
void mainframe::OnAniZMOFile(wxCommandEvent& event) { 
	updatestr(&m_anis[m_icurani-1]->zmofile, pnl->txtAniZMOFile->GetLineText(0));
}
void mainframe::OnAniDDSFile(wxCommandEvent& event) { 
	updatestr(&m_anis[m_icurani-1]->ddsfile, pnl->txtAniDDSFile->GetLineText(0));
}

//Animation Bool Changes
void mainframe::OnAniTwoSided(wxCommandEvent& event) {
	m_anis[m_icurani-1]->twosided = (DWORD)pnl->chkAniTwoSided->GetValue();
	maineft.setedited();
}
void mainframe::OnAniAlpha(wxCommandEvent& event) { 
	m_anis[m_icurani-1]->alphaenabled = (DWORD)pnl->chkAniAlpha->GetValue();
	maineft.setedited();
}
void mainframe::OnAniAlphaTest(wxCommandEvent& event) { 
	m_anis[m_icurani-1]->alphatestenabled = (DWORD)pnl->chkAniAlphaTest->GetValue();
	maineft.setedited();
}
void mainframe::OnAniZTest(wxCommandEvent& event) {
	m_anis[m_icurani-1]->ztestenabled = (DWORD)pnl->chkAniZTest->GetValue();
	maineft.setedited();
}
void mainframe::OnZWrite(wxCommandEvent& event) {
	m_anis[m_icurani-1]->zwriteenabled = (DWORD)pnl->chkAniZWrite->GetValue();
	maineft.setedited();
}

//Animation Blend Changes
void mainframe::OnSrcBlendSelect(wxCommandEvent& event) {
	m_anis[m_icurani-1]->sourceblendmode = pnl->cmbAniSourceBlend->GetSelection();
	maineft.setedited();
}
void mainframe::OnDestBlendSelect(wxCommandEvent& event) {
	m_anis[m_icurani-1]->destblendmode = pnl->cmbAniDestBlend->GetSelection();
	maineft.setedited();
}
void mainframe::OnBlendOpSelect(wxCommandEvent& event) {
	m_anis[m_icurani-1]->blendop = pnl->cmbAniBlendOp->GetSelection();
	maineft.setedited();
}
//Animation Float Changes
void mainframe::OnAniPosX(wxCommandEvent& event) { 
	updatefloat(&m_anis[m_icurani-1]->position.x, pnl->txtAniPosX->GetLineText(0));
}
void mainframe::OnAniPosY(wxCommandEvent& event) { 
	updatefloat(&m_anis[m_icurani-1]->position.y, pnl->txtAniPosY->GetLineText(0));
}
void mainframe::OnAniPosZ(wxCommandEvent& event) { 
	updatefloat(&m_anis[m_icurani-1]->position.z, pnl->txtAniPosZ->GetLineText(0));
}
void mainframe::OnAniRotX(wxCommandEvent& event) { 
	updatefloat(&m_anis[m_icurani-1]->rotation.x, pnl->txtAniRotX->GetLineText(0));
}
void mainframe::OnAniRotY(wxCommandEvent& event) { 
	updatefloat(&m_anis[m_icurani-1]->rotation.y, pnl->txtAniRotY->GetLineText(0));
}
void mainframe::OnAniRotZ(wxCommandEvent& event) { 
	updatefloat(&m_anis[m_icurani-1]->rotation.z, pnl->txtAniRotZ->GetLineText(0));
}
void mainframe::OnAniRotW(wxCommandEvent& event) { 
	updatefloat(&m_anis[m_icurani-1]->rotation.w, pnl->txtAniRotW->GetLineText(0));
}

//Animation DW Changes
void mainframe::OnAniSTBIndex(wxCommandEvent& event) { 
	updatedw(&m_anis[m_icurani-1]->stbindex, pnl->txtAniSTBIndex->GetLineText(0));
}
void mainframe::OnAniUseAni(wxCommandEvent& event) { 
	updatedw(&m_anis[m_icurani-1]->useani, pnl->txtAniUseAni->GetLineText(0));
}
void mainframe::OnAniAniLoopCt(wxCommandEvent& event) { 
	updatedw(&m_anis[m_icurani-1]->aniloopct, pnl->txtAniAniLoopCt->GetLineText(0));
}
void mainframe::OnAniAniSTBIndex(wxCommandEvent& event) { 
	updatedw(&m_anis[m_icurani-1]->anistbindex, pnl->txtAniAniSTBIndex->GetLineText(0));
}
void mainframe::OnAniDelay(wxCommandEvent& event) { 
	updatedw(&m_anis[m_icurani-1]->delay, pnl->txtAniDelay->GetLineText(0));
}
void mainframe::OnAniIsLinked(wxCommandEvent& event) { 
	updatedw(&m_anis[m_icurani-1]->islinked, pnl->txtAniIsLinked->GetLineText(0));
}
void mainframe::OnAniRepeatCt(wxCommandEvent& event) { 
	updatedw(&m_anis[m_icurani-1]->repeatct, pnl->txtAniRepeatCt->GetLineText(0));
}

//String reallocator
void mainframe::updatestr(char **dest, wxString s) {
	const char *src = static_cast<const char *>(s);
	int newlen = strlen(src);
	*dest = (char *)realloc((void *)*dest, newlen);
	sprintf(*dest, "%s", src);
	maineft.setedited();
	setstatus("String data saved.");
}

//DW updater
void mainframe::updatedw(DWORD *d, wxString s) {
	const char *c = static_cast<const char *>(s);
	errno = 0;
	DWORD newval = strtol(c, NULL, 0);
	if(errno)
		setstatus("!! Invalid values will not be saved! -> Please adjust your input!");
	else {
		*d = newval;
		setstatus("Data saved.");
		maineft.setedited();
	}
}

//Float updater
void mainframe::updatefloat(float *f, wxString s) {
	const char *c = static_cast<const char *>(s);
	errno = 0;
	float newfloat = strtof(c, NULL);
	if(errno)
		setstatus("!! Invalid values will not be saved! -> Please adjust your input!");
	else {
		*f = newfloat;
		setstatus("Float data saved.");
		maineft.setedited();
	}
}
