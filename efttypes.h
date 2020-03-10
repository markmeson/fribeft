#ifndef EFTTYPES_H
#define EFTTYPES_H

#include "mainframe.h"

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned DWORD;
typedef unsigned UINT;

enum BLENDMODE {
	ZERO = 1,
	ONE = 2,
	SRCCOLOR = 3,
	INVSRCCOLOR = 4,
	SRCALPHA = 5,
	INVSRCALPHA = 6,
	DESTALPHA = 7,
	INVDESTALPHA = 8,
	DESTCOLO = 9,
	INVDESTCOLOR = 10,
	SRCALPHASAT = 11,
	BOTHSRCALPHA = 12,
	BOTHINVSRCALPHA = 13,
	BLENDFACTOR = 14,
	INVBLENDFACTOR = 15,
	SRCCOLOR2 = 16,
	INVSRCCOLOR2 = 17
};

enum BLENDOPTYPE {
	ADD = 1,
	SUBTRACT = 2,
	REVSUBTRACT = 3,
	MIN = 4,
	MAX = 5
};

typedef struct _VECTOR3 {
	float x;
	float y;
	float z;
} VECTOR3;

typedef struct _QUARTERNION {
	float x;
	float y;
	float z;
	float w;
} QUARTERNION;

typedef struct _SYSTEM {
	char *name;
	char *uniquename;
	DWORD stbindex;
	char *ptlfile;
	DWORD useani;
	char *zmofile;
	DWORD aniloopct;
	DWORD anistbindex;
	VECTOR3 position;
  QUARTERNION rotation;
  DWORD delay;
  DWORD islinked;
} SYSTEM;

typedef struct _ANIMATION {
	char *name;
	char *uniquename;
	DWORD stbindex;
	char *zmsfile;
	char *zmofile;
	char *ddsfile;
	DWORD alphaenabled;
	DWORD twosided;
	DWORD alphatestenabled;
	DWORD ztestenabled;
	DWORD zwriteenabled;
	DWORD sourceblendmode;
	DWORD destblendmode;
	DWORD blendop;
	DWORD useani;
	char *aniname;
	DWORD aniloopct;
	DWORD anistbindex;
	VECTOR3 position;
	QUARTERNION rotation;
	DWORD delay;
	DWORD repeatct;
	DWORD islinked;
} ANIMATION;

#endif
