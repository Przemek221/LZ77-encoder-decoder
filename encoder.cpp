
#include "encoder.h"

unsigned char *encoder::longestSequence() { //finding the longest sequence in the dictionary

    int actual = 0, previous = 0; //number of elements in the actual and previous sequences
    int i = 0, j = 0;

    //emptying tab
    tab[0] = 0;
    tab[1] = 0;
    tab[2] = 0;


    while (i < dictionary.size()) {
        if (dictionary[i] == buffer[j]) { //if the symbol from dictionary matches to the buffer symbol
            actual++;
            i++;
            j++;
        } else {

            if (previous >= actual) { //if new sequence is longer than actual
                actual = 0;
            } else {
                previous = actual;
                actual = 0;

                tab[0] = (i - previous);

                if (j < buffer.size()) { //if the buffer is fully used
                    //no -> next symbol is the next symbol
                    tab[2] = buffer[j];
                } else {
                    //yes -> next symbol is the last one from the buffer and the length of the sequence is decreased by 1
                    tab[2] = buffer[j - 1];
                    tab[1] = 1;
                    break; //buffer is fully used so the loop is being break
                }
            }

            j = 0; //reseting the buffer index

            if (dictionary[i] != buffer[j]) i++; //if the symbols are not the same, there is no progress

        }


    }

    //additional verification in case of the break of the loop

    if (previous >= actual) {//if the actual sequence is longer than previous
        actual = 0;
    } else {
        previous = actual;
        actual = 0;

        tab[0] = (i - previous);

        if (j < buffer.size()) { //if the buffer is fully used
            //no -> next symbol is the next symbol
            tab[2] = buffer[j];
        } else {
            //yes -> next symbol is the last one from the buffer and the length of the sequence is decreased by 1
            tab[2] = buffer[j - 1];
            tab[1] = 1;
        }

    }


    if (tab[1] == 0) { //when the buffer wasn't fully used
        tab[1] = (previous);
    } else { //when the buffer was fully used
        tab[1] = (previous - 1);
    }
    if (previous == 0) tab[2] = buffer[0]; //when we won't find any symbol, so the previous sequence will be empty

    return tab;
}

void encoder::print() {
    for (unsigned char x: tab) {
        _out_encoder << x;
    }
}

void encoder::move(int arg) { //moving the symbols in the dictionary and in the buffer
    for (int i = 0; i < arg; ++i) {
        if (!dictionary.empty()) dictionary.pop_front();

        if (!buffer.empty()) {
            dictionary.push_back(buffer[0]);
            buffer.pop_front();
        }

        if (_in_encoder.peek() != EOF) buffer.push_back(read(_in_encoder));
    }
}

void encoder::initialize() {
    //After the initialization, the dictionary is filled with the elements from the buffer

    for (int i = 0; i < SIZE; ++i) {
        buffer.push_back(read(_in_encoder));
        dictionary.push_back(buffer[0]);
    }

    tab[0] = 0;
    tab[1] = 0;
    tab[2] = buffer[0];
    print();
    move(1);

}


void encoder::openFiles() {
    _in_encoder.open(_fileName, std::ios_base::binary);
    _out_encoder.open("output_encoder.txt", std::ios_base::binary);

    std::cout << "\n\t" << (_in_encoder && _out_encoder ? "encoder files opened" : "encoder files not opened");
}

void encoder::closeFiles() {
    _in_encoder.close();
    _out_encoder.close();
}

void encoder::encode() {
    openFiles();
    initialize();

    while (!buffer.empty()) { //while the buffer is not empty
        longestSequence();
        print();
        move((tab[1]) + 1);
    }

    closeFiles();
}

void encoder::setFileName(const std::string &arg) {
    encoder::_fileName = arg;
}
