// converter.h for coding challenge

#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>

using namespace std;

class Converter {
    private:
        int decimal = -999;
        string roman = "XXXXXXXXXX";

    public:
        Converter(int newDecimal):decimal(newDecimal) {}
        Converter(string newRoman):roman(newRoman) {}

        bool validateDecimal();
        bool validateRoman();
        void convertToDigit();
        void convertToRoman();

        int getDecimal();
        string getRoman();


};



#endif //end converter.h