#ifndef EFT_H
#define EFT_H

#define INVALIDFILE 1
#define FILEOPENERR 2
#define FILENOTFOUND 3

#include <cstdio>
#include "efttypes.h"

typedef struct _EFTFILE {
	char *name;
	DWORD usesound;
	char *soundfile;
	DWORD soundloopct;
	DWORD systemct;
	SYSTEM **systems;
	DWORD anict;
	ANIMATION **anis;
} EFTFILE;

class eft {
	public:
		eft();
		bool setfile(const char *path, const char *fname);
		char *getfile();
		int open();
		void close();
		bool save(const char *fname);
		bool save();
		bool isOpen() { return m_bOpen; }
		bool isEdited() { return m_bEdited; }
		EFTFILE *getcureft() { return cureft; }
		void loadsystem(int sysid);
		void loadani(int aniid);
		void setedited();
		void setunedited();
		SYSTEM **addsystem();
		ANIMATION **addani();

	private:
		void makelstr(char **loc);
		void writelstr(char *s);
		void makedw(DWORD *loc);
		void makefloat(float *loc);
		char m_fpath[500];
		char m_fname[100];
		int m_fsize;
		FILE *m_fh;
		bool m_bEdited;
		bool m_bOpen;
		EFTFILE *cureft;

		void loadpanel();
		void loadhdr();
};

#endif
