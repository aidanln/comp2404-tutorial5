// HeapArrays class file, defines everything in StackArrays.h

#include <iostream>
#include "defs.h"
#include "TAArray.h"
#include "TextArea.h"

using namespace std;


// 0-arg default constructor, initalizes the array and counter
TAArray::TAArray() {
    backingArray = new TextArea*[MAX_COMPONENTS];
    TAcount = 0;
}


// de-constructor, frees all dynamically allocated memory from heap
TAArray::~TAArray() {

    // delete each dynamic copy in the pointer array
    /*
    for (int i = 0; i < TAcount; ++i) {
        delete backingArray[i];
    }
    */

    // delete dynamic pointer array
    delete[] backingArray;
}


// 1-arg add method, adds the param TextArea to the back of the backing array
void TAArray::add(TextArea *ta) {
    // bounds check
    if (TAcount < MAX_COMPONENTS) {
        // create dynamically allocated copy
        backingArray[MAX_COMPONENTS - 1 - TAcount] = ta;
        TAcount++;
    }
}


// 2-arg add method, inserts the param TextArea to the specific
bool TAArray::add(TextArea *ta, int index) {
    // bounds check
    if (index >= 0 && index < TAcount) {
        backingArray[index] = ta;
        return true;
    }
    return false;
}


// removes an element from the backing array
TextArea* TAArray::remove(int index) {
    // bounds check
    if (index >= 0 && index < TAcount) {
        TextArea* temp = backingArray[MAX_COMPONENTS - 1 - index];
        // shift elements
        for (int i = index; i < TAcount - 1; i++) {
            backingArray[MAX_COMPONENTS - 1 - i] = backingArray[MAX_COMPONENTS - 2 - i];
        }
        TAcount--;
        return temp;
    }
    return nullptr;
}


// this method only exists to correct the dogshit test code
TextArea* TAArray::remove(string indexStr) {
    int index = stoi(indexStr);
    // bounds check
    if (index >= 0 && index < TAcount) {
        TextArea* temp = backingArray[MAX_COMPONENTS - 1 - index];
        // shift elements
        for (int i = index; i < TAcount - 1; i++) {
            backingArray[MAX_COMPONENTS - 1 - i] = backingArray[MAX_COMPONENTS - 2 - i];
        }
        TAcount--;
        return temp;
    }
    return nullptr;
}


// getter for a TextArea's pointer in the pointer array
TextArea* TAArray::get(int index) const {
    if (index >= 0 && index < TAcount) {
        return backingArray[index];
    }
    return nullptr;
}


// this method only exists to correct the dogshit test code
TextArea* TAArray::get(string indexStr) const {
    int index = stoi(indexStr);
    if (index >= 0 && index < TAcount) {
        return backingArray[index];
    }
    return nullptr;
}


// getter for the quantity of TextAreas in the backing array
int TAArray::getSize(void) const {
    return TAcount;
}


// getter for the full pointer array
TextArea** TAArray::getPointerArray(void) const {
    return backingArray;
}
