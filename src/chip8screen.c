#include "chip8screen.h"
#include <assert.h>

static void chip8_screen_check_bounds(int x, int y)
{
    assert(x >= 0 && x < CHIP8_WIDTH && y >= 0 && y < CHIP8_HEIGHT);
}
void chip8_screen_set(struct chip8screen *screen, int x, int y)
{
    chip8_screen_check_bounds(x, y);
    screen->pixels[x][y] = true;
}
bool chip8_screen_is_set(struct chip8screen *screen, int x, int y)
{
    chip8_screen_check_bounds(x, y);
    return screen->pixels[x][y];
}