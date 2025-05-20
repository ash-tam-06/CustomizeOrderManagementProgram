//
//  deleteOrder.cpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//
// sometime, we dont want to full our system and we decided to delete some really old orders or in the case that we has a false order

#include "../include/deleteOrder.hpp"
#include "../include/globalVariable.hpp"
#include <iostream>
#include <cctype> // for tolower
using namespace std;



string deleteOrderDeclaration::toLowerCase(const string &str) {
    string lowerStr = str;
    for (char &c : lowerStr) c = tolower(c);
    return lowerStr;
}

// Delete an Order
void deleteOrderDeclaration::deleteOrder() {
    string name;
    cout << "Enter the customer name to delete the order: "; // locate a specific order by the customer name and delete it.
    getline(cin, name);
    
    // Convert name to lowercase for case-insensitive comparison to improve the search 
    string lowerCaseName = toLowerCase(name);
    
    for (int i = 0; i < orderCount; i++) {
        if (orders[i].isActive) {
            string customerNameLower = toLowerCase(orders[i].customerInfo[0]);
            
            if (customerNameLower == lowerCaseName) {
                orders[i].isActive = false;  // since we deleted it, we change its status to false so it is not showing anymore
                totalRevenue -= orders[i].totalPrice; // now since we delete it, we Reduce the revenue
                cout << "Order deleted successfully!\n";
                return;  // exit this function once action is done
            }
        }
    }
    cout << "Order not found.\n";
}
