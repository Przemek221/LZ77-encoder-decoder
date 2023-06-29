
#ifndef ENCODER_DECODER_DECODER_H
#define ENCODER_DECODER_DECODER_H

#include "device.h"

class decoder: device {

private:
    std::ifstream _in_dekoder;
    std::ofstream _out_dekoder;
    std::string _fileName;
    void print();
    void move();
    void openFiles();
    void closeFiles();
    void read();
    void initialize();
public:
    void decode();
    void setFileName(const std::string &arg);
};


#endif //ENCODER_DECODER_DECODER_H
