// TextArea class file, defines everything in TextArea.h

#include <iostream>
#include "defs.h"
#include "RGB.h"
#include "TextArea.h"

using namespace std;

int TextArea::uniqueNum = 0;


// 8-arg constructor for initializing the text area
TextArea::TextArea(int xP, int yP, int widthP, int heightP,
    string idP, string labelP, RGB fillP, RGB borderP) {
        dimensions = {xP, yP, widthP, heightP};
        id = idP;
        text = labelP;
        fill = fillP;
        border = borderP;
    }


// 5-arg (via rectangle struct) constructor for initializing the text area
TextArea::TextArea(Rectangle dims, string idP, string labelP, RGB fillP, RGB borderP) {
    dimensions = dims;
    id = idP;
    text = labelP;
    fill = fillP;
    border = borderP;
}


// 0-arg constructor, initalizes the text area to default values
TextArea::TextArea() {
    dimensions = {10, 10, 200, 100};
    id = "Default Constructor #" + to_string(uniqueNum);
    uniqueNum++;
    text = "Lorem Ipsum";
    fill = RGB::WHITE();
    border = RGB::BLACK();
}


// 3-arg constructor, contained in test.cc but not the tutorial spec?
TextArea::TextArea(Rectangle dims, string idP, string labelP) {
    dimensions = dims;
    id = idP;
    text = labelP;
    fill = RGB::WHITE();
    border = RGB::BLACK();
}

// 6-arg construtor, contained in test2.cc but not the tutorial spec?
TextArea::TextArea(int xP, int yP, int widthP, int heightP, string idP, string labelP) {
    dimensions = {xP, yP, widthP, heightP};
    id = idP;
    text = labelP;
    fill = RGB::WHITE();
    border = RGB::BLACK();
}


// copy constructor, creates a new instance of an existing object
TextArea::TextArea(const TextArea &copied) {
    dimensions = copied.getRectangle();
    id = copied.getId() + to_string(uniqueNum);
    uniqueNum++;
    text = "DUPLICATE";
    fill = copied.getFill();
    border = copied.getBorder();
}


// generic de-constructor
TextArea::~TextArea() {}


// returns true if the param TextArea overlaps this TextArea, else false
bool TextArea::overlaps(TextArea ta) const {
    return dimensions.overlaps(ta.getRectangle());
}


// prints out a nicely formatted version of all the TextArea info
void TextArea::print() const {
	cout << "=-=-= Info For Text Area with ID \"" << id << "\" is Listed Below =-=-="
         << "\nDimensions -> x=" << dimensions.x << ", y=" << dimensions.y
         << ", width=" << dimensions.width << ", height=" << dimensions.height
         << "\nText -> " << text
         << "\nFill Colour Info -> ";
    fill.print();
    cout << "Border Colour Info -> ";
    border.print();
    cout << endl;
}


// definitions for getter functions
Rectangle TextArea::getRectangle(void) const { return dimensions; }
string TextArea::getId(void) const { return id; }
string TextArea::getText(void) const { return text; }
RGB TextArea::getFill(void) const { return fill; }
RGB TextArea::getBorder(void) const { return border; }

// definitions for setter functions
void TextArea::setFill(RGB fillP) { fill = fillP; }
void TextArea::setBorder(RGB borderP) { border = borderP; }
