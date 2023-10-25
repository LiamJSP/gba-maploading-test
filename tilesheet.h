
//{{BLOCK(tilesheet)

//======================================================================
//
//	tilesheet, 144x72@4, 
//	+ palette 256 entries, not compressed
//	+ 144 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 18x9 
//	Total size: 512 + 4608 + 324 = 5444
//
//	Time-stamp: 2023-10-24, 22:55:35
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TILESHEET_H
#define GRIT_TILESHEET_H

#define tilesheetTilesLen 4608
extern const unsigned int tilesheetTiles[1152];

#define tilesheetMapLen 324
extern const unsigned short tilesheetMap[162];

#define tilesheetPalLen 512
extern const unsigned short tilesheetPal[256];

#endif // GRIT_TILESHEET_H

//}}BLOCK(tilesheet)
