#ifndef CHIP8SCREEN_H
#define CHIP8SCREEN_H

#include <stdbool.h>
#include "config.h"

struct chip8screen
{
    bool pixels[CHIP8_HEIGHT][CHIP8_WIDTH];
};

void chip8_screen_set(struct chip8screen *screen, int x, int y);
void chip8_screen_dead(struct chip8screen *screen, int x, int y);
bool chip8_screen_is_set(struct chip8screen *screen, int x, int y);
void chip8_screen_clean(struct chip8screen *screen);
#endif