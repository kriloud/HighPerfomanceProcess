//
//  main.cpp
//  HighPerfomanceProcess
//
//  Created by Ilya on 04.09.2025.
//

#include "math_sqr.h"
#include <iostream>
using namespace std;



void rambo() {
    double number1;
    cout << "Enter number: " << endl;
    cin >> number1;
    cout << sqr((((number1+1)*5)/2)*19);
}

void chalanger() {
    double number1;
    cout << "Enter number: " << endl;
    cin >> number1;
    cout << round((((sqrt(number1)/19)*2)/5)-1) << endl; //sqrt((((number1-1)/5)*2)/19);

}


int main() {
    int usless;
    
    cout << "Hello, World!\n" << endl;
    cout << "HighPerfomanceProccess" << endl;
    cout << "To use rambo method press 1";
    cin >> usless;
    switch (usless) {
        case 1:
            rambo();
            break;
        case 2:
            chalanger();
            break;
            
        default:
            break;
    }
    
    return 0;
}
