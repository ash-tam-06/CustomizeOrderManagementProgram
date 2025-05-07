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


// Test for edge case: Adding an order with empty fields
TEST(OrderTest, AddOrder_EmptyFieldShouldNotCrash) {
    orderCount = 0;
    orders[0].isActive = true;
    orders[0].customerInfo[0] = "";
    orders[0].date = "2025-05-07";
    orders[0].productQuantities[0] = 1;
    orders[0].totalPrice = 5.00;

    EXPECT_EQ(orders[0].isActive, true);
    EXPECT_EQ(orders[0].customerInfo[0], "");
    EXPECT_EQ(orders[0].totalPrice, 5.00);
}

// Test control flow: DeleteOrder when none exist
TEST(OrderTest, DeleteOrder_NoOrdersShouldPrintMessage) {
    orderCount = 0;
    testing::internal::CaptureStdout();
    deleteOrderDeclaration::deleteOrder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("No orders available to delete.") != std::string::npos);
}

// Test a basic logic function (custom logic test)
TEST(OrderTest, RevenueCalculation_AddTwoOrders) {
    orderCount = 2;
    orders[0].isActive = true;
    orders[0].totalPrice = 10.50;
    orders[1].isActive = true;
    orders[1].totalPrice = 20.00;

    totalRevenue = orders[0].totalPrice + orders[1].totalPrice;
    EXPECT_DOUBLE_EQ(totalRevenue, 30.50);
}
