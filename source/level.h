
//{{BLOCK(level)

//======================================================================
//
//	level, 512x512@4, 
//	+ palette 256 entries, not compressed
//	+ 70 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 2240 + 8192 = 10944
//
//	Time-stamp: 2023-11-11, 12:52:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LEVEL_H
#define GRIT_LEVEL_H

#define levelTilesLen 2240
extern const unsigned int levelTiles[560];

#define levelMapLen 8192
extern const unsigned short levelMap[4096];

#define levelPalLen 512
extern const unsigned short levelPal[256];

#endif // GRIT_LEVEL_H

//}}BLOCK(level)
