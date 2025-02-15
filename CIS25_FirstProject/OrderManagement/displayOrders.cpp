//
//  displayOrders.cpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//

#include "displayOrders.hpp"
#include "globalVariable.hpp"
#include <iomanip>
#include <iostream>
using namespace std;
// Step 4: Display Orders

void displayOrderDeclaration::displayOrders() {
    cout << "List of all orders:\n";
    for (int i = 0; i < orderCount; i++) {
        if (!orders[i].isActive) continue;  // Skip inactive orders, we just want to print what is currently running, so by using continue, we skip all those below instruction untill the end of the loop

        // Only reach here if the order is active and print order's details
        cout << "Order #" << i + 1 << " (Date: " << orders[i].date << ")\n";  // print the date
        for (int j = 0; j < numFields; j++) {
            cout << customerFields[j] << ": " << orders[i].customerInfo[j] << "\n"; // print its name depending on how much informations the customer provided
        }
        for (int k = 0; k < numProducts; k++) {
            cout << products[k] << ": " << orders[i].quantities[k] << "\n"; // print its quantity (what the customer purchase
        }
        cout << "Total Price: $" << fixed << setprecision(2) << orders[i].totalPrice << "\n"; // print the price of each orders
        cout << "-------------------------\n";
    }

}

