//
//  main.cpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//
#include "include/setupProducts.hpp"// to access setupProducts since it is in the folder OrderMangement

#include "include/setupCustomerFields.hpp" // to access setupCustomerFields since it is in the folder OrderMangement
#include "include/menu.hpp"  // to access menu since it is in the folder OrderMangement

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(int argc, const char * argv[]) {

    // just want to make something fancy to welcome the user
    srand(time(0));
    double randNumber = 53 + (rand() % 2);

    // let's make a proper implementation of type conversion
    int numberCharacter = static_cast<int>(randNumber);

    cout << setfill('*')<<setw(numberCharacter)<<""<<endl<<endl;
    cout << "Welcome to the Customizable Order Management System!\n"<<endl;
    cout << setfill('*')<<setw(numberCharacter)<<""<<endl<<endl;


    setProductsDeclaration::setupProducts();  // using setProductsDeclaration because setupProducts is in the namespace named " setProductsDeclaration"

    // we want to start our program by setting up product because we can't do any actions if we don't have any product to sell


    setCustomerDeclaration::setupCustomerFields();
    // Now that we have product, we need customer to but it and this function help check in the customer by storing some details about the customer


    //keep repeting our menu to give option to the customer
    menuDeclaration::menu();

    return 0;
}

