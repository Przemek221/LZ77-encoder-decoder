
#include "decoder.h"


void decoder::read() { //filling tab with characters from a file
    for (unsigned char &i: tab) {
        i = device::read(_in_dekoder);
    }
}

void decoder::initialize() {
    tab[0] = 0;
    tab[1] = 0;
    tab[2] = 0;
    buffer.clear();
    dictionary.clear();
    read();

    //filling the dictionary with tab[2] element
    for (int i = 0; i < SIZE; ++i) {
        dictionary.push_back(tab[2]);
    }
}

void decoder::move() { //moving the elements in the dictionary
    for (unsigned char &el: buffer) {
        dictionary.pop_front();
        dictionary.push_back(el);
    }
}

void decoder::decode() {
    openFiles();
    initialize();

    while (!dictionary.empty()) {
        print();
        move();
        buffer.clear();
        if (_in_dekoder.peek() != EOF) { read(); } else { break; }
    }

    closeFiles();
}


void decoder::openFiles() {
    _in_dekoder.open(_fileName, std::ios_base::binary);
    _out_dekoder.open("output_decoder.txt", std::ios_base::binary);

    std::cout << "\n\t" << (_in_dekoder && _out_dekoder ? "decoder files opened" : "decoder files not opened");
}

void decoder::closeFiles() {
    _in_dekoder.close();
    _out_dekoder.close();
}

void decoder::print() { //printing decoded sequence
    //buffer => decoded sequence
    int y = tab[0];
    for (int i = 0; i < (tab[1]); i++, y++) {
        _out_dekoder << (char) (dictionary[y]);
        buffer.push_back(dictionary[y]);
    }
    _out_dekoder << (char) tab[2];
    buffer.push_back(tab[2]); //the next char in the sequence goes to the buffer
}

void decoder::setFileName(const std::string &arg) {
    decoder::_fileName = arg;
}