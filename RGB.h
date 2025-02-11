// RGB class header file
#ifndef RGB_H
#define RGB_H

#include <iostream>
#include "defs.h"

// Character class def
class RGB {

    // function prototypes
    public:

        // constructors
        RGB(int red, int green, int blue);
        RGB(CuColour colour);
        RGB();
        ~RGB();

        // getters
        int getR() const;
        int getG() const;
        int getB() const;
        CuColour getColour() const;

        // setters
        void setR(int red);
        void setG(int green);
        void setB(int blue);
        void setColour(CuColour colour);

        // required functions & helpers
        void print() const;

        // static functions
        static RGB WHITE();
        static RGB BLACK();
        static RGB RED();
        static RGB GREEN();
        static RGB BLUE();
    
    // variable prototypes
    private:
        int r, g, b;

};

#endif