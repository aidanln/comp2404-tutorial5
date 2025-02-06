// HeapArrays class header file
#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include <iostream>
#include "TextArea.h"

using std::string;


class TAArray {

    // function prototypes
    public:

        // constructors and deconstructor
        TAArray();
        ~TAArray();

        // required functions & helpers
        void add(TextArea *ta);
        bool add(TextArea *ta, int index);

        // test class specific functions, not listed in tutorial spec??
        TextArea* remove(int index);
        TextArea* remove(string indexStr);
        TextArea* get(int index) const;
        TextArea* get(string indexStr) const;
        int getSize(void) const;

        // from previous implementation
        TextArea** getPointerArray(void) const;

    // member variable declarations
    private:

        // arrays are dynamically allocated, assigned in the constructor
        TextArea** backingArray;
        int TAcount;

};

#endif