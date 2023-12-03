// Includes

#include <iostream>
#include <string>
#include <vector>

#include "bitmap_image.hpp"
#include "colorcode.hpp"
#include "instructions.hpp"


// Main function

int main() {
    std::string imageName;
    std::cout << "Enter input image file name like 'ImageFile.bmp' (must be .BMP): ";
    std::cin >> imageName;

    bitmap_image image(imageName);
    if (!image) {
        std::cout << "ERROR - Failed to open \"" << imageName <<"\"\n";
        return -1;
    }

    std::vector<rgb_t> imagePixels;
    for (size_t y = 0; y < image.height(); y++) {
        for (size_t x = 0; x < image.width(); x++) {
            rgb_t color;
            image.get_pixel(x, y, color);
            imagePixels.push_back(color);
            // std::cout << '(' << int(color.red) << ", " << int(color.green) << ", " << int(color.blue) << ") ";
        }
        // std::cout << '\n';
    }


    ColorCode colorCode;
    while (colorCode.getRegister(0) < imagePixels.size()) {
        int pixelIndex = colorCode.getRegister(0);
        rgb_t instructionPixel = imagePixels[pixelIndex];
        void (*instructionPointer)(ColorCode&, size_t, size_t) = instructionPointerArray[instructionPixel.red];
        instructionPointer(colorCode, instructionPixel.green, instructionPixel.blue);
        if (pixelIndex == colorCode.getRegister(0)) colorCode.setRegister(0, pixelIndex + 1);
    }

    return 0;
}
