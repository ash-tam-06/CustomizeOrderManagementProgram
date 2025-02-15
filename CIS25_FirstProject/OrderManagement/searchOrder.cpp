//
//  searchOrder.cpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//
// this function help us avoid to go though each order in case we have many orders
#include "searchOrder.hpp"
#include "globalVariable.hpp"
#include "displayOrders.hpp"
#include <iostream>
using namespace std;

// Search Order by Name or Date
void searchOrderDeclaration::searchOrder() {
    string searchQuery;
    
    // you can either search by the name or date, in case you are having trouble with name, you just want to enter the date
    cout << "Enter customer name or date to search: ";
    getline(cin, searchQuery);
    
    bool found = false;
    for (int i = 0; i < orderCount; i++) {
        if (orders[i].isActive &&
            (orders[i].customerInfo[0] == searchQuery || orders[i].date == searchQuery)) {
            cout << "Order Found!\n";
            displayOrderDeclaration::displayOrders();  //once found, we need to print it
            found = true;
            break;
            // I didn't use ternary operation here because I can't include break in there 
        }
    }
    if (!found) {  // in case it is notstore in the system 
        cout << "No matching order found.\n";
    }
}
