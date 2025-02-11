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


// 1-arg add method, adds the param TextArea pointer to the back
void TAArray::add(TextArea *ta) {
    // bounds check
    if (TAcount < MAX_COMPONENTS) {
        // allocate pointer to back
        backingArray[TAcount] = ta;
        TAcount++;
    }
}


// 2-arg add method, adds the param TextArea pointer to a specified index
bool TAArray::add(TextArea *ta, int index) {
    // ensure the array isn't full
    if (TAcount < MAX_COMPONENTS) {
        // handle back index
        if (index == TAcount) {
            add(ta);
            return true;
        }
        // else, bounds check
        else if (index >= 0 && index < TAcount) {
            // shift elements fowards to make space
            for (int i = TAcount - 1; i >= index; i--) {
                backingArray[i+1] = backingArray[i];
            }
            // allocate pointer to index
            backingArray[index] = ta;
            TAcount++;
            return true;
        }
    }
    return false;
}


// removes an element based on index param
TextArea* TAArray::remove(int index) {
    // bounds check
    if (index >= 0 && index < TAcount) {
        TextArea* temp = backingArray[index];
        // shift elements backwards to fill space
        for (int i = index; i < TAcount - 1; i++) {
            backingArray[i] = backingArray[i+1];
        }
        TAcount--;
        return temp;
    }
    return nullptr;
}


// removes an element and shifts based on an ID
TextArea* TAArray::remove(string indexStr) {
    // search for ID
    for (int i = 0; i < TAcount; i++) {
        if (indexStr == backingArray[i]->getId()) {
            TextArea* temp = backingArray[i];
            // shift elements backwards to fill space
            for (int j = i; j < TAcount - 1; j++) {
                backingArray[j] = backingArray[j+1];
            }
            TAcount--;
            return temp;
        }
    }
    return nullptr;
}


// retrieves a TextArea from the backing array based on index param
TextArea* TAArray::get(int index) const {
    if (index >= 0 && index < TAcount) {
        return backingArray[index];
    }
    return nullptr;
}


// retrieves a TextArea from the backing array based on ID 
TextArea* TAArray::get(string indexStr) const {
    // search for ID
    for (int i = 0; i < TAcount; i++) {
        if (indexStr == backingArray[i]->getId()) {
            return backingArray[i];
        }
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
