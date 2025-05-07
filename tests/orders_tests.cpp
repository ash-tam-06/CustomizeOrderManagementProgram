//
// Created by William Tissi on 5/6/25.
//
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "../include/getValidInt.hpp"
#include "../include/deleteOrder.hpp"
#include "../include/addOrder.hpp"
#include "../include/globalVariable.hpp"

// Redirect cin and cout for testing
using namespace std;

// Test getValidInt with valid and invalid input
TEST(InputValidationTest, ValidIntegerInput) {
    stringstream input("5\n");
    streambuf* origCin = cin.rdbuf(input.rdbuf());

    int result = intValidation::getValidInt(1, 10);
    EXPECT_EQ(result, 5);

    cin.rdbuf(origCin);
}

TEST(InputValidationTest, InvalidThenValidInput) {
    stringstream input("abc\n15\n7\n");
    streambuf* origCin = cin.rdbuf(input.rdbuf());

    int result = intValidation::getValidInt(1, 10);
    EXPECT_EQ(result, 7);

    cin.rdbuf(origCin);
}

// Helper to setup a fake order
void setupFakeOrder(string name, double price, bool active = true) {
    orderCount = 1;
    totalRevenue = price;
    orders[0].customerInfo[0] = name;
    orders[0].totalPrice = price;
    orders[0].isActive = active;
}

// Test deleteOrder for successful deletion
TEST(OrderManagementTest, DeleteOrderSuccess) {
    setupFakeOrder("Alice", 99.99);

    stringstream input("alice\n");
    streambuf* origCin = cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    deleteOrderDeclaration::deleteOrder();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(orders[0].isActive);
    EXPECT_DOUBLE_EQ(totalRevenue, 0);
    EXPECT_NE(output.find("Order deleted successfully"), string::npos);

    cin.rdbuf(origCin);
}

// Test deleteOrder when customer not found
TEST(OrderManagementTest, DeleteOrderNotFound) {
    setupFakeOrder("Bob", 50.00);

    stringstream input("Charlie\n");
    streambuf* origCin = cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    deleteOrderDeclaration::deleteOrder();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(orders[0].isActive);
    EXPECT_DOUBLE_EQ(totalRevenue, 50.00);
    EXPECT_NE(output.find("Order not found"), string::npos);

    cin.rdbuf(origCin);
}

// Test addOrder when max orders reached
TEST(OrderEdgeCaseTest, MaxOrderLimitReached) {
    orderCount = MAX_ORDERS;
    testing::internal::CaptureStdout();
    addOrderDeclaration::addOrder();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Order limit reached"), string::npos);
}
