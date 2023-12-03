
#pragma once

#ifndef __COLORCODE__COLORCODE_HPP__
#define __COLORCODE__COLORCODE_HPP__

#include <array>


class ColorCode {
private:
    std::array<int, 256> m_RegisterArray;
    // Register 0 is instruction pointer
    // Register 1 is operation resultant-1
    // Register 2 is operation resultant-2
    // Register 3 is operation resultant-3
    // Register 4 is operation resultant-4
public:
    ColorCode() {
        for (int registerIndex = 0; registerIndex < m_RegisterArray.max_size(); registerIndex++) {
            m_RegisterArray[registerIndex] = 0;
        }
    }

    ~ColorCode() {}

    
    int getRegister(size_t registerIndex) const {
        return m_RegisterArray[registerIndex];
    }

    void setRegister(size_t registerIndex, int value) {
        m_RegisterArray[registerIndex] = value;
    }
};

#endif
