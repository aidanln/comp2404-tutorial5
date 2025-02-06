// RGB class file, defines everything in RGB.h

#include <iostream>
#include "defs.h"
#include "RGB.h"

using namespace std;


// 3-arg constructor for initializing each r,g,b value individually
RGB::RGB(int red, int green, int blue) {

    // red bounds check
    if (red < 0 || red > 255) {
        cout << "\nred value is out of bounds (0-255), defaulting to 0." << endl;
        r = 0;
    } else {
        r = red;
    }

    // green bounds check
    if (green < 0 || green > 255) {
        cout << "\ngreen value is out of bounds (0-255), defaulting to 0." << endl;
        g = 0;
    } else {
        g = green;
    }

    // blue bounds check
    if (blue < 0 || blue > 255) {
        cout << "\nblue value is out of bounds (0-255), defaulting to 0." << endl;
        b = 0;
    } else {
        b = blue;
    }

}


// extracts bytes from CuColor to initialize RGB value
RGB::RGB(CuColour colour) {

    // prioritzes the least significant bytes each time (i.e. leftmost 8 bits)
    b = (colour & 255); // first byte (blue)
    g = (colour >> 8) & 255;  // second byte (green)
    r = (colour >> 16) & 255; // third byte (red)

}


// default constructor, no args, initializes r,g,b to 0,0,0
RGB::RGB() {
    r = 0;
    g = 0;
    b = 0;
}


// generic de-constructor
RGB::~RGB() {}


// standard r,g,b value getters
int RGB::getR() const { return r; }
int RGB::getG() const { return g; }
int RGB::getB() const { return b; }


// returns the RGB value in CuColor format
CuColour RGB::getColour() const {
    return ((r << 16) | (g << 8) | b);
}


// standard r,g,b value setters
void RGB::setR(int red) { r = red; }
void RGB::setG(int green) { g = green; }
void RGB::setB(int blue) { b = blue; }


// sets the RGB value based on a CuColor, identical to the 1-arg constructor
void RGB::setColour(CuColour colour) {
    b = (colour & 255);
    g = (colour >> 8) & 255;
    r = (colour >> 16) & 255;
}


// prints out a nicely formatted version of the RGB value
void RGB::print() const {
	cout << "RGB Color -> (" << r << ", " << g << ", " << b << ")\n" << endl;
}


// static functions for returning pre-set RGB colors
RGB RGB::WHITE() {
    return RGB(255, 255, 255);
}
RGB RGB::BLACK() {
    return RGB(0, 0, 0);
}
RGB RGB::RED() {
    return RGB(255, 0, 0);
}
RGB RGB::GREEN() {
    return RGB(0, 255, 0);
}
RGB RGB::BLUE() {
    return RGB(0, 0, 255);
}