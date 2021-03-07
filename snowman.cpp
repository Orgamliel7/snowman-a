//
// Created by orgam on 07/03/2021.
//
#include "snowman.hpp"
#include <iostream>
#include <string>
#include <array>
#include <exception>
using namespace std;

//  נייצר מערכים קבועים שייצגו את כל המרכיבים האפשריים לאיש שלג - 4 אופציות לכל אחד

const array<std::string,4> left_arm_tops = {" ","\\"," "," "}; // כל סוגי יד שמאל עליונה
const array<std::string,4> left_arms = {"<"," ","/"," "}; // כל סוגי יד שמאל תחתונה
const array<std::string,4> right_arm_tops = {" ","/"," "," "}; // כל סוגי יד ימין עליונה
const array<std::string,4> right_arms = {">"," ","\\"," "}; // כל סוגי יד ימין תחתונה
const array<std::string,4> hats = {"_===_"," ---\n .....", "  -\n  /_\\"," ---\n (_*_)"}; //  כל סוגי הכובעים
const array<std::string,4> noses = {",",".","_"," "}; // כל סוגי האף האפשריים
const array<std::string,4> left_eyes = {".","o","O","-"}; // כל סוגי עין שמאל
const array<std::string,4> right_eyes = {".","o","O","-"}; // כל סוגי עין ימין
const array<std::string,4> torsos = {" : ", "] [","> <", "   "}; // כל סוגי פלג גוף עליון
const array<std::string,4> bases = {" : ", "\" \"", "___","   "}; // כל סוגי הבסיס, תחתית איש השלג


std::string build_face(array<int,8> types)
{
    std::string face = left_arm_tops[types[4]]+"("+left_eyes[types[2]]+noses[types[1]]+right_eyes[types[3]]+")"+right_arm_tops[types[5]];
    return face;
}
std::string build_body(array<int,8> types)
{
    std::string body =left_arms[types[4]]+"("+torsos[types[6]]+")"+right_arms[types[5]];
    return body;
}
std::string build_base(int type)
{
    std::string lower_part = " ("+bases[type]+ ")";
    return lower_part;
}

array<int,8> validate_input(int type){
    if(type<11111111 || type>44444444){
        throw std::out_of_range("size is out of range");
    }
    array<int,8> types;
    for (int i = 8; i > 0; --i) {
        if(type%10<1||type%10>4){
            throw std::out_of_range("value out of range");
        }
        types[i-1] = type%10-1;
        type = type/10;
    }
    return types;
}

std::string build_snowman(array<int,8> types){
    //creates the string for the base
    std::string base = build_base(types[7]);
    //creates the string for the torso
    std::string body = build_body(types);
    //creates the string for the hat
    std::string hat = hats[(int)types[0]];
    //creates the string for the face
    std::string face = build_face(types);
    return " "+hat+"\n"+face+"\n"+body+"\n"+base+" ";
}

string ariel::snowman(int type){
    //validates the inputed data and returns it
    array<int,8> types = validate_input(type);
    //builds the string for he snowman
    return build_snowman(types);
}

// int main()
// {
//     std::cout<< ariel::snowman(11111111);
//    return 0;
// }