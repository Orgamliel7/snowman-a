//
// Created by orgam on 07/03/2021.
//

#include "snowman.hpp"
#include <iostream>
#include <string>
#include <array>
#include <exception>
using namespace std;

const int snowman_2=33232124; // סוג שני של איש שלג במטלה
const int snowman_1=11114411; // סוג ראשון של איש שלג במטלה

const int CheckS=10000000;


string ariel::snowman(int type)
{
    if(type<CheckS)  // קלט שלא עומד בתנאי הגודל (קטן ממנו) ולכן נזרוק שגיאה
    { 
        throw std::bad_typeid();
    }

    if(type==snowman_1) // אם זה הסוג הראשון - נדפיס בהתאם
    {
        return "_===_\n"
               "(.,.)\n"
               "( : )\n"
               "( : )";
    }
    if(type== snowman_2) // אם זה הסוג השני - נדפיס בהתאם
    {
        return "   _\n"
               "  /_\\\n"
               "\\(o_O)\n"
               " (] [)>\n"
               " (   )";
    }
    return "";
}