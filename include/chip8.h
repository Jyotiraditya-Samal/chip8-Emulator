#ifndef CHIP8_H
#define CHIP8_H

#include "config.h"
#include "chip8memory.h"
#include "chip8registers.h"
#include "chip8stack.h"

struct chip8
{
    struct chip8memory MEMORY;
    struct chip8registers REGISTERS;
    struct chip8stack STACK;
};

#endif