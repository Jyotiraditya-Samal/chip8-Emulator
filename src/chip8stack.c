#include "chip8stack.h"
#include <assert.h>
#include "chip8.h"

static void chip8_stack_in_bounds(struct chip8 *chip8)
{
    assert(chip8->REGISTERS.SP < CHIP8_TOTAL_STACK_DEPTH);
}
void chip8_stack_push(struct chip8 *chip8, unsigned short val)
{
    chip8_stack_in_bounds(chip8);
    chip8->STACK.stack[chip8->REGISTERS.SP] = val;
    chip8->REGISTERS.SP += 1;
}

unsigned chip8_stack_pop(struct chip8 *chip8)
{
    chip8->REGISTERS.SP -= 1;
    unsigned short val = chip8->STACK.stack[chip8->REGISTERS.SP];
    return val;
}