#include "../include/globalVariable.hpp"

// Define all global variables
double totalRevenue = 0;
int numProducts = 0, numFields = 0, orderCount = 0;
std::string products[MAX_PRODUCTS];
double prices[MAX_PRODUCTS]; 
std::string customerFields[5];
Order orders[MAX_ORDERS];