#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "../include/getValidInt.hpp"
#include "../include/deleteOrder.hpp"
#include "../include/addOrder.hpp"
#include "../include/globalVariable.hpp"
#include "../include/setupProducts.hpp"
#include "../include/searchOrder.hpp"

// Edge Case Test: Adding an order with empty fields
TEST(OrderTest, AddOrder_EmptyFieldShouldNotCrash) {
    orderCount = 0;
    orders[0].isActive = true;
    orders[0].customerInfo[0] = "";
    orders[0].date = "2025-05-07";
    orders[0].quantities[0] = 1;
    orders[0].totalPrice = 5.00;

    EXPECT_EQ(orders[0].isActive, true);
    EXPECT_EQ(orders[0].customerInfo[0], "");
    EXPECT_EQ(orders[0].totalPrice, 5.00);
}

// Control Flow Test: DeleteOrder when none exist
TEST(OrderTest, DeleteOrder_NoOrdersShouldPrintMessage) {
    orderCount = 0;
    testing::internal::CaptureStdout();

    // Redirect cin to avoid waiting for input
    std::istringstream dummy_input("dummy\n");
    std::streambuf* orig_cin = std::cin.rdbuf(dummy_input.rdbuf());

    deleteOrderDeclaration::deleteOrder();
    std::string output = testing::internal::GetCapturedStdout();

    // Restore cin
    std::cin.rdbuf(orig_cin);

    EXPECT_TRUE(output.find("Order not found.") != std::string::npos)
        << "Actual output was: " << output;
}

// Logic Test: Revenue calculation
TEST(OrderTest, RevenueCalculation_AddTwoOrders) {
    orderCount = 2;
    orders[0].isActive = true;
    orders[0].totalPrice = 10.50;
    orders[1].isActive = true;
    orders[1].totalPrice = 20.00;

    totalRevenue = orders[0].totalPrice + orders[1].totalPrice;
    EXPECT_DOUBLE_EQ(totalRevenue, 30.50);
}
//
//
//
//
//
//Tests to see that getValidInt rejects non-int input
TEST(InputValidationTest, RejectsNonIntegerForValidInt) {
    std::istringstream input("4.5\n10\n");
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    int result = intValidation::getValidInt(1, 100);
    std::cin.rdbuf(orig);
    EXPECT_EQ(result, 10);
}

//Tests to see if a non-whole number is a valid input
TEST(ProductQuantityTest, RejectsDecimalInputForQuantity) {
    std::istringstream input("3.2\n5\n");
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    int result = intValidation::getValidInt(0, 100);
    std::cin.rdbuf(orig);
    EXPECT_EQ(result, 5);
}

//tests to see if toLowerCase function is working
TEST(OrderSearchTest, CaseInsensitiveCustomerNameMatch) {
    std::string storedName = "John Smith";
    std::string searchInput = "john smith";
    EXPECT_EQ(deleteOrderDeclaration::toLowerCase(storedName), deleteOrderDeclaration::toLowerCase(searchInput));
}

//checks to see if space is valid input
TEST(ProductSetupTest, AcceptsSpaceAsProductName) {
    std::istringstream input("1\n \n1.99\n");
    std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

    setProductsDeclaration::setupProducts();

    std::cin.rdbuf(origCin);

    EXPECT_EQ(products[0], " ");
    EXPECT_DOUBLE_EQ(prices[0], 1.99);
}

//Tests if toLowerCase function is being used when searching
TEST(OrderSearchTest, IsCaseInsensitive) {
    Order testOrder;
    testOrder.customerInfo[0] = "Alice Johnson";
    testOrder.date = "2025-05-15";
    testOrder.totalPrice = 20.00;
    testOrder.isActive = true;
    orders[0] = testOrder;
    orderCount = 1;


    std::istringstream input("alice johnson\n");
    std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    searchOrderDeclaration::searchOrder();
    std::string output = testing::internal::GetCapturedStdout();

    std::cin.rdbuf(origCin);

    EXPECT_NE(output.find("Order Found"), std::string::npos) << "Order not found due to case sensitivity";
}