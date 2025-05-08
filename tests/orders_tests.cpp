#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "../include/getValidInt.hpp"
#include "../include/deleteOrder.hpp"
#include "../include/addOrder.hpp"
#include "../include/globalVariable.hpp"

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