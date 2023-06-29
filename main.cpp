#include <iostream>
#include "encoder.h"
#include "decoder.h"

int main() {
    bool end = false;
    char input;
    std::string fileName;

    //encoder and decoder objects
    encoder k;
    decoder d;

    std::cout << "\n*** LZ77 Algorithm ***"
                 "\nIntroduction:"
                 "\nfile: 'output_encoder.txt' - default file name for encoder output and decoder input"
                 "\nfile: 'output_decoder.txt' - default file name for decoder output";

    while (!end) {
        std::cout << "\nChoose option:"
                     "\n1.Encode"
                     "\n2.Decode"
                     "\nPress any other button to exit\n";
        std::cin >> input;

        switch (input) {
            case '1':
                std::cout<<"\nenter a file name to encode [example: file.txt]: ";
                std::cin >> fileName;
                k.setFileName(fileName);
                k.encode();
                std::cout<<'\n';
                break;
            case '2':
                std::cout<<"\nenter a file name to decode [default: output_encoder.txt]: ";
                std::cin >> fileName;
                d.setFileName(fileName);
                d.decode();
                std::cout<<'\n';
                break;
            default:
                end = true;
                break;
        }
    }

    return 0;
}