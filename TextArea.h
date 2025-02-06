// TextArea class header file
#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include "defs.h"
#include "RGB.h"

using std::string;


class TextArea {

    // function prototypes
    public:

        // constructors (tutorial specific)
        TextArea(int xP, int yP, int widthP, int heightP, string idP, string labelP, RGB fillP, RGB borderP);
        TextArea(Rectangle dims, string idP, string labelP, RGB fillP, RGB borderP);
        TextArea();

        // constructors (test file specific)
        TextArea(Rectangle dims, string idP, string labelP);
        TextArea(int xP, int yP, int widthP, int heightP, string idP, string labelP);

        // copy constructor
        TextArea(const TextArea &copied);

        // deconstructor
        ~TextArea();

        // required functions & helpers
        bool overlaps(TextArea ta) const;
        void print() const;

        // getters
        Rectangle getRectangle(void) const;
        string getId(void) const;
        string getText(void) const;
        RGB getFill(void) const;
        RGB getBorder(void) const;

        // setters
        void setFill(RGB fillP);
        void setBorder(RGB borderP);

        // helper counter variable to differentiate default TextAreas
        static int uniqueNum;
    
    // member variable declarations
    private:

        // required by tutorial spec
        Rectangle dimensions;
        string id, text;
        RGB fill, border;

};

#endif