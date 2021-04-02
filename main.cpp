//main for coding challenge

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "converter.h"

using namespace std;

void printOptions() {
    cout << "Options:" << endl;
    cout << "  1) Input a decimal value and output the roman numeral equivalent." << endl;
    cout << "  2) Input a roman numeral and output the decimal value equivalent." << endl;
    cout << "  3) Enter \"quit\" to end the progam." << endl;
    cout << "  4) Enter \"test\" to run an automated test that tests both converting from decimal to roman numeral as well as roman numeral to decimal." << endl;
    cout << "  5) Enter \"options\" to view the options again." << endl;
}

void runTest() {
    vector<int> decimalVals = {1, 15, 389, 2200, 49};
    cout << "Running tests on convertToRoman()" << endl;
    for(unsigned int val = 0; val < decimalVals.size(); val++) {
        cout << "input decimal value is: " << decimalVals.at(val) << endl;
        cout << "output roman numeral is: " << endl;
    }

}

int main() {
    string input;
    int decimalInput;
    cout << "This is a roman numeral converter." << endl;
    printOptions();
    cin >> input;

    while(input != "quit") {
        if(input == "options") {
            printOptions();
        }
        else if(input == "test"){
            runTest();
        }
        else {
            if(isdigit(input.at(0))) {
                stringstream intCasting(input);
                intCasting >> decimalInput;
                Converter userConverter = Converter(decimalInput);
                if(userConverter.validateDecimal()) {
                    userConverter.convertToRoman();
                    // cout << "Input decimal value is: " << decimalInput << endl;
                    cout << "Output roman numeral is: " << userConverter.getRoman() << endl;
                }
            }
            else if((input.at(0) == 'I') || (input.at(0) == 'V') || 
                    (input.at(0) == 'X') || (input.at(0) == 'L') || 
                    (input.at(0) == 'C') || (input.at(0) == 'D') || 
                    (input.at(0) == 'M')) {
                Converter userConverter = Converter(input);
                if(userConverter.validateRoman()) {
                    userConverter.convertToDigit();
                    // cout << "Input roman numeral is: " << input << endl;
                     cout << "Output decimal value is: " << userConverter.getDecimal() << endl;
                }
            }
            else {
                cout << "This is an invalid input." << endl;
                printOptions();
            }
        }
        cin >> input;
    }

    cout << "End of program." << endl;
    
    return 0;
}