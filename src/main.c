#include <stdio.h>
#include "SDL2/SDL.h"
#include "chip8.h"

const char keyboard_map[CHIP8_TOTAL_KEYS] = {
    SDLK_0, SDLK_1, SDLK_2, SDLK_3, SDLK_4, SDLK_5,
    SDLK_6, SDLK_7, SDLK_8, SDLK_9, SDLK_a, SDLK_b,
    SDLK_c, SDLK_d, SDLK_e, SDLK_f};

int main(int argc, char **argv)
{
    struct chip8 Chip8;
    chip8_init(&Chip8);

    // chip8_screen_set(&Chip8.SCREEN, 0, 0);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow( // Creates a Window
        EMULATOR_WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        CHIP8_WIDTH * CHIP8_WINDOW_MULTIPLIER, CHIP8_HEIGHT * CHIP8_WINDOW_MULTIPLIER, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);
    while (1)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                goto out;
                break;

            case SDL_KEYDOWN:
            {
                char key = event.key.keysym.sym;
                int vkey = chip8_keyboard_map(keyboard_map, key); // translated virtual key from physical key
                if (vkey != -1)
                {
                    chip8_keyboard_down(&Chip8.KEYBOARD, vkey);
                }
            }
            break;

            case SDL_KEYUP:
            {
                char key = event.key.keysym.sym;
                int vkey = chip8_keyboard_map(keyboard_map, key); // translated virtual key from physical key
                if (vkey != -1)
                {
                    chip8_keyboard_up(&Chip8.KEYBOARD, vkey);
                }
            }
            break;
            };
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

        for (int x = 0; x < CHIP8_WIDTH; x++)
        {
            for (int y = 0; y < CHIP8_HEIGHT; y++)
            {
                if (chip8_screen_is_set(&Chip8.SCREEN, x, y))
                {
                    SDL_Rect rect;
                    rect.x = x * CHIP8_WINDOW_MULTIPLIER; // position x
                    rect.y = y * CHIP8_WINDOW_MULTIPLIER; // position y
                    rect.h = 10;                          // size x
                    rect.w = 10;                          // size y
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }

        SDL_RenderPresent(renderer);
    }
out:
    SDL_DestroyWindow(window);
    return 0;
}