#include "chip8memory.h"
#include <assert.h>

static void chip8_memory_in_bounds(int index)
{
    assert(index >= 0 && index < CHIP8_MEMORY_SIZE);
}
void chip8_memory_set(struct chip8memory *Memory, int index, unsigned char val)
{
    chip8_memory_in_bounds(index);
    Memory->memory[index] = val;
}
unsigned char chip8_memory_get(struct chip8memory *Memory, int index)
{
    chip8_memory_in_bounds(index);
    return Memory->memory[index];
}
