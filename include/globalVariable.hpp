#ifndef GLOBAL_VARIABLE_HPP  // Use uppercase for header guards
#define GLOBAL_VARIABLE_HPP

#include <string>
#include <array>  // Consider using std::array instead of raw arrays

constexpr int MAX_ORDERS = 100;
constexpr int MAX_PRODUCTS = 10;

struct Order {
    std::string customerInfo[5];  // Customer details (Name, Phone, etc.)
    int quantities[MAX_PRODUCTS]; // Product quantities (FIXED NAME)
    double totalPrice;
    std::string date;
    bool isActive;
};

// Declare all extern variables
extern double totalRevenue;
extern std::string products[MAX_PRODUCTS];
extern double prices[MAX_PRODUCTS]; 
extern std::string customerFields[5];
extern int numProducts, numFields, orderCount;
extern Order orders[MAX_ORDERS];

#endif