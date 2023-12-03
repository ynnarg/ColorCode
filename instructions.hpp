
#pragma once

#ifndef __COLORCODE__INSTRUCTIONS_HPP__
#define __COLORCODE__INSTRUCTIONS_HPP__

#include <iostream>

#include "colorcode.hpp"


namespace instructions {
    void noOperation(ColorCode& colorCode, size_t g, size_t b) {
        return;
    }

    /* moves value at 'register[blue]' to 'register[green]' */
    void mov(ColorCode& colorCode, size_t g, size_t b) {
        colorCode.setRegister(g, colorCode.getRegister(b));
    }

    /* moves literal value 'blue' into 'register[green]' */
    void movLiteral(ColorCode& colorCode, size_t g, size_t b) {
        colorCode.setRegister(g, (int)(b));
    }

    /* does 'register[green] + register[blue]' then pushes the resultant into register 1 */
    void add(ColorCode& colorCode, size_t g, size_t b) {
        colorCode.setRegister(1, colorCode.getRegister(g) + colorCode.getRegister(b));
    }

    /* does 'register[green] - register[blue]' then pushes the resultant into register 1 */
    void sub(ColorCode& colorCode, size_t g, size_t b) {
        colorCode.setRegister(1, colorCode.getRegister(g) + colorCode.getRegister(b));
    }

    /* does 'register[green] * register[blue]' then pushes the resultant into register 1 */
    void mul(ColorCode& colorCode, size_t g, size_t b) {
        colorCode.setRegister(1, colorCode.getRegister(g) * colorCode.getRegister(b));
    }

    /* does 'register[green] / register[blue]' then pushes the resulant into register 1 and the remainder into register 2 */
    void div(ColorCode& colorCode, size_t g, size_t b) {
        colorCode.setRegister(1, colorCode.getRegister(g) / colorCode.getRegister(b));
        colorCode.setRegister(2, colorCode.getRegister(g) % colorCode.getRegister(b));
    }

    /* prints value in 'register[green]' converting the int into char */
    void print(ColorCode& colorCode, size_t g, size_t b) {
        std::cout << (char)(colorCode.getRegister(g));
    }
}


void (*instructionPointerArray[])(ColorCode&, size_t, size_t) = {
    &instructions::noOperation, // 000
    &instructions::mov,         // 001
    &instructions::movLiteral,  // 002
    &instructions::add,         // 003
    &instructions::sub,         // 004
    &instructions::mul,         // 005
    &instructions::div,         // 006
    &instructions::print,       // 007
}; 

#endif
