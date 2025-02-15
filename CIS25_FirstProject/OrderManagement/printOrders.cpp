//
//  printOrders.cpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//

// the boss of the store need to see how the activities is going and need to know what much the store make daily
//reason why i decided to have a functions that print everthings for the boss


#include "printOrders.hpp"
#include "displayOrders.hpp"
#include "globalVariable.hpp"

#include <iostream>
#include <iomanip>
using namespace std;
//Print Orders and Total Revenue
void printOrdersDeclaration::printOrders() {
    
    cout << "\n======= Order Summary =======\n";
    displayOrderDeclaration::displayOrders();  // displaying all orders and the total revenue 
    cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << "\n";
}
