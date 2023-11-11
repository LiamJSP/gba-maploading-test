#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_input.h>
#include <gba_sprites.h>

// Import the converted data from grit.
#include "level.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160
#define TILE_WIDTH 16
#define TILE_HEIGHT 16
#define MAP_WIDTH 64
#define MAP_HEIGHT 64

int cameraX = (MAP_WIDTH * TILE_WIDTH - SCREEN_WIDTH) / 2;
int cameraY = (MAP_HEIGHT * TILE_HEIGHT - SCREEN_HEIGHT) / 2;

int main(void) {
    REG_DISPCNT = MODE_0 | BG0_ON;

    // Load palette data.
    for (int i = 0; i < levelPalLen / 2; i++) {
        ((u16*)BG_PALETTE)[i] = levelPal[i];
    }

    // Load tile data.
    for (int i = 0; i < levelTilesLen / 4; i++) { 
        ((u32*)CHAR_BASE_BLOCK(0))[i] = levelTiles[i];
    }

    // Load map data.
    for (int i = 0; i < levelMapLen / 2; i++) {
        ((u16*)SCREEN_BASE_BLOCK(31))[i] = levelMap[i];
    }

    REG_BG0CNT = BG_SIZE_3 | BG_16_COLOR | CHAR_BASE(0) | SCREEN_BASE(31);

    // Main loop.
    while (1) {
        // Wait for VBlank
        while(REG_VCOUNT >= 160);
        while(REG_VCOUNT < 160);

        // Read input.
        scanKeys();
        u16 keys = keysHeld();

        // Update the camera based on D-pad inputs.
        if (keys & KEY_UP) cameraY -= 2;
        if (keys & KEY_DOWN) cameraY += 2;
        if (keys & KEY_LEFT) cameraX -= 2;
        if (keys & KEY_RIGHT) cameraX += 2;

        // Update BG0 scroll registers with the camera position.
        REG_BG0HOFS = cameraX;
        REG_BG0VOFS = cameraY;
    }

    return 0;
}
