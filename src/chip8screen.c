#include "chip8screen.h"
#include <assert.h>

static void chip8_screen_check_bounds(int x, int y)
{
    assert(x >= 0 && x < CHIP8_WIDTH && y >= 0 && y < CHIP8_HEIGHT);
}
void chip8_screen_set(struct chip8screen *screen, int x, int y)
{
    chip8_screen_check_bounds(x, y);
    screen->pixels[y][x] = true;
}
void chip8_screen_dead(struct chip8screen *screen, int x, int y)
{
    chip8_screen_check_bounds(x, y);
    screen->pixels[y][x] = false;
}
void chip8_screen_clean(struct chip8screen *screen) // adi :: cleans up garbage pixels
{
    for (int a = 0; a < CHIP8_WIDTH; a++)
    {
        for (int b = 0; b < CHIP8_HEIGHT; b++)
        {
            chip8_screen_dead(screen, a, b);
        }
    }
}
bool chip8_screen_is_set(struct chip8screen *screen, int x, int y)
{
    chip8_screen_check_bounds(x, y);
    return screen->pixels[y][x];
}