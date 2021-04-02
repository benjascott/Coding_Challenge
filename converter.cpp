//converter.cpp for coding challenge

#include "converter.h"

#include <iostream>
#include <sstream>

bool Converter::validateDecimal(){
    if((decimal > 0) && (decimal < 4000)) {
        return true;
    }
    cout << "There is no roman numeral equivalent for this decimal value." << endl;
    return false;
}

bool Converter::validateRoman(){
    for(unsigned int i = 0; i < roman.size(); i++) {
        if( (roman.at(i) != 'I') && (roman.at(i) != 'V') &&
            (roman.at(i) != 'X') && (roman.at(i) != 'L') && 
            (roman.at(i) != 'C') && (roman.at(i) != 'D') && 
            (roman.at(i) != 'M')) {
            return false;
        }
    }
    return true;
}

void Converter::convertToDigit() {
    int returnDecimal = 0;
    for (unsigned int i = 0; i < roman.size()-1; i++) {

        switch((char)roman.at(i)) {
            case 'I':
                if(roman.at(i+1) == 'V') {
                    returnDecimal += 4;
                }
                else {
                    returnDecimal += 1;
                }
                break;
            case 'V':
                returnDecimal += 5;
                break;
            case 'X':
                if(roman.at(i+1) == 'C') {
                    returnDecimal += 90;
                }
                else if(roman.at(i+1) == 'L') {
                    returnDecimal += 40;
                }
                else {
                    returnDecimal += 1;
                }
                break;
            case 'L':
                returnDecimal += 50;
                break;
            case 'C':
                if(roman.at(i+1) == 'M') {
                    returnDecimal += 900;
                }
                else if(roman.at(i+1) == 'D') {
                    returnDecimal += 400;
                }
                else {
                    returnDecimal += 100;
                }
                break;
            case 'D':
                returnDecimal += 500;
                break;
            case 'M':
                returnDecimal += 1000;
                break;
        }
    }
    decimal = returnDecimal;
}

void Converter::convertToRoman() {
    stringstream typeCasting;
    typeCasting << decimal;
    string integer = typeCasting.str();
    stringstream returnString;
    int decimalSpot = -1;
    for(unsigned int i = (integer.size()-1); i <= 0; i--) {
        decimalSpot++;
        //cout << "digit being converted is: " << integer.at(i) << endl;
        stringstream typeCasting2;
        typeCasting2 << integer.at(i);
        int x;
        typeCasting2 >> x;
        switch (x) {
            case 0:
                break;
            case 1:
                if(decimalSpot == 0) {
                    returnString << "I";
                }
                else if(decimalSpot == 1) {
                    returnString << "X";
                }
                else if(decimalSpot == 2) {
                    returnString << "C";
                }
                else if(decimalSpot == 3) {
                    returnString << "M";
                }
                break;
            case 2:
                if(decimalSpot == 0) {
                    returnString << "II";
                }
                else if(decimalSpot == 1) {
                    returnString << "XX";
                }
                else if(decimalSpot == 2) {
                    returnString << "CC";
                }
                else if(decimalSpot == 3) {
                    returnString << "MM";
                }
                break;
            case 3:
                if(decimalSpot == 0) {
                    returnString << "III";
                }
                else if(decimalSpot == 1) {
                    returnString << "XXX";
                }
                else if(decimalSpot == 2) {
                    returnString << "CCC";
                }
                else if(decimalSpot == 3) {
                    returnString <<  "MMM";
                }
                break;
            case 4:
                if(decimalSpot == 0) {
                    returnString << "IV";
                }
                else if(decimalSpot == 1) {
                    returnString << "XC";
                }
                else if(decimalSpot == 2) {
                    returnString << "CM";
                }
                break;
            case 5:
                if(decimalSpot == 0) {
                    returnString << "V";
                }
                else if(decimalSpot == 1) {
                    returnString << "L";
                }
                else if(decimalSpot == 2) {
                    returnString << "D";
                }
                break;
            case 6:
                if(decimalSpot == 0) {
                    returnString << "VI";
                }
                else if(decimalSpot == 1) {
                    returnString << "LX";
                }
                else if(decimalSpot == 2)  {
                    returnString << "DC";
                }
                break;
            case 7:
                if(decimalSpot == 0) {
                    returnString << "VII";
                }
                else if(decimalSpot == 1) {
                    returnString << "LXX";
                }
                else if(decimalSpot == 2)  {
                    returnString << "DCC";
                }
                break;
            case 8:
            if(decimalSpot == 0) {
                    returnString << "VIII";
                }
                else if(decimalSpot == 1) {
                    returnString << "LXXX";
                }
                else if(decimalSpot == 2)  {
                    returnString << "DCCC";
                }
                break;
            case 9:
                if(decimalSpot == 0) {
                    returnString << "IX";
                }
                else if(decimalSpot == 1) {
                    returnString << "XC";
                }
                else if(decimalSpot == 2)  {
                    returnString << "CM";
                }
                break;
            default:
                cout << "entered default" << endl;
        }
    }
    // cout << "\n output string is: " << returnString.str() << endl;
    roman = returnString.str();
}

int Converter::getDecimal() {
    return decimal;
}

string Converter::getRoman() {
    return roman;
}