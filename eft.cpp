#include "eft.h"
#include "mainframe.h"
#include <cstring>

extern mainframe *frame;
extern char buffer[2048];

eft::eft() {
	m_fh = NULL;
	m_fsize = 0;
	m_bOpen = false;
	m_bEdited = false;
	cureft = new EFTFILE;
}

bool eft::setfile(const char *path, const char *fname) {
	int ipath = strlen(path);
	int iname = strlen(fname);
	if(ipath > 499 || iname > 99)
		return false;

	sprintf(m_fpath, "%s", path);
	sprintf(m_fname, "%s", fname);
	return true;
}

char *eft::getfile() {
	return m_fpath;
}

void eft::makelstr(char **loc) {
	DWORD lssize;
	fread(&lssize, 4, 1, m_fh);
	*loc = (char *)malloc(lssize+1);
	if(lssize > 0)
		fread(*loc, 1, lssize, m_fh);
	(*loc)[lssize] = 0;
}

void eft::makedw(DWORD *loc) { fread(loc, 4, 1, m_fh); }

void eft::makefloat(float *loc) { fread(loc, 4, 1, m_fh); }

int eft::open() {
	if(!strlen(m_fpath))
		return FILENOTFOUND;

	m_fh = fopen(m_fpath, "rb");
	if(!m_fh)
		return FILEOPENERR;

	fseek(m_fh, 0, SEEK_END);
	m_fsize = ftell(m_fh);
	fseek(m_fh, 0, SEEK_SET);


	//------ start of parse EFT
	

	//name
	makelstr(&cureft->name);

	//usesound
	makedw(&cureft->usesound);

	//soundfile
	makelstr(&cureft->soundfile);

	//soundloopct
	makedw(&cureft->soundloopct);

	//systems[]
	makedw(&cureft->systemct);
	cureft->systems = (SYSTEM **)malloc(sizeof(SYSTEM *) * cureft->systemct);
	for(int i = 0; i < cureft->systemct; i++) {
		SYSTEM *s = cureft->systems[i] = (SYSTEM *)malloc(sizeof(SYSTEM));
		makelstr(&s->name);
		makelstr(&s->uniquename);
		makedw(&s->stbindex);
		makelstr(&s->ptlfile);
		makedw(&s->useani);
		makelstr(&s->zmofile);
		makedw(&s->aniloopct);
		makedw(&s->anistbindex);
		makefloat(&s->position.x);
		makefloat(&s->position.y);
		makefloat(&s->position.z);
		makefloat(&s->rotation.x);
		makefloat(&s->rotation.y);
		makefloat(&s->rotation.z);
		makefloat(&s->rotation.w);
		makedw(&s->delay);
		makedw(&s->islinked);
	}

	//anis[]
	makedw(&cureft->anict);
	cureft->anis = (ANIMATION **)malloc(sizeof(ANIMATION *) * cureft->anict);
	for(int i = 0; i < cureft->anict; i++) {
		ANIMATION *a = cureft->anis[i] = (ANIMATION *)malloc(sizeof(ANIMATION));
		makelstr(&a->name);
		makelstr(&a->uniquename);
		makedw(&a->stbindex);
		makelstr(&a->zmsfile);
		makelstr(&a->zmofile);
		makelstr(&a->ddsfile);
		makedw(&a->alphaenabled);
		makedw(&a->twosided);
		makedw(&a->alphatestenabled);
		makedw(&a->ztestenabled);
		makedw(&a->zwriteenabled);
		makedw(&a->sourceblendmode);
		makedw(&a->destblendmode);
		makedw(&a->blendop);
		makedw(&a->useani);
		makelstr(&a->aniname);
		makedw(&a->aniloopct);
		makedw(&a->anistbindex);
		makefloat(&a->position.x);
		makefloat(&a->position.y);
		makefloat(&a->position.z);
		makefloat(&a->rotation.x);
		makefloat(&a->rotation.y);
		makefloat(&a->rotation.z);
		makefloat(&a->rotation.w);
		makedw(&a->delay);
		makedw(&a->repeatct);
		makedw(&a->islinked);
	}

	//------ end of EFT parse
	
	fclose(m_fh);
	m_bOpen = true;
	m_bEdited = false;
	frame->enablesave(false);
	sprintf(buffer, "Done loading %s", m_fpath);
	frame->setstatus(buffer);

	loadpanel();

	return 0;
}

void eft::close() {
	if(!m_bOpen)
		return;
	
	//clear file details
	m_fh = NULL;
	m_fsize = 0;
	m_bOpen = false;

	//clear general EFT data
	free(cureft->name);
	cureft->name = NULL;
	cureft->usesound = 0;
	free(cureft->soundfile);
	cureft->soundfile = NULL;
	cureft->soundloopct = 0;

	//clear EFT system data
	for(int i = 0; i < cureft->systemct; i++) {
		SYSTEM *s = cureft->systems[i];
		free(s->name);
		free(s->uniquename);
		free(s->ptlfile);
		free(s->zmofile);
		free(s);
	}
	cureft->systemct = 0;
	free(cureft->systems);

	//clear EFT animation data
	for(int i = 0; i < cureft->anict; i++) {
		ANIMATION *a = cureft->anis[i];
		free(a->name);
		free(a->uniquename);
		free(a->zmsfile);
		free(a->zmofile);
		free(a->ddsfile);
		free(a->aniname);
		free(a);
	}
	cureft->anict = 0;
	free(cureft->anis);

	sprintf(buffer, "Closed %s", strlen(m_fname) > 0 ? m_fname : m_fpath);
	frame->setstatus(buffer);
}

bool eft::save(const char *fname) {
	char backup[500];
	strcpy(backup, m_fname); //backup in case failure
	strcpy(m_fname, fname);
	if(save()) {
		sprintf(buffer, "Frib EFT Editor - %s", m_fname);
		frame->SetLabel(buffer);
		return true;
	} else {
		strcpy(m_fname, backup); //return to original file name
		return false;
	}
}

bool eft::save() {
	if(!m_bOpen)
		return false;

	m_fh = fopen(m_fname, "wb");
	if(m_fh == NULL)
		return false;

	//Write header
	writelstr(cureft->name);
	fwrite(&cureft->usesound, 4, 1, m_fh);
	writelstr(cureft->soundfile);
	fwrite(&cureft->soundloopct, 4, 1, m_fh);

	//Write systems
	fwrite(&cureft->systemct, 4, 1, m_fh);
	for(int i = 0; i < cureft->systemct; i++) {
		SYSTEM *s = cureft->systems[i];
		writelstr(s->name);
		writelstr(s->uniquename);
		fwrite(&s->stbindex, 4, 1, m_fh);
		writelstr(s->ptlfile);
		fwrite(&s->useani, 4, 1, m_fh);
		writelstr(s->zmofile);
		fwrite(&s->aniloopct, 4, 1, m_fh);
		fwrite(&s->anistbindex, 4, 1, m_fh);
		fwrite(&s->position.x, 4, 1, m_fh);
		fwrite(&s->position.y, 4, 1, m_fh);
		fwrite(&s->position.z, 4, 1, m_fh);
		fwrite(&s->rotation.x, 4, 1, m_fh);
		fwrite(&s->rotation.y, 4, 1, m_fh);
		fwrite(&s->rotation.z, 4, 1, m_fh);
		fwrite(&s->rotation.w, 4, 1, m_fh);
		fwrite(&s->delay, 4, 1, m_fh);
		fwrite(&s->islinked, 4, 1, m_fh);
	}


	//Write animations
	fwrite(&cureft->anict, 4, 1, m_fh);
	for(int i = 0; i < cureft->anict; i++) {
		ANIMATION *a = cureft->anis[i];
		writelstr(a->name);
		writelstr(a->uniquename);
		fwrite(&a->stbindex, 4, 1, m_fh);
		writelstr(a->zmsfile);
		writelstr(a->zmofile);
		writelstr(a->ddsfile);
		fwrite(&a->alphaenabled, 4, 1, m_fh);
		fwrite(&a->twosided, 4, 1, m_fh);
		fwrite(&a->alphatestenabled, 4, 1, m_fh);
		fwrite(&a->ztestenabled, 4, 1, m_fh);
		fwrite(&a->zwriteenabled, 4, 1, m_fh);
		fwrite(&a->sourceblendmode, 4, 1, m_fh);
		fwrite(&a->destblendmode, 4, 1, m_fh);
		fwrite(&a->blendop, 4, 1, m_fh);
		fwrite(&a->useani, 4, 1, m_fh);
		writelstr(a->aniname);
		fwrite(&a->aniloopct, 4, 1, m_fh);
		fwrite(&a->anistbindex, 4, 1, m_fh);
		fwrite(&a->position.x, 4, 1, m_fh);
		fwrite(&a->position.y, 4, 1, m_fh);
		fwrite(&a->position.z, 4, 1, m_fh);
		fwrite(&a->rotation.x, 4, 1, m_fh);
		fwrite(&a->rotation.y, 4, 1, m_fh);
		fwrite(&a->rotation.z, 4, 1, m_fh);
		fwrite(&a->rotation.w, 4, 1, m_fh);
		fwrite(&a->delay, 4, 1, m_fh);
		fwrite(&a->repeatct, 4, 1, m_fh);
		fwrite(&a->islinked, 4, 1, m_fh);
	}

	m_bEdited = false;
	frame->enablesave(false);
	fclose(m_fh);
	return true;
}

void eft::writelstr(char *s) {
	DWORD lssize = strlen(s);
	fwrite(&lssize, 4, 1, m_fh);
	fwrite(s, 1, lssize, m_fh);
}

void eft::loadpanel() {
	pnlEFT *p = frame->pnl;

	//Header
	loadhdr();

	//Systems (Start with first)
	sprintf(buffer, "Systems (%d)", cureft->systemct);
	p->lblSystemsCt->SetLabel(buffer);
	if(cureft->systemct)
		loadsystem(1);

	//Animations (Start with first)
	sprintf(buffer, "Animations (%d)", cureft->anict);
	p->lblAnisCt->SetLabel(buffer);
	if(cureft->anict)
		loadani(1);
}

void eft::loadhdr() {
	pnlEFT *p = frame->pnl;

	//Header values
	p->txtEFTName->ChangeValue(cureft->name);
	sprintf(buffer, "%d", cureft->usesound);
	p->txtUseSound->ChangeValue(buffer);
	p->txtSoundFile->ChangeValue(cureft->soundfile);
	sprintf(buffer, "%d", cureft->soundloopct);
	p->txtSoundLoopCt->ChangeValue(buffer);
}

void eft::loadsystem(int sysid) {
	pnlEFT *p = frame->pnl;
	SYSTEM *s = cureft->systems[sysid - 1];
	sprintf(buffer, "%d", sysid);
	p->txtCurSystem->ChangeValue(buffer);

	//System Strings
	sprintf(buffer, "%s", s->name);
	p->txtSystemName->ChangeValue(buffer);
	sprintf(buffer, "%s", s->uniquename);
	p->txtSystemUName->ChangeValue(buffer);
	sprintf(buffer, "%s", s->ptlfile);
	p->txtSystemPTLFile->ChangeValue(buffer);
	sprintf(buffer, "%s", s->zmofile);
	p->txtSystemZMOFile->ChangeValue(buffer);

	//System Position and Rotations floats
	sprintf(buffer, "%.5f", s->position.x);
	p->txtSystemPosX->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", s->position.y);
	p->txtSystemPosY->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", s->position.z);
	p->txtSystemPosZ->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", s->rotation.x);
	p->txtSystemRotX->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", s->rotation.y);
	p->txtSystemRotY->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", s->rotation.z);
	p->txtSystemRotZ->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", s->rotation.w);
	p->txtSystemRotW->ChangeValue(buffer);;

	//Other System Values
	sprintf(buffer, "%d", s->stbindex);
	p->txtSystemSTBIndex->ChangeValue(buffer);
	sprintf(buffer, "%d", s->useani);
	p->txtSystemUseAni->ChangeValue(buffer);
	sprintf(buffer, "%d", s->aniloopct);
	p->txtSystemAniLoopCt->ChangeValue(buffer);
	sprintf(buffer, "%d", s->anistbindex);
	p->txtSystemAniSTBIndex->ChangeValue(buffer);
	sprintf(buffer, "%d", s->delay);
	p->txtSystemDelay->ChangeValue(buffer);
	sprintf(buffer, "%d", s->islinked);
	p->txtSystemIsLinked->ChangeValue(buffer);
}

void eft::loadani(int aniid) {
	pnlEFT *p = frame->pnl;
	ANIMATION *a = cureft->anis[aniid - 1];
	sprintf(buffer, "%d", aniid);
	p->txtCurAni->ChangeValue(buffer);


	//Animation Strings
	sprintf(buffer, "%s", a->name);
	p->txtAniName->ChangeValue(buffer);
	sprintf(buffer, "%s", a->uniquename);
	p->txtAniUName->ChangeValue(buffer);
	sprintf(buffer, "%s", a->zmsfile);
	p->txtAniZMSFile->ChangeValue(buffer);
	sprintf(buffer, "%s", a->zmofile);
	p->txtAniZMOFile->ChangeValue(buffer);
	sprintf(buffer, "%s", a->ddsfile);
	p->txtAniDDSFile->ChangeValue(buffer);

	//Animation Boolean Values
	p->chkAniTwoSided->SetValue(a->twosided);
	p->chkAniAlpha->SetValue(a->alphaenabled);
	p->chkAniAlphaTest->SetValue(a->alphatestenabled);
	p->chkAniZTest->SetValue(a->ztestenabled);
	p->chkAniZWrite->SetValue(a->zwriteenabled);

	//Animation Blend Values
	p->cmbAniSourceBlend->SetSelection(a->sourceblendmode);
	p->cmbAniDestBlend->SetSelection(a->destblendmode);
	p->cmbAniBlendOp->SetSelection(a->blendop);

	//Animation Position and Rotations floats
	sprintf(buffer, "%.5f", a->position.x);
	p->txtAniPosX->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", a->position.y);
	p->txtAniPosY->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", a->position.z);
	p->txtAniPosZ->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", a->rotation.x);
	p->txtAniRotX->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", a->rotation.y);
	p->txtAniRotY->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", a->rotation.z);
	p->txtAniRotZ->ChangeValue(buffer);;
	sprintf(buffer, "%.5f", a->rotation.w);
	p->txtAniRotW->ChangeValue(buffer);;

	//Other Animation Values
	sprintf(buffer, "%d", a->stbindex);
	p->txtAniSTBIndex->ChangeValue(buffer);
	sprintf(buffer, "%d", a->useani);
	p->txtAniUseAni->ChangeValue(buffer);
	sprintf(buffer, "%d", a->aniloopct);
	p->txtAniAniLoopCt->ChangeValue(buffer);
	sprintf(buffer, "%d", a->anistbindex);
	p->txtAniAniSTBIndex->ChangeValue(buffer);
	sprintf(buffer, "%d", a->delay);
	p->txtAniDelay->ChangeValue(buffer);
	sprintf(buffer, "%d", a->islinked);
	p->txtAniIsLinked->ChangeValue(buffer);
}

void eft::setedited() { 
	m_bEdited = true; 
	frame->enablesave(true);
}
void eft::setunedited() { m_bEdited = false; }

SYSTEM **eft::addsystem() {
	cureft->systemct++;
	cureft->systems = (SYSTEM **)realloc(cureft->systems, cureft->systemct * sizeof(SYSTEM *));
	cureft->systems[cureft->systemct-1] = (SYSTEM *)malloc(sizeof(SYSTEM));
	SYSTEM *s = cureft->systems[cureft->systemct-1];
	memset(s, 0x00, sizeof(SYSTEM));
	s->name = (char *)malloc(1);
	s->name[0] = 0;
	s->uniquename = (char *)malloc(1);
	s->uniquename[0] = 0;
	s->ptlfile = (char *)malloc(1);
	s->ptlfile[0] = 0;
	s->zmofile = (char *)malloc(1);
	s->zmofile[0] = 0;
	return cureft->systems;
}

ANIMATION **eft::addani() {
	cureft->anict++;
	cureft->anis = (ANIMATION **)realloc(cureft->anis, cureft->anict * sizeof(ANIMATION *));
	cureft->anis[cureft->anict-1] = (ANIMATION *)malloc(sizeof(ANIMATION));
	memset(cureft->anis[cureft->anict-1], 0x00, sizeof(ANIMATION));
	ANIMATION *a = cureft->anis[cureft->anict-1];
	memset(a, 0x00, sizeof(SYSTEM));
	a->name = (char *)malloc(1);
	a->name[0] = 0;
	a->uniquename = (char *)malloc(1);
	a->uniquename[0] = 0;
	a->zmsfile = (char *)malloc(1);
	a->zmsfile[0] = 0;
	a->zmofile = (char *)malloc(1);
	a->zmofile[0] = 0;
	a->ddsfile = (char *)malloc(1);
	a->ddsfile[0] = 0;
	a->aniname = (char *)malloc(1);
	a->aniname[0] = 0;
	return cureft->anis;
}
