#ifndef ENCODER_DECODER_DEVICE_H

#define ENCODER_DECODER_DEVICE_H

#include <iostream>
#include <fstream>
#include <deque>

#define SIZE 200 //size of the buffer and the dictionary

class device {
protected:
    std::deque<unsigned char> dictionary;
    std::deque<unsigned char> buffer;
    unsigned char tab[3] = {0, 0, 0};
    /*tab={A,B,C}
     * A - index of the 1st matching char in the dictionary
     * B - length of matching sequence
     * C - the next symbol after the matching sequence
     * */
public:
    static unsigned char read(std::ifstream &file);

};


#endif //ENCODER_DECODER_DEVICE_H
