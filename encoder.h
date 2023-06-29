
#ifndef ENCODER_DECODER_ENCODER_H
#define ENCODER_DECODER_ENCODER_H

#include "device.h"

class encoder: device {

private:
    std::ifstream _in_encoder;
    std::ofstream _out_encoder;
    std::string _fileName;
    unsigned char *longestSequence();
    void print();
    void move(int arg);
    void openFiles();
    void closeFiles();
    void initialize();
public:
    void encode();
    void setFileName(const std::string &arg);
};


#endif //ENCODER_DECODER_ENCODER_H
