//  globalVariable.hpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//




// Since my program required some variables and those variables would be use in many different functions (different files), I thought about creating a separete file for all my global variable so i can just include this library in any file that is using our global variable

#ifndef globalVariable_hpp
#define globalVariable_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

extern double totalRevenue; // Store’s total earnings
//The purpose of extern is to declare a variable or function that is defined in another file.
//since this is out header file and we just want to use it to declared variable that is why i used extern and now can can define it in the source file (cpp file)


 const int MAX_ORDERS= 100; // Max orders
const int MAX_PRODUCTS = 10; // Max products


//Here I try to be a little creative. Instead of using class I use struct abd it works pretty much like class, the difference is with a Struct, member are public by default .
// since an order require informations like the customer informations, the quantity of purchases, the total price and the date, I thought that using struct willl be a better idea and I came up with the idea about bool isActive to mark the status of an order in the system


struct Order {
    string customerInfo[5]; // Customer details (Name, Phone, etc.)
    int quantities[MAX_PRODUCTS]; // Product quantities
    double totalPrice; // Total price of the order
    string date;
    bool isActive;
};

// Global variables
extern string products[MAX_PRODUCTS]; // Product names
extern double prices[MAX_PRODUCTS]; // Product prices
extern string customerFields[5]; // Customer details required
extern int numProducts, numFields, orderCount ;
extern Order orders[MAX_ORDERS];// Array to store orders

#endif /* globalVariable_hpp */
