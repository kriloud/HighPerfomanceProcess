//
//  main.cpp
//  HighPerfomanceProcess
//
//  Created by Ilya on 04.09.2025.
//

#include "math_sqr.h"
#include "sha256.hpp"
#include "xor_cipher.h"
#include "chalanger.hpp"
#include "rambo.hpp"
#include <iostream>
using namespace std;

void use_sha256() {
    string input;
    cout << "Enter something: ";
    cin >> input;
    cout << sha256(input) << endl;
}

void use_xor() {
    string input;
    string key;
    cout << "Enter something: ";
    cin >> input;
    cout << "Enter Key: ";
    cin >> key;
   // cout << xor_encrypt_string(input, key) << endl;
}

int main() {
    int usless;
    
    cout << "Hello, World!\n" << endl;
    cout << "HighPerfomanceProccess" << endl;
    cout << "To use rambo method press 1 " << endl << "To use de rambo method press 2 " << endl << "To use sha256 press 3" << endl;
    cout << "To use XOR press 4" << endl;
    cout << "So, what do you need? #> ";
    cin >> usless;
    switch (usless) {
        case 1:
            rambo();
            break;
        case 2:
            chalanger();
            break;
        case 3:
            use_sha256();
            break;
        case 4:
            use_xor();
            break;
            
        default:
            break;
    }
    
    return 0;
}
