#ifndef CHIP8_H
#define CHIP8_H

#include "config.h"
#include "chip8memory.h"
#include "chip8registers.h"
#include "chip8stack.h"
#include "chip8keyboard.h"
#include "chip8screen.h"

struct chip8
{
    struct chip8memory MEMORY;
    struct chip8registers REGISTERS;
    struct chip8stack STACK;
    struct chip8keyboard KEYBOARD;
    struct chip8screen SCREEN;
};

void chip8_init(struct chip8 *chip8);

#endif