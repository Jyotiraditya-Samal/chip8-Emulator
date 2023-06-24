#ifndef CHIP8_MEMORY
#define CHIP8_MEMORY

#include "config.h"
struct chip8memory
{
    unsigned char memory[CHIP8_MEMORY_SIZE];
};
void chip8_memory_set(struct chip8memory *memory, int index, unsigned char val);
unsigned char chip8_memory_get(struct chip8memory *memory, int index);
#endif