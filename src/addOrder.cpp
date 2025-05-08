//
//  addOrder.cpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//
#include <iostream>
using namespace std;
#include "../include/addOrder.hpp"
#include "../include/globalVariable.hpp"
#include <iomanip>
#include "../include/getValidInt.hpp"

//  Add Order
void addOrderDeclaration::addOrder() {
    if (orderCount >= MAX_ORDERS) {   // I used 100 as the max order here, just because i dont want to make the program longer, but we can edit it anytime in global variable file
        cout << "Order limit reached! You may want to delete some really old order\n";
        //in this case, immediately get out of the function.
        return;      // can't use ternary operator because of the return
    }
    
    cout << "Enter order details:\n";
    for (int i = 0; i < numFields; i++) {
        cout << customerFields[i] << ": ";   // set up the customer details
        getline(cin, orders[orderCount].customerInfo[i]);
    }
    
    cout << "Enter order date (YYYY-MM-DD): ";  // set up the date
    getline(cin, orders[orderCount].date);
    
    double total = 0;
    cout << "Enter product quantities:\n";    // purchase of the customer
    for (int i = 0; i < numProducts; i++) {
        cout << products[i] << " ($" << fixed << setprecision(2) << prices[i] << " each): ";
        orders[orderCount].quantities[i] = intValidation::getValidInt(0, 1000);
        total += orders[orderCount].quantities[i] * prices[i];
    }
    // now we have the total amount of the purchase
    
    orders[orderCount].totalPrice = total;
    totalRevenue += total;    // add the specific purchase to the revenue
    orders[orderCount].isActive = true;  // make thee order active
    orderCount++;  // since the field is now full let increase the order count so the next time it moves on to the next case(array)
    
    cout << "Order added successfully! Total due: $" << fixed << setprecision(2) << total << "\n";
}
