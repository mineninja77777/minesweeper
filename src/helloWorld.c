#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <string.h>
#include <fxcg/misc.h>
#include <stdlib.h>
#include <time.h>

#define wh 0xFFFF // white
#define c1 0xe0c9 // red
#define c2 0xf406 // orange
#define c3 0xff03 // yellow
#define c4 0xbf68 // lime
#define c5 0x3d89 // green
#define c6 0x469e // cyan
#define c7 0x431a // blue
#define c8 0x90f6 // purple
#define c9 0xe99c // magenta

int oneSprite[15][15] = 
{
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,c1,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c1,c1,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c1,c1,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c1,c1,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh}
};

int twoSprite[15][15] =
{
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c2,c2,c2,c2,c2,c2,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c2,c2,c2,c2,c2,c2,c2,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c2,c2,c2,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,c2,c2,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,c2,c2,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,c2,c2,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c2,c2,c2,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,c2,c2,c2,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c2,c2,c2,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,c2,c2,c2,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c2,c2,c2,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c2,c2,c2,c2,c2,c2,c2,c2,wh,wh,wh},
    {wh,wh,wh,wh,c2,c2,c2,c2,c2,c2,c2,c2,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh}
};

int threeSprite[15][15] = 
{
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c3,c3,c3,c3,c3,c3,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c3,c3,c3,c3,c3,c3,c3,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c3,c3,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c3,c3,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c3,c3,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c3,c3,c3,c3,c3,c3,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c3,c3,c3,c3,c3,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c3,c3,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c3,c3,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c3,c3,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c3,c3,wh,wh,wh,wh},
    {wh,wh,wh,wh,c3,c3,c3,c3,c3,c3,c3,wh,wh,wh,wh},
    {wh,wh,wh,wh,c3,c3,c3,c3,c3,c3,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh}
};
int fourSprite[15][15] = 
{
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c4,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,c4,c4,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c4,c4,wh,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c4,c4,wh,wh,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,c4,c4,wh,wh,wh,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,c4,c4,c4,c4,c4,c4,c4,c4,c4,wh,wh,wh},
    {wh,wh,wh,c4,c4,c4,c4,c4,c4,c4,c4,c4,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,c4,c4,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh}
};

int fiveSprite[15][15] = 
{
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c5,c5,c5,c5,c5,c5,c5,wh,wh,wh,wh},
    {wh,wh,wh,wh,c5,c5,c5,c5,c5,c5,c5,wh,wh,wh,wh},
    {wh,wh,wh,wh,c5,c5,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c5,c5,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c5,c5,c5,c5,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c5,c5,c5,c5,c5,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,c5,c5,c5,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c5,c5,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c5,c5,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c5,c5,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,c5,c5,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c5,c5,c5,c5,c5,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c5,c5,c5,c5,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh}
};

int sixSprite[15][15] = 
{
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c6,c6,c6,c6,c6,c6,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,c6,c6,c6,c6,c6,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,c6,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,c6,c6,c6,c6,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,c6,c6,c6,c6,c6,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,c6,wh,wh,c6,c6,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,wh,wh,wh,c6,c6,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,wh,wh,wh,c6,c6,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,wh,wh,wh,c6,c6,wh,wh,wh,wh},
    {wh,wh,wh,wh,c6,c6,c6,wh,wh,c6,c6,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c6,c6,c6,c6,c6,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh}
};

int sevenSprite[15][15] = 
{
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c7,c7,c7,c7,c7,c7,c7,wh,wh,wh,wh},
    {wh,wh,wh,wh,c7,c7,c7,c7,c7,c7,c7,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,c7,c7,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,c7,c7,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c7,c7,c7,c7,c7,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c7,c7,c7,c7,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,c7,c7,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,c7,c7,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,c7,c7,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c7,c7,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c7,c7,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c7,c7,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c7,c7,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh}
};

int eightSprite[15][15] = 
{
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c8,c8,c8,c8,c8,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c8,c8,c8,c8,c8,c8,c8,wh,wh,wh,wh},
    {wh,wh,wh,wh,c8,c8,wh,wh,wh,c8,c8,wh,wh,wh,wh},
    {wh,wh,wh,wh,c8,c8,wh,wh,wh,c8,c8,wh,wh,wh,wh},
    {wh,wh,wh,wh,c8,c8,wh,wh,wh,c8,c8,wh,wh,wh,wh},
    {wh,wh,wh,wh,c8,c8,c8,c8,c8,c8,c8,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c8,c8,c8,c8,c8,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,c8,c8,wh,wh,wh,c8,c8,wh,wh,wh,wh},
    {wh,wh,wh,wh,c8,c8,wh,wh,wh,c8,c8,wh,wh,wh,wh},
    {wh,wh,wh,wh,c8,c8,wh,wh,wh,c8,c8,wh,wh,wh,wh},
    {wh,wh,wh,wh,c8,c8,wh,wh,wh,c8,c8,wh,wh,wh,wh},
    {wh,wh,wh,wh,c8,c8,c8,c8,c8,c8,c8,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,c8,c8,c8,c8,c8,wh,wh,wh,wh,wh},
    {wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh,wh}
};

int flagSprite[15][15] = 
{
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0,c1, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0,c1,c1, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3, 0, 0, 0, 0, 0, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3, 0, 0,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3},
    {0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3,0x9cf3}
};

// minefield: 13x13 grid
int mines[13][13]; // 0 means no mine, 1 means mine

// what the player can see
int field[13][13]; // 0 - 8 is mine count, 10 is covered, 11 is flagged


// functions
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

void renderScreen(int selX, int selY, int lost)
{
    Bdisp_AllClr_VRAM();
    unsigned short *p = GetVRAMAddress();

    for (int i=0; i<(13*16+1)*(13*16+1); i++) // 13*13 grid
    {
        int x = i % (13*16+1); // x and y are swapped
        int y = i / (13*16+1); 

        if ((x >= selX * 16) && (x <= selX * 16 + 16) && (y >= selY * 16 )&& (y <= selY * 16 + 16) && (x % 16 == 0 || y % 16 == 0))
        {
            // selected cell (outline)
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) 0x07E0; // green
        }
        else if (x % 16 == 0 || y % 16 == 0)
        {
            // outline
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) 0;
        }
        else if (lost == 1 && mines[y / 16][x / 16] == 1)
        {
            // mine, displays after losing
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) 0xF800; // red
        }
        else if (field[y / 16][x / 16] == 10)
        {
            // closed cell
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) 0x9cf3; // light gray
        }
        else if (field[y / 16][x / 16] == 11)
        {
            // flagged cell
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) flagSprite[y%16-1][x%16-1]; // flag sprite
        }
        else if (field[y / 16][x / 16] == 0)
        {
            // open cell (no neighboring mines)
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) 0xFFFF; // white
        }
        else if (field[y / 16][x / 16] == 1)
        {
            // open cell (one)
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) oneSprite[y%16-1][x%16-1]; // one sprite
        }
        else if (field[y / 16][x / 16] == 2)
        {
            // open cell (two)
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) twoSprite[y%16-1][x%16-1]; // two sprite
        }
        else if (field[y / 16][x / 16] == 3)
        {
            // open cell (three)
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) threeSprite[y%16-1][x%16-1]; // three sprite
        }
        else if (field[y / 16][x / 16] == 4)
        {
            // open cell (four)
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) fourSprite[y%16-1][x%16-1]; // four sprite
        }
        else if (field[y / 16][x / 16] == 5)
        {
            // open cell (five)
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) fiveSprite[y%16-1][x%16-1]; // five sprite
        }
        else if (field[y / 16][x / 16] == 6)
        {
            // open cell (six)
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) sixSprite[y%16-1][x%16-1]; // six sprite
        }
        else if (field[y / 16][x / 16] == 7)
        {
            // open cell (seven)
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) sevenSprite[y%16-1][x%16-1]; // seven sprite
        }
        else if (field[y / 16][x / 16] == 8)
        {
            // open cell (eight)
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) eightSprite[y%16-1][x%16-1]; // eight sprite
        }
        else
        {
            // this should never happen
            *(p + LCD_WIDTH_PX*y + x) = (unsigned short) 0xFF00; // magenta
        }
    }
}

int openTile(int x, int y)
{
    if (field[y][x] != 10)
    {
        // already opened or flagged
        return 0;
    }
    if (mines[y][x] == 1)
    {
        return 1; // tell main that a mine was hit
    }

    // count neighboring mines
    int mineCount = 0;
    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dx == 0 && dy == 0) continue; // skip self
            int bx = x + dx; // position on board
            int by = y + dy;
            if (bx >= 0 && bx < 13 && by >= 0 && by < 13) // ensure is in bounds
            {
                mineCount += mines[by][bx]; // uses fact that a mine is 1
            }
        }
    }

    field[y][x] = mineCount; // set the cell to show mine count

    // zero spreading
    if (mineCount == 0)
    {
        // recursively open neighboring cells
        for (int dy = -1; dy <= 1; dy++)
        {
            for (int dx = -1; dx <= 1; dx++)
            {
                if (dx == 0 && dy == 0) continue; // skip self
                int bx = x + dx; // position on board
                int by = y + dy;
                if (bx >= 0 && bx < 13 && by >= 0 && by < 13) // ensure is in bounds
                {
                    openTile(bx, by); // recursive call
                }
            }
        }
    }

    return 0;
}

void setup() // sets up game
{
    for (int y = 0; y < 13; y++)
    {
        for (int x = 0; x < 13; x++)
        {
            mines[y][x] = 0; // no mines
            field[y][x] = 10; // all cells
        }
    }

    
    srand(clock()); // update seed

    // place 30 mines 
    for(int i = 0; i < 30; i++)
    {
        int x = rand() % 13;
        int y = rand() % 13;
        mines[x][y] = 1;
    }
}

// main code
int main()
{
    Bdisp_EnableColor(1); // enable color display
    PrintXY(2,4,"--Press Any Key", TEXT_MODE_NORMAL, TEXT_COLOR_RED); // It ignores the first 2 characters of the string for whatever reason

    setup();
    int selX = 0;
    int selY = 0;

    int key;
    while(1)
    {
        GetKey(&key);
        

        

        if (key == 0x7542)
        {
            // up
            selY--;
        }
        else if (key == 0x7544)
        {
            // left
            selX--;
        }
        else if (key == 0x7545)
        {
            // right
            selX++;
        }
        else if (key == 0x7547)
        {
            // down
            selY++;
        }
        else if (key == 0x7538)
        {
            // open cell
            int lost = openTile(selX, selY); // will be 1 if a mine was hit
            if (lost == 1)
            {
                renderScreen(selX, selY, 1); // render with mines shown
                PrintXY(13,1,"--You Lost!", TEXT_MODE_NORMAL, TEXT_COLOR_RED);
                PrintXY(13,2,"--Press Key", TEXT_MODE_NORMAL, TEXT_COLOR_RED);

                GetKey(&key); // wait for key press

                setup(); // reset game
                selX = 0;
                selY = 0;
                renderScreen(selX, selY, 0); // reset screen

                continue; // prevent rest of iteration
            }
        }
        else if (key == 0x008B)
        {
            // flag cell
            if (field[selY][selX] == 10)
            {
                field[selY][selX] = 11; // flag it
            }
            else if (field[selY][selX] == 11)
            {
                field[selY][selX] = 10; // unflag it
            }
        }
        else if (key == KEY_CTRL_EXIT) 
        {
            break;
        }

        selX = mod(selX, 13);
        selY = mod(selY, 13);

        renderScreen(selX, selY, 0);

        // instructions
        PrintXY(13,1,"--optn=open", TEXT_MODE_NORMAL, TEXT_COLOR_RED);
        PrintXY(13,2,"--x^2 =flag", TEXT_MODE_NORMAL, TEXT_COLOR_RED);

        // win detection
        int unopenedCells = 0;
        for (int y = 0; y < 13; y++)
        {
            for (int x = 0; x < 13; x++)
            {
                if ((field[y][x] == 10 || field[y][x] == 11) && mines[y][x] == 0)
                {
                    unopenedCells++;
                    continue; // no point continuing if we found one
                }
            }
        }
        // win handling
        if (unopenedCells == 0)
        {
            renderScreen(selX, selY, 1); // render with mines shown
            PrintXY(13,1,"--You Win!", TEXT_MODE_NORMAL, TEXT_COLOR_RED);
            PrintXY(13,2,"--Press Key", TEXT_MODE_NORMAL, TEXT_COLOR_RED);

            GetKey(&key); // wait for key press

            setup(); // reset game
            selX = 0;
            selY = 0;
            renderScreen(selX, selY, 0); // reset screen

            continue; // prevent rest of iteration
        }

        /*
        char bufferX[20];
        itoa(selX,(unsigned char*)bufferX + 2);
        char bufferY[20];
        itoa(selY,(unsigned char*)bufferY + 2);
        
        PrintXY(3,8,bufferX, TEXT_MODE_NORMAL, TEXT_COLOR_RED);
        PrintXY(6,8,bufferY, TEXT_MODE_NORMAL, TEXT_COLOR_RED);
        */
    }

    return 0;
}