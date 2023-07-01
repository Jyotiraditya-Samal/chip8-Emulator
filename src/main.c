#include <stdio.h>
#include "SDL2/SDL.h"
#include "chip8.h"

int main(int argc, char **argv)
{
    struct chip8 Chip8;
    Chip8.REGISTERS.SP = 0;

    chip8_stack_push(&Chip8, 0xff);
    chip8_stack_push(&Chip8, 0xaa);

    printf("%x \n", chip8_stack_pop(&Chip8));
    printf("%x \n", chip8_stack_pop(&Chip8));

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
            if (event.type == SDL_QUIT)
            {
                goto out;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 57, 230, 0);
        SDL_Rect rect;
        rect.x = 193; // position x
        rect.y = 35;  // position y
        rect.h = 255; // size x
        rect.w = 255; // size y
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }
out:
    SDL_DestroyWindow(window);
    return 0;
}