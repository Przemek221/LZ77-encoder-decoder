#include "device.h"

unsigned char device::read(std::ifstream &file) { //reading one character from a file
    unsigned char input = 0;

    if (file.peek() != EOF) {
        file.read((char *) &input, sizeof(char));
    }

    return input;
}

