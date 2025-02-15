//
//  setupCustomerFields.cpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//

#include "setupCustomerFields.hpp"
#include "globalVariable.hpp"
#include "getValidInt.hpp"
#include <iostream>
using namespace std;

//Setup Customer Fields (e.g., Name, Phone). I use 5 max the max for this program but we can always increase it
void setCustomerDeclaration::setupCustomerFields() {
    cout << "How many details should customers provide? (e.g., Name, Phone) Max 5: ";
    numFields = intValidation::getValidInt(1, 5);  // make sure it is between 1 and 5
    
    
    // we can't use for ranged based loop here because we need to stop after the loop depending on the user answer
    for (int i = 0; i < numFields; i++) {
        cout << "Enter field #" << i + 1 << " (e.g., Name, Phone): ";
        getline(cin, customerFields[i]);   //storing customer informations 
    }
}
