//
//  setupProducts.cpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//

#include "../include/setupProducts.hpp"
#include "../include/getValidInt.hpp"
#include "../include/globalVariable.hpp"
#include "../include/getValidDouble.hpp"

using namespace std;
// Step 1: Setup Products and Prices
void setProductsDeclaration::setupProducts() {
    cout << "Enter the number of products you have (max " << MAX_PRODUCTS << "): ";
    numProducts = intValidation::getValidInt(1, MAX_PRODUCTS);  //giving the max product we have
    // tips: we wouldn't need this max product if I had used a vector since a vector don have an ending number of characer
    
    for (int i = 0; i < numProducts; i++) {
        cout << "Enter product #" << i + 1 << ": ";
        getline(cin, products[i]);  // setting up products
        
        cout << "Enter price for " << products[i] << ": $";  // setting up prices for each product
        prices[i] = doubleValidation::getValidDouble(0.01);  // a price can't go below $0.01, so we need to make sure 
    }
}
