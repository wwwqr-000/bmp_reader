#include <iostream>
#include "classes/dimensions.hpp"
#include "classes/bmp.hpp"

int main() {
    std::string path = "test.bmp";
    bmp img(path, 100, 100);
    int imgStat = -1;
    img.createPixels(imgStat);
    if (imgStat != 0) {

    }
    point3 pixel = img.getPixelValue(0, 0);
    std::cout << "Red: " << std::to_string(pixel.x_i) << "\nGreen: " << std::to_string(pixel.y_i) << "\nBlue: " << std::to_string(pixel.z_i) << "\n";
    std::cout << "\nRGB value of 24-bit bmp file at coordinate 0, 0\n";
}
